// Ejercicio 6.3
#include <stdio.h>
#include <string.h>

// Se crea una función que invierte los caracteres de una cadena de texto.
void invertir(char *frase) {
    // Se definen punteros al inicio y al final de la cadena.
    char *inicio = frase;
    char *fin = frase + strlen(frase) - 1;
    char temp;

    // Se intercambian los caracteres desde los extremos hasta el centro de la cadena.
    while (inicio < fin) {
        temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++;
        fin--;
    }
}

int main() {
    // Se declara un arreglo de caracteres para almacenar la frase.
    char frase[100];

    // Se carga la frase por teclado usando fgets.
    printf("Ingrese una frace: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';  // Se elimina el salto de línea al final de la cadena.

    // Se llama a la función invertir para invertir la frase.
    invertir(frase);

    // Se muestra la frase invertida por pantalla.
    printf("La frase invertida es: %s\n", frase);

    return 0;
}
