// Copyright 2024 tomdv18
#include "cliente.h"

#include <string>

Cliente::Cliente(int dni, const std::string& nombre, int telefono, const std::string& direccion):
        dni(dni), nombre(nombre), telefono(telefono), direccion(direccion) {}

void Cliente::cambiar_telefono(const int telefonoNuevo) { telefono = telefonoNuevo; }

void Cliente::cambiar_direccion(const std::string direc) { direccion = direc; }

int Cliente::get_dni() const { return dni; }

int Cliente::get_telefono() const { return telefono; }

std::string Cliente::get_nombre() const { return nombre; }

std::string Cliente::get_direccion() const { return direccion; }
