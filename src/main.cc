#include "../include/unidad-entrada.h"
#include "../include/unidad-salida.h"

#include <iostream>

int main() {
  UnidadEntrada entrada("input/entrada.txt");
  UnidadSalida salida("output/salida.txt");
  while (!entrada.entradaVacia()) {
    salida.guardarDatoSalida(entrada.leerDatoEntrada());
  }
  salida.exportarCintaSalida();
  return 0;
}