#include "cliente.h"

#include <string>



Cliente::Cliente(int dni, std::string  nombre,int telefono, std::string direccion)  : dni(dni), nombre(nombre), telefono(telefono), direccion(direccion){
}


void Cliente::cambiar_telefono(const int telefonoNuevo){
    telefono = telefonoNuevo;
}

void Cliente::cambiar_direccion(const std::string direc){
    direccion = direc;
}

 int Cliente::get_dni(){
    return dni;
 }

 int Cliente::get_telefono(){
    return telefono;
 }

 std::string Cliente::get_nombre(){
    return nombre;
 }

 std::string Cliente::get_direccion(){
    return direccion;
 }