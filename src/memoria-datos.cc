#include "../include/memoria-datos.h"

#include <iostream>

void MemoriaDatos::setDatoMemoria(int direccion, int dato) {
  if (direccion < 0 || direccion >= memoriaDatos_.size()) {
    throw std::out_of_range("Error: Dirección de memoria fuera de rango.");
  }
  memoriaDatos_[direccion] = dato;
}

int MemoriaDatos::getDatoMemoria(int direccion) const {
  if (direccion < 0 || direccion >= memoriaDatos_.size()) {
    throw std::out_of_range("Error: Dirección de memoria fuera de rango.");
  }
  return memoriaDatos_[direccion];
}