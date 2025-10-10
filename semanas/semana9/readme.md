# Cloud computing

## Modelos de servicio

### 1. IaaS (Infrastructure as a Service)

Proporciona recursos básicos de cómputo como **máquinas virtuales, redes y almacenamiento**.  
Ejemplos:

- Amazon S3
- Google Compute Engine

### 2. PaaS (Platform as a Service)

Ofrece una **plataforma completa** que incluye el sistema operativo, middleware y herramientas de desarrollo.  
Facilita el **despliegue y administración de aplicaciones** sin preocuparse por la infraestructura subyacente.  
Ejemplos:

- Microsoft Azure
- Heroku

### 3. SaaS (Software as a Service)

Proporciona **aplicaciones listas para usarse directamente desde la nube**, accesibles mediante un navegador o aplicación.  
Ejemplos:

- Google Workspace
- Microsoft 365

## Modelos de Implementación en la Nube

El Cloud Computing puede implementarse de diferentes maneras según las necesidades de la organización:

- Nube Pública:
- Nube Privada:
- Nube Híbrida:
- Nube Comunitaria:

## Tecnologias clave

- Virtualizacion
- Contenedores
- Redes definidas por software
- Automatizacion y orquestacion de recursos

## Provedoores principales

- Amazon web
- Microsoft Azure
- Google cloud platform

## Retos y oportunidades

### Retos

- **Seguridad y privacidad**: En la nube la informacion es guardada por terceros, lo que implica confiar en los proovedores con la seguridad de datos, por lo que requiere auditorias continuas y una buena gestion de los datos
- **Dependencia de proveedores**: Cada proovedor utiliza tecnologias distintas, por lo que seria dificil moverse de un proveedor a otro nuevo, por lo que se recomienda tener estandares abiertos para facilitar la migracion
- **Cumplimiento de normativas**: Los datos almacenados en centros de datos tienen que cumplir las normativas del lugar en el que se almacenan

### Oportunidades

- **Escalabilidad global**: Debido a la infraestructura virtualizada se puede escalar facilemtente de manera rapida, sin necesidad de obtener nueva infraestructura
- **Reduccion de costos de infraestructura**: No se requiere invertir en infraestructura, personal tecnico y energia para gestionar los datos, simplemente se paga por uso, es decir se paga por los recursos que se consumen
- **Acceso a tecnologiasd e IA, big data y machine learning**: La nube ofrece herramientas preconfiguradas y escalables que se puede acceder desde cualquier lugar, lo que permite comenzar proyectos sin la necesidad de inversiones necesarias

### Conclusiones

- La computacion se ha consolidado como una herramienta clave para el desarrollo tecnologico modero

- A pesar de que hay distintos retos, con buenas practicas, estandares y arquitecturas se pueden mitigar

- La nube presenta una evolucion natural en la gestion de datos o la gestion de recursos informaticos, lo que da mayor accesibilidad

# Sistemas Embebidos

Son sistemas diseñados para realizar una **tarea específica**, normalmente con **recursos limitados** y programados en **lenguajes de bajo nivel** para maximizar la eficiencia.

## Tipos de sistemas embebidos

- Sistemas móviles integrados  
- Sistemas de control industrial  
- Sistemas médicos  
- Sistemas de telecomunicaciones  
- Sistemas de seguridad

## Ejemplos

- Automóviles  
- Medicina  
- Electrodomésticos  
- Maquinaria industrial  
- Telecomunicaciones  
- Sistemas de seguridad  

---

## IoT (Internet of Things)

El **Internet de las Cosas (IoT)** es un conjunto de dispositivos interconectados que pueden **comunicarse entre sí y con la nube**, permitiendo la automatización y el monitoreo remoto.

---

## Entornos de desarrollo (IDE) para sistemas embebidos

Existen diferentes tipos de entornos de desarrollo integrados (IDE) que permiten programar y gestionar dispositivos embebidos:

### 1. Arduino IDE de escritorio

- Permite trabajar **sin conexión a internet**.  
- Ofrece **control total sobre bibliotecas, configuraciones y compilaciones locales**.  
- Es ideal para desarrolladores que desean un entorno completo en su computadora.

### 2. Arduino Web Editor (Arduino Cloud Editor)

- Permite **programar directamente desde el navegador**.  
- Sincroniza los proyectos automáticamente con la nube.  
- Facilita el trabajo colaborativo y el acceso desde distintos dispositivos.

### 3. Arduino IoT Cloud

- Es una **extensión enfocada al Internet de las Cosas (IoT)**.  
- Permite la **conexión y comunicación remota entre dispositivos** desde cualquier parte del mundo.  
- Ofrece funciones como:
  - Creación automática de código para dispositivos conectados.  
  - Configuración de variables y tipos de datos.  
  - Conexión Wi-Fi y generación de funciones que responden a eventos.  
  - Creación de **paneles de control personalizados (Dashboards)** para visualizar y controlar datos en tiempo real.

---

## Bibliotecas

Las bibliotecas de Arduino **amplían las funcionalidades básicas** de la placa y facilitan la interacción con sensores, pantallas LCD, actuadores y otros componentes.

Ventajas:

- Permiten **reutilizar código** y ahorrar tiempo de desarrollo.  
- Se pueden instalar tanto desde el **IDE de escritorio** como desde el **Arduino Cloud Editor**.  
- Incluyen **ejemplos preconfigurados** para facilitar el aprendizaje y la implementación.

---

### Raspberry Pi

La **Raspberry Pi** es una **minicomputadora de bajo costo y tamaño compacto**, capaz de ejecutar **Linux** y conectarse a monitores, teclados y mouse.

## Características principales

- Tamaño similar a una **tarjeta de crédito**.  
- Posee **puertos USB, HDMI, Wi-Fi, Bluetooth** y pines **GPIO** para conectar sensores y actuadores.  
- Permite realizar proyectos de **programación, electrónica, IoT y automatización**.

## Sistemas operativos

- **Raspbian:** sistema oficial basado en Linux.  
- **NOOBS:** instalador que facilita la configuración de distintos sistemas operativos.

## Usos comunes

- Mini PC para navegación web, ofimática y multimedia.  
- Servidor de impresión o servidor web (Apache, WordPress, MySQL).  
- Emulador de consolas retro (RetroPie).  
- Reproductor multimedia (Kodi).  
- Sistema NAS para almacenamiento centralizado.  
- Automatización del hogar (domótica).

## Aplicaciones del IoT y sistemas embebidos

- **Domótica:** control de luces, temperatura y seguridad del hogar.  
- **Robótica:** integración de sensores y actuadores para automatización.  
- **Dispositivos portátiles:** relojes inteligentes, monitores de salud.  
- **Automatización industrial:** control remoto y supervisión de procesos.  
- **Monitoreo ambiental:** calidad del aire, clima, contaminación.  
- **Telemedicina y seguridad:** cámaras, alarmas y sistemas médicos conectados.  
- **Educación y prototipado:** enseñanza de electrónica y programación.

## Ventajas generales

- Bajo costo y alto rendimiento.
- Consumo energético reducido.
- Amplia compatibilidad con sensores y lenguajes.
- Ideales para proyectos con conectividad y procesamiento en tiempo real.

## Areas laborales

- Firmware Developers
- IoT Developer
- Ingeniero Embebido
