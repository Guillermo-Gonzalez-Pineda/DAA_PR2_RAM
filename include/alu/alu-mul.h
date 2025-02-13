#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_MUL_H
#define ALU_MUL_H

class AluMul : public UnidadALU {
 public:
  AluMul(int operando) : operando_(operando) {}
  void ejecutar() { std::cout << "Ejecutando MUL con operando: " << operando_ << std::endl; }
 private:
  int operando_;
};

#endif