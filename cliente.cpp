#include "cliente.h"

#include <string.h>
#define MAXSIZE 1024


Cliente::Cliente(int id, char nombre[MAXSIZE],int telefono, char direccion[MAXSIZE]){
}

bool Cliente::cambiar_telefono(int telefonoNuevo){
    telefono = telefonoNuevo;
}

bool Cliente::cambiar_direccion(char direccionNueva[MAXSIZE]){
    memcpy(direccion, &direccionNueva, MAXSIZE);
}
