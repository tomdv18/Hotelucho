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

    // Devuelve verdadero si esta disponible
    bool esta_disponible();

    // Devuelve verdadero si esta en mantenimiento
    bool en_mantenimiento();

    /*
     * Comienza el mantenimiento de la habitacion
     */
    void comenzar_mantenimiento();

    /*
     * Comienza el mantenimiento de la habitacion
     */
    void terminar_mantenimiento();

    /*
     * Resetea la habitacion a disponible y comienza el mantenimiento
     */
    void terminar_reserva();

    /*
     * Reserva la habitacion para un cliente
     */
    void reservar(Cliente* clienteReserva);

    /*
     * Devuelve el dni del cliente que esta ocupando la habitacion, si no hay devuelve -1
     */
    int get_dni_cliente() const;

    /*
     * Si la habitacion esta ocupada por un cliente devuelve verdadero y pasa el nombre por
     * parametro
     */
    bool get_nombre_cliente(std::string& nombre) const;

    int get_piso() const;

    int get_numero() const;

    int get_capacidad() const;
};

#endif
