
#include "alu/unidad-alu.h"

#ifndef ELEGIR_INSTRUCCION_H
#define ELEGIR_INSTRUCCION_H

class ElegirInstruccion {
 public: 
  ElegirInstruccion(const std::string& cadenaInstruccion);
  void ejecutar();
 private:
  UnidadALU* instruccion_;
};

#endif