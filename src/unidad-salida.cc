#include "../include/unidad-salida.h"

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

void UnidadSalida::guardarDatoSalida(int dato) { 
  unidadSalida_.push(dato);       
  return;
}

void UnidadSalida::exportarCintaSalida() { 
  std::ofstream fichero(ficheroSalida_);
  if (!fichero) {
    throw std::runtime_error("Error: No se ha podido abrir el archivo de salida.");
  }
  while (!unidadSalida_.empty()) {
    fichero << unidadSalida_.front() << " ";
    unidadSalida_.pop();
  }
  fichero.close();
  return;
}
