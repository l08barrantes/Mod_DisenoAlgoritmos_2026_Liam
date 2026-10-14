#include <stdio.h>
 
int main(void) {
    int filas, fila, col;
 
    printf("Cantidad de filas: ");
    scanf("%d", &filas);
 
    for (fila = 1; fila <= filas; fila++) {     // ciclo externo: una vuelta por fila
        for (col = 1; col <= fila; col++) {     // interno: tantas vueltas como la fila
            printf("*");
        }
        printf("\n");                           // salta de linea al terminar la fila
    }
 
    for (fila = 1; fila <= filas; fila++) {     // mismo patron, ahora con numeros
        for (col = 1; col <= fila; col++) {
            printf("%d", col);
        }
        printf("\n");
    }
    return 0;
}