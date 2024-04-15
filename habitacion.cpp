#include "habitacion.h"
#include "cliente.h"
#include <string.h>
#define MAXSIZE 1024


Habitacion::Habitacion(int numero, int piso, int capacidad) : numero(numero), piso(piso), capacidad(capacidad) {
    estado = disponible;
    clienteActual = nullptr;

}

bool Habitacion::esta_disponible(){
    return (estado == disponible && clienteActual == nullptr);
}

void Habitacion::terminar_reserva(){
    clienteActual = nullptr;
    comenzar_mantenimiento();
}

void Habitacion::comenzar_mantenimiento(){
    estado = mantenimiento;
}

void Habitacion::terminar_mantenimiento(){
    estado = disponible;
}

void Habitacion::reservar(Cliente * clienteReserva){
    if (this->esta_disponible()){
        estado = ocupado;
        clienteActual = clienteReserva;
    }
}

int Habitacion::get_dni_cliente(){
    if (clienteActual == nullptr){
        return -1;
    }
    return clienteActual->get_dni();
}

bool Habitacion::get_nombre_cliente(std::string &nombre){
    if (clienteActual == nullptr){
        return false;
    }
    nombre =  clienteActual->get_nombre();
    return true;
}


int Habitacion::get_numero(){
    return numero;
}
int Habitacion::get_piso(){
    return piso;
}

int Habitacion::get_capacidad(){
    return capacidad;
}