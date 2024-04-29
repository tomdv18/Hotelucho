# Hotelucho


Sistema de gestion de hoteles con registro de clientes.

**Pantalla de inicio con sus diferentes opciones**
![img](/doc/pantalla_inicio.png?raw=true "img")

**Pantalla de gestion de las habitaciones**
![img](/doc/gestion_habitaciones.png?raw=true "img")

**Detalles particulares de cada habitacion**
![img](/doc/detalle_habitacion_particular.png?raw=true "img")

**Registro de clientes y su informacion personal**

![img](/doc/registro_clientes.png?raw=true "img")

##Testing

Incluye tests unitarios (+30 en total) para cada clase creada, utilizando GoogleTest https://github.com/google/googletest en conjunto con CMake

Para informacion sobre como testear ver la carpeta doc.

![img](/doc/test_pasando.png?raw=true "img")
Tests sobre la clase Hotel

##Compilacion
Simplemente es cuestion de utilizar el Makefile ejecutando el comando
make
El programa recibe hasta dos argumentos. El primero seteara el nombre del hotel. Mientras que, el segundo (El cual es opcional) corresponde al nombre del archivo de inicializacion.
Por ejemplo, en caso de querer inicializar el programa vacio habra que ejecutar:
```bash
make
./hotel <Nombre del hotel>
```
Si tenemos un archivo de inicializacion (Ver ejemplo en el archivo Input de este repositorio), entonces habra que ejecutar
```bash
make
./hotel <Nombre del hotel> <Nombre del archivo inicializador>
```
Para mayor informacion sobre el archivo inicializador ver la carpeta doc