#include "unidad-alu.h"

class AluDiv : public UnidadALU {
 public:
  AluDiv(int operando) : operando_(operando) {};
  ~AluDiv();
  void ejecutar();
 private:
  int operando_;
};