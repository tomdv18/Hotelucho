#ifndef HOTEL_H
#define HOTEL_H

#include <habitacion.h>
#include <cliente.h>
#define MAXSIZE 1024


class Hotel {
private:
    char nombre[MAXSIZE];
    int ocupacion;
    int capacidad;
    Habitacion * Habitaciones;
    Cliente * clientes;
    

public:
    Hotel(char nombre[MAXSIZE]);

    int agregar_habitacion();

    int crear_reserva();
 

    /*
     * No queremos permitir que alguien haga copias
     */
    Hotel(const Hotel&) = delete;
    Hotel& operator=(const Hotel&) = delete;

    /*Move semantics*/
    Hotel(Hotel&&) = default;
    Hotel& operator=(Hotel&&) = default;
};


#endif
