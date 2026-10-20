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
| - **Nombre del estudiante**: cadena de texto (`char[]`).<br>- **Tres calificaciones**: números flotantes (`float`) en un arreglo de tamaño 3.[cite: 3] | 1. Solicitar el nombre completo del estudiante.<br>2. Mediante un bucle `for` y validaciones `do-while`, solicitar y almacenar 3 calificaciones asegurando que se encuentren en el rango de 0 a 100.<br>3. Recorrer el arreglo para sumar las notas, calcular el promedio (`suma / 3`) y determinar la calificación más alta.<br>4. Evaluar la condición final mediante condicionales:<br>&nbsp;&nbsp;- Promedio $\ge$ 70: "APROBADO"<br>&nbsp;&nbsp;- Promedio entre 60 y 69.9: "EN RIESGO"<br>&nbsp;&nbsp;- Promedio $<$ 60: "NO APROBADO"<br>5. Asignar el texto correspondiente a la variable condición mediante `strcpy`.[cite: 3] | Reporte de resultados que incluye:<br>- Nombre del estudiante.<br>- Las 3 calificaciones individuales.<br>- Promedio final (con 2 decimales).<br>- Calificación más alta.<br>- Condición del estudiante (APROBADO / EN RIESGO / NO APROBADO).[cite: 3] | - Las calificaciones deben estar estrictamente entre 0 y 100; cualquier otro valor es rechazado.<br>- Se evalúa una cantidad fija de 3 calificaciones por estudiante.[cite: 3] |

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
