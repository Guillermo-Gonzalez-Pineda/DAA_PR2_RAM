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
 * @file unidad-alu.h: archivo que contiene la cabecera de la clase UnidadALU
 * @brief Contiene la cabecera de la clase UnidadALU del programa que implementa una RAM.
 */

#include <string>
#include "../memoria-datos.h"
#include "../unidad-entrada.h"
#include "../unidad-salida.h"
#include "../memoria-programa.h"

#ifndef UNIDAD_ALU_H
#define UNIDAD_ALU_H

/**
 * @class UnidadALU
 * @brief Clase que implementa las operaciones de la ALU.
 * 
 */
class UnidadALU {
 public:
  virtual void ejecutar() = 0;
  void setMemoriaDatos(MemoriaDatos* memoriaDatos) { memoriaDatos_ = memoriaDatos; }
  void setUnidadEntrada(UnidadEntrada* unidadEntrada) { unidadEntrada_ = unidadEntrada; }
  void setUnidadSalida(UnidadSalida* unidadSalida) { unidadSalida_ = unidadSalida; }
  void setMemoriaPrograma(MemoriaPrograma* memoriaPrograma) { memoriaPrograma_ = memoriaPrograma; }
  virtual ~UnidadALU() {}

 protected:
  MemoriaDatos* memoriaDatos_ = nullptr;
  UnidadEntrada* unidadEntrada_ = nullptr;
  UnidadSalida* unidadSalida_ = nullptr;
  MemoriaPrograma* memoriaPrograma_ = nullptr;
};

#endif