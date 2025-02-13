#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_JGTZ_H
#define ALU_JGTZ_H

class AluJgtz : public UnidadALU {
 public:
  AluJgtz(const std::string& etiqueta) : etiqueta_(etiqueta) {}
  void ejecutar() { std::cout << "Ejecutando JGTZ a la etiqueta: " << etiqueta_ << std::endl; }
 private:
  std::string etiqueta_;
};

#endif