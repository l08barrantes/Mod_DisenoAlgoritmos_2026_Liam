//ENUNCIADO: La biblioteca de un colegio necesita un sistema para controlar el préstamo de sus libros. Puede registrar hasta 5 libros. De cada libro se guarda: el código (100 a 999, no se repite), el título (una sola palabra, hasta 19 letras), los ejemplares disponibles y si el libro está activo o dado de baja. El programa inicia con 3 libros ya cargados (tabla de abajo). Debe mostrar un menú que se repite hasta elegir 0; toda opción o dato fuera de rango se vuelve a pedir

#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 5
#define LARGO_TITULO 20
#define COD_MIN 100
#define COD_MAX 999
#define EJ_MIN 1
#define EJ_MAX 20
#define ACTIVO 1
#define BAJA 0

int leerEntero(int minimo, int maximo, const char mensaje[]);
void leerTitulo(char titulo[]);
int buscarCodigo(const int codigos[], const int estados[], int n, int codigo);
void incluir(int codigos[], char titulos[][LARGO_TITULO], int disponibles[],
             int estados[], int *n);
void consultar(const int codigos[], const char titulos[][LARGO_TITULO],
               const int disponibles[], const int estados[], int n);
int prestar(int *disponibles);
void darDeBaja(int *estado);
void mostrarNoExiste(int codigo);

int main(void) {
    int codigos[MAX_LIBROS] = {101, 102, 103};
    char titulos[MAX_LIBROS][LARGO_TITULO] = {"Quijote", "Principito", "Cocori"};
    int disponibles[MAX_LIBROS] = {3, 2, 4};
    int estados[MAX_LIBROS] = {ACTIVO, ACTIVO, ACTIVO};
    int cantidad = 3;
    int opcion, codigo, pos;

    do {
        printf("\n===== BIBLIOTECA =====\n");
        printf("1. Incluir libro\n2. Consultar libros\n3. Prestar un ejemplar\n");
        printf("4. Dar de baja un libro\n5. Buscar libro\n0. Salir\n");
        opcion = leerEntero(0, 5, "Opcion: ");

        switch (opcion) {
        case 1:
            incluir(codigos, titulos, disponibles, estados, &cantidad);
            break;
        case 2:
            consultar(codigos, titulos, disponibles, estados, cantidad);
            break;
        case 3:
            codigo = leerEntero(COD_MIN, COD_MAX, "Codigo del libro: ");
            pos = buscarCodigo(codigos, estados, cantidad, codigo);
            if (pos == -1)
                mostrarNoExiste(codigo);
            else if (prestar(&disponibles[pos]))
                printf("Prestamo realizado. Quedan %d ejemplares.\n", disponibles[pos]);
            else
                printf("No hay ejemplares disponibles.\n");
            break;
        case 4:
            codigo = leerEntero(COD_MIN, COD_MAX, "Codigo del libro: ");
            pos = buscarCodigo(codigos, estados, cantidad, codigo);
            if (pos == -1)
                mostrarNoExiste(codigo);
            else {
                darDeBaja(&estados[pos]);
                printf("Libro %s dado de baja.\n", titulos[pos]);
            }
            break;
        case 5:
            codigo = leerEntero(COD_MIN, COD_MAX, "Codigo del libro: ");
            pos = buscarCodigo(codigos, estados, cantidad, codigo);
            if (pos == -1)
                mostrarNoExiste(codigo);
            else
                printf("%d %s: %d disponibles.\n", codigos[pos], titulos[pos],
                       disponibles[pos]);
            break;
        case 0:
            printf("Gracias por usar el sistema. Hasta pronto.\n");
            break;
        }
    } while (opcion != 0);

    return 0;
}

// Repite hasta que que cambie la opcion
int leerEntero(int minimo, int maximo, const char mensaje[]) {
    int valor, leidos, c;
    do {
        printf("%s", mensaje);
        leidos = scanf("%d", &valor);
        
        // Limpia el resto de la linea (tambien si se escribio texto)
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        if (leidos != 1 || valor < minimo || valor > maximo) {
            printf("Dato invalido. Debe ser un numero entre %d y %d.\n", minimo, maximo);
            leidos = 0;
        }
        if (c == EOF && leidos != 1)
            return minimo; 
    } while (leidos != 1);
    return valor;
}

// solo lee max 19 letras, sino lo vuelve a pedir
void leerTitulo(char titulo[]) {
    char buffer[100];
    int c;
    do {
        printf("Titulo (una palabra, max 19 letras): ");
        if (scanf("%99s", buffer) != 1)
            buffer[0] = '\0';
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        if (strlen(buffer) == 0 || strlen(buffer) >= LARGO_TITULO) {
            printf("Titulo invalido.\n");
            buffer[0] = '\0';
        }
        if (c == EOF && buffer[0] == '\0')
            strcpy(buffer, "SinTitulo");
    } while (buffer[0] == '\0');
    strcpy(titulo, buffer);
}

// busqueda de libro activo
int buscarCodigo(const int codigos[], const int estados[], int n, int codigo) {
    int i;
    for (i = 0; i < n; i++)
        if (estados[i] == ACTIVO && codigos[i] == codigo)
            return i;
    return -1;
}

// guarda el libro
void incluir(int codigos[], char titulos[][LARGO_TITULO], int disponibles[],
             int estados[], int *n) {
    int codigo;
    if (*n >= MAX_LIBROS) {
        printf("No hay espacio para mas libros.\n");
        return;
    }
    codigo = leerEntero(COD_MIN, COD_MAX, "Codigo (100-999): ");
    if (buscarCodigo(codigos, estados, *n, codigo) != -1) {
        printf("El codigo %d ya existe.\n", codigo);
        return;
    }
    codigos[*n] = codigo;
    leerTitulo(titulos[*n]);
    disponibles[*n] = leerEntero(EJ_MIN, EJ_MAX, "Ejemplares (1-20): ");
    estados[*n] = ACTIVO;
    (*n)++;
    printf("Libro incluido (%d de %d).\n", *n, MAX_LIBROS);
}

// se muestran los datos en columnas
void consultar(const int codigos[], const char titulos[][LARGO_TITULO],
               const int disponibles[], const int estados[], int n) {
    int i, activos = 0;
    printf("\n%-8s %-20s %s\n", "Codigo", "Titulo", "Disponibles");
    for (i = 0; i < n; i++)
        if (estados[i] == ACTIVO) {
            printf("%-8d %-20s %d\n", codigos[i], titulos[i], disponibles[i]);
            activos++;
        }
    printf("Libros activos: %d\n", activos);
}

// Resta un ejemplar si hay, devuelve 1 si pudo y 0 si no
int prestar(int *disponibles) {
    if (*disponibles > 0) {
        (*disponibles)--;
        return 1;
    }
    return 0;
}

// Marca el libro como dado de baja
void darDeBaja(int *estado) {
    *estado = BAJA;
}

void mostrarNoExiste(int codigo) {
    printf("No existe un libro activo con el codigo %d.\n", codigo);
}
