//hola.c - pruba de entorno de ua2
#include <stdio.h>

int main(void) {
    int edad;
    //muestra de msj por pantalla 
    printf ("entorno listo para la UA2\n");
    //pide y lee un numero
    printf ("Digite su edad: ");
    scanf("%d", &edad);

    //mostrar la salida
    printf("Edad registrada: %d\n", &edad);
    return 0;
}