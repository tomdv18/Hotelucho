// Copyright 2024 tomdv18
#include "hotel.h"

#include <algorithm>
#include <iostream>
#include <string>
#define ERROR -1

Hotel::Hotel(const std::string& nombreHotel):
        nombre(nombreHotel),
        ocupacion(0),
        capacidad(0),
        porcentajeOcupacion(0),
        lhotel(ocupacion, capacidad, porcentajeOcupacion, habitaciones, clientes) {}

/*-- -- -- METODOS MANEJADOS POR EL GESTOR DE LOGICA -- -- --*/
int Hotel::agregar_habitacion(const int numero, const int piso, const int capacidadHabitacion) {
    return lhotel.agregar_habitacion(numero, piso, capacidadHabitacion);
}

int Hotel::eliminar_habitacion(const int numero, const int piso) {
    return lhotel.eliminar_habitacion(numero, piso);
}

bool Hotel::existe_habitacion(int numero, int piso) {
    return lhotel.existe_habitacion(numero, piso);
}

bool Hotel::habitacion_en_mantenimiento(int numero, int piso) {
    return lhotel.habitacion_en_mantenimiento(numero, piso);
}

bool Hotel::habitacion_disponible(int numero, int piso) {
    return lhotel.habitacion_disponible(numero, piso);
}

int Hotel::comenzar_mantenimiento(int numero, int piso) {
    return lhotel.comenzar_mantenimiento(numero, piso);
}

int Hotel::terminar_mantenimiento(int numero, int piso) {
    return lhotel.terminar_mantenimiento(numero, piso);
}

int Hotel::crear_reserva(int numero, int piso, int dni_cliente, const std::string& nombre,
                         int telefonoCl, const std::string& direccion) {

    return lhotel.crear_reserva(numero, piso, dni_cliente, nombre, telefonoCl, direccion);
}

int Hotel::finalizar_reserva(int numero, int piso) {
    return lhotel.finalizar_reserva(numero, piso);
}

void Hotel::registrar_cliente(int dni, const std::string& nombre, int telefono,
                              const std::string& direccion) {
    lhotel.registrar_cliente(dni, nombre, telefono, direccion);
}

void Hotel::modificar_cliente(int dni, const std::string& telefono, const std::string& direccion) {
    lhotel.modificar_cliente(dni, telefono, direccion);
}

bool Hotel::existe_cliente(const int dni) { return lhotel.existe_cliente(dni); }

bool Hotel::eliminar_cliente(int dni) { return lhotel.eliminar_cliente(dni); }

/*Metodos de consulta para el Launcher*/

info_habitacion Hotel::informacion_habitacion(int numero, int piso) {
    info_habitacion info;
    for (Habitacion& hab: habitaciones) {
        if (hab.get_numero() == numero && hab.get_piso() == piso) {
            info.numero = hab.get_numero();
            info.piso = hab.get_piso();
            info.capacidad = hab.get_capacidad();
            if (hab.esta_disponible()) {
                info.estado = "Disponible";
            } else if (hab.en_mantenimiento()) {
                info.estado = "Mantenimiento";
            } else {
                info.estado = "Ocupada";
            }
            info.dni_cliente = hab.get_dni_cliente();
            if (info.dni_cliente != -1) {
                hab.get_nombre_cliente(info.nombre_cliente);
            } else {
                info.nombre_cliente = "N/A";
            }
        }
    }
    return info;
}

std::vector<std::string> Hotel::habitaciones_disponibles() {
    std::vector<std::string> vector;
    std::string str;
    std::string str_int1;
    std::string str_int2;
    std::string str_int3;
    for (Habitacion& hab: habitaciones) {
        if (hab.esta_disponible()) {
            str_int1 = std::to_string(hab.get_piso());
            str_int2 = std::to_string(hab.get_numero());
            str_int3 = std::to_string(hab.get_capacidad());
            str = str_int1 + "," + str_int2 + "," + str_int3;
            vector.emplace_back(str);
        }
    }
    std::sort(vector.begin(), vector.end(), [](const std::string& a, const std::string& b) {
        int piso_a = std::stoi(a.substr(0, a.find(',')));
        int piso_b = std::stoi(b.substr(0, b.find(',')));
        int numero_a = std::stoi(a.substr(a.find(',') + 1, a.rfind(',') - a.find(',') - 1));
        int numero_b = std::stoi(b.substr(b.find(',') + 1, b.rfind(',') - b.find(',') - 1));

        if (piso_a != piso_b) {
            return piso_a < piso_b;
        } else {
            return numero_a < numero_b;
        }
    });
    return vector;
}

std::vector<std::string> Hotel::habitaciones_status() {
    std::vector<std::string> vector;
    std::string str;
    std::string str_int1;
    std::string str_int2;
    std::string str_int3;
    for (Habitacion& hab: habitaciones) {
        str_int1 = std::to_string(hab.get_piso());
        str_int2 = std::to_string(hab.get_numero());
        str_int3 = std::to_string(hab.get_capacidad());
        str = str_int1 + "," + str_int2 + "," + str_int3 + ",";
        if (hab.esta_disponible()) {
            str = str + "Disponible";
        } else if (hab.en_mantenimiento()) {
            str = str + "Mantenimiento";
        } else {
            str = str + "Ocupada";
        }
        vector.emplace_back(str);
    }
    std::sort(vector.begin(), vector.end(), [](const std::string& a, const std::string& b) {
        int piso_a = std::stoi(a.substr(0, a.find(',')));
        int piso_b = std::stoi(b.substr(0, b.find(',')));
        int numero_a = std::stoi(a.substr(a.find(',') + 1, a.rfind(',') - a.find(',') - 1));
        int numero_b = std::stoi(b.substr(b.find(',') + 1, b.rfind(',') - b.find(',') - 1));

        if (piso_a != piso_b) {
            return piso_a < piso_b;
        } else {
            return numero_a < numero_b;
        }
    });

    return vector;
}

std::vector<std::string> Hotel::informacion_clientes_registrados() {
    std::vector<std::string> vector;
    std::string dni;
    std::string nombre;
    std::string telefono;
    std::string direccion;
    std::string str;
    for (Cliente& cli: clientes) {
        dni = std::to_string(cli.get_dni());
        nombre = cli.get_nombre();
        telefono = std::to_string(cli.get_telefono());
        direccion = cli.get_direccion();
        str = dni + "," + nombre + "," + telefono + "," + direccion;
        vector.emplace_back(str);
    }

    std::sort(vector.begin(), vector.end(), [](const std::string& a, const std::string& b) {
        int dni_a = std::stoi(a.substr(0, a.find(',')));
        int dni_b = std::stoi(b.substr(0, b.find(',')));

        if (dni_a != dni_b) {
            return dni_a < dni_b;
        } else {
            return false;
        }
    });

    return vector;
}


std::vector<int> Hotel::dni_clientes_registrados() {
    std::vector<int> vector(clientes.size());
    std::transform(clientes.begin(), clientes.end(), vector.begin(),
                   [](const Cliente& cli) { return cli.get_dni(); });
    return vector;
}

int Hotel::cantidad_clientes_registrados() { return clientes.size(); }

int Hotel::cantidad_habitaciones() { return habitaciones.size(); }


int Hotel::get_capacidad() { return capacidad; }
int Hotel::get_ocupacion() { return ocupacion; }
int Hotel::get_ocupacion_porcentual() { return porcentajeOcupacion; }
std::string Hotel::get_nombre() { return nombre; }
