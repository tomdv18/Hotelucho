// Copyright 2024 tomdv18
#include "logica_hotel.h"

#include <algorithm>
#include <iostream>
#include <string>
#define ERROR -1

Logica_Hotel::Logica_Hotel(int& ocupacion, int& capacidad, int& porcentaje_ocupacion,
                           std::vector<Habitacion>& habitaciones, std::vector<Cliente>& clientes):
        ocupacion(ocupacion),
        capacidad(capacidad),
        porcentajeOcupacion(porcentaje_ocupacion),
        habitaciones(habitaciones),
        clientes(clientes) {}

/*-- -- -- MANEJO DE HABITACIONES -- -- --*/
int Logica_Hotel::agregar_habitacion(const int numero, const int piso,
                                     const int capacidadHabitacion) {
    if (!existe_habitacion(numero, piso)) {
        Habitacion nuevaHab(numero, piso, capacidadHabitacion);
        habitaciones.emplace_back(nuevaHab);
        capacidad = capacidadHabitacion + capacidad;
        actualizar_ocupacion();
        return 0;
    }
    return ERROR;
}

int Logica_Hotel::eliminar_habitacion(const int numero, const int piso) {
    if (!existe_habitacion(numero, piso)) {
        return ERROR;
    }

    if (!habitacion_disponible(numero, piso)) {
        return ERROR;
    }
    for (auto hab = habitaciones.begin(); hab != habitaciones.end(); ++hab) {
        if (hab->get_numero() == numero && hab->get_piso() == piso) {
            capacidad = capacidad - hab->get_capacidad();
            habitaciones.erase(hab);
            actualizar_ocupacion();
            return 0;
        }
    }
    return ERROR;
}

bool Logica_Hotel::existe_habitacion(int numero, int piso) {
    return std::any_of(habitaciones.begin(), habitaciones.end(),
                       [numero, piso](const Habitacion& hab) {
                           return hab.get_numero() == numero && hab.get_piso() == piso;
                       });
}

bool Logica_Hotel::habitacion_en_mantenimiento(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        throw std::runtime_error("Habitacion no existe");
    }
    Habitacion* habitacion = get_habitacion(numero, piso);
    return habitacion->en_mantenimiento();
}


bool Logica_Hotel::habitacion_disponible(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        throw std::runtime_error("Habitacion no existe");
    }
    Habitacion* habitacion = get_habitacion(numero, piso);
    return habitacion->esta_disponible();
}

int Logica_Hotel::comenzar_mantenimiento(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        return ERROR;
    }
    Habitacion* hab = get_habitacion(numero, piso);
    hab->comenzar_mantenimiento();
    return 0;
}

int Logica_Hotel::terminar_mantenimiento(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        return ERROR;
    }
    Habitacion* hab = get_habitacion(numero, piso);
    hab->terminar_mantenimiento();
    return 0;
}

/*-- -- -- MANEJO DE RESERVAS -- -- --*/

int Logica_Hotel::crear_reserva(int numero, int piso, int dni_cliente, const std::string& nombre,
                                int telefonoCl, const std::string& direccion) {
    if (!existe_habitacion(numero, piso))
        return ERROR;
    if (!existe_cliente(dni_cliente)) {
        registrar_cliente(dni_cliente, nombre, telefonoCl, direccion);
    }
    if (habitacion_disponible(numero, piso)) {
        Habitacion* habitacion_reservada = get_habitacion(numero, piso);
        Cliente* cliente_reserva = get_cliente(dni_cliente);
        habitacion_reservada->reservar(cliente_reserva);
        actualizar_ocupacion();
        return 0;
    }
    return ERROR;
}

int Logica_Hotel::finalizar_reserva(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        return ERROR;
    }
    Habitacion* hab = get_habitacion(numero, piso);
    hab->terminar_reserva();
    actualizar_ocupacion();
    return 0;
}

/*-- -- -- MANEJO DE CLIENTES -- -- --*/

void Logica_Hotel::registrar_cliente(int dni, const std::string& nombre, int telefono,
                                     const std::string& direccion) {
    Cliente nuevo(dni, nombre, telefono, direccion);
    clientes.emplace_back(nuevo);
}

void Logica_Hotel::modificar_cliente(int dni, const std::string& telefono,
                                     const std::string& direccion) {
    for (Cliente& cli: clientes) {
        if (cli.get_dni() == dni) {
            if (telefono != "0") {
                cli.cambiar_telefono(std::stoi(telefono));
            }
            if (direccion != "0") {
                cli.cambiar_direccion(direccion);
            }
        }
    }
}

bool Logica_Hotel::existe_cliente(const int dni) {
    return std::any_of(clientes.begin(), clientes.end(),
                       [dni](const Cliente& c) { return c.get_dni() == dni; });
}

bool Logica_Hotel::eliminar_cliente(int dni) {
    if (std::any_of(habitaciones.begin(), habitaciones.end(),
                    [dni](const Habitacion& hab) { return hab.get_dni_cliente() == dni; })) {
        return false;
    }
    auto it = std::find_if(clientes.begin(), clientes.end(),
                           [dni](const Cliente& cli) { return cli.get_dni() == dni; });

    if (it != clientes.end()) {
        clientes.erase(it);
        return true;
    }
    return false;
}

/*-- -- -- METODOS PRIVADOS PARA REUTILIZAR CODIGO -- -- --*/

Habitacion* Logica_Hotel::get_habitacion(int numero, int piso) {
    auto it = std::find_if(habitaciones.begin(), habitaciones.end(),
                           [numero, piso](const Habitacion& hab) {
                               return hab.get_numero() == numero && hab.get_piso() == piso;
                           });

    return (it != habitaciones.end()) ? &(*it) : nullptr;
}

Cliente* Logica_Hotel::get_cliente(int dni) {
    auto it = std::find_if(clientes.begin(), clientes.end(),
                           [dni](const Cliente& cli) { return cli.get_dni() == dni; });

    return (it != clientes.end()) ? &(*it) : nullptr;
}
void Logica_Hotel::actualizar_ocupacion() {
    int ocupacion = 0;
    for (Habitacion& hab: habitaciones) {
        if (!hab.esta_disponible() && !hab.en_mantenimiento()) {
            ocupacion = ocupacion + hab.get_capacidad();
        }
    }
    this->ocupacion = ocupacion;
    if (capacidad != 0) {
        porcentajeOcupacion = ocupacion * 100 / capacidad;
    } else {
        porcentajeOcupacion = 0;
    }
}
