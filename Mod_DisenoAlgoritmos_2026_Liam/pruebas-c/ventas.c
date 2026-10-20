//ventas.c Ventas de una cadena de sodas por sucursal y por día
//Qué logra: Guardar en una matriz las ventas de 3 sucursales en 4 días.
/*Suma cada sucursal (fila) y cada día por medio de la (columna) e identifica la sucursal que más vendió, con su nombre guardado en una cadena.
RESULTADO ESPERADO: Centro 470, Norte 350, Sur 410; por día 330 270 330 300; Sucursal con más ventas: Centro (470).
*/
#include <stdio.h>
#include <string.h>             //strcpy
#include <stdlib.h>             //system("pause")
#define SUC 3                   //filas: sucursales
#define DIAS 4                  //columnas: días

int main(void){
    //Arreglo de cadenas: una fila por nombre (hasta 9 letras + '\0')
    char nombres[SUC][10] = {"Centro", "Norte", "Sur"};

    //Ventas en miles de colones
    int ventas[SUC][DIAS] = { {120, 100, 130, 120},
                              {90, 80, 100, 80},
                              {120, 90, 100, 100} };
    char mejor[10];             //nombre de la sucursal ganadora
    int s, d, total, totalDia, mayor = 0;

    //Encabezado: D1 a D4
    printf("%-8s", "");
    for (d = 0; d < DIAS; d++){
        printf("   D%d", d + 1);
    }
    printf(" | Total\n");

    //RECORRIDO POR FILAS
    for (s = 0; s < SUC; s++){
        total = 0;                          //reinicia cada fila
        printf("%-8s", nombres[s]);         //nombre a la izquierda
        for (d = 0; d < DIAS; d++){
            printf("%5d", ventas[s][d]);
            total += ventas[s][d];
        }
        printf(" | %5d\n", total);           //470, 350, 410

        //Guardar la sucursal con mayor total; strcpy copia el nombre
        if (total > mayor){
            mayor = total;
            strcpy(mejor, nombres[s]);      //mejor = Centro
        }
    }