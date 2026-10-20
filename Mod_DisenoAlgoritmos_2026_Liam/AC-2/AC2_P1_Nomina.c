/*ESTE DOCUMENTO FORMA PARTE DE LA AC-2 LLAMADO NOMINA  */
#include <stdio.h>
#include <string.h>
/*definicion de variables*/
#define TASA_CAJA 0.095      
#define TASA_IESS 0.025      
#define TASA_RENTA 0.10      
#define LIMITE_RENTA 800.0  
#define MAX_NOMBRE 100      

int main(void) {
    char nombre[MAX_NOMBRE]; 
    double bruto;           
    double caja, iess;       
    double renta = 0.0;     
    double neto;             
    int leidos;             
    int c;                  

    printf("=== Calculo de nomina ===\n");
/* datos del empleado*/
    do {
        printf("Nombre del empleado: ");
        if (fgets(nombre, sizeof(nombre), stdin) == NULL) {
            return 1;
        }
        nombre[strcspn(nombre, "\n")] = '\0';
        if (strlen(nombre) == 0) {
            printf("El nombre no puede estar vacio.\n");
        }
    } while (strlen(nombre) == 0);
/*solicitud del monto bruto*/
    do {
        printf("Salario bruto: ");
        leidos = scanf("%lf", &bruto);
        if (leidos != 1) {
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            if (c == EOF) {
                return 1;
            }
            bruto = 0;
        }
        if (bruto <= 0) {
            printf("El salario debe ser mayor que 0.\n");
        }
    } while (bruto <= 0);

    caja = bruto * TASA_CAJA;
    iess = bruto * TASA_IESS;
    if (bruto > LIMITE_RENTA) {
        renta = bruto * TASA_RENTA;
    }
    neto = bruto - caja - iess - renta;

    printf("------- Comprobante de pago -------\n");
    printf("%-24s %s\n", "Empleado:", nombre);
    printf("%-24s %9.2f\n", "Salario bruto:", bruto);
    printf("%-24s %9.2f\n", "Descuento CAJA (9.5%):", caja);
    printf("%-24s %9.2f\n", "Descuento IESS (2.5%):", iess);
    printf("%-24s %9.2f\n", "Impuesto renta (10%):", renta);
    printf("%-24s %9.2f\n", "Salario neto:", neto);

    return 0;
}