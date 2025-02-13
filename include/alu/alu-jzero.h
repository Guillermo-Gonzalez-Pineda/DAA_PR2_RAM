#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_JZERO_H
#define ALU_JZERO_H

class AluJzero : public UnidadALU {
 public:
  AluJzero(const std::string& etiqueta) : etiqueta_(etiqueta) {}
  void ejecutar() { std::cout << "Ejecutando JZERO a la etiqueta: " << etiqueta_ << std::endl; }
 private:
  std::string etiqueta_;
};

#endif