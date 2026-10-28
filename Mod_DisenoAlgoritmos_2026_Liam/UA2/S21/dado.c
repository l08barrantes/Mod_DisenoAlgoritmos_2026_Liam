/*
 * Enunciado: simular 600 lanzamientos de un dado.
 * Se logra: contar cuantas veces sale cada cara y mostrar barras.
 * Como: rand/srand, int lanzarDado(void), void mostrarBarra(int)
 *       y un arreglo de contadores.
 * Resultado: seis lineas "Cara n: cantidad ****" (un * por 10).
 */
#include <stdio.h>
#include <stdlib.h>

#define LANZAMIENTOS 600 // total de lanzamientos

int lanzarDado(void);
void mostrarBarra(int cantidad);

int main(void) {
    int frecuencia[7] = {0}; // contador por cara (indice 1 a 6)
    int i;                   // control de ciclos

    srand(2026);
    for (i = 1; i <= LANZAMIENTOS; i++) {
        frecuencia[lanzarDado()]++;
    }
    for (i = 1; i <= 6; i++) {
        printf("Cara %d: %d ", i, frecuencia[i]);
        mostrarBarra(frecuencia[i]);
    }
    return 0;
}

/* No recibe nada; simula un dado; devuelve un numero de 1 a 6 */
int lanzarDado(void) {
    return rand() % 6 + 1;
}

/* Recibe una cantidad; dibuja un * por cada 10; no devuelve nada */
void mostrarBarra(int cantidad) {
    int i; // control del ciclo
    for (i = 1; i <= cantidad / 10; i++) {
        printf("*");
    }
    printf("\n");
}
