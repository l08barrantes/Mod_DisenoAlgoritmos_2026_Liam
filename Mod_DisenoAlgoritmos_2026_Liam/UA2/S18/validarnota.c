#include <stdio.h>

int main(void) {
    // Varialble de nota 
    double nota;

    // Se pide la nota 
    printf("Nota (0 a 100): ");
    scanf("%lf", &nota);

    // Decisión anidada
    if (nota < 0 || nota > 100) {
        printf("Nota invalida: debe estar entre 0 y 100\n");
    } else if (nota >= 70) {
        printf("Aprobado (%.1f)\n", nota);
    } else {
        printf("Reprobado (%.1f)\n", nota);
    }

    return 0;
}