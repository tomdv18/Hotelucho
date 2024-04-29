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

    int agregar_habitacion(int numero, int piso, int capacidad);

    int eliminar_habitacion(const int numero, const int piso);

    int comenzar_mantenimiento(int numero, int piso);

    int terminar_mantenimiento(int numero, int piso);

    bool existe_habitacion(int numero, int piso);

    int crear_reserva(int numero, int piso, int dni_cliente, const std::string& nombre,
                      int telefonoCl, const std::string& direccion);

    int finalizar_reserva(int numero, int piso);

    bool habitacion_disponible(int numero, int piso);

    bool habitacion_en_mantenimiento(int numero, int piso);

    bool existe_cliente(const int dni);

    bool eliminar_cliente(int dni);

    void modificar_cliente(int dni, const std::string& telefono, const std::string& direccion);

    void registrar_cliente(int dni, const std::string& nombre, int telefono,
                           const std::string& direccion);

    /*No copias*/
    Logica_Hotel(const Logica_Hotel&) = delete;
    Logica_Hotel& operator=(const Logica_Hotel&) = delete;

    /*Move semantics*/
    Logica_Hotel(Logica_Hotel&&) = default;
    Logica_Hotel& operator=(Logica_Hotel&&) = default;
};

#endif
