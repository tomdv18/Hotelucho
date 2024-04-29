#ifndef VALIDADOR_H
#define VALIDADOR_H
#include <string>
#include <vector>

class Validador {
private:
public:
    Validador();

    // Un nombre es valdo si no esta vacio y todos sus caracteres son letras, espacios o guiones
    bool nombre_valido(std::string nombre);

    // Un telefono es valido si no esta vacio y todos sus caracteres son digitos
    bool telefono_valido(std::string numero);

    // Un dni es valido si no esta vacio y todos sus caracteres son digitos y no esta en la lista de
    // dnis (Evitando repetidos)
    bool dni_valido(std::string dni, std::vector<int> dnis);

    // Una direccion es valida si no esta vacia y todos sus caracteres son letras, digitos, espacios
    // o guiones
    bool direccion_valida(std::string direccion);

    // Un dato de habitacion es valido si no esta vacio y si todos sus caracteres son numericos
    bool dato_habitacion_valido(std::string dato);
};
#endif
