// Ejercicio 2.1
// Se crean variables de tipo int, float y char.
// Se muestran sus valores por pantalla.

#include <stdio.h>

int main() {
    // Se declaran e inicializan las variables.
    int edad = 26;
    float altura = 1.69;
    char inicial = 'M';

    // Se muestran las variables por pantalla.
    printf("Mi edad es: %d años\n", edad);
    printf("Mi altura es: %.2f metros\n", altura);
    printf("La inicial de mi apellido es: %c\n", inicial);

    return 0;
}
