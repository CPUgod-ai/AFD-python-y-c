#include <stdio.h>
#include <ctype.h>
#include <string.h>

int es_entero(char *s) {
    int i = 0;
    if (s[0] == '\0') return 0;

    while (s[i] != '\0') {
        if (s[i] < '0' || s[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int es_id(char *s) {
    int i = 0;
    int estado;

    if (s[0] == '\0')
        return 0;

    if (!isalpha(s[0]))
        return 0;

    estado = 1;
    i = 1;

    while (s[i] != '\0') {
        if (estado == 1) {
            if (s[i] >= 'a' && s[i] <= 'z')
                estado = 2;
            else
                return 0;
        }
        else if (estado == 2) {
            if (s[i] >= '0' && s[i] <= '9')
                estado = 1;
            else
                return 0;
        }
        i++;
    }

    return estado == 1;
}

int acepta(char *s) {
    if (strcmp(s, "+") == 0)
        return 1;
    if (strcmp(s, "++") == 0)
        return 1;
    if (es_entero(s))
        return 1;
    if (es_id(s))
        return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *archivo;
    char linea[100];

    if (argc < 2) {
        printf("Uso: afd archivo.txt\n");
        return 0;
    }

    archivo = fopen(argv[1], "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 0;
    }

    while (fgets(linea, sizeof(linea), archivo)) {
        linea[strcspn(linea, "\n")] = '\0';

        if (acepta(linea))
            printf("ACEPTA\n");
        else
            printf("NO ACEPTA\n");
    }

    fclose(archivo);
    return 0;
}
