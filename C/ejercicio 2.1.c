// Ejercicio 2.1
// Creamos Variables de tipo int, float y char y mostramos sus valores por pantalla.
#include <stdio.h>

int main () {
// declaramos e inicializamos variables de tipo int, float y char.
    int edad = 26;
    float altura = 1.69;
    char inicial = 'M';

// mostramos las variables por pantalla.
    printf ("mi edad es: %d anios\n", edad);
    printf ("Mi altura es: %.2f metros\n", altura);
    printf ("la inicial de mi apellido es: %c\n", inicial);

    return 0;
}

