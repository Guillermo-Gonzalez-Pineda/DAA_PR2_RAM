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
 * @file alu-jzero.h: archivo que contiene la cabecera de la clase AluJzero
 * @brief Contiene la cabecera de la clase AluJzero que implementa la operación JZERO de la ALU.
 */

#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_JZERO_H
#define ALU_JZERO_H

/**
 * @class AluJzero
 * @brief Clase que implementa la operación JZERO de la ALU.
 * 
 */
class AluJzero : public UnidadALU {
 public:
  AluJzero(const std::string& etiqueta) : etiqueta_(etiqueta) {}
  void ejecutar() override;
 private:
  std::string etiqueta_;
};

#endif