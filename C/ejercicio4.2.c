// Ejercicio 4.2
#include <stdio.h>

// Se crea una función que toma dos punteros a int y los ordena de menor a mayor, intercambiando el orden si es necesario.
void ordenarAscendente(int *x, int *y) {
    if (*x > *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}

int main() {
    // Se crean dos variables para guardar los números.
    int a, b;

    // Se cargan los números por teclado.
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);

    // Se muestran los números antes del cambio, se llama a la función ordenarAscendente pasándole las direcciones de los números cargados y se muestran los números nuevamente.
    printf("El valor de los numeros antes de la operacion es: %d y %d\n", a, b);
    ordenarAscendente(&a, &b);
    printf("El valor de los numeros despues de la operacion es: %d y %d\n", a, b);

    return 0;
}
