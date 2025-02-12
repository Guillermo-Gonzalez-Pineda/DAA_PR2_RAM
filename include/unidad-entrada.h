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
 * @file unidad-entrada.h: archivo que contiene la cabecera de la clase UnidadEntrada
 * @brief Contiene la cabecera de la clase UnidadEntrada del programa que implementa una RAM.
 */

#include <queue>
#include <string>

#ifndef UNIDAD_ENTRADA_H
#define UNIDAD_ENTRADA_H

/**
 * @class UnidadEntrada
 * @brief Clase que gestiona la entrada de datos desde la cinta de entrada.
 */
class UnidadEntrada {
 public:
  UnidadEntrada(const std::string& nombreFichero);
  ~UnidadEntrada() {}
  int leerDatoEntrada();
  bool entradaVacia() const { return unidadEntrada_.empty(); }
 private:
  std::queue<int> unidadEntrada_;
};

#endif