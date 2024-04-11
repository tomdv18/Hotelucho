#include "hotel.h"
#include "habitacion.h"
#include "cliente.h"
#include <string>
#include <iostream>
#define ERROR -1



int main(int argc, char* argv[]){
    Hotel hotel("Hotelucho");
    std::cout << hotel.get_capacidad() <<std::endl;
    hotel.agregar_habitacion(01,01,4);
    hotel.agregar_habitacion(01,052,5);
    std::cout << hotel.get_capacidad() <<std::endl;
    std::cout << hotel.get_ocupacion() <<std::endl;

    std::string s("Juan carlos");
    std::string j("Por alla");
    hotel.crear_reserva(01,01,42886658,s, 69566411, j);

    std::cout << hotel.get_capacidad() <<std::endl;
    std::cout << hotel.get_ocupacion() <<std::endl;
    std::cout << hotel.get_ocupacion_porcentual() << "%"<<std::endl;
}
