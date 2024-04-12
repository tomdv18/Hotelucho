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
    Cliente(int dni, std::string nombre,int telefono, std::string direccion);

    void cambiar_telefono(int telefonoNuevo);

    void cambiar_direccion(std::string  direccion);

    int get_dni();

    int get_telefono();

    std::string get_nombre();

    std::string get_direccion();
    /*
     * No queremos permitir que alguien haga copias
     
    Cliente(const Cliente&) = delete;
    Cliente& operator=(const Cliente&) = delete;

    //Move semantics
    Cliente(Cliente&&) = default;
    Cliente& operator=(Cliente&&) = default;
    */
};


#endif
