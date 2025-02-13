#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_SUB_H
#define ALU_SUB_H

class AluSub : public UnidadALU {
 public:
  AluSub(int operando) : operando_(operando) {}
  void ejecutar() { std::cout << "Ejecutando SUB con operando: " << operando_ << std::endl; }
 private:
  int operando_;
};

#endif