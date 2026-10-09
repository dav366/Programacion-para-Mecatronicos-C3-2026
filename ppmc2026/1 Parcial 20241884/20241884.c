/**************************************************************/
/*           Programación para mecatrónicos                   */
/* Nombre:    Omar David Guzmán Guerrero                      */
/* Matricula: 2024-1884                                       */
/* Correo: 20241884@itla.edu.do                               */
/* Seccion:   Sabados                                         */
/* Practica:  20241884.c (primer parcial)                     */
/* Fecha de entrega:     09/10/2026                           */                       
/* Link Repositorio GitHub:                                   */
/* Link del Video:                                            */
/**************************************************************/

/* RETO 06: Energia - mesetas de consumo alto */

/* Definiendo las librerías */
#include <stdio.h>
#include <stdlib.h>

/* #include <stdio.h> permite usar scanf() y printf(). */
/* #include <stdlib.h> nos permitirá utilizar abs() para calcular diferencias absolutas. */

/* Definiendo la función principal */
int main(void) {

    /* PARTE 1. DECLARACION DE VARIABLES Y ARREGLOS */

    int N, M;
    int L, U;

    /* N, M, L, U representan las dimensiones de la matriz de consumo */

    int consumo[30][30];

    /* consumo[30][30] reserva espacio para una matriz de 30x30 elementos */
    
    /* Arreglos para guardar los resultados de cada fila */
    int eventosFila[30] = {0};
    int impactoFila[30] = {0};
    int rachaFila[30] = {0};
    int inicioFila[30] = {0};
    int eventosColumna[30] = {0};
    int impactoColumna[30] = {0};
    int rachaColumna[30] = {0};
    int inicioColumna[30] = {0};

    /* Variables para el procesamiento de datos */

    int i, j;
    int x, anterior, diferencia;
    int eventos, impacto;
    int rachaActual, rachaMaxima, inicioRacha;
    int totalEventos = 0;
    int filaPrioritaria = 0;
    int columnaDestacada = 0;
    int error = 0;

    /* PARTE 2. LECTURA DE DIMENSIONES Y LIMITES */

    if (scanf("%d %d %d %d", &N, &M, &L, &U) != 4) 
    {
        printf("ERROR\n");
        return 0;
    }

    /* PARTE 3. VALIDACION Y LECTURA DE LA MATRIZ */

    /* Validación de las dimensiones y los límites */

    if (N < 1 || N > 30 ||
        M < 1 || M > 30 ||
        L < 0 || U > 1000 || L > U) {

        printf("ERROR\n");
        return 0;
    }

