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

# Clase 2

## Inteligencia Artificial (IA)

Busca reproducir la inteligencia humana en máquinas mediante:

- Razonamiento probabilístico  
- Percepción  
- Robótica  
- Toma de decisiones  

La IA intenta crear una **red neurológica a partir de datos**.

---

## Machine Learning (ML)

- Subconjunto de la IA.  
- Se centra en **aprender patrones a partir de datos**.  
- Se utiliza para **clasificar, predecir o inferir**, sin necesidad de programación explícita.  

---

## IA Tradicional

- Basada en **reglas y razonamiento explícito**.  
- Usada principalmente por personas expertas.  

## IA Moderna

- Aprende de **grandes volúmenes de datos**.  
- Es más **flexible, adaptable y escalable**.  
- Puede ser utilizada por cualquier persona con mayor facilidad.  

## Herramientas y Lenguajes

**Python** → Lenguaje más utilizado en ciencia de datos por su simplicidad y versatilidad, ademas posee miles de bibliotecas útiles para el análisis de datos.  

### Bibliotecas principales

- **Scikit-learn** → Predicción de datos.  
- **TensorFlow** y **PyTorch** → Deep Learning y redes neuronales.  

## Entornos de Desarrollo

- Jupyter Notebooks  
- Google Colab  
- Azure ML  
- Kaggle  

## Aplicaciones Reales

 **Sistemas de recomendación** → Analizan lo que consumimos y generan recomendaciones personalizadas.  
 **Chatbots y asistentes virtuales** → Usan PLN y ML para conversaciones en tiempo real.  
 **Mantenimiento preventivo** → Análisis de fallas en tiempo real con sensores + IA.  
 **Visión por computadora** → Permite a las máquinas interpretar imágenes y videos.  

## Datos y sociedad

- **Bases de datos = infraestructura social** → no son neutrales, influyen en la vida diaria.  
- **Sesgos en datos** → producen tecnologías sesgadas que generan desigualdades.  
- **Aspecto ético** → las IA funcionan como sistemas sociotécnicos invisibles que afectan decisiones cotidianas.  

## Datos Sintéticos

**Definición** → datos generados artificialmente por algoritmos para imitar datos reales.  
**Ventajas** → privacidad, balance de clases, escalabilidad.  
**Riesgos**:  

- Reproducción de sesgos originales.  
- Resultados poco realistas (ej: combinaciones absurdas).  
- Dependencia del modelo generador (si está sesgado, se traslada).  

## Riesgos de Sesgo

- Datos de entrenamiento poco representativos → sesgos de género, raza, edad, geografía, etc.  
- No solo es falta de datos, sino **cómo se recolectan y seleccionan variables**.  
- Los intereses de empresas pueden influir en qué datos se usan.  
- Consecuencia: sistemas injustos o discriminatorios.

## Privacidad

- Los sistemas automatizados pueden usar **datos privados sin transparencia** sobre su uso y almacenamiento.  
- Es necesario establecer **métodos claros** para la recolección y manejo de datos.  
- Debe existir **seguimiento continuo** al aprendizaje de la IA para evitar sesgos o interpretaciones incorrectas.  

## Areas laborales

- Data scientist
- ML Engineer
- AI Researcher

## Bases de Datos y Big Data

### Tipos de Bases de Datos

- **Relacionales** → Esquema fijo, cada columna tiene un valor específico.  
  Permiten consultas estructuradas y relaciones entre tablas.  
- **No relacionales** → No requieren esquema fijo.  
  Guardan distintos tipos de datos (JSON, key-value, etc.).  

### Evolución de los Datos

- El volumen de datos ha crecido exponencialmente.  
- Se requiere mayor **velocidad de consulta y análisis**.  
- Han surgido **nuevos tipos de datos**, lo que hace insuficiente el procesamiento tradicional.  

### Big Data

Surge como solución a estos retos, caracterizado por:

- **Segmentación de datos**  
- **Procesamiento en paralelo**  
- **ETL (Extracción, Transformación y Carga)**  

### Casos de uso

- Netflix IA para sistemas de recomendaciones
- Amazon Base de datos para Analisis predictivo 
- Uber Utiliza los datos para calcular rutas, tiempos y asi poder calcular el tiempo

### Problemas a Resolver

- Los datos modernos incluyen **fotos, videos, imágenes y archivos pesados**.  
- Requieren sistemas más **flexibles y estables** que las bases de datos tradicionales.  

### Areas laborales

- Database administrator
- Data Engineer
- Arquitecto de datos