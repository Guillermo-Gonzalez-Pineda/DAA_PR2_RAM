#include "unidad-alu.h"

class AluSub : public UnidadALU {
 public:
  AluSub(int operando) : operando_(operando) {};
  ~AluSub();
  void ejecutar();
 private:
  int operando_;
};