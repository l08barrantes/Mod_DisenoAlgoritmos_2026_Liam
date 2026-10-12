//caja.c Caja registradora con menu

#include <stdio.h>

int main(void) {
    //declaracion de variables
    int opcion;              //opcion elegida en el menu
    int productos = 0;       //Contador de productos de la venta (inicia en 0)
    double precio;           //precio para cada producto
    double total = 0;        //ACUMULADOR de la venta (inicia en 0)

    //DO ... WHILE el menu se muestra al menos una vez
    do {
        //muestra el menu y lee la opcion
        printf("\n1. Agregar 2. Ver total 3. Cobrar 0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        //SWITCH (segun): salta al case que coincida con la opcion elegida
        switch (opcion) {
            case 1:
                //validacion: repite mientras el precio no sea positivo
                do {
                    printf("Precio del producto: ");
                    scanf("%lf", &precio);   //-> 1500 (-200 se rechaza)
                    if (precio <= 0) {
                        printf("Precio invalido\n");
                    }
                } while (precio <= 0);

                productos++;                 //cuenta productos
                total += precio;             //suma el precio
                break;                       //sale del switch

            case 2:
                //muestra el avance
                printf("Productos: %d Total: %.2f\n", productos, total);
                break;

            case 3:
                //cobra, reinicia contador y acumulador
                printf("Cobrado: %.2f\nNueva venta\n", total);
                productos = 0;
                total = 0;
                break;

            case 0:
                printf("Caja cerrada\n");
                break;

            default:
                //ningun case coincide
                printf("Opcion invalida\n");
        }
        //repite el menu mientras no se elija 0
    } while (opcion != 0);

    return 0;
}