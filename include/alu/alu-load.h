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
 * @file alu-load.h: archivo que contiene la cabecera de la clase AluLoad
 * @brief Contiene la cabecera de la clase AluLoad que implementa la operación LOAD de la ALU.
 */

#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_LOAD_H
#define ALU_LOAD_H

/**
 * @class AluLoad
 * @brief Clase que implementa la operación LOAD de la ALU.
 * 
 */
class AluLoad : public UnidadALU {
 public:
  AluLoad(const std::string& operando) : operando_(operando) {}
  void ejecutar() override;
 private:
  std::string operando_;
};

#endif