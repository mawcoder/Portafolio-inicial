// Ejercicio 6.4 - Versión con return único al final
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Se crea una función que verifica si una cadena es un palíndromo.
// Devuelve true si es palíndromo y false en caso contrario.
bool palindromo(char *frase) {
    // Se definen punteros al inicio y al final de la cadena.
    char *inicio = frase;
    char *fin = frase + strlen(frase) - 1;
    bool es_palindromo = true;

    // Se recorren los caracteres desde ambos extremos hasta encontrarse en el centro.
    while (inicio < fin) {
        // Saltar espacios y signos desde el inicio.
        if (*inicio == ' ' || *inicio == ',' || *inicio == '.') {
            inicio++;
            continue; // Volver al while sin comparar.
        }

        // Saltar espacios y signos desde el final.
        if (*fin == ' ' || *fin == ',' || *fin == '.') {
            fin--;
            continue; // Volver al while sin comparar.
        }

        // Comparar los caracteres en minúscula.
        if (tolower(*inicio) != tolower(*fin)) {
            es_palindromo = false; // Ya no es un palíndromo.
            break; // Salir del bucle.
        }

        // Avanzar los punteros.
        inicio++;
        fin--;
    }

    // Retorna true si es palíndromo, false en caso contrario.
    return es_palindromo;
}

int main() {
    // Se declara un arreglo de caracteres para almacenar la frase.
    char frase[100];

    // Se carga la frase por teclado usando fgets.
    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Se elimina el salto de línea si quedó al final de la cadena.
    frase[strcspn(frase, "\n")] = '\0';

    // Se llama a la función palindromo y se muestra el resultado en pantalla.
    if (palindromo(frase))
        printf("La frase es un palíndromo, ¡felicitaciones!\n");
    else
        printf("La frase no es un palíndromo, intentá otra vez\n");

    return 0;
}
