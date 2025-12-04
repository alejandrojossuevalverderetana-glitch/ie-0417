# Reporte Final – Mejoras Propuestas del Sistema de Usuarios

Este documento resume las mejoras proyectadas para el sistema de usuarios, así como una ruta sugerida de implementación y elementos que, aunque no se completaron en este ciclo, aportarían un valor significativo al proyecto.

---

## 1. Mejoras Propuestas

### **Mejora 1: Unificación completa del sistema de usuarios**

**Estado actual:**  
El sistema cuenta con un login unificado y reforzado en seguridad, permitiendo un control más consistente de sesiones y permisos.

**Pendiente:**  
Implementar el registro unificado directamente en la plataforma para que usuarios (estudiantes, profesores, administrativos y alumni) puedan crearse sin depender del panel de administración.

**Beneficio:**  

- Permite que cualquier módulo nuevo se conecte fácilmente al sistema de usuarios.  
- Reduce inconsistencias y errores como los observados en proyectos anteriores.

---

### **Mejora 2: Corrección del desacople entre frontend y backend**

Existen diferencias en nombres de campos que afectan procesos como el registro de estudiantes (por ejemplo, `contraseña` vs `password`).

**Pendiente:**  
Alinear completamente los nombres y estructuras entre las capas frontend y backend.

**Beneficio:**  

- Menor fricción durante el registro.  
- Mayor confiabilidad y mantenibilidad del sistema.

---

### **Mejora 3: Implementación de pruebas automáticas y CI/CD**

Actualmente no existe un flujo automatizado de verificación ni despliegue.

**Pendiente:**  

- Crear un conjunto de pruebas automáticas (unitarias y funcionales).  
- Incorporar un pipeline de CI/CD para integrar, validar y desplegar cambios de forma segura.

**Beneficio:**  

- Reduce errores al añadir nuevas funcionalidades.  
- Aumenta la calidad del código y agiliza el desarrollo.

---

## 2. Hoja de Ruta Propuesta

### **Fase 1 — Estandarización y base técnica (Semana 1–2)**

- Alinear nombres de campos entre frontend y backend.  
- Documentar endpoints, modelos y procesos importantes.  
- Definir estándares de desarrollo y estructura del proyecto.

### **Fase 2 — Implementación del registro unificado (Semana 3–4)**

- Crear vistas y formularios de registro para cada tipo de usuario.  
- Ajustar validaciones, permisos y carga inicial de roles.  
- Probar el flujo completo de creación de cuentas.

### **Fase 3 — Pruebas automáticas (Semana 5–6)**

- Crear pruebas unitarias para login, permisos y creación de usuarios.  
- Añadir pruebas funcionales para roles específicos.  
- Integrar un umbral de cobertura mínima (60–70%).

### **Fase 4 — CI/CD (Semana 6–7)**

- Configurar pipeline en GitHub Actions o GitLab CI.  
- Automatizar instalación → pruebas → build → despliegue.  
- Validar que no se puedan fusionar cambios que no pasen las pruebas.

### **Fase 5 — Documentación final (Semana 8)**

- Documentación completa del sistema de usuarios.  
- Agregar guía de contribución y buenas prácticas.

---

## 3. Aspectos No Logrados pero Valiosos

### **Gestión mejorada de súper usuarios**

No se completaron cambios como:

- Ajustes al menú del súper usuario.  
- Uso obligatorio de correos institucionales (`@ucr.ac.cr`) como usernames.

**Valor agregado:**  
Mejoraría la navegación y estandarización de usuarios con permisos elevados.

---

### **Documentación profunda y estándares**

Se generó documentación parcial, pero falta completar:

**Pendiente:**  

- Documentar flujos avanzados de sesión, seguridad y permisos.  
- Unificar estándares de estilo, arquitectura y buenas prácticas.

---

## **Conclusión**

Las mejoras propuestas fortalecen la cohesión del sistema, aumentan la calidad del código y permiten que el proyecto escale de manera ordenada. La hoja de ruta presentada facilita la implementación progresiva y reduce riesgos en el desarrollo futuro.
