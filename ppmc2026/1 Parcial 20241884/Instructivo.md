# Instructivo de compilación y ejecución

## 1. Descripción

Este programa corresponde al **Reto 06: Energía: mesetas de consumo alto**. Está desarrollado en lenguaje C y procesa una matriz de valores para identificar eventos, calcular impactos y rachas consecutivas, y determinar la fila de prioridad y la columna destacada.

## 2. Requisitos

Para compilar y ejecutar el programa necesitas:

- El archivo fuente `20241884.c`.
- Un compilador de C, como **GCC**.
- Una terminal o consola de comandos.

En Windows puedes instalar GCC mediante una distribución como MinGW-w64 o MSYS2. En Linux, puedes instalarlo desde el gestor de paquetes de tu distribución.

Para comprobar si GCC está disponible, ejecuta:

```bash
gcc --version
```

Si aparece la versión del compilador, está disponible para utilizarse.

## 3. Compilación

Abre una terminal en la carpeta donde se encuentra `20241884.c`.

### Windows (CMD o PowerShell)

Ejecuta:

```bash
gcc -std=c11 -Wall -Wextra 20241884.c -o 20241884.exe
```

Si la compilación termina sin errores, se generará el ejecutable `20241884.exe`.

### Linux

Ejecuta:

```bash
gcc -std=c11 -Wall -Wextra 20241884.c -o 20241884
```

Si la compilación termina sin errores, se generará el ejecutable `20241884`.

> **Nota:** `-std=c11` indica que se utiliza el estándar C11. Las opciones `-Wall -Wextra` activan advertencias útiles para detectar posibles problemas en el código.

## 4. Ejecución

### Windows (CMD)

Desde la carpeta que contiene el ejecutable, escribe:

```bat
20241884.exe
```

### Windows (PowerShell)

Escribe:

```powershell
.\20241884.exe
```

### Linux

Escribe:

```bash
./20241884
```

Después de iniciar el programa, introduce los datos solicitados. La primera línea contiene cuatro enteros en este orden:

```text
N M L U
```

- `N`: cantidad de filas.
- `M`: cantidad de columnas.
- `L`: límite máximo de diferencia entre dos valores consecutivos para que pueda ocurrir un evento.
- `U`: umbral mínimo que debe alcanzar el valor actual.

A continuación, introduce los `N × M` valores de la matriz, organizados por filas.

**Importante:** si utilizas una versión del código que muestra el mensaje `Defina la entrada:`, ese mensaje es una indicación para el usuario. Para una entrega que requiera comparar la salida exacta, la versión final debe mostrar únicamente las líneas de salida especificadas en el enunciado, sin mensajes adicionales.

## 5. Ejemplo de ejecución

Este ejemplo utiliza el caso de prueba oficial del enunciado.

### Entrada

Introduce los siguientes datos cuando el programa esté esperando la entrada:

```text
3 5 5 15
8 18 34 12 28
28 12 8 23 34
12 23 18 8 38
```

### Salida esperada

```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 3 EVENTOS 1 IMPACTO 4 RACHA 1 INICIO 3
COLUMNAS 0 0 1 0 0
PRIORIDAD 3
COLUMNA 3
```

### Interpretación breve

- **Fila 1:** no registra eventos.
- **Fila 2:** no registra eventos.
- **Fila 3:** registra un evento, con impacto total de cuatro. La racha máxima es de un evento y comienza en la columna tres.
- **Vector `COLUMNAS`:** indica la cantidad de eventos detectados en cada columna.
- **`PRIORIDAD 3`:** la tercera fila es la fila de prioridad.
- **`COLUMNA 3`:** la tercera columna es la columna destacada.

## 6. Ejemplo de entrada inválida

Si introduces una cantidad de filas fuera del rango permitido, por ejemplo:

```text
0 3 10 20
```

el programa debe rechazar la entrada y mostrar:

```text
ERROR
```

Las dimensiones deben estar entre 1 y 30; además, deben cumplirse las restricciones de `L`, `U` y los valores de la matriz establecidas en el enunciado.

## 7. Recomendaciones

- Ejecuta la compilación desde la carpeta donde está guardado el archivo `.c`.
- Si modificas el código fuente, vuelve a compilarlo antes de ejecutar el programa.
- Revisa que el nombre del archivo en el comando coincida exactamente con el nombre del archivo fuente.
- Si el sistema indica que `gcc` no se reconoce o no existe, comprueba que GCC esté instalado y disponible en el `PATH`.
- Compara la salida del programa con la salida esperada de cada caso de prueba.
- Para la entrega final, verifica que no haya mensajes adicionales que alteren el formato de salida exigido por el enunciado.

## 8. Autoría

- **Asignatura:** Programación para Mecatrónicos
- **Reto:** Reto 06 — Energía: mesetas de consumo alto
- **Archivo fuente:** `20241884.c`
