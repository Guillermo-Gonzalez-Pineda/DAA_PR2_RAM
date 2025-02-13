#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_ADD_H
#define ALU_ADD_H

class AluAdd : public UnidadALU {
 public:
  AluAdd(int operando) : operando_(operando) {}
  void ejecutar() { std::cout << "Ejecutando ADD con operando: " << operando_ << std::endl; }
 private:
  int operando_;
};

#endif