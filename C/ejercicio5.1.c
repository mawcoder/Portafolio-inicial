// Ejercicio 5.1
#include <stdio.h>

// Se crea una función que suma los elementos de un arreglo de enteros y devuelve la suma.
int sumarElementos(int *arr, int cantidad) {
    int suma = 0;
    // Se recorre el arreglo sumando cada elemento.
    for (int j = 0; j < cantidad; j++) {
        suma += *(arr + j);
    }
    return suma;
}

int main() {
    // Se declara un arreglo de 5 enteros.
    int numeros[5];

    // Se cargan los números en el arreglo mediante teclado.
    for (int i = 0; i < 5; i++) {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }

    // Se llama a la función sumarElementos y se guarda el resultado.
    int resultado = sumarElementos(numeros, 5);

    // Se muestra el resultado de la suma en pantalla.
    printf("El resultado de la suma es: %d\n", resultado);

    return 0;
}
