// Ejercicio 3.1
// Se crea una variable de tipo int y un puntero que apunta a ella.
// Luego se muestra el valor del int, su dirección en memoria, el contenido del puntero y el valor apuntado.

#include <stdio.h>

int main() {
    int altura = 164;
    int *punteroAltura;
    punteroAltura = &altura;

    printf("El valor de altura es: %d\n", altura);
    printf("La dirección de altura es: %p\n", &altura);
    printf("El contenido del puntero a altura es: %p\n", punteroAltura);
    printf("El valor apuntado por el puntero a altura es: %d\n", *punteroAltura);

    return 0;
}
