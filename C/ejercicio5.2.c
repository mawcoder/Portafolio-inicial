// Ejercicio 5.2
#include <stdio.h>

// Se crea una función que calcula el promedio de los elementos de un arreglo de enteros y devuelve el resultado como float.
float promedio(int *arr, int cantidad) {
    int suma = 0;
    // Se recorre el arreglo sumando cada elemento.
    for (int j = 0; j < cantidad; j++) {
        suma += *(arr + j);
    }
    // Se calcula el promedio convirtiendo la suma a float y dividiéndola entre la cantidad de elementos.
    float resultado = (float) suma / cantidad;
    return resultado;
}

int main() {
    // Se declara un arreglo de 5 enteros.
    int numeros[5];

    // Se cargan los números en el arreglo mediante teclado.
    for (int i = 0; i < 5; i++) {
        printf("Ingresa un numero: ");
        scanf("%d", numeros + i);
    }

    // Se llama a la función promedio y se guarda el resultado.
    float resultado = promedio(numeros, 5);

    // Se muestra el promedio en pantalla.
    printf("El promedio es: %.2f\n", resultado);

    return 0;
}
