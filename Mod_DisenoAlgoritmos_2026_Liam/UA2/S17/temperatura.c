#include <stdio.h>  

int main(void)     
{
    double celsius, fahrenheit;  

    printf("Temperatura en grados Celsius: ");   
    scanf("%lf", &celsius);                      

    fahrenheit = celsius * 9.0 / 5.0 + 32;       

    printf("%.1f C equivalen a %.1f F\n", celsius, fahrenheit);   
    return 0;        
}