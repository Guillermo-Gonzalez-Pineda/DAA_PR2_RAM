/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 3º
 * Práctica 2: Experimentación y complejidad computacional
 * @autor Daniel Carbonell González de Chaves
 * @email alu0101578064@ull.edu.es
 * @autor Guillermo González Pineda
 * @email alu0101574899@ull.edu.es
 * @date 12/02/2025
 * @file alu.cc: archivo que contiene la implementacion de la clase UnidadAlu y sus subclases
 * @brief Contiene la implementacion de la clase UnidadAlu y sus subclases del programa que implementa una RAM.
 */

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
#include "../include/alu/alu-mod.h"

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
    } 
    else if (operando_[0] == '*') {
      suma = std::stoi(operando_.substr(1));
      suma = memoriaDatos_->getDatoMemoria(suma);
      suma = memoriaDatos_->getDatoMemoria(suma);
    } 
    else {
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
      } 
      else {
        std::cout << "Error en la linea: " << + memoriaPrograma_->lineaError() << std::endl;
        throw std::invalid_argument("No se puede dividir por cero");
      }
    } 
    else if (operando_[0] == '*') {
      divisor = std::stoi(operando_.substr(1));
      divisor = memoriaDatos_->getDatoMemoria(divisor);
      divisor = memoriaDatos_->getDatoMemoria(divisor);
      if (divisor != 0) {
        memoriaDatos_->setDatoMemoria(0, valorRegistro0 / divisor);
      }
      else {
        std::cout << "Error en la linea: " << + memoriaPrograma_->lineaError() << std::endl;
        throw std::invalid_argument("No se puede dividir por cero");
      }
    } 
    else {
      divisor = memoriaDatos_->getDatoMemoria(std::stoi(operando_));
      if (divisor != 0) {
        memoriaDatos_->setDatoMemoria(0, valorRegistro0 / divisor);
      }
      else {
        std::cout << "Error en la linea: " << + memoriaPrograma_->lineaError() << std::endl;
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
    }
    else if (operando_[0] == '*') {
      multiplicador = std::stoi(operando_.substr(1));
      multiplicador = memoriaDatos_->getDatoMemoria(multiplicador);
      multiplicador = memoriaDatos_->getDatoMemoria(multiplicador);
    } 
    else {
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
    }
    else if (operando_[0] == '*') {
      resta = std::stoi(operando_.substr(1));
      resta = memoriaDatos_->getDatoMemoria(resta);
      resta = memoriaDatos_->getDatoMemoria(resta);
    } 
    else {
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
      std::cout << "Error en la linea: " << + memoriaPrograma_->lineaError() << std::endl;
      throw std::invalid_argument("No se puede leer de una dirección de memoria constante");
    }
    else if (operando_[0] == '*') {
      int dato = unidadEntrada_->leerDatoEntrada();
      int registro = std::stoi(operando_.substr(1));
      registro = memoriaDatos_->getDatoMemoria(registro);
      memoriaDatos_->setDatoMemoria(registro, dato);
    } 
    else {
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
    } 
    else if (operando_[0] == '*') {
      int registro = std::stoi(operando_.substr(1));
      registro = memoriaDatos_->getDatoMemoria(registro);
      if (registro == 0) {
        std::cout << "Error en la linea: " << + memoriaPrograma_->lineaError() << std::endl;
        throw std::invalid_argument("No se puede escribir un dato del registro 0.");
      }
      int dato = memoriaDatos_->getDatoMemoria(registro);
      unidadSalida_->guardarDatoSalida(dato);
    } 
    else {
      if (std::stoi(operando_) == 0) {
        std::cout << "Error en la linea: " << + memoriaPrograma_->lineaError() << std::endl;
        throw std::invalid_argument("No se puede escribir un dato del registro 0.");
      }
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
    }
    else if (operando_[0] == '*') {
      int registro = std::stoi(operando_.substr(1));
      registro = memoriaDatos_->getDatoMemoria(registro);
      int dato = memoriaDatos_->getDatoMemoria(registro);
      memoriaDatos_->setDatoMemoria(0, dato);
    } 
    else {
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
      std::cout << "Error en la linea: " << + memoriaPrograma_->lineaError() << std::endl;
      throw std::invalid_argument("No se puede almacenar en una dirección de memoria constante");
    } 
    else if (operando_[0] == '*') {
      int registro = std::stoi(operando_.substr(1));
      registro = memoriaDatos_->getDatoMemoria(registro);
      int dato = memoriaDatos_->getDatoMemoria(0);
      memoriaDatos_->setDatoMemoria(registro, dato);
    } 
    else {
      int dato = memoriaDatos_->getDatoMemoria(0);
      memoriaDatos_->setDatoMemoria(std::stoi(operando_), dato);
    }
  }
  return;
}

/**
 * @brief Operación ejecutar de la clase AluMod
 * 
 * @param operando Operando que se calculara el modulo al registro 0.
 * @return AluMod
 */
void AluMod::ejecutar() {
  if (memoriaDatos_) {
    int valorRegistro0 = memoriaDatos_->getDatoMemoria(0);
    int modulo = 0;
    if (operando_[0] == '=') {
      modulo = std::stoi(operando_.substr(1));
    } 
    else if (operando_[0] == '*') {
      modulo = std::stoi(operando_.substr(1));
      modulo = memoriaDatos_->getDatoMemoria(modulo);
      modulo = memoriaDatos_->getDatoMemoria(modulo);
    } 
    else {
      modulo = memoriaDatos_->getDatoMemoria(std::stoi(operando_));
    }
    memoriaDatos_->setDatoMemoria(0, valorRegistro0 % modulo);
  }
  return;
}