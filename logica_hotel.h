#ifndef LOGICA_HOTEL_H
#define LOGICA_HOTEL_H
#include <string>
#include <vector>

#include "cliente.h"
#include "habitacion.h"

class Logica_Hotel {
private:
    int& ocupacion;
    int& capacidad;
    int& porcentajeOcupacion;
    std::vector<Habitacion>& habitaciones;
    std::vector<Cliente>& clientes;

    Habitacion* get_habitacion(int numero, int piso);
    Cliente* get_cliente(int dni);
    void actualizar_ocupacion();

public:
    Logica_Hotel(int& ocupacion, int& capacidad, int& porcentaje_ocupacion,
                 std::vector<Habitacion>& habitaciones, std::vector<Cliente>& clientes);

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


    /*No copias*/
    Logica_Hotel(const Logica_Hotel&) = delete;
    Logica_Hotel& operator=(const Logica_Hotel&) = delete;

    /*Move semantics*/
    Logica_Hotel(Logica_Hotel&&) = default;
    Logica_Hotel& operator=(Logica_Hotel&&) = default;
};

#endif
