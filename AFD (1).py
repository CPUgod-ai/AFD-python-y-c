# reconoce si una cadena completa cumple alguno de estos parametros:
#   ID = [A-Za-z]([a-z][0-9])*
#   SUMA = +
#   ENTERO = [0-9]+
#   INCREMENTO = ++

def es_entero(cadena):
    if len(cadena) == 0:
        return False
    for caracter in cadena:
        if not ('0' <= caracter <= '9'):
            return False
    return True


def es_id(cadena):
    if len(cadena) == 0:
        return False

    def es_primera(caracter):
        return ('A' <= caracter <= 'Z') or ('a' <= caracter <= 'z')

    def es_minuscula(caracter):
        return 'a' <= caracter <= 'z'

    def es_digito(caracter):
        return '0' <= caracter <= '9'

    if not es_primera(cadena[0]):
        return False

    estado = 1
    indice = 1

    while indice < len(cadena):
        caracter = cadena[indice]

        if estado == 1:
            if es_minuscula(caracter):
                estado = 2
            else:
                return False
        elif estado == 2:
            if es_digito(caracter):
                estado = 1
            else:
                return False

        indice += 1

    return estado == 1


def acepta(cadena):
    if cadena == "+":
        return True
    if cadena == "++":
        return True
    if es_entero(cadena):
        return True
    if es_id(cadena):
        return True
    return False


def main():
    with open("entrada.txt", "r", encoding="utf-8") as archivo:
        for linea in archivo:
            cadena = linea.strip()
            if acepta(cadena):
                print("ACEPTA")
            else:
                print("NO ACEPTA")


if __name__ == "__main__":
    main()
