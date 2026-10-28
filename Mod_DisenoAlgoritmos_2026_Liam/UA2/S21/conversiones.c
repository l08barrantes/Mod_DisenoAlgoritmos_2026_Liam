/*
 * Enunciado: biblioteca de conversiones y validaciones.
 * Se logra: reunir 4 algoritmos de la UA1 en funciones.
 * Como: prototipos, parametros y return; main las prueba.
 * Resultado: cada prueba coincide con el valor esperado.
 */
#include <stdio.h>

#define COLONES_POR_DOLAR 510.0 // tipo de cambio

double celsiusAFahrenheit(double c);
double colonesADolares(double c);
int esBisiesto(int anio);
int esNotaValida(double nota);

int main(void) {
    printf("25 C = %.1f F (esperado 77.0)\n", celsiusAFahrenheit(25));
    printf("5100 colones = %.2f dolares (esperado 10.00)\n", colonesADolares(5100));
    printf("2024 bisiesto: %d (esperado 1)\n", esBisiesto(2024));
    printf("1900 bisiesto: %d (esperado 0)\n", esBisiesto(1900));
    printf("Nota 105 valida: %d (esperado 0)\n", esNotaValida(105));
    printf("Nota 85 valida: %d (esperado 1)\n", esNotaValida(85));
    return 0;
}

/* Recibe grados C; convierte; devuelve grados F */
double celsiusAFahrenheit(double c) {
    return c * 9.0 / 5.0 + 32;
}

/* Recibe colones; divide por el tipo de cambio; devuelve dolares */
double colonesADolares(double c) {
    return c / COLONES_POR_DOLAR;
}

/* Recibe un anio; devuelve 1 si es bisiesto y 0 si no */
int esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

/* Recibe una nota; devuelve 1 si esta entre 0 y 100, 0 si no */
int esNotaValida(double nota) {
    return nota >= 0 && nota <= 100;
}
