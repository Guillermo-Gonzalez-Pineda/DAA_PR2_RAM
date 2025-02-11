#include "unidad-alu.h"

class AluAdd : public UnidadALU {
 public:
  AluAdd(int operando) : operando_(operando) {};
  ~AluAdd();
  void ejecutar();
 private:
  int operando_;
};