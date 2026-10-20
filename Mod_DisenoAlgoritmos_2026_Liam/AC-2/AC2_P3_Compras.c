#include <stdio.h>
#include <string.h>
/*definir variables*/
#define MAX_PRODUCTOS 10    
#define MAX_NOMBRE 50        
#define IMPUESTO 0.13        
#define LIM_DESC1 100.0      
#define LIM_DESC2 500.0      
#define LIM_DESC3 1000.0    
#define DESC1 0.05          
#define DESC2 0.10           
#define DESC3 0.15           
 
int main(void) {
    char cliente[MAX_NOMBRE];                  
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];    
    double precios[MAX_PRODUCTOS];              
    int cantidades[MAX_PRODUCTOS];              
    int n = 0;                                  
    char opcion;                                
    double subtotal = 0.0;                      
    double tasaDesc = 0.0;                      
    double descuento, totalDesc, impuesto, total;
    int leidos;                                
    int c;                                      
    int i;                                      
 
    printf("=== Compra en la tienda ===\n");
    printf("Nombre del cliente: ");
    if (fgets(cliente, sizeof(cliente), stdin) == NULL) {
        return 1;
    }
    cliente[strcspn(cliente, "\n")] = '\0';
 
    do {
        printf("Producto %d\n", n + 1);
 
        do {
            printf(" Nombre: ");
            if (fgets(nombres[n], MAX_NOMBRE, stdin) == NULL) {
                return 1;
            }
            nombres[n][strcspn(nombres[n], "\n")] = '\0';
            if (strlen(nombres[n]) == 0) {
                printf(" El nombre no puede estar vacio.\n");
            }
        } while (strlen(nombres[n]) == 0);
 
        do {
            printf(" Precio unitario: ");
            leidos = scanf("%lf", &precios[n]);
            if (leidos != 1) {
                while ((c = getchar()) != '\n' && c != EOF) {
                }
                if (c == EOF) {
                    return 1;
                }
                precios[n] = 0;
            }
            if (precios[n] <= 0) {
                printf(" El precio debe ser positivo.\n");
            }
        } while (precios[n] <= 0);
 
        do {
            printf(" Cantidad: ");
            leidos = scanf("%d", &cantidades[n]);
            if (leidos != 1) {
                while ((c = getchar()) != '\n' && c != EOF) {
                }
                if (c == EOF) {
                    return 1;
                }
                cantidades[n] = 0;
            }
            if (cantidades[n] <= 0) {
                printf(" La cantidad debe ser positiva.\n");
            }
        } while (cantidades[n] <= 0);
 
        printf(" Subtotal: %.2f\n", precios[n] * cantidades[n]);
        subtotal += precios[n] * cantidades[n];
        n++;
 
        if (n == MAX_PRODUCTOS) {
            printf("Se alcanzo el maximo de %d productos.\n", MAX_PRODUCTOS);
            opcion = 'N';
        } else {
            do {
                printf("Desea agregar otro producto? (S/N): ");
                leidos = scanf(" %c", &opcion);
                while ((c = getchar()) != '\n' && c != EOF) {
                }
                if (leidos != 1) {
                    return 1;
                }
                if (opcion != 'S' && opcion != 's' &&
                    opcion != 'N' && opcion != 'n') {
                    printf("Responda solo S o N.\n");
                }
            } while (opcion != 'S' && opcion != 's' &&
                     opcion != 'N' && opcion != 'n');
        }
    } while (opcion == 'S' || opcion == 's');
 
    if (subtotal > LIM_DESC3) {
        tasaDesc = DESC3;
    } else if (subtotal >= LIM_DESC2) {
        tasaDesc = DESC2;
    } else if (subtotal >= LIM_DESC1) {
        tasaDesc = DESC1;
    }

    /*descuentos de productos*/
    descuento = subtotal * tasaDesc;
    totalDesc = subtotal - descuento;
    impuesto = totalDesc * IMPUESTO;
    total = totalDesc + impuesto;
 
    printf("================= FACTURA =================\n");
    printf("Cliente: %s\n", cliente);
    printf("%-20s %9s %5s %10s\n", "Producto", "Precio", "Cant", "Subtotal");
    for (i = 0; i < n; i++) {
        printf("%-20s %9.2f %5d %10.2f\n", nombres[i], precios[i],
               cantidades[i], precios[i] * cantidades[i]);
    }
    printf("Productos registrados: %d\n", n);
    printf("Subtotal: %.2f\n", subtotal);
    printf("Descuento: %.2f (%.0f%%)\n", descuento, tasaDesc * 100);
    printf("Total con descuento: %.2f\n", totalDesc);
    printf("Impuesto (13%%): %.2f\n", impuesto);
    printf("TOTAL A PAGAR: %.2f\n", total);
 
    return 0;
}
 