#include <stdio.h>

#define LIMITE 48
#define RECARGO 1.5
#define CENTINELA -1

int main(void) {
    double horas, tarifa, pago;
    double total = 0;                   // acumulador y contadores en 0
    int personas = 0, conExtra = 0;

    printf("Horas de la semana (-1 para terminar): ");
    scanf("%lf", &horas);               // lectura previa del centinela

    while (horas != CENTINELA) {        // repite hasta digitar -1
        printf("Tarifa por hora: ");
        scanf("%lf", &tarifa);

        if (horas > LIMITE) {           // con extra: 50 h a 3000 -> 153000
            pago = LIMITE * tarifa + (horas - LIMITE) * tarifa * RECARGO;
            conExtra++;
        } else {
            pago = horas * tarifa;
        }

        printf("Pago: %.2f\n", pago);
        total += pago;
        personas++;

        printf("Horas de la semana (-1 para terminar): ");
        scanf("%lf", &horas);
    }

    printf("Personas: %d\n", personas);
    printf("Con horas extra: %d\n", conExtra);
    printf("Total de la planilla: %.2f\n", total);
    return 0;
}