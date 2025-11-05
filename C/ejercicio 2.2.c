// Ejercicio 2.2
// Se crean variables de tipo int, float y char.
// Se muestran sus valores por pantalla y se calcula el año de nacimiento.

#include <stdio.h>

int main() {
    // Se declaran e inicializan las variables.
    int edad = 28, anioActual = 2025;
    float altura = 1.71;
    char inicial = 'M';

    // Se muestran las variables por pantalla, además de calcular y mostrar el año de nacimiento.
    printf("Mi edad es: %d\n", edad);
    printf("Mi altura es: %.2f\n", altura);
    printf("La inicial de mi apellido es: %c\n", inicial);
    printf("El año de mi nacimiento es: %d\n", anioActual - edad);

    return 0;
}
