// Ejercicio 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Se crea una función que elimina los signos de puntuación de una cadena.
// Solo se conservan letras, números y espacios.
void eliminarPuntuacion(char *frase) {
    size_t leer = 0, escribir = 0;

    // Se recorre cada carácter de la cadena.
    while (frase[leer] != '\0') {
        // Se copian los caracteres alfanuméricos y los espacios.
        if (isalnum(frase[leer]) > 0 || isspace(frase[leer]) > 0) {
            frase[escribir++] = frase[leer++];
        } else {
            // Se omiten los signos de puntuación.
            leer++;
        }
    }

    // Se termina la cadena con carácter nulo.
    frase[escribir] = '\0';
}

// Se crea una función que convierte todos los caracteres de la cadena a minúsculas.
void pasaraMinusculas(char *frase) {
    for (size_t l = 0; l < strlen(frase); l++) {
        frase[l] = tolower(frase[l]);
    }
}

// Se crea una función que elimina espacios extra en la cadena.
// Deja un solo espacio entre palabras y elimina los espacios al inicio y al final.
void eliminarEspacios(char *frase) {
    size_t escribir = 0, leer = 0;
    bool espacio = false;

    // Saltar los espacios al inicio.
    while (frase[leer] == ' ') {
        leer++;
    }

    // Recorrer la cadena y copiar caracteres.
    while (frase[leer] != '\0') {
        if (frase[leer] != ' ') {
            // Copiar caracteres no espacios.
            frase[escribir++] = frase[leer++];
            espacio = false;
        } else if (!espacio) {
            // Copiar un solo espacio entre palabras.
            frase[escribir++] = ' ';
            espacio = true;
            leer++;
        } else {
            leer++;
        }
    }

    // Eliminar espacio al final si existe.
    if (escribir > 0 && frase[escribir - 1] == ' ') {
        escribir--;
    }

    // Terminar la cadena con carácter nulo.
    frase[escribir] = '\0';
}

// Se crea una función que convierte el primer carácter de la cadena a mayúscula.
void primeraaMayuscula(char *frase) {
    if (strlen(frase) > 0) {
        frase[0] = toupper(frase[0]);
    }
}

int main() {
    // Se declara un arreglo de caracteres para almacenar la frase.
    char frase[100];

    // Se carga la frase por teclado usando fgets.
    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';  // Se elimina el salto de línea si existe.

    // Se aplican las funciones para limpiar y formatear la frase.
    eliminarPuntuacion(frase);
    pasaraMinusculas(frase);
    eliminarEspacios(frase);
    primeraaMayuscula(frase);

    // Se muestra la frase modificada por pantalla.
    printf("La frase modificada es: %s\n", frase);

    return 0;
}
