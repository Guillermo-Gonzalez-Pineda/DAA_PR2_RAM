#include "../include/alu/alu-add.h"
#include "../include/alu/alu-div.h"
#include "../include/alu/alu-jgtz.h"
#include "../include/alu/alu-jump.h"
#include "../include/alu/alu-jzero.h"
#include "../include/alu/alu-mul.h"
#include "../include/alu/alu-sub.h"

/**
 * @brief Constructor de la clase AluAdd.
 * 
 * @param operando Operando que se sumará al registro 0.
 * @return AluAdd
 */
void AluAdd::ejecutar() {
  if (memoriaDatos_) {
    std::cout << "Valor Registro 0: " << memoriaDatos_->getDatoMemoria(0) << std::endl;
    std::cout << "Valor Registro " << operando_ << ": " << memoriaDatos_->getDatoMemoria(operando_) << std::endl;
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    memoriaDatos_->setDatoMemoria(0, valorRegistro0 + operando_);
  }
  std::cout << "Ejecutando ADD con operando: " << operando_ << std::endl;
  return;
}

/**
 * @brief Constructor de la clase AluDiv.
 * 
 * @param operando Operando por el que se dividirá el registro 0.
 * @return AluDiv
 */
void AluDiv::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    if (valorRegistro0 == 0) {
      std::cerr << "Error: división por cero." << std::endl;
      return;
    }
    memoriaDatos_->setDatoMemoria(0, valorRegistro0 / operando_);
  }
  return;
}

/**
 * @brief Constructor de la clase AluJgtz.
 * 
 * @param etiqueta Etiqueta a la que se saltará si el registro 0 es mayor que cero.
 * @return AluJgtz
 */
void AluJgtz::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    if (valorRegistro0 > 0) {
      std::cout << "Ejecutando JGTZ a la etiqueta: " << etiqueta_ << std::endl;
    }
  }
  return;
}

/**
 * @brief Constructor de la clase AluJump.
 * 
 * @param etiqueta Etiqueta a la que se saltará.
 * @return AluJump
 */
void AluJump::ejecutar() {
  std::cout << "Ejecutando JUMP a la etiqueta: " << etiqueta_ << std::endl;
  return;
}

/**
 * @brief Constructor de la clase AluJzero.
 * 
 * @param etiqueta Etiqueta a la que se saltará si el registro 0 es cero.
 * @return AluJzero
 */
void AluJzero::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    if (valorRegistro0 == 0) {
      std::cout << "Ejecutando JZERO a la etiqueta: " << etiqueta_ << std::endl;
    }
  }
  return;
}

/**
 * @brief Constructor de la clase AluMul.
 * 
 * @param operando Operando por el que se multiplicará el registro 0.
 * @return AluMul
 */
void AluMul::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    memoriaDatos_->setDatoMemoria(0, valorRegistro0 * operando_);
  }
  return;
}

/**
 * @brief Constructor de la clase AluSub.
 * 
 * @param operando Operando que se restará al registro 0.
 * @return AluSub
 */
void AluSub::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    memoriaDatos_->setDatoMemoria(0, valorRegistro0 - operando_);
  }
  return;
}