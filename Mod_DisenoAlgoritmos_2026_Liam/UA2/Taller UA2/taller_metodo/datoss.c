/*
 * ENUNCIADO: Una empresa de telefonia factura a sus clientes (de 1 a 10).
 * De cada uno se digita el numero (una palabra), el plan (1 Basico: 5 GB por
 * 6000; 2 Medio: 10 GB por 9000; 3 Plus: 20 GB por 14000) y los GB usados en
 * el mes (de 0 a 100, con decimales); un dato invalido se vuelve a pedir.
 * Cada GB que pase de los incluidos cuesta 1200, pero la factura nunca
 * supera 25000. Mostrar una tabla con numero, GB y monto, el total
 * facturado, el cliente con la factura mayor y cuantos llegaron al tope. */

#include <stdio.h>
#include <stdlib.h>

// Constantes
#define MAX_CLIENTES 10
#define GB_MAXIMO 100
#define PRECIO_GB_EXTRA 1200
#define TOPE_FACTURA 25000
#define PRECIO_BASICO 6000
#define PRECIO_MEDIO 9000
#define PRECIO_PLUS 14000
#define GB_BASICO 5
#define GB_MEDIO 10
#define GB_PLUS 20

// Prototipos
int leerEntero(const char mensaje[], int minimo, int maximo);
double leerDecimal(const char mensaje[], double minimo, double maximo);
double precioPlan(int plan);
double gbIncluidos(int plan);
double calcularMonto(int plan, double gb);
void resumir(const double monto[], int n, double *total, int *posMayor, int *conTope);

int main(void) {
    char clientes[MAX_CLIENTES][15]; // numero de cada cliente
    double gbUsados[MAX_CLIENTES];   // GB usados por cliente
    double montos[MAX_CLIENTES];     // factura de cada cliente
    int n, i, plan;                  // cantidad, indice y plan
    double totalFacturado;           // suma de las facturas
    int posMayor, conTope;           // resultados del resumen

    printf("===== Facturacion de Datos Moviles =====\n");
    printf("Planes: 1 Basico 5 GB 6000, 2 Medio 10 GB 9000, 3 Plus 20 GB 14000\n");

    n = leerEntero("Cantidad de clientes (1 a 10): ", 1, MAX_CLIENTES);

    for (i = 0; i < n; i++) {
        printf("\n--- Cliente %d ---\n", i + 1);
        printf("Numero (una palabra): ");
        scanf("%14s", clientes[i]);
        plan = leerEntero("Plan (1 a 3): ", 1, 3);
        gbUsados[i] = leerDecimal("GB usados (0 a 100): ", 0, GB_MAXIMO);
        montos[i] = calcularMonto(plan, gbUsados[i]);
    }

    printf("\n%-12s %8s %10s\n", "Numero", "GB", "Monto");
    for (i = 0; i < n; i++) {
        printf("%-12s %8.1f %10.0f\n", clientes[i], gbUsados[i], montos[i]);
    }

    resumir(montos, n, &totalFacturado, &posMayor, &conTope);

    printf("\nTotal facturado: %.0f\n", totalFacturado);
    printf("Factura mayor: %s con %.0f\n", clientes[posMayor], montos[posMayor]);
    printf("Clientes que llegaron al tope: %d\n", conTope);
    return 0;
}

// Pide un entero en [minimo, maximo]; repite si es invalido
int leerEntero(const char mensaje[], int minimo, int maximo) {
    int valor, ok, c;
    do {
        printf("%s", mensaje);
        ok = scanf("%d", &valor);
        if (ok == EOF) exit(1);
        while ((c = getchar()) != '\n' && c != EOF) { } // limpia la linea
        if (ok != 1 || valor < minimo || valor > maximo) {
            printf("Dato invalido, intente de nuevo.\n");
            ok = 0;
        }
    } while (!ok);
    return valor;
}

// Pide un decimal en [minimo, maximo]; repite si es invalido
double leerDecimal(const char mensaje[], double minimo, double maximo) {
    double valor;
    int ok, c;
    do {
        printf("%s", mensaje);
        ok = scanf("%lf", &valor);
        if (ok == EOF) exit(1);
        while ((c = getchar()) != '\n' && c != EOF) { }
        if (ok != 1 || valor < minimo || valor > maximo) {
            printf("Dato invalido, intente de nuevo.\n");
            ok = 0;
        }
    } while (!ok);
    return valor;
}

// Precio fijo del plan
double precioPlan(int plan) {
    switch (plan) {
        case 1: return PRECIO_BASICO;
        case 2: return PRECIO_MEDIO;
        default: return PRECIO_PLUS;
    }
}

// GB incluidos en el plan
double gbIncluidos(int plan) {
    switch (plan) {
        case 1: return GB_BASICO;
        case 2: return GB_MEDIO;
        default: return GB_PLUS;
    }
}

// Precio del plan + exceso, con tope
double calcularMonto(int plan, double gb) {
    double monto = precioPlan(plan);
    double incluidos = gbIncluidos(plan);
    if (gb > incluidos) {
        monto += (gb - incluidos) * PRECIO_GB_EXTRA;
    }
    if (monto > TOPE_FACTURA) {
        monto = TOPE_FACTURA;
    }
    return monto;
}

// Calcula total, posicion del mayor y cuantos llegaron al tope
void resumir(const double monto[], int n, double *total, int *posMayor, int *conTope) {
    int i;
    *total = 0;
    *posMayor = 0;
    *conTope = 0;
    for (i = 0; i < n; i++) {
        *total += monto[i];
        if (monto[i] > monto[*posMayor]) {
            *posMayor = i;
        }
        if (monto[i] >= TOPE_FACTURA) {
            (*conTope)++;
        }
    }
}