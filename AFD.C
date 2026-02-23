#include <stdio.h>
#include <ctype.h>

int main() {
    char cadena[100];
    int i = 0;
    int estado = 0;

    printf("Ingrese una cadena: ");
    scanf("%s", cadena);

    while (cadena[i] != '\0') {
        char c = cadena[i];

        if (estado == 0) {
            if (isalpha(c))
                estado = 1;
            else
                estado = 2;
        }
        else if (estado == 1) {
            if (isalnum(c))
                estado = 1;
            else
                estado = 2;
        }
        else {
            break;
        }

        i++;
    }

    if (estado == 1)
        printf("Cadena aceptada\n");
    else
        printf("Cadena rechazada\n");

    return 0;
}