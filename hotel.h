#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <vector>

#include "cliente.h"
#include "habitacion.h"
#include "logica_hotel.h"

struct info_habitacion {
    // cppcheck-suppress unusedStructMember
    int numero;
    // cppcheck-suppress unusedStructMember
    int piso;
    // cppcheck-suppress unusedStructMember
    int capacidad;
    std::string estado;
    // cppcheck-suppress unusedStructMember
    int dni_cliente;
    std::string nombre_cliente;
};

class Hotel {
private:
    std::string nombre;
    int ocupacion;
    int capacidad;
    int porcentajeOcupacion;
    std::vector<Habitacion> habitaciones;
    std::vector<Cliente> clientes;
    Logica_Hotel lhotel;

public:
    explicit Hotel(const std::string& nombre);


    /*
     * Devuelve 0 si se agrego correctamente, -1 si ya existe la habitacion
     */
    int agregar_habitacion(int numero, int piso, int capacidad);

    /*
     * Devuelve 0 si se elimino correctamente, -1 si no existe la habitacion o esta ocupada
     */
    int eliminar_habitacion(const int numero, const int piso);

    /*
     * Devuelve verdadero si existe la habitacion
     */
    bool existe_habitacion(int numero, int piso);

    /*
     * Devuelve verdadero si la habitacion esta en mantenimiento
     */
    bool habitacion_en_mantenimiento(int numero, int piso);

    /*
     * Devuelve verdadero si la habitacion esta disponible
     */
    bool habitacion_disponible(int numero, int piso);

    /*
     * Comienza el mantenimiento, si ocurre un error devuelve -1
     */
    int comenzar_mantenimiento(int numero, int piso);

    /*
     * Finaliza el mantenimiento, si ocurre un error devuelve -1
     */
    int terminar_mantenimiento(int numero, int piso);

    /*
     * Crea una reserva, si no existe la habitacion devuelve -1.
     * Si el cliente no existe lo crea
     */
    int crear_reserva(int numero, int piso, int dni_cliente, const std::string& nombre,
                      int telefonoCl, const std::string& direccion);

    /*
     * Finaliza una reserva, si no existe la habitacion devuelve -1
     */
    int finalizar_reserva(int numero, int piso);


    // Registra un cliente
    void registrar_cliente(int dni, const std::string& nombre, int telefono,
                           const std::string& direccion);
    /*
     * Modifica los datos de un cliente.
     * Si alguno de los datos a cambiar son vacios, se mantiene el valor anterior
     */
    void modificar_cliente(int dni, const std::string& telefono, const std::string& direccion);

    /*
     * Devuelve verdadero si existe el cliente
     */
    bool existe_cliente(const int dni);

    /*
     * Elimina un cliente, si no existe o ese cliente esta en una reserva actualmente devuelve falso
     */
    bool eliminar_cliente(int dni);


    info_habitacion informacion_habitacion(int numero, int piso);

    /*
     * Devuelve un vector con las habitaciones (SOLO LAS DISPONIBLES) con su informacion separada
     * por coma
     */
    std::vector<std::string> habitaciones_disponibles();

    /*
     * Devuelve un vector con TODAS las habitaciones con su informacion separada por coma
     */
    std::vector<std::string> habitaciones_status();

    /*
     * Devuelve un vector con la informacion de los clientes registrados
     */
    std::vector<std::string> informacion_clientes_registrados();

    /*
     * Devuelve un vector con los dni de los clientes registrados
     */
    std::vector<int> dni_clientes_registrados();

    int cantidad_clientes_registrados();

    int cantidad_habitaciones();

    int get_capacidad();

    int get_ocupacion();

    int get_ocupacion_porcentual();

    std::string get_nombre();

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
