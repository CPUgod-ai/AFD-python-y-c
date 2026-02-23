## Automata Finito Determinista (AFD) en Python y C

En este taller se implementa un Autómata Finito Determinista (AFD) en Python y en C.  
El programa analiza una cadena ingresada por el usuario y determina si es aceptada o rechazada según las reglas del autómata.

---

## ¿Qué hace el AFD?

El AFD reconoce identificadores con las siguientes reglas:

- Debe comenzar con una letra  
- Puede contener letras y números  
- Si inicia con un número o tiene símbolos, se rechaza  

### Ejemplos aceptados
xvar1 abc123

### Ejemplos rechazados
1x, 23abcf
---

## Programa en Python

### Requisitos
- Tener Python 3 instalado

### Ejecución
1. Abrir la terminal
2. Ubicarse en la carpeta donde está el archivo
3. Ejecutar: python AFD.py

4. Ingresar la cadena cuando el programa lo solicite  
El programa mostrará si la cadena es aceptada o rechazada.

---

## Programa en C

### Requisitos
- Tener un compilador de C (por ejemplo gcc)

### Compilación
Desde la terminal:gcc afd.c -o afd

Luego se ingresa la cadena y el programa indica el resultado.

---

## Funcionamiento del AFD

- Se usan estados numerados (0, 1 y 2)
- La cadena se recorre carácter por carácter
- El estado cambia según el carácter leído
- Si el AFD termina en el estado de aceptación, la cadena es válida

---

## Observaciones

Este taller se realizó para practicar el uso de autómatas finitos deterministas y comprender cómo se valida una cadena usando estados y transiciones.

