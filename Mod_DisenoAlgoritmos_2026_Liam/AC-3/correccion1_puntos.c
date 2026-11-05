#include <stdio.h>

void sumarPuntos(int *puntos, int compra) {
    *puntos = *puntos + compra / 1000;
}
//ERROR: no se recibian datos pero no los sacaba
//POR QUÉ: porque c copia pero main no los ve
//recirbir la dirección con el *
int main(void) {
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        scanf("%d", &compra);
        //ERROR: no tiene el &
        //POR QUÉ: el scanf lo ocupa para guardar el dato 
        //CORRECIÓN: se cambia por el &compra
        sumarPuntos(&puntos, compra);
    }
//se corrige con & para que recopilen los datos y se liberen
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
