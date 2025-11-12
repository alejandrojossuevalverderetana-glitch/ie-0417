# Resumen ejecutivo del sistema

La virtualización de la información y de los procesos asociados resulta esencial para optimizar la gestión y agilizar las operaciones institucionales. Es igualmente importante que dicha virtualización se base en prácticas escalables y sostenibles, que garanticen la integridad de los datos, la mantenibilidad y la eficiencia del sistema a largo plazo.

El sistema EIEInfo surge como respuesta a esta necesidad. Se trata de una plataforma web desarrollada para centralizar la gestión académica y administrativa de la Escuela de Ingeniería Eléctrica de la Universidad de Costa Rica. Su propósito es ofrecer información relevante al público general sobre las actividades y servicios de la Escuela, a la vez que brinda a estudiantes, docentes y personal administrativo un entorno integrado que facilita la realización de sus funciones. El sistema incorpora módulos de noticias, proyectos, cursos, personal, trámites y servicios, los cuales se interconectan dentro de una arquitectura escalable basada en Django y bases de datos relacionales, garantizando así un funcionamiento estable y escalable.

Con su implementación, la Escuela busca fortalecer su capacidad de gestión, reducir los tiempos de tramitación de datos, mejorar la trazabilidad de la información y promover una administración más transparente y eficiente. En conjunto, EIEInfo representa un avance significativo hacia la transformación digital y la modernización de la gestión universitaria dentro de la Universidad de Costa Rica.

# Descripción funcional del sistema

## Flujo de navegación principal
El flujo de navegación principal del sistema se puede describir por medio del siguiente diagrama:

El sistema EIEInfo inicia con una página principal o landing page, que funciona como punto de acceso común para todos los usuarios, salvo que se ingresen rutas específicas de forma directa. En esta página se despliega una barra de navegación dinámica con menús desplegables que permiten acceder a las distintas secciones del sitio. Cada opción redirige al usuario a una ruta diferente, cuya funcionalidad depende del contenido definido por el programador. En modo de desarrollo, si la base de datos se encuentra vacía, pueden presentarse errores al acceder a rutas como “/primer-ingreso”, lo que evidencia limitaciones en el manejo de excepciones.

La página principal también incluye un buscador para localizar elementos dentro del portal y ofrece las opciones de inicio de sesión y registro. Los usuarios pueden ingresar como estudiante, profesor o administrativo. En caso de no contar con una cuenta, el sistema permite registrarse como estudiante o solicitar una cuenta de profesor o administrativo. Una vez autenticado, el usuario es redirigido a su respectiva página de inicio bajo la ruta “/usuario/home/perfil”, donde puede visualizar su información personal, editar su perfil o cerrar sesión (lo cual devuelve al usuario al landing page).

Estudiantes: tienen acceso a la visualización y filtrado de cursos, asistencia en concursos, proyectos eléctricos (por categoría o tipo), documentos relevantes y ofertas de pasantías o empleo. Además, pueden enviar sugerencias mediante un formulario. Cada acción corresponde a una URL distinta dentro del sistema.

Profesores: pueden visualizar y modificar su perfil, consultar nombramientos y publicaciones, crear o filtrar anuncios y eventos, acceder a proyectos asignados o globales, consultar cursos y documentos de interés, así como enviar sugerencias mediante un formulario.

Administrativos: pueden visualizar su perfil, consultar y filtrar estudiantes, crear y filtrar anuncios y eventos (con rutas diferentes a las de los profesores), observar la reserva de espacios del edificio (aunque en modo de desarrollo se presentan colisiones de visualización en el menú lateral), consultar nombramientos interinos o en continuidad por departamento y ciclo, observar comisiones, proyectos, resúmenes del ciclo y documentos relevantes. También pueden emitir sugerencias mediante formulario.

El flujo principal se puede observar en la siguiente figura:
![<img src="./flujo_principal.png" alt="Flujo principal" width="100%">](/proyecto/images/flujo_principal.png)

## Módulos existentes

Los módulos existentes dentro del proyecto son:

- eieindo
- administrativos
- alumni
- anuncios 
- asistencias 
- atributos
- conferencias 
- cursos
- estudiantes 
- eventos
- inventario 
- laboratorios 
- practica_profesional 
- profesores
- proyecto_electrico
- profesores 
- proyectos
- trabajos_finales
- webpage

## Tipos de usuarios

Los tipos de usuario principales son: 
- Estudiantes
- Profesores
- Administrativos
- Alumni

Se consideró a alumni como un tipo de usuario ya que se debe de registrar para acceder a la página.

## Datos almacenados y gestionados.

## Datos Almacenados y Gestionados en el Sistema EIEInfo

El sistema EIEInfo organiza, almacena y gestiona información integral relacionada con la Escuela de Ingeniería Eléctrica de la Universidad de Costa Rica.  
A continuación se describen, de forma detallada, los datos almacenados (registrados en la base de datos) y los datos gestionados (usados, procesados o derivados sin ser almacenados permanentemente).

---

### 1. Datos Académicos y de Estudiantes

**Datos almacenados**  
El sistema guarda información completa sobre cada estudiante:  
- Identificación: nombre, apellidos, cédula y número de carné.  
- Contacto: correo institucional y alternativo, teléfonos y dirección.  
- Información académica: plan de estudio y estado de activación de la cuenta.  
- Seguridad: contraseñas cifradas y hashes de verificación.  
- Información bancaria: tipo de banco, número de cuenta y cuenta IBAN.  
- Imagen de perfil y estado de usuario activo o inactivo.  
- Registros de asistencias vinculadas a cursos, laboratorios o comisiones, incluyendo horas trabajadas, descripciones de tareas, tipo de asistencia, estado, nivel de urgencia y ciclo correspondiente.  
- Historial de recuperación y verificación de contraseñas con fecha de creación, expiración y estado de uso.

**Datos gestionados**  
- Envío automatizado de correos electrónicos de verificación y recuperación.  
- Activación y validación de cuentas mediante enlaces únicos.  
- Generación temporal de comprobantes o notificaciones en formato texto o HTML.  

**Constantes gestionadas**  
- `TIPOS_ASISTENCIA`: Estudiante, Asistente, Asistente Graduado.  
- `ESTADOS_ASISTENCIA`: Solicitada, En Concurso, Confirmada, Aprobada, Rechazada, Lista P9.  
- `BANCOS`: Banco Nacional, Banco de Costa Rica, Banco Popular.  
- `ESTADOS_URGENCIA`: Baja, Media, Alta.  
- `ESTADOS_PRACTICA_PROFESIONAL`: Desde Revisión de requisitos hasta Finalizada.  
- `ESTADO_REQUISITOS_GRADUCION`: Pendientes, Completos.

---

### 2. Datos Administrativos y del Personal

**Datos almacenados**  
- Información de funcionarios y profesores: nombre, apellidos, cargo, departamento y datos de contacto.  
- Registros de nombramientos con detalle de ciclo, carga horaria, rol y presupuesto asignado.  
- Estructura organizacional mediante roles, comisiones, encargados y presupuestos asociados.  
- Historial de ciclos académicos utilizados para organizar periodos de trabajo y docencia.

**Datos gestionados**  
- Generación automática de nombramientos y actualización de carga docente.  
- Validación de periodos activos y gestión de responsabilidades académicas.

---

### 3. Datos de Evaluación y Rúbricas

**Datos almacenados**  
- Niveles de rúbrica, criterios, indicadores, descriptores y atributos que conforman el modelo de evaluación.  
- Configuraciones activas de rúbricas con puntajes máximos, niveles asociados y criterios ponderados.  
- Evaluaciones realizadas a estudiantes o grupos con valores numéricos, niveles y descripciones.

**Datos gestionados**  
- Cálculo automático de valores ponderados a partir de criterios y niveles.  
- Activación y validación de configuraciones de evaluación.  
- Generación de reportes y exportaciones temporales en formato PDF o LaTeX.

---

### 4. Datos de Laboratorios y Proyectos

**Datos almacenados**  
- Información de cada laboratorio: nombre, acrónimo, tipo, departamento, descripción corta y larga, ubicación, teléfono, imagen institucional y página web.  
- Asociación de proyectos universitarios, coordinadores y colaboradores docentes.  
- Relación entre laboratorios y ciclos académicos, incluyendo nombramientos automáticos y horas de carga docente.

**Datos gestionados**  
- Creación y actualización dinámica de nombramientos según el ciclo y la persona responsable.  
- Control del estado operativo de cada laboratorio y su personal.

---

### 5. Datos de Inventario y Préstamos

**Datos almacenados**  
- Peculios: tipos de materiales o activos disponibles en bodega o laboratorio.  
- Bienes: descripción, ubicación, tipo, medio de obtención, estado operativo, fechas de adquisición, imágenes y observaciones.  
- Activos: bienes con placa, código, marca, modelo, serie, año y estado de bodega.  
- Componentes: piezas o dispositivos electrónicos con valor, tolerancia, potencia, cantidad y fabricante.  
- Computadoras: hardware detallado (procesador, RAM, almacenamiento, sistema operativo y direcciones MAC).  
- Préstamos: fechas de inicio y fin, cantidad, estado del préstamo y relación con estudiantes o funcionarios.  
- Solicitudes de peculio: cantidad y tipo de recursos solicitados.

**Datos gestionados**  
- Control y seguimiento de activos en operación, reparación o préstamo.  
- Generación de listados y reportes sobre disponibilidad y uso de recursos.  
- Actualización automática de estados según devoluciones o asignaciones.

**Constantes gestionadas**  
- `TIPO_BIENES`: Mueble, Eléctrico.  
- `TIPO_ESTADO`: Operativo, Inactivo, Reparación.  
- `TIPO_OBTENCION`: Donación, Presupuesto.  
- `ESTADOS_ACTIVO`: En Bodega, Prestado, Otro.  
- `ESTADOS_PRESTAMO`: Solicitado, Prestado, Devuelto, Devuelto Defectuoso.

---

### 6. Datos de Eventos, Conferencias y Actividades

**Datos almacenados**  
- Eventos: título, descripción corta y larga, fechas de inicio y fin, imagen, archivos descargables, lugar, funcionario responsable y estado de publicación.  
- Conferencias: expositor, institución, cantidad de cuotas, imagen, descripción y vínculo con evento.  
- Cuotas de conferencia: relación entre estudiante y conferencia con comprobante de asistencia.

**Datos gestionados**  
- Sincronización con Google Calendar.  
- Publicación automática de eventos en Facebook institucional.  
- Envío de correos automáticos de confirmación de asistencia o cuota conferencia.  
- Generación temporal de comprobantes y descripciones dinámicas (no almacenadas en la base de datos).

---

### 7. Datos de Soporte, Seguridad y Verificación

**Datos almacenados**  
- Hashes de activación y recuperación, fechas de creación y expiración, y estado de validez.  
- Relación con cuentas de usuario (estudiantes o funcionarios).  
- Registro de procesos de verificación y recuperación de contraseñas.

**Datos gestionados**  
- Envío automatizado de correos de activación y recuperación.  
- Generación temporal de enlaces seguros para verificación y restablecimiento de credenciales.  
- Validación de caducidad y control de enlaces únicos.

---

### 8. Datos Multimedia y Archivos Asociados

**Datos almacenados**  
- Rutas de acceso a archivos multimedia (no el archivo en sí).  
  - `/media/estudiantes/...` — imágenes de perfil.  
  - `/media/conferencias/...` — archivos y fotografías de eventos.  
  - `/media/inventario/...` — imágenes de activos y componentes.  
  - `/media/laboratorios/...` — fotografías institucionales.

**Datos gestionados**  
- Carga, reemplazo y eliminación de archivos multimedia.  
- Asignación de imágenes predeterminadas según categoría.  
- Actualización de rutas y referencias dentro de los modelos.

---

### 9. Datos Derivados y Procesos No Persistentes

**Datos gestionados (no almacenados)**  
- Reportes y documentos PDF o LaTeX generados dinámicamente con `GenerarLaTeX`.  
- Envío de correos automáticos mediante `EnviarEmailTemplate` o `send_mail`.  
- Sincronización con Google Calendar y publicación en Facebook.  
- Generación temporal de comprobantes, constancias y reportes bajo demanda.


# Arquitectura General del Sistema

El **diagrama de arquitectura** muestra cómo se organiza y comunica todo el ecosistema de EIEInfo, desde el **frontend** hasta la **infraestructura de despliegue**.  
Proporciona una vista global del sistema y sus interacciones principales.

### Descripción general

La arquitectura se compone de **seis niveles principales**:

1. **Frontend**  
   - Interfaz utilizada por los usuarios (navegadores y dispositivos móviles).  
   - Se comunica con el backend mediante HTTP/HTTPS.

2. **Backend principal**  
   - Núcleo del sistema encargado de procesar solicitudes y coordinar módulos internos.  
   - Basado en frameworks web (por ejemplo, Django / uWSGI).

3. **Módulos funcionales**  
   - Agrupados por dominios:
     - *Académico:* estudiantes, cursos, laboratorios, proyectos.  
     - *TFG:* trabajos finales de graduación.  
     - *Administrativo:* personal, inventario, conferencias, eventos, alumni.  
     - *Web / Soporte:* anuncios, atributos, página institucional.  

4. **Servicios externos**  
   - Extienden la funcionalidad del sistema: CRON jobs, Wiki, CKEditor/Martor y Captcha.

5. **Persistencia**  
   - Almacenamiento permanente en **PostgreSQL**, y manejo de archivos estáticos/media en `/var/info`.

6. **Infraestructura y despliegue**  
   - Basada en **Docker**, **uWSGI** y **Nginx (Servidor Faraday)** para ejecución y publicación.

### Flujo general

Usuarios → Nginx → uWSGI → Backend → Módulos → Servicios / Base de datos / Almacenamiento

### Diagrama

![Arquitectura General EIEInfo](./images/arquitectura_general_eieinfo.png)

---

## 2. Relación entre Componentes

El **diagrama de componentes** detalla cómo los **módulos y clusters** se relacionan entre sí dentro del ecosistema EIEInfo.  
Muestra dependencias funcionales y flujos de interacción a nivel de sistema, sin entrar aún en el modelo de datos.

### Estructura general

- **Cluster Administrativo:** nodo central que coordina la comunicación entre los módulos académicos y de eventos.  
- **Cluster Académico:** agrupa entidades como Cursos, Estudiantes, Profesores, Atributos y Laboratorios.  
- **Cluster de Eventos y Comunicaciones:** abarca Eventos, Conferencias, Anuncios y Alumni.

### Conexiones principales

- El **administrativo** gestiona y conecta con los módulos académicos y de eventos.  
- **Cursos, Estudiantes y Profesores** comparten dependencias con Atributos y Laboratorios.  
- **Anuncios y Alumni** se vinculan con la capa administrativa para comunicación y gestión institucional.

### Diagrama

![Componentes de EIEInfo](./images/componentes_de_eieinfo.png)

---

## 3. Modelo General de Datos

El **modelo de datos** describe las principales entidades y sus relaciones dentro del sistema EIEInfo.  
Representa una **visión lógica y conceptual** de la base de datos, organizada por dominios o módulos.

### Estructura por dominios

| Dominio | Entidades principales | Ejemplo de relaciones |
|----------|----------------------|------------------------|
| **Administrativos** | `Funcionario`, `Nombramiento`, `Jefatura`, `Lugar` | Un funcionario puede tener varios nombramientos y pertenecer a una jefatura. |
| **Alumni** | `Alumnus`, `OfertaEmpleo`, `RecuperarPasswordAlumnus` | Los exalumnos pueden publicar ofertas y recuperar su acceso. |
| **Anuncios** | `Frase`, `Anuncio` | Las frases se vinculan con anuncios activos. |
| **Atributos** | `NivelRubrica`, `Indicador`, `Criterio`, `Descriptor` | Los descriptores se construyen combinando niveles, criterios e indicadores. |
| **Conferencias** | `Conferencia`, `CuotasConferencia` | Cada conferencia tiene cuotas asociadas a estudiantes. |
| **Cursos** | `Curso`, `Catedra`, `Grupo` | Los cursos se imparten por grupos asociados a profesores y estudiantes. |
| **Estudiantes** | `Estudiante`, `Asistencia` | Cada estudiante registra su asistencia a distintas actividades. |
| **Eventos** | `Evento` | Pueden estar asociados a conferencias o actividades especiales. |
| **Laboratorios** | `Laboratorio`, `LaboratorioCiclo` | Los laboratorios se organizan por ciclo académico. |
| **Profesores** | `Profesor` | Relacionado con cátedras y grupos. |

### Diagrama

![Modelo General de Datos EIEInfo](./images/modelo_general_de_datos_eieinfo.png)

---

## Notas finales

- Los tres diagramas fueron generados con la librería [**Diagrams (by Mingrammer)**](https://diagrams.mingrammer.com/), utilizando Python para definir relaciones y colores personalizados.  
- Los **colores representan dominios funcionales**, y las **flechas indican flujos de comunicación o dependencia**.  
- En conjunto, estos diagramas ofrecen una **visión completa** del sistema:  
  - **Arquitectura general** (estructura y flujo global).  
  - **Componentes** (interacción entre módulos).  
  - **Modelo de datos** (estructura lógica de la información).

---

# Identificación de problemas y oportunidades

## Repetición de código
En primer lugar, el sistema presenta una cantidad significativa de **código duplicado** en diversos módulos que ejecutan las mismas funciones con simples variaciones. Los módulos **profesores**, **estudiantes** y **administrativos** poseen vistas separadas para las mismas operaciones con leves diferencias, como por ejemplo en `views/practicas_profesionales` para ambos profesores y administrativos.  

Esto no solamente ocurre en estos módulos; de hecho, es un problema recurrente en gran cantidad de módulos del sistema **EIEInfo**, sin embargo, es especialmente común en estos tres.  

La solución para lo anterior es que, en los casos en que esto ocurra (ya que no ocurre únicamente en el ejemplo brindado), se utilice un **patrón creacional `Factory Method`**, en donde se tenga una clase base que se encargue de brindar la funcionalidad necesaria a las demás subclases y se instancie la subclase necesaria en vez de redefinir nuevamente el mismo método para cada módulo.  

*Esto se puede considerar una mejora técnica.*

---

## Falta de validación o seguridad
Actualmente, el sistema presenta un **sistema de autenticación manual** en donde la autenticidad del usuario depende del *cookie* de ID proporcionado por la página. Esto puede representar un **riesgo de seguridad**, ya que si un tercero obtiene este *cookie* o logra que el usuario utilice un ID conocido de sesión, puede **impersonar al usuario**. Esto ocurre al mismo tiempo en que se utiliza código repetido para el inicio de sesión de estudiante, profesor y administrativo.  

La solución propuesta a lo anterior es tener un **sistema de usuario base** en donde se utilice la autenticación brindada por Django (`django.contrib.auth`) y autenticar al usuario dependiendo de su tipo específico.  

*Esto se puede considerar una mejora técnica.*  

Por otro lado, con respecto a la seguridad, en diversos segmentos como `estudiantes/models.py`, se muestra que se permite subir archivos de cualquier tipo sin límite de extensión ni inspección de contenido. Esto presenta un **riesgo**, ya que se podría subir un archivo malicioso que no sería detectado.  

Como solución, se puede agregar **validación del tipo de archivo** que se agrega, lo cual encaja como una mejora técnica relacionada con el código.

---

## Falta de modularidad
En diversos segmentos del sistema se encuentra una gran cantidad de **lógica dentro de un mismo módulo**, lo cual **viola el principio de responsabilidad única**. Como ejemplo, el método `ActualizarGruposUsuario()` presente en `profesores/models.py` mezcla seis tareas distintas en un solo método dentro del módulo.  

Esto requiere una **mejora técnica**, y se propone generar una **capa de servicios** que se ubique entre los modelos y las vistas. Dicha capa se encargaría de proporcionar servicios específicos para diversas tareas, los cuales podrían ser llamados por métodos, evitando así implementar la lógica directamente dentro de cada uno.  

Es importante destacar que el caso de `ActualizarGruposUsuario()` es solo un ejemplo de muchos otros segmentos en el sistema en donde ocurre lo mismo. Por ejemplo, en `estudiantes/views/asistencias.py`, el método `aceptar_rechazar_asistencia()` es extenso y cumple demasiadas funciones dentro de un mismo bloque, como aceptar asistencias, enviar correo al estudiante, enviar correo al profesor, etc.  

**Solución:** generar una **capa de servicios** que se encargue de proporcionar estas funcionalidades (que pueden ser reutilizadas por otros módulos de ser necesario, por ejemplo, si un profesor desea enviar un correo a un estudiante). De esta forma, se obtendría un **código más modular**, evitando métodos que definan varias funciones dentro de sí. Esto también ayudaría a **reducir la repetición de código** dentro del sistema.  

*Esto se considera una mejora técnica de arquitectura, ya que se busca lograr una separación por capas dentro de los módulos.*

---

## Problemas de UI/UX
En la página de la escuela, al momento de hacer clic sobre el logo de **Universidad de Costa Rica**, el sistema redirige al sitio oficial de la Universidad y **sale completamente de EIEInfo**.  

**Solución:** en lugar de salir completamente de la página, se debe abrir una **nueva pestaña** que envíe al usuario al sitio oficial, de forma que este permanezca dentro de EIEInfo después de hacer clic.  
*Esto se considera una mejora funcional.*  

Además, otro error presente en cuanto a UI/UX se observa en que muchos de los **mensajes están codificados directamente (hard-coded)** en español. Aunque la mayoría de usuarios comprende el idioma, no es una buena práctica de programación.  

**Solución:** utilizar el sistema **i18n de Django**, el cual permite traducir los mensajes al idioma configurado por el usuario o el proyecto.  
*Esto representa una mejora técnica de código.*  

Por otro lado, otro problema de UI/UX se presenta en **mensajes poco informativos**, como en `estudiantes/views/asistencias.py`, donde se indica:  
> “Formulario inválido. Por favor corrija los errores e intente de nuevo.”

Esto ocurre en diversos segmentos del sistema.  

**Solución:** implementar **mensajes de error específicos** que informen al usuario exactamente qué campos tienen errores y cuál es la naturaleza del problema. En lugar de mostrar un mensaje genérico, se debe iterar sobre los errores del formulario y presentar cada uno de manera clara.  
*Esto representa una mejora técnica de código.*

---

## Carencia de documentación
Gran parte del sistema presenta una **documentación débil o insuficiente**. En la mayoría de secciones únicamente se tiene una idea general de lo que hace el módulo; por ejemplo, en `profesores/models.py` solo se incluye una breve descripción:  
> “Modelo de un profesor, hereda de funcionario.”

Los comentarios en la mayor parte del sistema **no aportan información relevante** sobre el funcionamiento interno de los módulos, por lo que en la mayoría de los casos no resultan útiles para que un programador pueda escalar el sistema o agregar nuevas funcionalidades.  

**Solución:** implementar una **estructura definida de comentarios más descriptivos**, siguiendo estándares como **PEP 257** (docstrings formales y consistentes).  
*Esto constituye una mejora técnica del código.*

---







