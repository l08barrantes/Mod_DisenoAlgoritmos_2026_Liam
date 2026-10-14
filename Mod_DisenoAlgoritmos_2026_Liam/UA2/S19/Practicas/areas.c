#include <stdio.h>

#define PI 3.14159265

int main(void) {
    int opcion;
    double lado, base, altura, radio;

    do {                                // repite el menu hasta digitar 0
        printf("1. Cuadrado 2. Rectangulo 3. Circulo 0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:                     // cada case termina con break
                printf("Lado: ");
                scanf("%lf", &lado);
                printf("Area: %.2f\n", lado * lado);
                break;
            case 2:
                printf("Base: ");
                scanf("%lf", &base);
                printf("Altura: ");
                scanf("%lf", &altura);
                printf("Area: %.2f\n", base * altura);
                break;
            case 3:
                printf("Radio: ");
                scanf("%lf", &radio);
                printf("Area: %.2f\n", PI * radio * radio);
                break;
            case 0:
                printf("Hasta luego\n");
                break;
            default:                    // cualquier otra opcion
                printf("Opcion invalida\n");
        }
    } while (opcion != 0);
    return 0;
}
