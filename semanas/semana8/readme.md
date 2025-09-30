# Clase 1

## Contenedores 

### Que es un contenedor

Es una unidad ligera autonoma y ejecutable que contiene todo lo necesario para ejecutar una aplicacion: codigo, librerias, dependencias y configuraciones

permite mover, ejecutar y escalar con facilidad

### Contenedores vs maquinas virtuales

La maquina virtual "piensa" que es la maquina normal en la que se ejecuta todo, permite la virtualizacion a nivel de hardware permitiendo que varios sistemas operativos se ejecuten en la misma maquina, requiere una maquina fisica con un sistema operativo, un hipervisor, un sistema operativo para el invitado y el software con sus bibliotecas/binarios necesarios

Los contenedores se ejecutan en el sistema operativo local, requiere la maquina fisica con un sistema operativo el motor del contenedor  y el software con todos sus bibliotecas y binarios necesarios

### Docker

Es una plataforma abierta que permite gestionar los contenedores

- **Docker client**: Herramienta con la que interactua el usuario
- **Docker Daemon**: Ejecuta y gestiona contenedores
- **Docker Images**: Plantillas con todo lo necesario para crear una app
- **Docker containers**: Instancia viva de una imagen
- **Docker Registry (ej. Docker Hub)**:  Lugar donde se descargan o suben las imagenes

### Arquitectura de docker

Cliente, se conecta al Daemon que ejecuta o crea un contenedor, en caso de que todavia no este creado, solicita que se registre si no hay ni contenedor, ni imagen definida

### Dockerfile

Tiene todo lo necesario para convertir algo en un contenedor

Ejemplo:

```Dockerfile
# Todo contenedor debe tener una imagen base
FROM imagen

COPY requirements.txt

RUN pip install --no-cache-dir -r requirements.txt

COPY . .

# Expone el puesto de desarrollo por defecto de django
EXPOSE 8000

CMD [¨python¨, ¨manage.py¨, ¨runserver¨]
```
### Volumenes, redes y persistencia en Docker

los volumenes son almacenes de datos persistentes para contenedores
Al crear un volumen, este se almacena en un directorio del host de Docker. Al montar el volumen en un contenedor este directorio es el que se monta en el contenedor (Se monta la ruta hacia el directorio)
Por defecto los datos de un contenedor se pierden al eliminarlo

Container Networking se refiere a la capacidad de loscontenedores para conectarse y comunicarse entre sí

Tipos de redes

- **Bridge**: Solo permite realizar conecciones dentro de la maquina fisica.

- **None**: No tiene acceso a ningun otro contenedor.

- **Host**: Permite realizar coneccion con todo fuera de la maquina fisica incluso.

### Kubernetes

Permite gestionar varios contenedores para trabajar en conjunto

Un manifiesto YAML 

Es un archivo de estructurado que define las estructuras que se tienen que seguir, puede describir pods, deployments, servicios, secretos, etc

### Containerd

Es un runtime de contenedores de bajo nivel, ejecuta, pausa y gestiona el ciclo de vida de los contenedores
