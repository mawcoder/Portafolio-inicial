// Ejercicio 6.1
#include <stdio.h>
#include <string.h>

// Se crea una función que cuenta los caracteres, vocales y palabras de una cadena de texto.
void contadorElementos(char *frace, int *caracteres, int *vocales, int *palabras) {
    // Se recorre cada carácter de la cadena.
    for (size_t l = 0; l < strlen(frace); l++) {
        // Se cuenta la primera palabra.
        if (l == 0) {
            *palabras += 1;
        }
        // Se incrementa el contador de palabras al encontrar un espacio seguido de un carácter distinto de '\0'.
        if (frace[l] == ' ' && frace[l + 1] != '\0') {
            *palabras += 1;
        }
        else {
            // Se incrementa el contador de caracteres.
            *caracteres += 1;
        }
    }
}

int main() {
    // Se declara un arreglo de caracteres y las variables contadoras.
    char frace[25];
    int caracteres = 0, vocales = 0, palabras = 0;

    // Se carga la frase por teclado usando fgets.
    printf("Ingrese una frace: ");
    fgets(frace, sizeof(frace), stdin);
    frace[strcspn(frace, "\n")] = '\0'; // Se elimina el salto de línea al final de la cadena.

    // Se llama a la función contadorElementos pasando la dirección de las variables contadoras.
    contadorElementos(frace, &caracteres, &vocales, &palabras);

    // Se muestran los resultados por pantalla.
    printf("La frace tiene: %d caracteres, %d palabras\n", caracteres, palabras);

    return 0;
}
