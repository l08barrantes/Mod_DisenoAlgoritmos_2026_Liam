#include <stdio.h>
#define N 5
int main(void) {
    double notas[N] = {80, 75, 90, 65, 100};
    double suma = 0, mayor, menor;
    int i;
    mayor = menor = notas[0];       // se empieza con la primera
    for (i = 0; i < N; i++) {
        suma += notas[i];
        if (notas[i] > mayor) { mayor = notas[i]; }
        if (notas[i] < menor) { menor = notas[i]; }
    }
    printf("Promedio: %.2f\n", suma / N);
    printf("Mayor: %.1f  Menor: %.1f\n", mayor, menor);
    return 0;
}