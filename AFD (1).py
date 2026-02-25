def es_entero(s):
    if len(s) == 0:
        return False
    for ch in s:
        if not ('0' <= ch <= '9'):
            return False
    return True

def es_id(s):
    if len(s) == 0:
        return False

    def es_primera(ch):
        return ('A' <= ch <= 'Z') or ('a' <= ch <= 'z')

    def es_minuscula(ch):
        return 'a' <= ch <= 'z'

    def es_digito(ch):
        return '0' <= ch <= '9'

    if not es_primera(s[0]):
        return False

    estado = 1
    i = 1

    while i < len(s):
        ch = s[i]

        if estado == 1:
            if es_minuscula(ch):
                estado = 2
            else:
                return False
        elif estado == 2:
            if es_digito(ch):
                estado = 1
            else:
                return False
        i += 1

    return estado == 1


def acepta(s):
    if s == "+":
        return True
    if s == "++":
        return True
    if es_entero(s):
        return True
    if es_id(s):
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
