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
    int consumo[30][30];

    /* consumo[30][30] reserva espacio para una matriz de 30x30 elementos */
