#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <string>
#include "hotel.h"


class Launcher{
    private:
    std::string nombre;
    Hotel hotel;
    void pantalla_reserva();
    void display();
    void header();
    void footer();
    public:
    Launcher(std::string nombre);
    int run();
};

#endif
