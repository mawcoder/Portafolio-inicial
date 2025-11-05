// Ejercicio 3.3
// Se cargan dos números por teclado y se intercambian usando punteros y una variable temporal.

#include <stdio.h>

int main() {
    // Se declaran las variables int y los punteros a int.
    int a, b, temp;
    int *pA = NULL, *pB = NULL;

    // Se cargan los dos números por teclado.
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);

    // Se asignan los punteros a las variables para poder intercambiarlas y se muestran los valores antes del cambio.
    pA = &a;
    pB = &b;

    printf("Los valores antes del intercambio son: %d y %d\n", a, b);

    // Se realiza el intercambio usando los punteros y la variable temporal, y se muestran los valores actualizados.
    temp = *pA;
    *pA = *pB;
    *pB = temp;

    printf("Los valores despues del intercambio son: %d y %d\n", *pA, *pB);

    return 0;
}
