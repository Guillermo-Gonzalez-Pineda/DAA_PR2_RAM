#include "../include/elegir-instruccion.h"
#include "../include/alu/unidad-alu.h"
#include "../include/alu/alu-add.h"
#include "../include/alu/alu-sub.h"
#include "../include/alu/alu-div.h"
#include "../include/alu/alu-mul.h"
#include "../include/alu/alu-jump.h"
#include "../include/alu/alu-jzero.h"
#include "../include/alu/alu-jgtz.h"
#include "../include/memoria-datos.h"

ElegirInstruccion::ElegirInstruccion(const std::string& cadenaInstruccion, MemoriaDatos* memoria) {
  std::string instruccion = "", operando = "";
  bool leyendoInstruccion = true;
  for (int i = 0; i < cadenaInstruccion.size(); i++) {
    if (cadenaInstruccion[i] == ' ') {
      leyendoInstruccion = false;
      continue;
    }
    if (leyendoInstruccion) {
      instruccion += cadenaInstruccion[i];
    }
    else {
      operando += cadenaInstruccion[i];
    }
  }
  if (instruccion == "add") {
    instruccion_ = new AluAdd(std::stoi(operando));
  }
  else if (instruccion == "sub") {
    instruccion_ = new AluSub(std::stoi(operando));
  }
  else if (instruccion == "div") {
    instruccion_ = new AluDiv(std::stoi(operando));
  }
  else if (instruccion == "mul") {
    instruccion_ = new AluMul(std::stoi(operando));
  }
  else if (instruccion == "jump") {
    instruccion_ = new AluJump(operando);
  }
  else if (instruccion == "jzero") {
    instruccion_ = new AluJzero(operando);
  }
  else if (instruccion == "jgtz") {
    instruccion_ = new AluJgtz(operando);
  }

  if (instruccion_) {
    instruccion_->setMemoriaDatos(memoria);
  }
}

void ElegirInstruccion::ejecutar() { 
  if (instruccion_) {
    instruccion_->ejecutar();
  }
}