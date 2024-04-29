#ifndef LECTOR_ARCHIVO_H
#define LECTOR_ARCHIVO_H
#include <string>

#include "hotel.h"

class Lector_Archivo {
private:
    std::string nombreArchivo;
    Hotel& hotel;

public:
    Lector_Archivo(const std::string& nombreArchivo, Hotel& hotel);
    void inicializar_desde_archivo(const std::string& nombreArchivo);
};

#endif
