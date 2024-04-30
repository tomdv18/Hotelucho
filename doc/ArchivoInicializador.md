# Archivo Inicializador

En el siguiente documento describire como se debe componer el archivo incializador. 
Para esto tenemos 3 "Clases"

Recordar que entre cada entidad a crear hay que poner un salto de linea y que los valores van separados por coma
Notar que entre la palabra clave de la entidad y sus datos hay un espacio

## Cliente
Para los clientes hay que respetar el siguiente formato: "CLIENTE" <DNI>,<NOMBRE_CLIENTE>,<TELEFONO_CLIENTE>,<DIRECCION_CLIENTE>

Por ejemplo:
CLIENTE 10251667,Juan Ejemplo,11663344,Calle ejemplar 124

## Habitacion
Para las habitaciones se sigue el siguiente formato: "HABITACION" <NUMERO_HABITACION>,<PISO_HABITACION>,<CAPACIDAD_HABITACION>,<ESTADO>

Donde todos los valores son numeros enteros y el valor estado vale 0 si la habitacion esta disponible, 1 si esta ocupada y 2 si esta en mantenimiento

Por ejemplo:
HABITACION 15,1,3,0

**NOTA:**
Si una habitacion tiene de estado al numero 1, es decir, esta ocupada, se espera que haya una reserva que justifique esa ocupacion

## Reserva
El formato de las reservas es el siguiente: RESERVA <NUMERO_HABITACION>,<PISO_HABITACION>,<DNI_CLIENTE>,<NOMBRE_CLIENTE>,<TELEFONO_CLIENTE>,<DIRECCION_CLIENTE>

Por ejemplo:
RESERVA 1,2,10251667,Juan Ejemplo,11663344,Calle ejemplar 124