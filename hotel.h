#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <vector>

#include "cliente.h"
#include "habitacion.h"



class Hotel {
private:
    std::string nombre;
    int ocupacion;
    int capacidad;
    int porcentajeOcupacion;
    std::vector<Habitacion> habitaciones;
    std::vector<Cliente> clientes;
    
    Habitacion  * get_habitacion(int numero, int piso);
    Cliente *  get_cliente(int dni);

public:
    Hotel(std::string nombre);

    int agregar_habitacion(int numero, int piso, int capacidad);
    
    int eliminar_habitacion(const int numero, const int piso);

    int comenzar_mantenimiento(int numero, int piso);

    int terminar_mantenimiento(int numero, int piso);

    int finalizar_reserva(int numero, int piso);

    bool existe_habitacion(int numero, int piso);

    int crear_reserva(int numero, int piso, int dni_cliente, std::string nombre, int telefonoCl,std::string direccion);

    bool existe_cliente(const int dni);

    bool habitacion_disponible(int numero, int piso);

    int get_capacidad();

    int get_ocupacion();

    int get_ocupacion_porcentual();


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
