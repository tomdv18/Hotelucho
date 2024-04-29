#include <iostream>
#include <fstream>
#include <sstream>
#include "lector_archivo.h"

Lector_Archivo::Lector_Archivo(const std::string& nombreArchivo, Hotel &hotel) : nombreArchivo(nombreArchivo), hotel(hotel) {
}

void Lector_Archivo::inicializar_desde_archivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string tipo;
        ss >> tipo;

        if (tipo == "CLIENTE") {
            std::string nombre, direccion, dni, telefono;
            std::getline(ss, dni, ',');
            std::getline(ss, nombre, ',');
            std::getline(ss, telefono, ',');
            std::getline(ss, direccion);
            hotel.registrar_cliente(stoi(dni), nombre, stoi(telefono), direccion);
        } else if (tipo == "HABITACION") {
            std::string estado, capacidad, piso, numero;
            std::getline(ss, numero, ',');
            std::getline(ss, piso, ',');
            std::getline(ss, capacidad, ',');
            std::getline(ss, estado);

            hotel.agregar_habitacion(stoi(numero), stoi(piso), stoi(capacidad));
            if (estado == "2"){
                hotel.comenzar_mantenimiento(stoi(numero), stoi(piso));
            }
        } else if (tipo == "RESERVA") {
            std::string numero, piso, dni, nombre, telefono,direccion;
            std::getline(ss, numero, ',');
            std::getline(ss, piso, ',');
            std::getline(ss, dni, ',');
            std::getline(ss, nombre, ',');
            std::getline(ss, telefono, ',');
            std::getline(ss, direccion);
            hotel.crear_reserva(stoi(numero), stoi(piso), stoi(dni), nombre, stoi(telefono), direccion);
        }
    }

    archivo.close();
}
