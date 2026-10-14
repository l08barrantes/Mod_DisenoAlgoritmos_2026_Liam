#include <stdio.h>

int main(void) {
    int cantidad, i;
    double nota, suma = 0;

    do {
        printf("Cuantas notas (1 a 10): ");
        scanf("%d", &cantidad);
    } while (cantidad < 1 || cantidad > 10);    // repite si la cantidad es invalida

    for (i = 1; i <= cantidad; i++) {
        do {
            printf("Nota %d (0 a 100): ", i);
            scanf("%lf", &nota);
        } while (nota < 0 || nota > 100);       // repite si la nota es invalida
        suma += nota;                           // solo se suman notas validas
    }

    printf("Suma: %.2f\n", suma);
    printf("Promedio: %.2f\n", suma / cantidad);    // 245 / 3 = 81.67
    return 0;
}