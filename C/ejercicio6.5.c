#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Se crea una función que elimina espacios extra en una cadena.
// Deja un solo espacio entre palabras y elimina los espacios al inicio y al final.
void limpiar_espacios(char *frase) {
    int leer = 0, escribir = 0;
    bool en_espacio = false;

    // Saltar los espacios al inicio de la cadena.
    while (frase[leer] == ' ') {
        leer++;
    }

    // Recorrer la cadena y copiar caracteres.
    while (frase[leer] != '\0') {
        if (frase[leer] != ' ') {
            // Copiar caracteres no espacios.
            frase[escribir++] = frase[leer];
            en_espacio = false;
        } else if (!en_espacio) {
            // Copiar un solo espacio entre palabras.
            frase[escribir++] = ' ';
            en_espacio = true;
        }
        leer++;
    }

    // Eliminar espacio al final si existe.
    if (escribir > 0 && frase[escribir - 1] == ' ') {
        escribir--;
    }

    // Terminar la cadena con carácter nulo.
    frase[escribir] = '\0';
}

int main() {
    // Se declara un arreglo de caracteres para almacenar la frase.
    char frase[100];

    // Se carga la frase por teclado usando fgets.
    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';  // Eliminar el salto de línea si existe.

    // Se llama a la función limpiar_espacios para normalizar la cadena.
    limpiar_espacios(frase);

    // Se muestra la frase limpia por pantalla.
    printf("Frase limpia: '%s'\n", frase);

    return 0;
}
