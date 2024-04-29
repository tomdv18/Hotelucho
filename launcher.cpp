#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <vector>
#include "launcher.h"
#include "hotel.h"
#include "habitacion.h"
#include "cliente.h"
#include <iomanip>

#define ERROR -1

// Definir códigos de color ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"


#define ANCHO_DNI 12
#define ANCHO_NOMBRE 20
#define ANCHO_TELEFONO 15
#define ANCHO_DIRECCION 25
#define ANCHO_PISO 12
#define ANCHO_NUMERO 12
#define ANCHO_CAPACIDAD 15
#define ANCHO_ESTADO 25

Launcher::Launcher(std::string nombreHotel) :
    nombre(nombreHotel), hotel(nombre) {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << std::endl;
    std::cout << "~~~~~~~~~~~~ Bienvenido al sistema de gestion de hoteles Hotelucho ~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;

    std::cout << std::endl;
    std::cout << "+ Inicializando Hotel:\t" << nombreHotel <<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("clear");
}

void Launcher::header() {
    std::cout << BOLD << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << BOLD <<"  Hotel: " << nombre << std::endl;
    std::cout << BOLD << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout <<std::endl;
    std::cout <<std::endl;
}

void Launcher::footer() {
    std::cout << BOLD << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << "Capacidad actual: " << hotel.get_capacidad() << std::endl;
    std::cout << "Ocupacion actual: " << hotel.get_ocupacion_porcentual()
        << "% (" <<hotel.get_ocupacion() << " personas)" <<std::endl;
    std::cout << BOLD << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET <<std::endl;
}

void Launcher::display() {
    header();
    std::cout << BOLD << BLUE <<"Presiona 1 " <<RESET<< "para ver las habitaciones disponibles \n" <<std::endl; //READY
    std::cout << BOLD << BLUE <<"Presiona 2 " <<RESET<< "para ver todas las habitaciones registradas\n" <<std::endl; 
    std::cout << BOLD << BLUE <<"Presiona 3 " <<RESET<< "para ver los clientes registrados\n" <<std::endl;        //READY
    std::cout << BOLD << BLUE <<"Presiona q " <<RESET<< "para salir" <<std::endl;        //READY
    footer();
    char input;
    std::cin >> input;
    std::cin.ignore();
   
    if (input == '1') {
        pantalla_habitaciones_disponibles();
        system("clear");
        display();
    } else if (input == '2') {
        pantalla_habitaciones();
        system("clear");
        display();
    } else if (input == '3') {
        pantalla_clientes_registrados();
        system("clear");
        display();
    } else if (tolower(input) == 'q'){
        std::cout << "Saliendo..." << std::endl;
        return;
    } 
    else {
        std::cout << "Comando invalido" << std::endl;
    }

}

void Launcher::pantalla_habitaciones_disponibles() {
    system("clear");
    header();
    std::cout << "Habitaciones disponibles para reservas \n"<< RESET <<std::endl;
    std::cout <<std::endl;
    std::vector<std::string> habitaciones = hotel.habitaciones_disponibles();
    if (habitaciones.size() == 0) {
        std::cout << "No hay habitaciones disponibles" <<std::endl;
    } else {
        std::cout << std::left << std::setw(ANCHO_PISO) << "\tPiso"
        << std::setw(ANCHO_NUMERO) << "Numero"
        << std::setw(ANCHO_CAPACIDAD) << "Capacidad" << std::endl;
        std::string piso, numero, estado, capacidad;
        for (std::string hab : habitaciones) {
            std::stringstream ss(hab);
            getline(ss, piso, ',');
            getline(ss, numero, ',');
            getline(ss, capacidad);
            std::cout << BOLD << std::left << std::setw(ANCHO_PISO) << "\t" + piso
            << std::setw(ANCHO_NUMERO) << numero << std::setw(ANCHO_CAPACIDAD)
            << capacidad + " personas" << RESET<< std::endl;
        }
    }
    std::cout <<std::endl;
    std::cout <<std::endl;
    char input;
    std::cout << BOLD << BLUE <<"Reservar - 1\tVolver - q" << RESET << std::endl;
    footer();
    std::cin >> input;
    std::cin.ignore();
    if (input == '1') {
        pantalla_reserva();
        return;
    } else if (tolower(input) == 'q') {
        return;
    } else {
        std::cout << "Comando invalido" << std::endl;
    }
}


void Launcher::agregar_habitacion(){

    int numero;
    int piso;
    solicitar_datos_habitacion(piso, numero);
    std::cout << "Ingrese la capacidad de la habitacion: " << std::endl;
    std::string capacidad;
    std::getline(std::cin, capacidad);
    while (!validador.dato_habitacion_valido(capacidad)) {
            std::cout << "Capacidad invalida" << std::endl;
            std::getline(std::cin, capacidad);
    }
    if (!hotel.existe_habitacion(numero, piso)) {
        hotel.agregar_habitacion(numero, piso, stoi(capacidad));
    } else {
        std::cout << "ERROR: Ya existe una habitacion registrada en ese piso y numero" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    system("clear");
    pantalla_habitaciones();
}

void Launcher::eliminar_habitacion(){
    int numero;
    int piso;
    solicitar_datos_habitacion(piso, numero);
    if (!hotel.existe_habitacion(numero, piso)) {
        std::cout << BOLD << "ERROR: No existe una habitacion registrada en ese piso y numero" << RESET << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    } else if (!hotel.habitacion_disponible(numero, piso)) {
        std::cout << BOLD << "ERROR: La habitacion a eliminar esta ocupada" << RESET << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    } else {
        if (hotel.eliminar_habitacion(numero, piso) != 0) {
            std::cout << BOLD << "ERROR: No se pudo eliminar la habitacion" << RESET << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    system("clear");
    pantalla_habitaciones();
}

void Launcher::pantalla_habitacion(int numero, int piso){
    info_habitacion info = hotel.informacion_habitacion(numero, piso);
    header();
    std::cout << "Detalles de la habitacion\n" <<std::endl;
    std::cout <<std::endl;
    std::cout << std::left << "\tPiso:\t\t" << info.piso << std::endl;
    std::cout << std::left << "\tNumero:\t\t" << info.numero << std::endl;
    std::cout << std::left << "\tCapacidad:\t" << info.capacidad << " personas" << std::endl;
    std::cout << std::left << "\tEstado:\t\t";
    if (info.estado =="Disponible") {
        std::cout << std::left  << GREEN << info.estado << RESET<< std::endl;
    }
    if (info.estado =="Mantenimiento") {
        std::cout << std::left  << YELLOW  << info.estado << RESET<< std::endl;
    }
    if (info.estado =="Ocupada") {
        std::cout << std::left  << RED << info.estado << RESET<< std::endl;
    }
    if (info.dni_cliente != -1) {
        std::cout << std::left << "\tOcupante actual: " << info.nombre_cliente << " (DNI: " << info.dni_cliente << ")" << std::endl;
    }
    std::cout <<std::endl;
    std::cout <<std::endl;
    char input;

    std::cout << BOLD << BLUE <<"Volver - q" << RESET << std::endl;
    footer();
    std::cin >> input;
    std::cin.ignore();
    if (tolower(input) == 'q') {
        pantalla_habitaciones();
        return;
    } else {
        std::cout << "Comando invalido" << std::endl;
    }

}
void Launcher::mantenimientos() {
    int numero;
    int piso;
    solicitar_datos_habitacion(piso, numero);
    if (!hotel.existe_habitacion(numero, piso)) {
        std::cout << "ERROR: No existe una habitacion registrada en ese piso y numero" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
        pantalla_habitaciones();
    } else {
        std::cout << BOLD;
        if (hotel.habitacion_disponible(numero, piso)) {
            std::cout  << "La habitacion " << numero << " del piso " << piso
                      << " comenzara su mantenimiento" << std::endl;
            hotel.comenzar_mantenimiento(numero, piso);
        } else if (hotel.habitacion_en_mantenimiento(numero, piso)) {
            std::cout << "La habitacion " << numero << " del piso " << piso
                      << " finalizara su mantenimiento" << std::endl;
            hotel.terminar_mantenimiento(numero, piso);
        } else {
            std::cout << "ERROR: La habitacion a modificar esta ocupada" << std::endl;
        }
        std::cout << RESET;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
        pantalla_habitaciones();
    }
}

void Launcher::solicitar_datos_habitacion(int &piso, int & numero){
     std::cout << "Ingrese el piso de la habitacion: " << std::endl;
    std::string numero_piso;

    std::getline(std::cin, numero_piso);
    while (!validador.dato_habitacion_valido(numero_piso)) {
            std::cout << "Piso invalido" << std::endl;
            std::getline(std::cin, numero_piso);
    }
    std::cout << "Ingrese el numero de la habitacion: " << std::endl;
    std::string num;
    std::getline(std::cin, num);
    while (!validador.dato_habitacion_valido(num)) {
            std::cout << "Numero invalido" << std::endl;
            std::getline(std::cin, num);
    }
    piso = stoi(numero_piso);
    numero = stoi(num);
}

void Launcher::detalles_habitacion() {
    int numero;
    int piso;
    solicitar_datos_habitacion(piso, numero);
    if (!hotel.existe_habitacion(numero, piso)) {
        std::cout << "ERROR: No existe una habitacion registrada en ese piso y numero" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
        pantalla_habitaciones();
    } else {
        system("clear");
        pantalla_habitacion(numero, piso);
    }
}

void Launcher::pantalla_reserva() {
    int numero;
    int piso;
    solicitar_datos_habitacion(piso, numero);

    if (!hotel.existe_habitacion(numero, piso)) {
        std::cout << "ERROR: No existe una habitacion registrada en ese piso y numero" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        pantalla_habitaciones();
    } else if (!hotel.habitacion_disponible(numero, piso)) {
        std::cout << "ERROR: La habitacion seleccionada no esta disponible" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
        pantalla_habitaciones();
    } else {
        system("clear");
        std::cout << "La habitacion esta disponible!" << std::endl;
        std::cout << BOLD << "Habitacion seleccionada con numero " << numero << " del piso " << piso << std::endl;
        std::cout << RESET << "Ingrese los datos del cliente" << std::endl;
        std::string dni, nombre, telefono, direccion;
        std::cout <<  "Ingrese DNI: "<< std::endl;
        std::cin >> dni;
        std::cin.ignore();
        std::vector<int> dnis; // NO se usa, queda vestigial para reutilizar la funcion
        while (!validador.dni_valido(dni, dnis)) {
            std::cout << "DNI invalido" << std::endl;
            std::cin >> dni;
            std::cin.ignore();
        }
        std::cout <<  "Ingrese nombre: "<< std::endl;
        std::getline(std::cin, nombre);
        while (!validador.nombre_valido(nombre)) {
            std::cout << "Nombre invalido" << std::endl;
            std::getline(std::cin, nombre);
        }
        std::cout <<  "Ingrese Telefono: "<< std::endl;
        std::cin >> telefono;
        std::cin.ignore();
        while (!validador.telefono_valido(telefono)) {
            std::cout << "Telefono invalido" << std::endl;
            std::cin >> telefono;
            std::cin.ignore();
        }
        std::cout <<  "Ingrese Direccion: "<< std::endl;
        std::getline(std::cin, direccion);
        while (!validador.direccion_valida(direccion)) {
            std::cout << "Direccion invalida" << std::endl;
            std::getline(std::cin, direccion);
        }

        if( hotel.crear_reserva(numero, piso, stoi(dni), nombre, stoi(telefono), direccion) != 0) {
            std::cout << "ERROR: No se pudo realizar la reserva" << std::endl;
        } else { std::cout << "Reserva realizada con exito" << std::endl; 
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void Launcher::pantalla_habitaciones() {
    system("clear");
    header();
    std::cout << "Habitaciones\n"<< RESET <<std::endl;
    std::cout <<std::endl;
    std::vector<std::string> habitaciones = hotel.habitaciones_status();
    if (habitaciones.size() == 0) {
        std::cout << "No hay habitaciones disponibles" <<std::endl;
    } else {
        std::cout << std::left << std::setw(ANCHO_PISO) << "\tPiso"
        << std::setw(ANCHO_NUMERO) << "Numero"
        << std::setw(ANCHO_CAPACIDAD) << "Capacidad"
        << std::setw(ANCHO_ESTADO) << "Estado" << std::endl;
        std::string piso, numero, estado, capacidad;
        for (std::string hab : habitaciones) {
            std::stringstream ss(hab);
            getline(ss, piso, ',');
            getline(ss, numero, ',');
            getline(ss, capacidad, ',');
            getline(ss, estado);
            std::cout <<BOLD << std::left << std::setw(ANCHO_PISO) <<  "\t" + piso
            << std::setw(ANCHO_NUMERO) << numero << std::setw(ANCHO_CAPACIDAD) << capacidad + " personas";
            if (estado =="Disponible") {
                std::cout << GREEN << std::setw(ANCHO_ESTADO) << estado << RESET<< std::endl;
            }
            if (estado =="Mantenimiento") {
                std::cout << YELLOW << std::setw(ANCHO_ESTADO) << estado << RESET<< std::endl;
            }
            if (estado =="Ocupada") {
                std::cout << RED << std::setw(ANCHO_ESTADO) << estado << RESET<< std::endl;
            }
        }
    }
    std::cout <<std::endl;
    std::cout <<std::endl;
    char input;
    std::cout << BOLD << BLUE <<"Agregar - 1\tEliminar - 2\tMantenimientos - 3\tInformacion - 4\nReservas - 5\tVolver - q" << RESET << std::endl;
    footer();
    std::cin >> input;
    std::cin.ignore();
    if (input == '1') {
        agregar_habitacion();
        return;
    } else if (input == '2') {
        eliminar_habitacion();
        return;
    } else if (input == '3') {
        mantenimientos();
        return;
     } else if (input == '4') {
        detalles_habitacion();
        return;
    } else if (input == '5') {
        pantalla_reserva();
        return;
    } else if (tolower(input) == 'q') {
        return;
    } else {
        std::cout << "Comando invalido" << std::endl;
    }
}


std::string Launcher::recortarCampo(const std::string& campo, int ancho) {
    return campo.substr(0, ancho - 2);
}


void Launcher::pantalla_agregar() {
    std::string dni, nombre, telefono, direccion;

    std::cout <<  "Ingrese DNI: "<< std::endl;
        std::cin >> dni;
        std::cin.ignore();
        std::vector<int> dnis_registrados = hotel.dni_clientes_registrados();
        if (!validador.dni_valido(dni, dnis_registrados)) {
            while (!validador.dni_valido(dni, dnis_registrados)) {
                std::cout << "DNI invalido" << std::endl;
                std::cin >> dni;
                std::cin.ignore();
            }
        }
        std::cout <<  "Ingrese nombre: "<< std::endl;
        std::getline(std::cin, nombre);
        if (!validador.nombre_valido(nombre)) {
            while (!validador.nombre_valido(nombre)) {
                std::cout << "Nombre invalido" << std::endl;
                std::getline(std::cin, nombre);
            }
        }
        std::cout <<  "Ingrese Telefono: "<< std::endl;
        std::cin >> telefono;
        std::cin.ignore();
        if (!validador.telefono_valido(telefono)) {
            while (!validador.telefono_valido(telefono)) {
                std::cout << "Telefono invalido" << std::endl;
                std::cin >> telefono;
                std::cin.ignore();
            }
        }
        std::cout <<  "Ingrese Direccion: "<< std::endl;
        std::getline(std::cin, direccion);
        if (!validador.direccion_valida(direccion)) {
            while (!validador.direccion_valida(direccion)) {
                std::cout << "Direccion invalida" << std::endl;
                std::getline(std::cin, direccion);
            }
        }
        hotel.registrar_cliente(stoi(dni), nombre, stoi(telefono), direccion);
        system("clear");
        pantalla_clientes_registrados();
        return;

}

void Launcher::pantalla_clientes_registrados() {
    system("clear");
    header();
    std::cout << "Clientes Registrados\n"<< RESET <<std::endl;
    std::cout <<std::endl;
    if (hotel.cantidad_clientes_registrados() <= 0) {
        std::cout << "No hay clientes registrados" <<std::endl;
    } else {
        std::cout << std::left << std::setw(ANCHO_DNI) << "\tDNI"
         << std::setw(ANCHO_NOMBRE) << "Nombre"
         << std::setw(ANCHO_TELEFONO) << "Telefono"
         << std::setw(ANCHO_DIRECCION) << "Direccion" << std::endl;
        std::string dni, nombre, telefono, direccion;
        std::vector<std::string> clientes = hotel.informacion_clientes_registrados();
        for (std::string cliente : clientes) {
            std::stringstream ss(cliente);
            getline(ss, dni, ',');
            getline(ss, nombre, ',');
            getline(ss, telefono, ',');
            getline(ss, direccion);
            std::cout <<BOLD << std::left  << std::setw(ANCHO_DNI) << "\t" + recortarCampo(dni, ANCHO_DNI)
            << std::setw(ANCHO_NOMBRE) << recortarCampo(nombre, ANCHO_NOMBRE)
            << std::setw(ANCHO_TELEFONO) << recortarCampo(telefono, ANCHO_TELEFONO)
            << std::setw(ANCHO_DIRECCION) << recortarCampo(direccion, ANCHO_DIRECCION) << RESET<< std::endl;
        }
    }
    std::cout <<std::endl;
    std::cout <<std::endl;
    char input;
    std::cout << BOLD << BLUE <<"Agregar - 1\tEliminar - 2\tModificar - 3\tVolver - q" << RESET << std::endl;
    footer();
    std::cin >> input;
    std::cin.ignore();
    if (input == '1') {
        pantalla_agregar();
        return;
    } else if (input == '2') {
        eliminar_cliente();
        return;

    } else if (input == '3') {
        modificar_cliente();
        return;
    } else if (tolower(input) == 'q') {
        return;
    } else {
        std::cout << "Comando invalido" << std::endl;
    }
}

std::string Launcher::modificacion_telefono() {
    std::cout << "Ingrese el nuevo telefono (Colocar 0 para mantener el actual): " << std::endl;
    std::string telefono;

    std::getline(std::cin, telefono);
    if (telefono != "0") {
        while (!validador.telefono_valido(telefono)) {
            std::cout << "Telefono invalido" << std::endl;
            std::getline(std::cin, telefono);
        }
    }
    return telefono;
}

std::string Launcher::modificacion_direccion() {
    std::cout << "Ingrese la nueva direccion (Colocar 0 para mantener la actual): " << std::endl;
    std::string direccion;

    std::getline(std::cin, direccion);
    if (direccion != "0") {
        while (!validador.direccion_valida(direccion)) {
            std::cout << "Direccion invalida" << std::endl;
            std::cout << direccion << std::endl;
            std::getline(std::cin, direccion);
        }
    }
    return direccion;
}

void Launcher::modificar_cliente() {
    std::string dni;
    std::cout <<  "Ingrese DNI: "<< std::endl;
    std::cin >> dni;
    std::cin.ignore();
    std::vector<int> dnis_registrados = hotel.dni_clientes_registrados();
    for (int id : dnis_registrados) {
        if (stoi(dni) == id) {
            std::cout << "Cliente encontrado" << std::endl;
            std::string telefono = modificacion_telefono();
            std::string direccion = modificacion_direccion();
            hotel.modificar_cliente(stoi(dni), telefono, direccion);
            system("clear");
            pantalla_clientes_registrados();
            return;
        }
    }
    std::cout << "No existe cliente registrado con ese dni" << std::endl;
}

void Launcher::eliminar_cliente() {
    std::string dni;
    std::cout <<  "Ingrese DNI: "<< std::endl;
    std::cin >> dni;
    std::cin.ignore();
    std::vector<int> dnis_registrados = hotel.dni_clientes_registrados();
    for (int id : dnis_registrados) {
        if (stoi(dni) == id) {
            if (!hotel.eliminar_cliente(stoi(dni))) {
                std::cout << "ERROR: El cliente actualmente esta registrado en una habitacion" << std::endl;
                return;
            }
            system("clear");
            pantalla_clientes_registrados();
            return;
        }
    }
    std::cout << "No existe cliente registrado con ese dni" << std::endl;
}



int Launcher::run() {   
    hotel.agregar_habitacion(1, 1, 4);
    hotel.agregar_habitacion(52, 1, 5);
    hotel.agregar_habitacion(2, 2, 5);
    hotel.crear_reserva(01, 01, 12886666, "Juan carlos", 69566411, "Por alla");
    hotel.registrar_cliente(12999742, "El negro tecla", 444668, "Lanus 1003");
    hotel.comenzar_mantenimiento(52, 1);
    system("clear");
    display();

    return 0;
}
