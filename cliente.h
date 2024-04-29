#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

class Cliente {
private:
    int dni;
    std::string nombre;
    int telefono;
    std::string direccion;

public:
    Cliente(int dni, const std::string& nombre, int telefono, const std::string& direccion);

    void cambiar_telefono(int telefonoNuevo);

    void cambiar_direccion(std::string direccion);

    int get_dni() const;

    int get_telefono() const;

    std::string get_nombre() const;

    std::string get_direccion() const;
};
#endif
