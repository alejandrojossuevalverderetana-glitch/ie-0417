# Clase 1
## Introduccion a ingenieria en software

### Areas clave

Requerimentos

Diseno de software

Desarrollo y mantenimiento:

Pruebas y validacion:
Hacer todas las pruebas posibles

Gestion de proyectos

### Desafios actuales

Seguridad: se debe de proteger los datos con multiples tipos de proteccion.

Inteligencia artificial

Etica:
eyes on / off: Si se puede ver los datos que se estan procesando o por el contrario solo metricas de los mismos

### Acronimos

  SLA:
  Se cobra mas por los proyectos que ya existen que por proyectos nuevos
  
  E2E (end to end):
  Sistema de principio a fin
  
  MVP (producto minimo viable):

  Elicitacion:
  proceso de descubrir, recopilar y definir los requisitos de un sistema de software desde diferentes partes interesadas

  CIT:
  Pruebas de integracion continua

  MFA:
  Multiple factor de autenticacion

# Clase 2

## Metodologías de desarrollo y diseño

### ¿Usan Agile, Scrum, Kanban, DevOps, o enfoques propios?

Meta usa un enfoque mas propio, basado en "move fast".
Trabajan con herramientas internas y aunque no usan DevOps como tal declaran aplicar DevOps si usan muchos de sus principios, como la automatizacion, integración continua y que los mismos ingenieros operen sus sistemas. 
En resumen usan un enfoque propio, agil y que aprovecha su infraestructura interna
**Buck:**  un sistema de construcción (build system) creado por Facebook.

### ¿Cómo escalan estas metodologías en proyectos con miles de desarrolladores?

Para Escalar sus proyectos trabajan todos en un mismo repositorio gigante, aprovechando sus herramientas internas como Buck junto a CI/CD (Continuous Integration/Continuous Deployment), de forma que se integra nuevo codigo de manera constante, además de que la automatizacion está lista para desplegar el codigo a producción.

## Pregunta 2:
## 2. Principios de diseño de software
a. ¿Qué principios de arquitectura aplican (microservicios, APIs, modularidad,
cloud-native)?

1. Microservicios
Aplicación: Aunque Meta empezó con un monolito, hoy gran parte de su backend está compuesto por microservicios distribuidos.
Ejemplo: sistemas como Messenger, Instagram y Ads Ranking funcionan sobre miles de servicios independientes que se comunican vía RPC.

2. APIs
Aplicación: Meta expone y consume APIs internas y externas.
- Internamente, cada microservicio tiene interfaces bien definidas.
- Externamente, APIs públicas como Graph API permiten a terceros interactuar con Facebook e Instagram.

3. Modularidad
Aplicación: Uso de un monorepo enorme, pero estructurado en módulos bien definidos.
- Los equipos pueden reutilizar librerías internas (auth, pagos, storage) sin duplicar código.

4. Cloud-native / Infra propia
Aplicación: Aunque Meta no usa AWS ni GCP, aplica los principios cloud-native en su propia infraestructura.
- Opera data centers globales con orquestación interna (similar a Kubernetes).
- Uso de containers y sistemas de despliegue propios, más balanceo de carga a escala planetaria.

5. Escalabilidad distribuida
Aplicación: Cada servicio se diseña para soportar miles de millones de usuarios.
Ejemplo: TAO (base de datos social distribuida) y Haystack (almacenamiento de fotos) creados para escala única de Meta.

b. ¿Ejemplos de cómo estos principios impactan en productos clave (ej. Gmail
en Google, iOS en Apple)?

1. Microservicios
Impacto en Facebook e Instagram: Permite que funciones como el feed, el sistema de notificaciones o el chat evolucionen de forma independiente. Ejemplo: el equipo de Reels puede innovar sin afectar la mensajería.

2. APIs abiertas y estandarizadas
Impacto en WhatsApp Business y Messenger: Gracias a APIs, empresas pueden integrar bots, pagos y atención al cliente sin depender del código central de WhatsApp.

3. Modularidad
Impacto en Reality Labs (Oculus/Meta Quest): El software del casco de realidad virtual se organiza en módulos (tracking, gráficos, interacción), lo que permite optimizar cada parte y lanzar mejoras rápidas sin rediseñar todo el sistema.

4. Cloud-native (infraestructura propia y escalable)
Impacto en el feed de Facebook: Se procesan miles de millones de interacciones por segundo gracias a sistemas distribuidos en la nube interna de Meta, lo que permite personalización en tiempo real (ejemplo: mostrarte contenido relevante al instante).


## **3.Herramientas y ecosistemas internos**
### **¿Tienen frameworks internos o herramientas que luego se vuelven estándarde la industria (ej. React de Meta, Kubernetes de Google)?**
Los frameworks internos que luego se volvieron estandares en la industria como React(Construir paginas web),PyTorch(relacionado a la inteligencia artificial),cassandra (base de datos distribuida),Open Compute Project (diseños de servidores y centros de datos compartidos)

### **¿Cómo diseñan software para millones de usuarios concurrentes?**
tienen una arquitectura basada para el alto volumen de trafico
**ZippyDB**:Es una base de datos distribuida de clave-valor que permite escalar verticalmente y horizontalmente

**Async:** Plataforma de computo asincronico que maneja cargas variables donde permite adsorver los picos de demandam, mediante la la organizacion del trabajo 


## 4. Cultura de ingeniería
a. ¿Cómo se organiza el trabajo de los ingenieros?
La organización se define como se muestra en las siguientes imágenes:

<img width="224" height="736" alt="01CC4406-A057-4078-8C77-ACB41188CB2B" src="https://github.com/user-attachments/assets/cca3e905-e90b-4fca-87cd-663d045ff2e4" />

<img width="224" height="736" alt="8CD8B2D7-F513-4647-95A4-2CED5E36FD85" src="https://github.com/user-attachments/assets/6af9ae0d-6dda-4fec-861e-65b20dbda46b" />

Datos relevantes:
Bootcamp → Todos los nuevos ingenieros pasan por un entrenamiento inicial.
Ownership → Cada ingeniero es dueño de lo que lanza (lo mantiene y arregla si falla).
Métricas → Se decide con datos: engagement, tiempo de carga, ingresos, etc.

b. ¿Qué valores destacan en el diseño de software (simplicidad, escalabilidad,
rendimiento, seguridad)?

Los valores principales son los siguientes:
- Simplicidad
- Escalabilidad
- Rendimiento
- Seguridad y Privacidad
- Iteración rápida (Move Fast & Learn)
- Ownership (responsabilidad total)
- Cultura Data-driven
- Colaboración abierta
- Automatización y eficiencia
- Enfoque en la experiencia del usuario
- Innovación continua.

1. Simplicidad

Descripción: Mantener el código fácil de entender, modificar y extender.
Aplicación: Se priorizan soluciones claras y prototipos rápidos antes de invertir en sistemas complejos. Filosofía: “Code wins arguments”.

2. Escalabilidad

Descripción: Diseñar software que soporte miles de millones de usuarios en tiempo real.
Aplicación: Sistemas distribuidos internos como TAO (base de datos social) o Haystack (almacenamiento de fotos). Siempre se evalúa si un cambio funcionará a escala global.

3. Rendimiento

Descripción: Optimizar latencia y uso de recursos.
Aplicación: Apps como Facebook Lite muestran compromiso con países de baja conectividad. Además, Meta desarrolla hardware propio (como chips MTIA) para acelerar inteligencia artificial y reducir costos de cómputo.

4. Seguridad y Privacidad

Descripción: Proteger la información y generar confianza.
Aplicación: Revisiones obligatorias de seguridad antes de producción, auditorías internas y detección de abuso en tiempo real. Escándalos como Cambridge Analytica impulsaron una cultura de “seguridad por defecto”.

5. Iteración rápida (Move Fast & Learn)

Descripción: Lanzar cambios rápido y aprender de los resultados.
Aplicación: Todos los lanzamientos pasan por experimentos A/B en un porcentaje pequeño de usuarios antes de expandirse globalmente.

6. Ownership (responsabilidad total)

Descripción: Cada ingeniero es dueño de lo que crea.
Aplicación: El mismo ingeniero que escribe el código debe desplegarlo, monitorearlo y corregirlo si falla (“You ship it, you own it”).

7. Cultura Data-driven

Descripción: Decisiones basadas en métricas, no en opiniones.
Aplicación: Features en Feed, Reels o Ads se mantienen solo si mejoran engagement o ingresos medidos por analítica de datos.

8. Colaboración abierta

Descripción: Transparencia y acceso compartido al conocimiento.
Aplicación: Uso de un monorepo gigante, visible a todos los ingenieros, lo que permite proponer mejoras incluso en proyectos fuera del propio equipo.

9. Automatización y eficiencia

Descripción: Reducir tareas repetitivas mediante herramientas internas.
Aplicación: Sistemas internos de testing, despliegue, monitoreo y rollback automáticos que permiten a los ingenieros enfocarse en innovar.

10. Enfoque en la experiencia del usuario

Descripción: Priorizar que los productos funcionen para cualquier persona.
Aplicación: WhatsApp y Facebook Lite optimizados para redes lentas, diseño minimalista y pruebas con usuarios de diferentes regiones.

11. Innovación continua

Descripción: Incentivar ideas nuevas, incluso fuera del plan oficial.
Aplicación: Hackatones internos regulares donde ingenieros presentan prototipos; de ahí nacieron el botón Like, Timeline y mejoras de Messenger.

## Pregunta 5: ¿Qué prácticas o herramientas originadas en Meta se usan hoy globalmente?

Meta ha desarrollado herramientas y prácticas que hoy son utilizadas globalmente y han marcado la evolución del software.

### 1. React (2013)
Biblioteca de JavaScript para construir interfaces de usuario.  
- Uno de los frameworks más usados en el mundo.  
- Adoptado por empresas como Netflix, Uber y Airbnb.  
- Introdujo el DOM virtual y el desarrollo por componentes, hoy estándar en frontend.  

---

### 2. GraphQL (2015)
Lenguaje de consultas para APIs, alternativa a REST.  
- Adoptado por GitHub, Twitter, Shopify, entre otros.  
- Permite obtener exactamente los datos necesarios, optimizando rendimiento.  
- Se convirtió en un estándar moderno de diseño de APIs.  

---

### 3. PyTorch (2016)
Framework de *machine learning* en Python.  
- Estándar de facto en investigación de IA, superando a TensorFlow en popularidad.  
- Usado por OpenAI, Tesla, Microsoft, Amazon y universidades.  
- Clave en el boom actual de la inteligencia artificial.  

---

### 4. HHVM y Hack (2010s)
- HHVM: mejoró el rendimiento de PHP.  
- Hack: añadió tipado estático a PHP.  
- Aunque menos adoptados, influyeron en la evolución de lenguajes dinámicos.  

---

### 5. Cultura “Move Fast” y DevOps
Práctica de iteración rápida, despliegues continuos y experimentación masiva.  
- Popularizó la idea de lanzar rápido y mejorar en producción.  
- Inspiró prácticas modernas como DevOps, CI/CD y A/B testing a gran escala.  

---


