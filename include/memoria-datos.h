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
 * @file memoria-datos.h: archivo que contiene la cabecera de la clase MemoriaDatos
 * @brief Contiene la cabecera de la clase MemoriaDatos del programa que implementa una RAM.
 */

#include <vector>

#ifndef MEMORIA_DATOS_H
#define MEMORIA_DATOS_H

class MemoriaDatos {
 public:
  MemoriaDatos() {}
  ~MemoriaDatos() {}
  void setDatoMemoria(int direccion, int dato) { memoriaDatos_[direccion] = dato; return; }
  int getDatoMemoria(int direccion) const { return memoriaDatos_[direccion]; }
 private:
  std::vector<int> memoriaDatos_;
};

#endif