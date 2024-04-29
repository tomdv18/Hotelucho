#include "hotel.h"
#include "habitacion.h"
#include "cliente.h"
#include <iostream>
#include <string>
#include <algorithm>
#define ERROR -1


Hotel::Hotel(std::string nombreHotel) : nombre(nombreHotel), ocupacion(0), capacidad(0), porcentajeOcupacion(0) {
}

int Hotel::agregar_habitacion(const int numero, const int piso, const int capacidadHabitacion) {
    if (!existe_habitacion(numero, piso)) {
        Habitacion nuevaHab(numero, piso, capacidadHabitacion);
        habitaciones.emplace_back(nuevaHab);
        capacidad = capacidadHabitacion + capacidad;
        actualizar_ocupacion();
        return 0;
    }
    return ERROR;
}

int Hotel::eliminar_habitacion(const int numero, const int piso) {
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
bool Hotel::existe_cliente(const int dni) {
    for (Cliente & c : clientes) {
        if (c.get_dni() == dni) return true;
    }
    return false;
}

bool Hotel::existe_habitacion(int numero, int piso) {
    for (Habitacion & hab : habitaciones) {
        if (hab.get_numero() == numero && hab.get_piso() == piso) return true;
    }
    return false;
}

void Hotel::actualizar_ocupacion() {
    int ocupacion = 0;
    for (Habitacion & hab : habitaciones) {
        if (!hab.esta_disponible() && !hab.en_mantenimiento()) {
            ocupacion = ocupacion + hab.get_capacidad();
        }
    }
    this->ocupacion = ocupacion;
    porcentajeOcupacion = ocupacion *100 / capacidad;
}


int Hotel::crear_reserva(int numero, int piso, int dni_cliente, std::string nombre,
                            int telefonoCl, std::string direccion) {
    if (!existe_habitacion(numero, piso)) return ERROR;
    if (!existe_cliente(dni_cliente)) {
        registrar_cliente(dni_cliente, nombre, telefonoCl, direccion);
    }
    if (habitacion_disponible(numero, piso)) {
        Habitacion * habitacion_reservada = get_habitacion(numero, piso);
        Cliente * cliente_reserva = get_cliente(dni_cliente);
        habitacion_reservada->reservar(cliente_reserva);
        actualizar_ocupacion();
        return 0;
    }
    return ERROR;
}

int Hotel::finalizar_reserva(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        return ERROR;
    }
    Habitacion* hab = get_habitacion(numero, piso);
    hab->terminar_reserva();
    actualizar_ocupacion();
    return 0;
}

int Hotel::comenzar_mantenimiento(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        return ERROR;
    }
    Habitacion* hab = get_habitacion(numero, piso);
    hab->comenzar_mantenimiento();
    return 0;
}

int Hotel::terminar_mantenimiento(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        return ERROR;
    }
    Habitacion* hab = get_habitacion(numero, piso);
    hab->terminar_mantenimiento();
    return 0;

}

bool Hotel::habitacion_disponible(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        throw std::runtime_error("Habitacion no existe");
    }
    Habitacion * habitacion = get_habitacion(numero, piso);
    return habitacion->esta_disponible();
}

bool Hotel::habitacion_en_mantenimiento(int numero, int piso) {
    if (!existe_habitacion(numero, piso)) {
        throw std::runtime_error("Habitacion no existe");
    }
    Habitacion * habitacion = get_habitacion(numero, piso);
    return habitacion->en_mantenimiento();
}

std::vector<int> Hotel::habitaciones_por_piso(int piso) {
    std::vector<int> habitaciones_piso;
    for (Habitacion & hab : habitaciones) {
        if (hab.get_piso() == piso) habitaciones_piso.push_back(hab.get_numero());
    }
    return habitaciones_piso;
}

std::vector<std::string> Hotel::habitaciones_disponibles() {
    std::vector<std::string> vector;
    std::string str;
    std::string str_int1;
    std::string str_int2;
    std::string str_int3;
    for (Habitacion & hab : habitaciones) {
        if (hab.esta_disponible()) {
            str_int1 = std::to_string(hab.get_piso());
            str_int2 = std::to_string(hab.get_numero());
            str_int3 = std::to_string(hab.get_capacidad());
            str = str_int1 + "," + str_int2 + ","+ str_int3;
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
    for (Habitacion & hab : habitaciones) {
        str_int1 = std::to_string(hab.get_piso());
        str_int2 = std::to_string(hab.get_numero());
        str_int3 = std::to_string(hab.get_capacidad());
        str = str_int1 + "," + str_int2 + ","+ str_int3 + ",";
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

info_habitacion Hotel::informacion_habitacion(int numero, int piso) {
    info_habitacion info;
    for (Habitacion & hab : habitaciones) {
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

std::vector<int> Hotel::dni_clientes_registrados() {
    std::vector<int> vector;
    for (Cliente & cli : clientes) {
        vector.emplace_back(cli.get_dni());
    }
    return vector;
}
void Hotel::modificar_cliente(int dni, std::string telefono, std::string direccion) {
    for (Cliente & cli : clientes) {
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

bool Hotel::eliminar_cliente(int dni) {
    for (Habitacion & hab : habitaciones) {
        if (hab.get_dni_cliente() == dni) {
            return false;
        }
    }
    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->get_dni() == dni) {
            clientes.erase(it);
            break;
        }
    }
    return true;
}

std::vector<std::string> Hotel::informacion_clientes_registrados() {
    std::vector<std::string> vector;
    std::string dni;
    std::string nombre;
    std::string telefono;
    std::string direccion;
    std::string str;
    for (Cliente & cli : clientes) {
        dni = std::to_string(cli.get_dni());
        nombre = cli.get_nombre();
        telefono = std::to_string(cli.get_telefono());
        direccion = cli.get_direccion();
        str = dni + ","+ nombre + "," +telefono + "," + direccion;
        vector.emplace_back(str);
    }

    std::sort(vector.begin(), vector.end(), [](const std::string& a, const std::string& b) {
        int dni_a = std::stoi(a.substr(0, a.find(',')));
        int dni_b = std::stoi(b.substr(0, b.find(',')));
        
        if (dni_a != dni_b) {
            return dni_a < dni_b;
        }
        else {
        return false;
        }
    });

    return vector;
}
void Hotel::registrar_cliente(int dni, std::string nombre, int telefono, std::string direccion) {
        Cliente nuevo(dni, nombre, telefono, direccion);
        clientes.emplace_back(nuevo);

}

Habitacion* Hotel::get_habitacion(int numero, int piso) {
    Habitacion * habit(nullptr);
    for (Habitacion & hab : habitaciones) {
        if (hab.get_numero() == numero && hab.get_piso() == piso) habit = &hab;
    }
    return habit;
}

Cliente* Hotel::get_cliente(int dni) {
    Cliente * cliente(nullptr);
    for (Cliente & cli : clientes) {
        if (cli.get_dni() == dni) cliente = &cli;
    }
    return cliente;
}

int Hotel::cantidad_habitaciones() {
    return habitaciones.size();
}

int Hotel::cantidad_clientes_registrados() {
    return clientes.size();
}

int Hotel::get_capacidad() {
    return capacidad;
}
int Hotel::get_ocupacion() {
    return ocupacion;
}
int Hotel::get_ocupacion_porcentual() {
    return porcentajeOcupacion;
}

std::string Hotel::get_nombre() {
    return nombre;
}