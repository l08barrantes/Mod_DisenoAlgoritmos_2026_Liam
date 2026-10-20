# AC2 · Mi primera aplicación en C

**Estudiante:** (nombre completo)  
**Fecha:** 20/10/2026  
**Módulo:** CSTI12010 Diseño de algoritmos · UA2

## Problema 1 · Nómina (AC2_P1_Nomina.c)

| Datos de entrada | Proceso | Datos de salida | Limitaciones |
|---|---|---|---|
- **Nombre del empleado**: cadena de texto (`char[]`).<br>- **Salario bruto**: número flotante (`float`).[cite: 2] | 1. Solicitar el nombre del empleado y validar que no esté vacío utilizando `fgets` y `strlen`.<br>2. Solicitar el salario bruto y validar con un ciclo `do-while` que sea un monto mayor a 0.<br>3. Calcular el descuento de CAJA (9.5% sobre el bruto).<br>4. Calcular el descuento de IESS (2.5% sobre el bruto).<br>5. Verificar si el salario bruto supera los 800; de ser así, calcular el impuesto sobre la renta (10% sobre el excedente).<br>6. Calcular el salario neto sustrayendo la suma de todos los descuentos al salario bruto.[cite: 2] | Comprobante de pago detallado que contiene:<br>- Nombre del empleado.<br>- Salario bruto.<br>- Descuento CAJA (9.5%).<br>- Descuento IESS (2.5%).<br>- Impuesto sobre la renta.<br>- Salario neto con 2 decimales y montos alineados.[cite: 2] | - No se aceptan salarios brutos menores o iguales a 0.<br>- El nombre del empleado no puede ser una cadena vacía.<br>- El cálculo del impuesto de renta únicamente aplica cuando el salario bruto supera los 800.[cite: 2] |

**Ejecución con los datos del ejemplo:**

![Ejecución](captura_p.png)

## Problema 2 · Calificaciones (AC2_P2_Calificaciones.c)

| Datos de entrada | Proceso | Datos de salida | Limitaciones |
|---|---|---|---|
|  |  |  |  |

**Ejecución con los datos del ejemplo:**

![Ejecución](captura_p.png)

## Problema 3 · Compras (AC2_P3_Compras.c)

| Datos de entrada | Proceso | Datos de salida | Limitaciones |
|---|---|---|---|
|  |  |  |  |

**Ejecución con los datos del ejemplo:**

![Ejecución](captura_p.png)

## Conclusión

(Qué aprendí y qué fue lo más difícil de pasar de PSeInt a C.)
