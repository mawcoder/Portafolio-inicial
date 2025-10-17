// Ejercicio 3.1
// Creamos un int y un puntero que apunta a él.
// Luego mostramos el valor del int, su dirección en memoria, el contenido del puntero, y el valor apuntado.
#include <stdio.h>

int main () {
    int altura = 164;
    int *punteroAltura;
    punteroAltura = &altura;

    printf ("el valor de altura es: %d\n", altura);
    printf ("la dirección de altura es: %p\n", &altura);
    printf ("el contenido del puntero a altura es: %p\n", punteroAltura);
    printf ("el valor apuntado por el puntero a altura es: %d\n", *punteroAltura);

    return 0;
}

