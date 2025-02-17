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
 * @file alu.cc: archivo que contiene la implementacion de la clase ElegirInstruccion
 * @brief Contiene la implementacion de la clase ElegirInstruccion del programa que implementa una RAM.
 */

#include "../include/elegir-instruccion.h"
#include "../include/alu/unidad-alu.h"
#include "../include/alu/alu-add.h"
#include "../include/alu/alu-sub.h"
#include "../include/alu/alu-div.h"
#include "../include/alu/alu-mul.h"
#include "../include/alu/alu-jump.h"
#include "../include/alu/alu-jzero.h"
#include "../include/alu/alu-jgtz.h"
#include "../include/alu/alu-load.h"
#include "../include/alu/alu-store.h"
#include "../include/alu/alu-read.h"
#include "../include/alu/alu-write.h"

/**
 * @brief Constructor de la clase ElegirInstruccion.
 *
 * Este constructor analiza la cadena de instrucción dada, identifica el tipo de instrucción
 * y crea una instancia de la operación correspondiente. Luego, enlaza la instrucción con 
 * las unidades de memoria, entrada y salida.
 *
 * @param cadenaInstruccion Cadena de texto que contiene la instrucción a procesar.
 * @param memoria Puntero a la memoria de datos.
 * @param unidadEntrada Puntero a la unidad de entrada.
 * @param unidadSalida Puntero a la unidad de salida.
 * @param memoriaPrograma Puntero a la memoria del programa.
 */
ElegirInstruccion::ElegirInstruccion(const std::string& cadenaInstruccion, MemoriaDatos* memoria, UnidadEntrada* unidadEntrada, UnidadSalida* unidadSalida, MemoriaPrograma* memoriaPrograma) {
  std::string instruccion = "", operando = "";
  bool leyendoInstruccion = true;
  for (size_t i = 0; i < cadenaInstruccion.size(); i++) {
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
  if (instruccion == "add" || instruccion == "ADD") {
    instruccion_ = new AluAdd(operando);
  }
  else if (instruccion == "sub" || instruccion == "SUB") {
    instruccion_ = new AluSub(operando);
  }
  else if (instruccion == "div" || instruccion == "DIV") {
    instruccion_ = new AluDiv(operando);
  }
  else if (instruccion == "mul" || instruccion == "MUL") {
    instruccion_ = new AluMul(operando);
  }
  else if (instruccion == "jump" || instruccion == "JUMP") {
    instruccion_ = new AluJump(operando);
  }
  else if (instruccion == "jzero" || instruccion == "JZERO") {
    instruccion_ = new AluJzero(operando);
  }
  else if (instruccion == "jgtz" || instruccion == "JGTZ") {
    instruccion_ = new AluJgtz(operando);
  }
  else if (instruccion == "load" || instruccion == "LOAD") {
    instruccion_ = new AluLoad(operando);
  }
  else if (instruccion == "store" || instruccion == "STORE") {
    instruccion_ = new AluStore(operando);
  }
  else if (instruccion == "read" || instruccion == "READ") {
    instruccion_ = new AluRead(operando);
  }
  else if (instruccion == "write" || instruccion == "WRITE") {
    instruccion_ = new AluWrite(operando);
  }
  if (instruccion_) {
    instruccion_->setMemoriaDatos(memoria);
    instruccion_->setUnidadEntrada(unidadEntrada);
    instruccion_->setUnidadSalida(unidadSalida);
    instruccion_->setMemoriaPrograma(memoriaPrograma);
  }
}

/**
 * @brief Ejecuta la instrucción seleccionada.
 *
 * Si la instrucción ha sido correctamente creada, se ejecuta su operación correspondiente.
 */
void ElegirInstruccion::ejecutar() { 
  if (instruccion_) {
    instruccion_->ejecutar();
  }
}