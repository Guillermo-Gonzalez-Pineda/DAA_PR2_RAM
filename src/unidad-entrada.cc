#include "../include/unidad-entrada.h"

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

UnidadEntrada::UnidadEntrada(const std::string& nombreFichero) {
  std::ifstream fichero(nombreFichero, std::ios::in);
  if (!fichero) {
    throw std::runtime_error("Error: No se ha podido abrir el archivo de entrada.");
  }
  int dato;
  while (fichero >> dato) {
    unidadEntrada_.push(dato);
  }
  fichero.close();
  return;
}

int UnidadEntrada::leerDatoEntrada() { 
  int dato = unidadEntrada_.front();
  unidadEntrada_.pop();           
  return dato;
}
