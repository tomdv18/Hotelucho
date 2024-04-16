#include "launcher.h"
#include "hotel.h"
#include "habitacion.h"
#include "cliente.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <thread>  
#include <chrono>
#define ERROR -1



Launcher::Launcher(std::string nombreHotel) : nombre(nombreHotel), hotel(nombre){
}

void Launcher::header(){
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << "Hotel: " << nombre << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout <<std::endl;
    std::cout <<std::endl;
}

void Launcher::footer(){
    std::cout <<std::endl;
    std::cout <<std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << "Capacidad actual: " << hotel.get_capacidad() << std::endl;
    std::cout << "Ocupacion actual: " << hotel.get_ocupacion_porcentual() << "% (" <<hotel.get_ocupacion() << " personas)" <<std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
}

void Launcher::display(){
    header();
    std::cout << "Presiona 1 para ver las habitaciones" <<std::endl;
    std::cout << "Presiona 2 para ver las habitaciones disponibles" <<std::endl;
    std::cout << "Presiona 3 para ver los clientes registrados" <<std::endl;
    footer();
    std::this_thread::sleep_for(std::chrono::seconds(2));

}

void Launcher::pantalla_reserva(){
    header();
    std::cout <<std::endl;
    std::cout <<std::endl;
    std::cout << "Presiona 1 para ver las habitaciones" <<std::endl;
    std::cout << "Presiona 2 para ver las habitaciones disponibles" <<std::endl;
    std::cout << "Presiona 3 para ver los clientes registrados" <<std::endl;
    std::cout <<std::endl;
    std::cout <<std::endl;
    footer();
}


int Launcher::run(){
    std::cout <<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("clear");
    display();

    /*
    hotel.agregar_habitacion(1,1,4);
    hotel.agregar_habitacion(52,1,5);

    std::string s("Juan carlos");
    std::string j("Por alla");
    hotel.crear_reserva(01,01,42886658,s, 69566411, j);
    system("clear");
    display(hotel);
    std::vector<std::string> habitaciones = hotel.habitaciones_disponibles();
    for(std::string hab : habitaciones){
            std::cout << hab <<std::endl;
    } */
    return 0;
}
