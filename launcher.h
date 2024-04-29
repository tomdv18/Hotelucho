#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <string>
#include "hotel.h"
#include "validador.h"

class Launcher{
 private:
    Validador validador;
    std::string nombre;
    Hotel hotel;
    void pantalla_reserva();
    void display();
    void header();
    void footer();
    void pantalla_habitaciones_disponibles();
    void pantalla_habitaciones();
    void pantalla_clientes_registrados();
    std::string recortarCampo(const std::string& campo, int ancho);
    void eliminar_cliente();
    void pantalla_agregar();
    void modificar_cliente();
    std::string modificacion_direccion();
    std::string modificacion_telefono();
    void solicitar_datos_habitacion(int & piso, int & numero);
    void agregar_habitacion();
    void eliminar_habitacion();
    void detalles_habitacion();
    void pantalla_habitacion(int numero, int piso);
    void mantenimientos();

 public:
    explicit Launcher(std::string nombre);
    int run();
};

#endif
