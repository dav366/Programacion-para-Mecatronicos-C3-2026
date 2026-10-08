# Análisis — Reto 06: Energía: mesetas de consumo alto

## Datos del estudiante

- **Nombre:** Omar David Guzman Guerrero
- **Matrícula:** 2024-1884
- **Asignatura:** Programación para Mecatrónicos
- **Profesor:** Wilkins Gabriel Cedano

---

## 1. Descripción del problema

El programa tiene como objetivo analizar una matriz de valores de consumo
representados por horas.

Cada fila representa una entidad y cada columna representa una hora.
El programa debe identificar posiciones que cumplen una regla específica
de consumo alto y estabilidad respecto al valor anterior de la misma fila.

A partir de los eventos encontrados, se deben calcular resultados por
fila y por columna, determinar las mayores rachas consecutivas y
seleccionar una fila prioritaria y una columna destacada.

Los datos originales de la matriz no deben ser modificados.

---

## 2. Entradas

El programa recibe cuatro valores iniciales:

- `N`: cantidad de filas.
- `M`: cantidad de columnas.
- `L`: cambio máximo permitido entre valores consecutivos.
- `U`: consumo mínimo necesario para generar un evento.

Después se reciben `N` filas con `M` valores enteros que representan
los consumos.

---

## 3. Restricciones

Los datos deben cumplir las siguientes condiciones:

- `1 <= N <= 30`
- `1 <= M <= 30`
- `0 <= L <= U <= 1000`
- Cada valor de la matriz debe estar entre `0` y `1000`.

Si alguna restricción no se cumple, el programa debe mostrar solamente:

`ERROR`

y terminar su ejecución.

---

## 4. Regla para determinar un evento

Un evento solamente puede ocurrir desde la segunda columna, porque se
necesita comparar el valor actual con el valor anterior de la misma fila.

Para cada posición se utilizan:

- `x`: valor actual.
- `p`: valor anterior.
- `d`: diferencia absoluta entre el valor actual y el anterior.

La diferencia se calcula como:

`d = |x - p|`

Una posición genera un evento cuando se cumplen simultáneamente las
siguientes condiciones:

- Existe un valor anterior.
- `d <= L`
- `x >= U`

En otras palabras, el consumo actual debe ser suficientemente alto y
su cambio respecto al consumo anterior no debe superar el límite
permitido.

---

## 5. Cálculo del impacto

Cuando una posición genera un evento, se calcula su impacto mediante:

`impacto = x - U + 1`

El impacto solamente se suma cuando existe un evento.

Las posiciones que no generan eventos aportan `0` al impacto total.

---

## 6. Resultados por fila

Para cada fila se deben obtener cuatro resultados:

- **Eventos:** cantidad total de posiciones que generaron eventos.
- **Impacto:** suma de los impactos de todos los eventos de la fila.
- **Racha:** longitud de la mayor secuencia de eventos consecutivos.
- **Inicio:** posición donde comienza la mayor racha.

Una posición que no genere un evento interrumpe la racha.

Si existen varias rachas con la misma longitud máxima, se selecciona
la que comienza primero.

Si una fila no tiene eventos, su racha y su inicio deben ser `0`.

---

## 7. Resultados por columna

También se debe construir un vector que almacene la cantidad de eventos
en cada columna, considerando todas las filas.

Las rachas se calculan siempre de forma horizontal, dentro de cada fila.

La primera columna no puede generar eventos porque no tiene un valor
anterior con el cual realizar la comparación.

---

## 8. Selección de la fila prioritaria

La fila prioritaria se selecciona utilizando los siguientes criterios,
en este orden:

1. Mayor longitud de racha.
2. Mayor impacto total.
3. Mayor cantidad de eventos.
4. En caso de mantenerse el empate, se selecciona la fila con menor
   número.

Si no existe ningún evento en toda la matriz, la fila prioritaria será `0`.

---

## 9. Selección de la columna destacada

La columna destacada es aquella que contiene la mayor cantidad de
eventos considerando todas las filas.

Si existe un empate entre varias columnas, se selecciona la columna
con el menor número.

Si no existe ningún evento en toda la matriz, la columna destacada será `0`.

---

## 10. Salida

El programa debe mostrar los resultados en el siguiente orden:

Para cada fila:

`FILA i EVENTOS e IMPACTO s RACHA r INICIO b`

Después se muestra el vector de eventos por columna:

`COLUMNAS c1 c2 ... cM`

Finalmente se muestran:

`PRIORIDAD f`

`COLUMNA k`

Las etiquetas deben utilizarse en mayúsculas y sin tildes.

---

## 11. Diseño de la solución

Para resolver el problema se utilizará:

- Una matriz de tamaño máximo `30 x 30` para almacenar los consumos.
- Un vector para almacenar los eventos de cada fila.
- Un vector para almacenar el impacto de cada fila.
- Un vector para almacenar la mayor racha de cada fila.
- Un vector para almacenar el inicio de la mayor racha.
- Un vector para almacenar los eventos de cada columna.

El algoritmo recorrerá la matriz mediante ciclos. Durante el recorrido
se analizará cada posición, se determinará si genera un evento y se
actualizarán los resultados correspondientes.

Para controlar las rachas se utilizarán dos valores:

- `rachaActual`: cantidad de eventos consecutivos encontrados hasta el
  momento.
- `inicioActual`: posición donde comenzó la racha actual.

Cuando aparece un evento, la racha aumenta. Cuando aparece una posición
sin evento, la racha se reinicia.

Al finalizar el análisis de la matriz se compararán los resultados
obtenidos para determinar la fila prioritaria y la columna destacada.

---

## 12. Pruebas

El algoritmo será probado utilizando el caso proporcionado en el
enunciado y pruebas adicionales.

Las pruebas permitirán comprobar:

- Validación de las dimensiones.
- Validación de los límites.
- Lectura de la matriz.
- Detección correcta de eventos.
- Cálculo del impacto.
- Cálculo de rachas.
- Conteo de eventos por fila.
- Conteo de eventos por columna.
- Selección de la fila prioritaria.
- Selección de la columna destacada.
- Caso en el que no existen eventos.
