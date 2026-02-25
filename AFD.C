#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Reconoce si la cadena es un entero: [0-9]+ */
int es_entero(char *cadena) {
    int i = 0;

    if (cadena[0] == '\0')
        return 0;

    while (cadena[i] != '\0') {
        if (cadena[i] < '0' || cadena[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/* Reconoce identificadores:
   ID = [A-Za-z]([a-z][0-9])*
*/
int es_id(char *cadena) {
    int i = 1;
    int estado = 1;

    if (cadena[0] == '\0')
        return 0;

    if (!isalpha(cadena[0]))
        return 0;

    while (cadena[i] != '\0') {
        if (estado == 1) {
            if (cadena[i] >= 'a' && cadena[i] <= 'z')
                estado = 2;
            else
                return 0;
        }
        else if (estado == 2) {
            if (cadena[i] >= '0' && cadena[i] <= '9')
                estado = 1;
            else
                return 0;
        }
        i++;
    }

    return estado == 1;
}

/* Verifica si la cadena es aceptada por el AFD */
int acepta(char *cadena) {
    if (strcmp(cadena, "+") == 0)
        return 1;
    if (strcmp(cadena, "++") == 0)
        return 1;
    if (es_entero(cadena))
        return 1;
    if (es_id(cadena))
        return 1;
    return 0;
}

int main() {
    FILE *archivo;
    char linea[100];

    /* Equivalente a: with open("entrada.txt", "r") */
    archivo = fopen("entrada.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo entrada.txt\n");
        return 1;
    }

    while (fgets(linea, sizeof(linea), archivo)) {
        linea[strcspn(linea, "\n")] = '\0';  // quitar salto de línea

        if (acepta(linea))
            printf("ACEPTA\n");
        else
            printf("NO ACEPTA\n");
    }

    fclose(archivo);
    return 0;
}
