#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Se crea una función que cuenta caracteres visibles, vocales y palabras en una cadena de texto.
void contadorElementos(char *frase, int *caracteres, int *vocales, int *palabras) {
    int enPalabra = 0;

    // Se recorre cada carácter de la cadena hasta el carácter nulo.
    for (size_t i = 0; frase[i] != '\0'; i++) {
        char c = frase[i];

        // Contar solo caracteres visibles (excluye espacios, tabs, etc.).
        if (!isspace(c)) {
            (*caracteres)++;
        }

        // Contar vocales usando switch, considerando mayúsculas y minúsculas.
        switch (tolower(c)) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                (*vocales)++;
                break;
        }

        // Detectar inicio de palabra.
        if (!isspace(c) && !enPalabra) {
            (*palabras)++;
            enPalabra = 1;
        } else if (isspace(c)) {
            enPalabra = 0;
        }
    }
}

int main() {
    // Se declara un arreglo de caracteres y variables contadoras.
    char frase[100];
    int caracteres = 0, vocales = 0, palabras = 0;

    // Se carga la frase por teclado usando fgets.
    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';  // Se elimina el salto de línea al final de la cadena.

    // Se llama a la función contadorElementos pasando la dirección de las variables contadoras.
    contadorElementos(frase, &caracteres, &vocales, &palabras);

    // Se muestran los resultados por pantalla.
    printf("\nResumen de la frase:\n");
    printf("Caracteres (sin espacios): %d\n", caracteres);
    printf("Vocales: %d\n", vocales);
    printf("Palabras: %d\n", palabras);

    return 0;
}
