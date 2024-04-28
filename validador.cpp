#include <string>

#include "validador.h"

Validador::Validador(){}

bool Validador::nombre_valido(std::string nombre) {
      if (nombre.empty()) {
         return false;
      }
      for (char c : nombre) {
          if (!isalpha(c)) {
              if (c != ' ' && c != '-') {
                  return false;
              }
          }
      }
      return true;
}

bool Validador::telefono_valido(std::string numero) {
      if (numero.empty()) {
        return false;
      }
      for (char c : numero) {
          if (!isdigit(c)) {
              return false;
          }
      }
      return true;
}
bool Validador::dni_valido(std::string dni, std::vector<int> dnis) {
      if (dni.empty()) {
        return false;
      }
      for (char c : dni) {
          if (!isdigit(c)) {
              return false;
          }
      }
      for (int dniv : dnis) {
         if (dniv == stoi(dni)) {
            return false;
         }
      }
      return true;
}

bool Validador::direccion_valida(std::string direccion) {
      if (direccion.empty()) {
         return false;
      }
      for (char c : direccion) {
          if (!isalnum(c)) {
              if (c != ' ' && c != '-') {
                  return false;
              }
          }
      }
      return true;
}
bool Validador::dato_habitacion_valido(std::string dato) {
      if (dato.empty()) {
        return false;
      }
      for (char c : dato) {
          if (!isdigit(c)) {
              return false;
          }
      }
      return true;
}