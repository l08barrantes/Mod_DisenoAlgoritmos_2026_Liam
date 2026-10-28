/*
 * Enunciado: analizar una frase.
 * Se logra: mostrarla en mayusculas y contar vocales,
 *           consonantes y digitos.
 * Como: getchar/putchar, isalpha, isdigit, toupper y la
 *       funcion propia esVocal.
 * Resultado: la frase en mayusculas y los tres conteos.
 */
#include <stdio.h>
#include <ctype.h>

int esVocal(int c);

int main(void) {
    int c;                // caracter leido
    int vocales = 0;      // cantidad de vocales
    int consonantes = 0;  // cantidad de consonantes
    int digitos = 0;      // cantidad de digitos

    printf("Frase: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        putchar(toupper(c));
        if (isalpha(c)) {
            if (esVocal(c)) {
                vocales++;
            } else {
                consonantes++;
            }
        } else if (isdigit(c)) {
            digitos++;
        }
    }
    printf("\nVocales: %d Consonantes: %d Digitos: %d\n",
           vocales, consonantes, digitos);
    return 0;
}

/* Recibe un caracter; devuelve 1 si es vocal y 0 si no */
int esVocal(int c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
