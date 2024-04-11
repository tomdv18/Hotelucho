#include "hotel.h"
#include "habitacion.h"
#include "cliente.h"
#include <string>
#include <iostream>
#define ERROR -1


Hotel::Hotel(std::string nombreHotel) : nombre(nombreHotel), ocupacion(0),capacidad(0),porcentajeOcupacion(0) {
}

int Hotel::agregar_habitacion(const int numero, const int piso, const int capacidadHabitacion){

    if(!existe_habitacion(numero,piso)){
        Habitacion nuevaHab(numero,piso,capacidadHabitacion);
        habitaciones.emplace_back(nuevaHab);
        capacidad = capacidadHabitacion + capacidad;
        return 0;
    }
    return ERROR;
}

int Hotel::eliminar_habitacion(const int numero, const int piso){

    if(!existe_habitacion(numero,piso)){
        return ERROR;
    }

    if (!habitacion_disponible(numero,piso)){
        return ERROR;
    }
    for (auto hab = habitaciones.begin(); hab != habitaciones.end(); ++hab) {
        if (hab->get_numero() == numero && hab->get_piso() == piso) {
            habitaciones.erase(hab);
            return 0;
        }
    }
    return ERROR;
}

bool Hotel::existe_cliente(const int dni){
    
    for (Cliente & c : clientes){
        if(c.get_dni() == dni) return true;
    }
    return false;
}

bool Hotel::existe_habitacion(int numero, int piso){
    for (Habitacion & hab : habitaciones){
        if(hab.get_numero() == numero && hab.get_piso() == piso) return true;
    }
    return false;
}



int Hotel::crear_reserva(int numero, int piso, int dni_cliente, std::string nombre, int telefonoCl, std::string direccion){
    if(!existe_habitacion(numero, piso)) return ERROR;
    if(!existe_cliente(dni_cliente)){

        Cliente nuevo(dni_cliente,nombre,telefonoCl,direccion);
        clientes.emplace_back(nuevo);
    }
    if(habitacion_disponible(numero,piso)){
        Habitacion * habitacion_reservada = get_habitacion(numero,piso);
        Cliente * cliente_reserva = get_cliente(dni_cliente);
        habitacion_reservada->reservar(cliente_reserva);
        ocupacion = ocupacion + habitacion_reservada->get_capacidad();
        porcentajeOcupacion = ocupacion *100 / capacidad;
    return 0;
    }
    return ERROR;
}

int Hotel::finalizar_reserva(int numero, int piso){
    if (!existe_habitacion(numero,piso)){
        return ERROR;
    }
    Habitacion* hab = get_habitacion(numero, piso);
    hab->terminar_reserva();
    return 0;
}

int Hotel::comenzar_mantenimiento(int numero, int piso){
    if (!existe_habitacion(numero,piso)){
        return ERROR;
    }
    Habitacion* hab = get_habitacion( numero, piso);
    hab->comenzar_mantenimiento();
    return 0;

}

int Hotel::terminar_mantenimiento(int numero, int piso){
    if (!existe_habitacion(numero,piso)){
        return ERROR;
    }
    Habitacion* hab = get_habitacion( numero, piso);
    hab->terminar_mantenimiento();
    return 0;

}

bool Hotel::habitacion_disponible(int numero, int piso){
    if (!existe_habitacion(numero,piso)){
        throw std::runtime_error("Habitacion no existe");
    }
    Habitacion * habitacion = get_habitacion(numero,piso);
    return habitacion->esta_disponible();
}



Habitacion* Hotel::get_habitacion(int numero, int piso){
    Habitacion * habit(nullptr);
    for (Habitacion & hab : habitaciones){
        if(hab.get_numero() == numero && hab.get_piso() == piso) habit = &hab;
    }
    return habit;
}

Cliente* Hotel::get_cliente(int dni){
    Cliente * cliente(nullptr);
    for (Cliente & cli : clientes){
        if(cli.get_dni() == dni) cliente = &cli;
    }
    return cliente;
}

int Hotel::get_capacidad(){
    return capacidad;
}
int Hotel::get_ocupacion(){
    return ocupacion;
}
int Hotel::get_ocupacion_porcentual(){
    return porcentajeOcupacion;
}