# Laboratorio Docker: De Cero a Capas (con Flask)

## 2. Evidencias gráficas

A continuación se incluyen capturas de pantalla que muestran la ejecución exitosa de cada etapa:

1. **Contenedor en ejecución**  
   ![docker ps](images/Docker-ps.jpg)

2. **Prueba en navegador**  
   ![curl localhost](images/Prueba-navegador.jpg)

3. **Historial de capas (`docker history`)**  
   ![docker history](images/Docker-history.jpg)

4. **Contenedor marcado como `healthy` en HEALTHCHECK**  
   ![healthcheck](images/Docker-healthcheck.jpg)

5. **Uso de variables de entorno (`-e SALUDO` o `--env-file`)**  
   ![env variables](images/Docker--e.jpg)

6. **Ejecución con Docker Compose levantando el servicio**  
   - Primeramente se obtuvo un error debido a no detener la ejecución del contenedor anterior:  
     ![docker compose1](images/Docker-compose1.jpg)  
   - Luego de finalizar la ejecución del otro contenedor, se pudo inicializar el nuevo correctamente con Compose:  
     ![docker compose2](images/Docker-compose2.jpg)

7. **Comparación de tamaños de imagen en multi-stage**  
   - Inicialmente no se pudo observar correctamente el cambio en los tamaños, debido a que era un tamaño muy pequeño en comparación con la imagen completa:  
     ![multi-stage size1](images/Docker-multistage1.jpg)  
   - Se utilizó `docker inspect` para ver claramente la diferencia en los tamaños:  
     ![multi-stage size2](images/Docker-multistage2.jpg)

## 3. Breve explicación de lo realizado

- **Comportamiento del caché:**  
  Docker reutiliza capas previamente construidas si no hay cambios, marcándolas como `cached` y omitiéndolas, acelerando la construcción.

- **Diferencia entre `CMD` y `ENTRYPOINT`:**  
  - `CMD` define un comando por defecto que puede ser sobrescrito al ejecutar el contenedor, ya sea con `-e` o `--env-file`.  
  - `ENTRYPOINT` define el comando principal que siempre se ejecuta, permitiendo pasar argumentos adicionales; no permite sobrescribir el comando.

- **Multi-stage builds:**  
  Se utiliza para reducir el tamaño final de la imagen, copiando solo los artefactos necesarios desde la etapa de construcción.

- **Volúmenes en modo desarrollo:**  
  Permiten reflejar cambios en el código sin reconstruir la imagen cada vez.
