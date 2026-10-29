/*
 * Que se logra: inventario de una pulperia con menu para listar,
 * vender (solo si hay existencias), reponer y consultar el valor.
 * Resultado esperado: vende 5 de Cafe (quedan 7), rechaza 20 de Aceite
 * ("Solo hay 8 unidades"), repone 10 de Aceite (quedan 18) y el valor
 * final del inventario es 164100.00.
 */
#include <stdio.h>

#define N 4

int leerEntero(const char mensaje[], int minimo, int maximo);
void listar(const char nombres[][20], const double precios[],
            const int existencias[], int n);
int vender(int *existencia, int cantidad);
void reponer(int *existencia, int cantidad);
double valorInventario(const double precios[], const int existencias[], int n);

int main(void)
{
    const char nombres[N][20] = {"Arroz 2 kg", "Frijoles 1 kg",
                                 "Cafe 1 kg", "Aceite 1 L"};
    const double precios[N] = {2400, 1800, 4500, 3200};
    int existencias[N] = {20, 15, 12, 8};
    int opcion, p, cantidad;

    do {
        printf("1. Listar 2. Vender 3. Reponer 4. Valor 0. Salir\n");
        opcion = leerEntero("Opcion (0 a 4): ", 0, 4);

        switch (opcion) {
        case 1:
            listar(nombres, precios, existencias, N);
            break;
        case 2:
            p = leerEntero("Producto (1 a 4): ", 1, N) - 1;
            cantidad = leerEntero("Cantidad (1 a 50): ", 1, 50);
            if (vender(&existencias[p], cantidad)) {
                printf("Vendido: %d x %s = %.2f\n", cantidad, nombres[p],
                       cantidad * precios[p]);
            } else {
                printf("Solo hay %d unidades\n", existencias[p]);
            }
            break;
        case 3:
            p = leerEntero("Producto (1 a 4): ", 1, N) - 1;
            cantidad = leerEntero("Cantidad (1 a 50): ", 1, 50);
            reponer(&existencias[p], cantidad);
            printf("Existencias de %s: %d\n", nombres[p], existencias[p]);
            break;
        case 4:
            printf("Valor del inventario: %.2f\n",
                   valorInventario(precios, existencias, N));
            break;
        default:
            printf("Hasta luego\n");
        }
    } while (opcion != 0);

    return 0;
}

/* Repite hasta recibir un entero dentro del rango */
int leerEntero(const char mensaje[], int minimo, int maximo)
{
    int valor, ok, c;

    do {
        printf("%s", mensaje);
        ok = scanf("%d", &valor);
        /* Limpia el resto de la linea */
        while ((c = getchar()) != '\n' && c != EOF) {
        }
        if (c == EOF && ok != 1) {
            return minimo;
        }
        if (ok != 1 || valor < minimo || valor > maximo) {
            printf("Entrada invalida\n");
            ok = 0;
        }
    } while (!ok);

    return valor;
}

/* Muestra numero, nombre, precio y existencias */
void listar(const char nombres[][20], const double precios[],
            const int existencias[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d. %s %.2f %d\n", i + 1, nombres[i], precios[i],
               existencias[i]);
    }
}

/* Descuenta si alcanza; devuelve 1 si vendio, 0 si no */
int vender(int *existencia, int cantidad)
{
    if (*existencia >= cantidad) {
        *existencia -= cantidad;
        return 1;
    }
    return 0;
}

/* Suma la cantidad a la existencia */
void reponer(int *existencia, int cantidad)
{
    *existencia += cantidad;
}

/* Suma existencias x precio de todos los productos */
double valorInventario(const double precios[], const int existencias[], int n)
{
    double total = 0;
    int i;

    for (i = 0; i < n; i++) {
        total += existencias[i] * precios[i];
    }
    return total;
}
