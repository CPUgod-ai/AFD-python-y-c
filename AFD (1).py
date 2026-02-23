def automata_lexico(cadena):
    tokens = []
    i = 0
    estado = 0
    actual = ""

    while i < len(cadena):
        c = cadena[i]

        if estado == 0:
            if c.isdigit():
                estado = 1
                actual += c
            elif c.isalpha():
                estado = 2
                actual += c
            elif c in "+-*/":
                tokens.append(("OPERADOR", c))
            elif c in "()":
                tokens.append(("PARENTESIS", c))
            elif c == " ":
                pass
            i += 1

        elif estado == 1:
            if c.isdigit():
                actual += c
                i += 1
            else:
                tokens.append(("NUMERO", actual))
                actual = ""
                estado = 0

        elif estado == 2:
            if c.isalnum():
                actual += c
                i += 1
            else:
                tokens.append(("IDENTIFICADOR", actual))
                actual = ""
                estado = 0

    if actual != "":
        if estado == 1:
            tokens.append(("NUMERO", actual))
        elif estado == 2:
            tokens.append(("IDENTIFICADOR", actual))

    return tokens


entrada = "x = 25 + y * (3 + 4)"
resultado = automata_lexico(entrada)

for t in resultado:
    print(t)