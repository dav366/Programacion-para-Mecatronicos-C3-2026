#include <stdio.h>
#include <string.h>

int main() {
    char palabra[100];
    int longitud;

    printf("Introduce una palabra: ");
    scanf("%s", palabra);

    longitud = strlen(palabra);

    if (longitud <= 5) {
        printf("%s\n", palabra);
    } else {
        printf("%c%d%c\n", palabra[0], longitud - 2, palabra[longitud - 1]);
    }

    return 0;
}
