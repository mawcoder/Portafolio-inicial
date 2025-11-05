// Ejercicio 4.2
#include <stdio.h>

int main() {
    // Se declara una variable int y un puntero a int.
    int edad = 0;
    int *pEdad = NULL;

    // Se carga la edad por teclado con scanf.
    printf("por favor, ingresa tu edad: ");
    scanf("%d", &edad);

    // Se asigna el puntero a la variable edad.
    pEdad = &edad;

    // Se muestra el valor de la variable edad.
    printf("el valor de edad es: %d\n", edad);

    // Se muestra el valor apuntado por pEdad.
    printf("el valor al que apunta el puntero pEdad es: %d\n", *pEdad);

    // Se muestra la dirección de la variable edad.
    printf("la dirección en memoria de la variable edad es: %p\n", &edad);

    // Se muestra el contenido del puntero pEdad, es decir, la dirección de la variable edad.
    printf("el contenido del puntero pEdad es: %p\n", pEdad);

    return 0;
}
