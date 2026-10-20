/*ESTE DOCUMENTE FORMA PARTE DE LA AC-2 LLAMADO CALIFICACIONES */
#include <stdio.h>
#include <string.h>
/*definicion de variables*/
#define NUM_NOTAS 3          
#define NOTA_MIN 0.0f        
#define NOTA_MAX 100.0f    
#define LIM_APROBADO 70.0f  
#define LIM_RIESGO 60.0f     
#define MAX_NOMBRE 100       
 
int main(void) {
    char nombre[MAX_NOMBRE]; 
    char condicion[15];      
    float notas[NUM_NOTAS];  
    float suma = 0.0f;      
    float promedio;          
    float mayor;            
    int i;                   
    int leidos;             
    int c;                  
 
    printf("=== Calificaciones del estudiante ===\n");
 /*dotos del estudiante y notas*/
    printf("Nombre del estudiante: ");
    if (fgets(nombre, sizeof(nombre), stdin) == NULL) {
        return 1;
    }
    nombre[strcspn(nombre, "\n")] = '\0';
 
    for (i = 0; i < NUM_NOTAS; i++) {
        do {
            printf("Calificacion %d (0 a 100): ", i + 1);
            leidos = scanf("%f", &notas[i]);
            if (leidos != 1) {
                while ((c = getchar()) != '\n' && c != EOF) {
                }
                if (c == EOF) {
                    return 1;
                }
                notas[i] = -1.0f;
            }
            if (notas[i] < NOTA_MIN || notas[i] > NOTA_MAX) {
                printf("Calificacion fuera de rango. Intente de nuevo.\n");
            }
        } while (notas[i] < NOTA_MIN || notas[i] > NOTA_MAX);
    }
 
    mayor = notas[0];
    for (i = 0; i < NUM_NOTAS; i++) {
        suma += notas[i];
        if (notas[i] > mayor) {
            mayor = notas[i];
        }
    }
    promedio = suma / NUM_NOTAS;
 /* aqui se aplica el promedio aprov o no aprov*/
    if (promedio >= LIM_APROBADO) {
        strcpy(condicion, "APROBADO");
    } else if (promedio >= LIM_RIESGO) {
        strcpy(condicion, "EN RIESGO");
    } else {
        strcpy(condicion, "NO APROBADO");
    }
 
    printf("------- Resultado -------\n");
    printf("Estudiante: %s\n", nombre);
    for (i = 0; i < NUM_NOTAS; i++) {
        printf("Calificacion %d: %.1f\n", i + 1, notas[i]);
    }
    printf("Promedio: %.2f\n", promedio);
    printf("Nota mas alta: %.1f\n", mayor);
    printf("Condicion: %s\n", condicion);
 
    return 0;
}
 