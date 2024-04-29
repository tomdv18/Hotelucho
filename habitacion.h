#ifndef HABITACION_H
#define HABITACION_H
#include <string>

#include "cliente.h"

enum estado_habitacion { disponible, ocupado, mantenimiento };

class Habitacion {
private:
    int numero;
    int piso;
    int capacidad;
    estado_habitacion estado;
    Cliente* clienteActual;

public:
    Habitacion(int numero, int piso, int capacidad);

    bool esta_disponible();

    bool en_mantenimiento();

    void comenzar_mantenimiento();

    void terminar_mantenimiento();

    void terminar_reserva();

    void reservar(Cliente* clienteReserva);

    int get_dni_cliente() const;

    bool get_nombre_cliente(std::string& nombre) const;

    int get_piso() const;

    int get_numero() const;

    int get_capacidad() const;
};

#endif
