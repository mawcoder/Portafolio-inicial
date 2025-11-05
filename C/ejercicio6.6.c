// Ejercicio 6.6
#include <stdio.h>
#include <string.h>

// Se crea una función que elimina los signos de puntuación de una cadena.
// Solo se conservan letras, números y espacios.
void eliminarPuntuacion(char *frase) {
    size_t leer = 0, escribir = 0;

    // Se recorre cada carácter de la cadena.
    while (frase[leer] != '\0') {
        // Se copian solo los caracteres alfanuméricos y espacios.
        if ((frase[leer] >= '0' && frase[leer] <= '9') ||
            (frase[leer] >= 'a' && frase[leer] <= 'z') ||
            (frase[leer] >= 'A' && frase[leer] <= 'Z') ||
            (frase[leer] == ' ')) {
            frase[escribir++] = frase[leer++];
        } else {
            // Se omiten los signos de puntuación.
            leer++;
        }
    }

    // Se termina la cadena con carácter nulo.
    frase[escribir] = '\0';
}

int main() {
    // Se declara un arreglo de caracteres para almacenar la frase.
    char frase[100];

    // Se carga la frase por teclado usando fgets.
    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';  // Se elimina el salto de línea si existe.

    // Se llama a la función eliminarPuntuacion para limpiar la cadena.
    eliminarPuntuacion(frase);

    // Se muestra la frase modificada por pantalla.
    printf("La frase modificada es: %s\n", frase);

    return 0;
}
