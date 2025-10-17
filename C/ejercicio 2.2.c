// Ejercicio 2.2
// Creamos Variables de tipo int, float y char y mostramos sus valores por pantalla.
#include <stdio.h>

int main () {
// Declaramos e inicializamos variables de tipo int, float y char.
    int edad = 28, anioActual = 2025;
    float altura = 1.71;
    char inicial = 'M';

// Mostramos las variables por pantalla además de obtener el año de nacimiento.
    printf ("mi edad es: %d\n", edad);
    printf ("mi altura es: %.2f\n", altura);
    printf ("la inicial de mi apellido es: %c\n", inicial);
    printf ("el anio de mi nacimiento es: %d\n", anioActual - edad);

    return 0;
}
