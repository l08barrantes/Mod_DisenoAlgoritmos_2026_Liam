/*
 * Enunciado: redondear un monto al multiplo de 5 mas cercano.
 * Se logra: 1232 -> 1230; 1233 -> 1235; 1237.5 -> 1240.
 * Como: round(monto / 5) * 5.
 * Resultado: tres redondeos correctos.
 */
#include <stdio.h>
#include <math.h>

double redondearCinco(double monto);

int main(void) {
    printf("1232 -> %.0f\n", redondearCinco(1232));
    printf("1233 -> %.0f\n", redondearCinco(1233));
    printf("1237.5 -> %.0f\n", redondearCinco(1237.5));
    return 0;
}

/* Recibe un monto; redondea al multiplo de 5; devuelve el resultado */
double redondearCinco(double monto) {
    return round(monto / 5) * 5;
}
