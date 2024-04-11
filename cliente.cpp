#include "cliente.h"

#include <string>



Cliente::Cliente(int dni, std::string  nombre,int telefono, std::string direccion)  : dni(dni), nombre(nombre), telefono(telefono), direccion(direccion){
}

void Cliente::cambiar_telefono(int telefonoNuevo){
    telefono = telefonoNuevo;
}

int Cliente::get_dni(){
    return dni;
}
/*
bool Cliente::cambiar_direccion(std::string  direccionNueva){
    direccion(direccionNueva);
}*/
