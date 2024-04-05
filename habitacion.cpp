#include "habitacion.h"
#include "cliente.h"
#include <string.h>
#define MAXSIZE 1024


Habitacion::Habitacion(int numero, int piso, int capacidad)  {
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
