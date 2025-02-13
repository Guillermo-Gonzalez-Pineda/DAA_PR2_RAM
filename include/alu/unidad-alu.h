#include <string>

#ifndef UNIDAD_ALU_H
#define UNIDAD_ALU_H

class UnidadALU {
 public:
  virtual void ejecutar() = 0;
  virtual ~UnidadALU() {}
};

#endif