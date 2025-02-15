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
 * @file alu-jgtz.h: archivo que contiene la cabecera de la clase AluJgtz
 * @brief Contiene la cabecera de la clase AluJgtz que implementa la operación JGTZ de la ALU.
 */

#include "unidad-alu.h"

#include <iostream>

#ifndef ALU_JGTZ_H
#define ALU_JGTZ_H

/**
 * @class AluJgtz
 * @brief Clase que implementa la operación JGTZ de la ALU.
 * 
 */
class AluJgtz : public UnidadALU {
 public:
  AluJgtz(const std::string& etiqueta) : etiqueta_(etiqueta) {}
  void ejecutar() override;
 private:
  std::string etiqueta_;
};

#endif