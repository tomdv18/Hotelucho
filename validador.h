#ifndef VALIDADOR_H
#define VALIDADOR_H
#include <string>
#include <vector>

class Validador {
private:
public:
    Validador();
    bool nombre_valido(std::string nombre);
    bool telefono_valido(std::string numero);
    bool dni_valido(std::string dni, std::vector<int> dnis);
    bool direccion_valida(std::string direccion);
    bool dato_habitacion_valido(std::string dato);
};
#endif
