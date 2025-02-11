#include "unidad-alu.h"

class AluMul : public UnidadALU {
 public:
  AluMul(int operando) : operando_(operando) {};
  ~AluMul();
  void ejecutar();
 private:
  int operando_;
};