# Definiendo las 17 casos para comprobar el buen funcionamiento del programa
## (Mas otros dos casos propios que él ha solicitado)
## ¿Qué debemos comprobar?

- Validación de dimensiones, límites y valores de la matriz.
- Detección de eventos desde la segunda columna, aplicando simultáneamente la condición de cambio absoluto y consumo mínimo.
- Cálculo del impacto solo en posiciones que generan eventos.
- Conteos por fila y columna, longitud de la mayor racha e inicio más temprano.
- Selección de la fila prioritaria y la columna destacada, incluidos los empates y el caso sin eventos.
- Formato exacto de salida y manejo de matrices de tamaño mínimo y máximo.

---

## `caso_01` — Ejemplo principal del enunciado

Comprueba el caso de referencia con tres filas y cinco columnas. Permite verificar el cálculo general de eventos, impactos, rachas, conteos por columna y la selección de la fila y columna destacadas. La tercera fila genera un evento en la columna 3, con impacto 4.

**Entrada (`.in`):**

```text
3 5 5 15
8 18 34 12 28
28 12 8 23 34
12 23 18 8 38
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 3 EVENTOS 1 IMPACTO 4 RACHA 1 INICIO 3
COLUMNAS 0 0 1 0 0
PRIORIDAD 3
COLUMNA 3
```

---

## `caso_02` — Matriz mínima de 1 × 1

Verifica que el programa funcione con la menor matriz permitida. Como solo existe una columna, no hay valor anterior para comparar y, por tanto, no puede generarse ningún evento. La prioridad y la columna destacada deben ser 0.

**Entrada (`.in`):**

```text
1 1 0 0
0
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
COLUMNAS 0
PRIORIDAD 0
COLUMNA 0
```

---

## `caso_03` — Igualdad con los límites y meseta

Comprueba el caso en que todos los valores son iguales a L y U (10). Desde la segunda columna, cada valor cumple la condición del evento: la diferencia es 0 y el consumo alcanza U. Cada fila debe registrar cinco eventos consecutivos, con inicio en la columna 2.

**Entrada (`.in`):**

```text
2 6 10 10
10 10 10 10 10 10
10 10 10 10 10 10
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 5 IMPACTO 5 RACHA 5 INICIO 2
FILA 2 EVENTOS 5 IMPACTO 5 RACHA 5 INICIO 2
COLUMNAS 0 2 2 2 2 2
PRIORIDAD 1
COLUMNA 2
```

---

## `caso_04` — Una fila, cambios y valores extremos

Comprueba una fila con valores alternados entre 0 y 1000, con L = 0 y U = 0. Los cambios entre valores consecutivos son mayores que L, por lo que ninguna posición desde la segunda columna genera evento. También verifica que el programa maneje los extremos permitidos.

**Entrada (`.in`):**

```text
1 6 0 0
0 1000 0 1000 0 1000
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
COLUMNAS 0 0 0 0 0 0
PRIORIDAD 0
COLUMNA 0
```

---

## `caso_05` — Una columna y comparación entre filas

Comprueba una matriz de cuatro filas y una sola columna. No hay comparación horizontal posible, así que ninguna fila puede registrar eventos, independientemente de los valores de consumo.

**Entrada (`.in`):**

```text
4 1 0 20
0
10
20
1000
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 3 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 4 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
COLUMNAS 0
PRIORIDAD 0
COLUMNA 0
```

---

## `caso_06` — Empates, rachas separadas y final de fila

El caso contiene valores alternados 0, 20 y 40, con L = 0 y U = 0. Como los cambios entre posiciones consecutivas no son cero, no se generan eventos. Sirve para comprobar que el programa no marque valores solo por alcanzar U y que las rachas no se formen sin cumplir toda la regla.

**Entrada (`.in`):**

```text
3 9 0 0
0 20 40 0 20 40 0 20 40
0 20 40 0 20 40 0 20 40
0 20 40 0 20 40 0 20 40
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 3 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
COLUMNAS 0 0 0 0 0 0 0 0 0
PRIORIDAD 0
COLUMNA 0
```

---

## `caso_07` — Valores debajo, iguales y encima de los límites

Comprueba varios valores cercanos a U = 20 y diferencias que están dentro, fuera o justo en L = 10. La condición debe cumplir ambas reglas simultáneamente. También permite observar rachas de distinta longitud y comprobar que se conserva el inicio correcto.

**Entrada (`.in`):**

```text
3 6 10 20
9 10 11 19 20 21
21 20 19 11 10 9
10 20 10 20 10 20
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 2 IMPACTO 3 RACHA 2 INICIO 5
FILA 2 EVENTOS 1 IMPACTO 1 RACHA 1 INICIO 2
FILA 3 EVENTOS 3 IMPACTO 3 RACHA 1 INICIO 2
COLUMNAS 0 2 0 1 1 2
PRIORIDAD 1
COLUMNA 2
```

---

## `caso_08` — Matriz máxima de 30 × 30

Verifica que la matriz y los vectores admitan las dimensiones máximas permitidas sin accesos fuera de rango. La entrada contiene 30 filas y 30 columnas. La salida esperada indica que no hay eventos, por lo que también se comprueba el tratamiento de una matriz grande sin coincidencias.

**Entrada (`.in`):**

```text
30 30 5 30
0 19 38 57 76 95 114 133 152 171 190 209 228 247 266 285 304 323 342 361 380 399 418 437 456 475 494 513 532 551
37 56 75 94 113 132 151 170 189 208 227 246 265 284 303 322 341 360 379 398 417 436 455 474 493 512 531 550 569 588
74 93 112 131 150 169 188 207 226 245 264 283 302 321 340 359 378 397 416 435 454 473 492 511 530 549 568 587 606 625
111 130 149 168 187 206 225 244 263 282 301 320 339 358 377 396 415 434 453 472 491 510 529 548 567 586 605 624 643 662
148 167 186 205 224 243 262 281 300 319 338 357 376 395 414 433 452 471 490 509 528 547 566 585 604 623 642 661 680 699
185 204 223 242 261 280 299 318 337 356 375 394 413 432 451 470 489 508 527 546 565 584 603 622 641 660 679 698 717 736
222 241 260 279 298 317 336 355 374 393 412 431 450 469 488 507 526 545 564 583 602 621 640 659 678 697 716 735 754 773
259 278 297 316 335 354 373 392 411 430 449 468 487 506 525 544 563 582 601 620 639 658 677 696 715 734 753 772 791 810
296 315 334 353 372 391 410 429 448 467 486 505 524 543 562 581 600 619 638 657 676 695 714 733 752 771 790 809 828 847
333 352 371 390 409 428 447 466 485 504 523 542 561 580 599 618 637 656 675 694 713 732 751 770 789 808 827 846 865 884
370 389 408 427 446 465 484 503 522 541 560 579 598 617 636 655 674 693 712 731 750 769 788 807 826 845 864 883 902 921
407 426 445 464 483 502 521 540 559 578 597 616 635 654 673 692 711 730 749 768 787 806 825 844 863 882 901 920 939 958
444 463 482 501 520 539 558 577 596 615 634 653 672 691 710 729 748 767 786 805 824 843 862 881 900 919 938 957 976 995
481 500 519 538 557 576 595 614 633 652 671 690 709 728 747 766 785 804 823 842 861 880 899 918 937 956 975 994 12 31
518 537 556 575 594 613 632 651 670 689 708 727 746 765 784 803 822 841 860 879 898 917 936 955 974 993 11 30 49 68
555 574 593 612 631 650 669 688 707 726 745 764 783 802 821 840 859 878 897 916 935 954 973 992 10 29 48 67 86 105
592 611 630 649 668 687 706 725 744 763 782 801 820 839 858 877 896 915 934 953 972 991 9 28 47 66 85 104 123 142
629 648 667 686 705 724 743 762 781 800 819 838 857 876 895 914 933 952 971 990 8 27 46 65 84 103 122 141 160 179
666 685 704 723 742 761 780 799 818 837 856 875 894 913 932 951 970 989 7 26 45 64 83 102 121 140 159 178 197 216
703 722 741 760 779 798 817 836 855 874 893 912 931 950 969 988 6 25 44 63 82 101 120 139 158 177 196 215 234 253
740 759 778 797 816 835 854 873 892 911 930 949 968 987 5 24 43 62 81 100 119 138 157 176 195 214 233 252 271 290
777 796 815 834 853 872 891 910 929 948 967 986 4 23 42 61 80 99 118 137 156 175 194 213 232 251 270 289 308 327
814 833 852 871 890 909 928 947 966 985 3 22 41 60 79 98 117 136 155 174 193 212 231 250 269 288 307 326 345 364
851 870 889 908 927 946 965 984 2 21 40 59 78 97 116 135 154 173 192 211 230 249 268 287 306 325 344 363 382 401
888 907 926 945 964 983 1 20 39 58 77 96 115 134 153 172 191 210 229 248 267 286 305 324 343 362 381 400 419 438
925 944 963 982 0 19 38 57 76 95 114 133 152 171 190 209 228 247 266 285 304 323 342 361 380 399 418 437 456 475
962 981 1000 18 37 56 75 94 113 132 151 170 189 208 227 246 265 284 303 322 341 360 379 398 417 436 455 474 493 512
999 17 36 55 74 93 112 131 150 169 188 207 226 245 264 283 302 321 340 359 378 397 416 435 454 473 492 511 530 549
35 54 73 92 111 130 149 168 187 206 225 244 263 282 301 320 339 358 377 396 415 434 453 472 491 510 529 548 567 586
72 91 110 129 148 167 186 205 224 243 262 281 300 319 338 357 376 395 414 433 452 471 490 509 528 547 566 585 604 623
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 3 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 4 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 5 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 6 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 7 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 8 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 9 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 10 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 11 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 12 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 13 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 14 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 15 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 16 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 17 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 18 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 19 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 20 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 21 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 22 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 23 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 24 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 25 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 26 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 27 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 28 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 29 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 30 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
COLUMNAS 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
PRIORIDAD 0
COLUMNA 0
```

---

## `caso_09` — Dimensión inválida: cero

N vale 0, pero la cantidad de filas debe estar entre 1 y 30. El programa debe rechazar la entrada y mostrar únicamente ERROR.

**Entrada (`.in`):**

```text
0 3 10 20
```

**Salida esperada (`.out`):**

```text
ERROR
```

---

## `caso_10` — Dimensión inválida: más de 30

N vale 31, que supera el máximo permitido de 30 filas. El programa debe mostrar únicamente ERROR y terminar.

**Entrada (`.in`):**

```text
31 2 10 20
```

**Salida esperada (`.out`):**

```text
ERROR
```

---

## `caso_11` — Límites invertidos

L = 20 y U = 10, por lo que L es mayor que U. Esto incumple la condición 0 <= L <= U <= 1000 y la entrada debe rechazarse con ERROR.

**Entrada (`.in`):**

```text
2 2 20 10
```

**Salida esperada (`.out`):**

```text
ERROR
```

---

## `caso_12` — Límite fuera de rango

L vale -1. Como los límites no pueden ser negativos, el programa debe mostrar únicamente ERROR.

**Entrada (`.in`):**

```text
1 1 -1 20
```

**Salida esperada (`.out`):**

```text
ERROR
```

---

## `caso_13` — Matriz con valor negativo

La matriz contiene el valor -1, que está fuera del intervalo permitido de 0 a 1000. El programa debe detectar el valor inválido y mostrar ERROR.

**Entrada (`.in`):**

```text
2 2 0 10
0 10
-1 5
```

**Salida esperada (`.out`):**

```text
ERROR
```

---

## `caso_14` — Matriz con valor mayor que 1000

La matriz contiene el valor 1001, que supera el máximo permitido. El programa debe rechazar los datos y mostrar únicamente ERROR.

**Entrada (`.in`):**

```text
1 2 0 10
10 1001
```

**Salida esperada (`.out`):**

```text
ERROR
```

---

## `caso_15` — Límite superior inválido

U vale 1001, por encima del máximo de 1000. Aunque las dimensiones y L sean válidos, la entrada completa no cumple las restricciones y debe producir ERROR.

**Entrada (`.in`):**

```text
1 1 0 1001
```

**Salida esperada (`.out`):**

```text
ERROR
```

---

## `caso_16` — Eventos activos de la regla particular

Con L = 0 y U = 0, todos los valores son cero. Desde la segunda columna, el cambio absoluto es 0 y el valor actual es al menos U; por eso se genera un evento en cada posición desde la columna 2. Cada fila tiene cuatro eventos consecutivos, con impacto total 4 e inicio en la columna 2. Los empates se resuelven a favor de la primera fila y la primera columna con el máximo de eventos.

**Entrada (`.in`):**

```text
3 5 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 4 IMPACTO 4 RACHA 4 INICIO 2
FILA 2 EVENTOS 4 IMPACTO 4 RACHA 4 INICIO 2
FILA 3 EVENTOS 4 IMPACTO 4 RACHA 4 INICIO 2
COLUMNAS 0 3 3 3 3
PRIORIDAD 1
COLUMNA 2
```

---

## `caso_17` — Ausencia total de eventos

U vale 5, mientras que todos los consumos son 0. Ningún valor alcanza el mínimo requerido, así que no se genera ningún evento. Todos los conteos e impactos son cero y tanto la fila prioritaria como la columna destacada deben ser 0.

**Entrada (`.in`):**

```text
3 5 0 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
```

**Salida esperada (`.out`):**

```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 3 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
COLUMNAS 0 0 0 0 0
PRIORIDAD 0
COLUMNA 0
```
