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

   /* N y M representan las dimensiones de la matriz. */
   /* L y U representan los límites para detectar eventos. */

    int consumo[30][30];

    /* consumo[30][30] reserva espacio para una matriz de 30x30 elementos */
    
    /* Arreglos para guardar los resultados de cada fila */
    int eventosFila[30] = {0};
    int impactoFila[30] = {0};
    int rachaFila[30] = {0};
    int inicioFila[30] = {0};
    int eventosColumna[30] = {0};

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

    /* Lectura de la matriz de consumo */

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {

            if (scanf("%d", &consumo[i][j]) != 1) {
                printf("ERROR\n");
                return 0;
            }

    /* Validación de los valores de consumo */

            if (consumo[i][j] < 0 ||
                consumo[i][j] > 1000) {
                error = 1;
            }
        }
    }

    if (error == 1) {
        printf("ERROR\n");
        return 0;
    }

    /* PARTE 4. PROCESAMIENTO DE CADA FILA */

    for (i = 0; i < N; i++) {

        eventos = 0;
        impacto = 0;
        rachaActual = 0;
        rachaMaxima = 0;
        inicioRacha = 0;

        for (j = 0; j < M; j++) {

            x = consumo[i][j];

            /*
             * La primera columna no puede generar eventos,
             * porque no tiene un valor anterior en su fila.
             */
            if (j == 0) {
                rachaActual = 0;
            } else {
                    anterior = consumo[i][j - 1];
                    diferencia = abs(x - anterior);

            /* Evaluación de eventos y rachas */
            
            if (diferencia <= L && x >= U) {

                eventos++;
                impacto += x - U + 1;
                eventosColumna[j]++;
                totalEventos++;
            
            /*Calculo de rachas*/
            
                rachaActual++;

            if (rachaActual > rachaMaxima) {
               rachaMaxima = rachaActual;
               inicioRacha = j - rachaActual + 2;
               }
            } else {

                    /*
                     * Una posicion sin evento interrumpe
                     * la racha consecutiva.
                     */
                    rachaActual = 0;
                }
            }
        }

        /* Guardamos el resumen de la fila. */
        eventosFila[i] = eventos;
        impactoFila[i] = impacto;
        rachaFila[i] = rachaMaxima;

        if (rachaMaxima == 0) {
            inicioFila[i] = 0;
        } else {
            inicioFila[i] = inicioRacha;
        }
    }

    /* PARTE 5. FILA PRIORITARIA Y COLUMNA DESTACADA */

    if (totalEventos > 0) {

        /* La primera fila es la candidata inicial. */

        filaPrioritaria = 1;

        for (i = 1; i < N; i++) {

            int filaActual = i + 1;
            int mejorFila = filaPrioritaria - 1;

            /*
             * Criterios de prioridad:
             * 1. Mayor racha.
             * 2. Mayor impacto total.
             * 3. Mayor cantidad de eventos.
             * 4. Menor numero de fila.
             */
            
            if (rachaFila[i] > rachaFila[mejorFila] ||

                (rachaFila[i] == rachaFila[mejorFila] &&
                 impactoFila[i] > impactoFila[mejorFila]) ||

                (rachaFila[i] == rachaFila[mejorFila] &&
                 impactoFila[i] == impactoFila[mejorFila] &&
                 eventosFila[i] > eventosFila[mejorFila]) ||

                (rachaFila[i] == rachaFila[mejorFila] &&
                 impactoFila[i] == impactoFila[mejorFila] &&
                 eventosFila[i] == eventosFila[mejorFila] &&
                 filaActual < filaPrioritaria)) {

                filaPrioritaria = filaActual;
            }
        }


        /*
         * Seleccionamos la columna con mas eventos.
         * En caso de empate, se conserva la columna menor.
         */
        columnaDestacada = 1;

        for (j = 1; j < M; j++) {

            if (eventosColumna[j] >
                eventosColumna[columnaDestacada - 1]) {

                columnaDestacada = j + 1;
            }
        }

    } else {

        /*
         * Si no hubo eventos en toda la matriz,
         * la fila prioritaria y la columna destacada son 0.
         */
        
        filaPrioritaria = 0;
        columnaDestacada = 0;
    }

  /* PARTE 6. SALIDA DE RESULTADOS */

    /* Resumen de cada fila, en orden. */

    for (i = 0; i < N; i++) {

        printf(
            "FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d\n",
            i + 1,
            eventosFila[i],
            impactoFila[i],
            rachaFila[i],
            inicioFila[i]
        );
    }

    /* Vector de eventos por columna. */

    printf("COLUMNAS");

    for (j = 0; j < M; j++) {
        printf(" %d", eventosColumna[j]);
    }

    printf("\n");

  /* Fila prioritaria y columna destacada. */

    printf("PRIORIDAD %d\n", filaPrioritaria);
    printf("COLUMNA %d\n", columnaDestacada);

    return 0;
}
