#ifndef HABITACION_H
#define HABITACION_H

#include <cliente.h>

enum estado_habitacion{
    disponible,
    ocupado,
    mantenimiento
};

class Habitacion {
private:
    int numero;
    int piso;
    int capacidad;
    estado_habitacion estado;
    Cliente * clienteActual;
    

public:
    Habitacion(int numero, int piso, int capacidad);

    bool esta_disponible();

    void comenzar_mantenimiento();

    void terminar_mantenimiento();

    void terminar_reserva();

    void reservar(Cliente * clienteReserva);

    

    /*
     * No queremos permitir que alguien haga copias
     */
    Habitacion(const Habitacion&) = delete;
    Habitacion& operator=(const Habitacion&) = delete;

    /*Move semantics*/
    Habitacion(Habitacion&&) = default;
    Habitacion& operator=(Habitacion&&) = default;
};


#endif
