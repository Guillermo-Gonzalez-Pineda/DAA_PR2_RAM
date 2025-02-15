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
 * @date 14/02/2025
 * @file alu-div.h: archivo que contiene la cabecera de la clase AluDiv
 * @brief Contiene la cabecera de la clase AluDiv que implementa la operación DIV de la ALU.
 */

#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_DIV_H
#define ALU_DIV_H

/**
 * @class AluDiv
 * @brief Clase que implementa la operación DIV de la ALU.
 * 
 */
class AluDiv : public UnidadALU {
 public:
  AluDiv(int operando) : operando_(operando) {}
  void ejecutar() override;
 private:
  int operando_;
};

#endif