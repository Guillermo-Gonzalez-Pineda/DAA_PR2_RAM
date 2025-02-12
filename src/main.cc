#include "../include/unidad-entrada.h"

#include <iostream>

int main() {
  UnidadEntrada entrada("input/entrada.txt");
  while (!entrada.entradaVacia()) {
    std::cout << entrada.leerDatoEntrada() << std::endl;

  }
  return 0;
}