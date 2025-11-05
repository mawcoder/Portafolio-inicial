// Ejercicio 4.1
#include <stdio.h>

// Se crea una función para duplicar un número usando un puntero.
void duplicar(int *num) {
    *num = *num * 2;
}

int main() {
    // Se crea una variable int para almacenar el número.
    int num;

    // Se carga el número por teclado y se muestra antes de pasarlo a la función.
    printf("Ingrese el numero a duplicar: ");
    scanf("%d", &num);

    printf("El valor del numero antes de la operacion es: %d\n", num);

    // Se pasa la dirección del número en memoria a la función duplicar, lo que equivale a pasar un puntero.
    // Luego se muestra el resultado en pantalla.
    duplicar(&num);
    printf("El valor del numero despues de la operacion es: %d\n", num);

    return 0;
}
