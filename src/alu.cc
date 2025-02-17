#include "../include/alu/alu-add.h"
#include "../include/alu/alu-div.h"
#include "../include/alu/alu-jgtz.h"
#include "../include/alu/alu-jump.h"
#include "../include/alu/alu-jzero.h"
#include "../include/alu/alu-mul.h"
#include "../include/alu/alu-sub.h"
#include "../include/alu/alu-read.h"
#include "../include/alu/alu-write.h"
#include "../include/alu/alu-load.h"
#include "../include/alu/alu-store.h"

/**
 * @brief Operación ejecutar de la clase AluAdd.
 * 
 * @param operando Operando que se sumará al registro 0.
 * @return AluAdd
 */
void AluAdd::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    int suma = 0;

    if (operando_[0] == '=') {
      suma = std::stoi(operando_.substr(1));
    } else {
      suma = memoriaDatos_->getDatoMemoria(std::stoi(operando_));
    }
    memoriaDatos_->setDatoMemoria(0, valorRegistro0 + suma);
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluDiv.
 * 
 * @param operando Operando por el que se dividirá el registro 0.
 * @return AluDiv
 */
void AluDiv::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    int divisor = 0;
    if (operando_[0] == '=') {
      divisor = std::stoi(operando_.substr(1));
      if (divisor != 0) {
        memoriaDatos_->setDatoMemoria(0, valorRegistro0 / divisor);
      } else {
        throw std::invalid_argument("No se puede dividir por cero");
      }
    } else {
      divisor = memoriaDatos_->getDatoMemoria(std::stoi(operando_));
      if (divisor != 0) {
        memoriaDatos_->setDatoMemoria(0, valorRegistro0 / divisor);
      } else {
        throw std::invalid_argument("No se puede dividir por cero");
      }
    }
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluJgtz.
 * 
 * @param etiqueta Etiqueta a la que se saltará si el registro 0 es mayor que cero.
 * @return AluJgtz
 */
void AluJgtz::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    if (valorRegistro0 > 0) {
      memoriaPrograma_->saltarEtiqueta(etiqueta_);
    }
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluJump.
 * 
 * @param etiqueta Etiqueta a la que se saltará.
 * @return AluJump
 */
void AluJump::ejecutar() {
  if (memoriaPrograma_) {
    memoriaPrograma_->saltarEtiqueta(etiqueta_);
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluJzero.
 * 
 * @param etiqueta Etiqueta a la que se saltará si el registro 0 es cero.
 * @return AluJzero
 */
void AluJzero::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    if (valorRegistro0 == 0) {
      memoriaPrograma_->saltarEtiqueta(etiqueta_);
    }
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluMul.
 * 
 * @param operando Operando por el que se multiplicará el registro 0.
 * @return AluMul
 */
void AluMul::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    int multiplicador = 0;
    if (operando_[0] == '=') {
      multiplicador = std::stoi(operando_.substr(1));
    } else {
      multiplicador = memoriaDatos_->getDatoMemoria(std::stoi(operando_));
    }
    memoriaDatos_->setDatoMemoria(0, valorRegistro0 * multiplicador);
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluSub.
 * 
 * @param operando Operando que se restará al registro 0.
 * @return AluSub
 */
void AluSub::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    int resta = 0;
    if (operando_[0] == '=') {
      resta = std::stoi(operando_.substr(1));
    } else {
      resta = memoriaDatos_->getDatoMemoria(std::stoi(operando_));
    }
    memoriaDatos_->setDatoMemoria(0, valorRegistro0 - resta);
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluRead.
 * 
 * @param direccion Dirección de memoria de la que se leerá un dato.
 * @return AluRead
 */
void AluRead::ejecutar() {
  if (memoriaDatos_ && unidadEntrada_) {
    if (operando_[0] == '=') {
      throw std::invalid_argument("No se puede leer de una dirección de memoria constante");
    } else {
      int dato = unidadEntrada_->leerDatoEntrada();
      memoriaDatos_->setDatoMemoria(std::stoi(operando_), dato);
    }
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluWrite.
 * 
 * @param operando Dirección de memoria en la que se escribirá un dato.
 * @return AluWrite
 */
void AluWrite::ejecutar() {
  if (memoriaDatos_) {
    if (operando_[0] == '=') {
      int dato = std::stoi(operando_.substr(1));
      unidadSalida_->guardarDatoSalida(dato);
    } else {
      int dato = memoriaDatos_->getDatoMemoria(std::stoi(operando_));
      unidadSalida_->guardarDatoSalida(dato);
    }
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluLoad.
 * 
 * @param operando Dirección de memoria de la que se cargará un dato en el registro 0.
 * @return AluLoad
 */
void AluLoad::ejecutar() {
  if (memoriaDatos_) {
    if (operando_[0] == '=') {
      int dato = std::stoi(operando_.substr(1));
      memoriaDatos_->setDatoMemoria(0, dato);
    } else {
      int dato = memoriaDatos_->getDatoMemoria(std::stoi(operando_));
      memoriaDatos_->setDatoMemoria(0, dato);
    }
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluStore.
 * 
 * @param operando Dirección de memoria en la que se almacenará el dato del registro 0.
 * @return AluStore
 */
void AluStore::ejecutar() {
  if (memoriaDatos_) {
    if (operando_[0] == '=') {
      throw std::invalid_argument("No se puede almacenar en una dirección de memoria constante");
    } else {
      int dato = memoriaDatos_->getDatoMemoria(0);
      memoriaDatos_->setDatoMemoria(std::stoi(operando_), dato);
    }
  }
  return;
}