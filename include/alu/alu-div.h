#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_DIV_H
#define ALU_DIV_H

class AluDiv : public UnidadALU {
 public:
  AluDiv(int operando) : operando_(operando) {}
  void ejecutar() { std::cout << "Ejecutando DIV con operando: " << operando_ << std::endl; }
 private:
  int operando_;
};

#endif