#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <vector>

#include "cliente.h"
#include "habitacion.h"

struct info_habitacion{
    int numero;
    int piso;
    int capacidad;
    std::string estado;
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

    info_habitacion informacion_habitacion(int numero, int piso);

    std::vector<int> habitaciones_por_piso(int piso);

    std::vector<std::string> habitaciones_disponibles();
    
    std::vector<std::string> habitaciones_status();

    std::vector<std::string> informacion_clientes_registrados();

    std::vector<int> dni_clientes_registrados();

    bool eliminar_cliente(int dni);

    void modificar_cliente(int dni, std::string telefono, std::string direccion);

    void registrar_cliente(int dni, std::string nombre, int telefono, std::string direccion);

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
