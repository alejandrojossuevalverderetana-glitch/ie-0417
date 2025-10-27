# 易 Laboratorio – Técnicas de Depuración en C++

## ⚙️ Fase 1 – Fundamentos prácticos de depuración

### 離 Actividad 1: Exploración con gdb

**Comandos utilizados:**

```bash
g++ -g -O0 -std=c++17 suma_vector.cpp -o suma_vector
gdb ./suma_vector
```

**Comandos de depuración usados:**

- `run`
- `next`
- `step`
- `print`
- `where` o `bt`

**Evidencia:**  

![suma_vector](images/suma_vector.png)

### 易 Preguntas (Fase 1)

1. ¿Qué tipo de error genera el fallo de ejecución?  

    El error de ejecucion en el programa se debe a que se intenta a un indice fuera de rango

2. ¿Qué comando permite identificar la línea exacta donde ocurre el fallo?  

    Se puede utilizar el comando `where` para ubicar la linea que tiene el fallo

3. ¿Qué diferencia existe entre los comandos `next` y `step` en gdb?  

    `next` Es un comando con el que se ejecuta la siguiente linea **sin entrar en funciones**

    `step` Es un comando con el que se ejecuta la siguiente linea **entrando a funciones**

## 燐 Fase 2 – Detección de errores de memoria

### 離 Actividad 2: Diagnóstico con AddressSanitizer y Valgrind

**Comandos:**

```bash
clang++ -g -O0 -fsanitize=address -fno-omit-frame-pointer buffers.cpp -o buffers
./buffers
```

```bash
valgrind --leak-check=yes --track-origins=yes --show-leak-kinds=all ./buffers
```

**Evidencia:**  

![buffers1](images/buffers1.png)
![buffers2](images/buffers2.png)
![buffers3](images/buffers3.png)

### 易 Preguntas (Fase 2)

1. ¿Qué tipo de error detectó primero AddressSanitizer?  

    El primer error detectado el es overflow

2. ¿Cuál fue la causa de la fuga de memoria?  

    Se reservan 128 bytes para leak y en ningun lugar se liberan

3. ¿Por qué es importante compilar con la opción `-g`?  

    Esta opcion le dice al compilador que incluya informacion de depuración en el binario, lo que es necesario para que una herramienta de depuracion pueda encontrar los errores

## ⚡ Fase 3 – Análisis de concurrencia

### 離 Actividad 3: Detección de condiciones de carrera

**Descripción:**  
Analizar un programa con accesos concurrentes a una variable compartida sin sincronización. Detectar y corregir condiciones de carrera usando **ThreadSanitizer (TSan)** y **Helgrind**.

**Comandos:**

```bash
clang++ -g -O1 -fsanitize=thread -std=c++17 race.cpp -o race -lpthread
./race
```

```bash
valgrind --tool=helgrind ./race
```

**Evidencia:**  

![race1](images/race1.png)
![race2](images/race2.png)

### 易 Preguntas (Fase 3)

1. ¿Qué tipo de acceso detecta ThreadSanitizer como data race?  

    ThreadSanitizer detectó una data race porque ambos hilos escriben simultáneamente en la variable global **contador** sin sincronización.

2. ¿Por qué Helgrind tiene un mayor costo de ejecución?  

    Helgrind realiza una vigilancia intensiva de todos los accesos a memoria compartida, con el fin de detectar errores que normalmente no se ven durante ejecución normal.

3. ¿Qué ventajas tiene usar `std::atomic` frente a `std::mutex`?  

    - Tiene mayor rendimiento
    - No hay riesgo de deadlocks

## 藺 Fase 4 – Integración y automatización

### 離 Actividad 4: Makefile y perfiles de análisis

**Evidencia:**  

![make](images/make.png)

## 隣 Fase 5 – Análisis conceptual y reflexivo

### 易 Preguntas finales

1. ¿Qué diferencias existen entre un error de ejecución y un error lógico?

    Ejecucion: Causa que el programa falle o se cierre

    Lógico: El programa corre pero produce resultados incorrectos

2. ¿Qué ventajas presenta AddressSanitizer frente a Valgrind?  

    - Es más rapido y ligero
    - Detecta errores de memoria y fugas
    - Proporciona reportes claros

3. ¿Cómo afectan las herramientas de depuración el rendimiento del programa?  

    Hacen que el programa se ejecute mas lento por las comprobaciones que agregan

4. ¿Por qué se recomienda compilar con `-O0` durante la depuración?  

    Evita optimizaciones del compilador que pueden reescribir o eliminar codigo, lo que facilita rastrear errores

5. ¿Qué aprendiste sobre la importancia de diagnosticar errores antes de liberar un programa?  

    Permite detectar y corregir fallos que podrían causar crashes, pérdidas de datos o vulnerabilidades
