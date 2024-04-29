# Hotelucho


Hotelucho es una aplicación de gestión de hotel desarrollada en c++ que permite administrar clientes, habitaciones y reservas. Proporciona una interfaz fácil de usar para gestionar todas las operaciones necesarias para mantener un hotel funcionando sin problemas.


**Pantalla de inicio con sus diferentes opciones**

En la pantalla principal, se puede acceder a todas las funciones principales de la aplicación, como gestionar habitaciones, registrar clientes y realizar reservas.

![img](/doc/pantalla_inicio.png?raw=true "img")

**Pantalla de gestion de las habitaciones**

Desde la pantalla de gestión de habitaciones, se ven y administran todas las habitaciones disponibles en el hotel. Aqui se puede agregar nuevas habitaciones, eliminar habitaciones existentes y ver detalles sobre cada habitación.

![img](/doc/gestion_habitaciones.png?raw=true "img")

**Detalles particulares de cada habitación**

Sobre cada habitación se puede ver los detalles completos, incluido su número, capacidad, estado e información sobre el cliente asociado si está ocupada.

![img](/doc/detalle_habitacion_particular.png?raw=true "img")

**Registro de clientes y su información personal**

Tambien se almacena la información de cada cliente que haya efectuado alguna reserva en algún momento.

![img](/doc/registro_clientes.png?raw=true "img")

## Testing

Incluye tests unitarios (+30 en total) para cada clase creada, utilizando GoogleTest https://github.com/google/googletest en conjunto con CMake

Para información sobre como testear ver la carpeta doc.

![img](/doc/tests_pasando.png?raw=true "img")
Tests sobre la clase Hotel

## Compilacion
Simplemente es cuestion de utilizar el Makefile ejecutando el comando
make
El programa recibe hasta dos argumentos. El primero establecerá el nombre del hotel. Mientras que, el segundo (opcional) corresponde al nombre del archivo de inicialización.

Por ejemplo, en caso de querer inicializar el programa habra que ejecutar:
```bash
make
./hotel <Nombre del hotel>
```
Si tenemos un archivo de inicialización y queremos utilizarlo (Ver ejemplo en el archivo Input de este repositorio), entonces habra que ejecutar
```bash
make
./hotel <Nombre del hotel> <Nombre del archivo inicializador>
```
Para mayor información sobre el archivo inicializador ver la carpeta doc