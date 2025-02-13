#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_JUMP_H
#define ALU_JUMP_H

class AluJump : public UnidadALU {
 public:
  AluJump(const std::string& etiqueta) : etiqueta_(etiqueta) {}
  void ejecutar() { std::cout << "Ejecutando JUMP a la etiqueta: " << etiqueta_ << std::endl; }
 private:
  std::string etiqueta_;
};

#endif