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
 * @file unidad-salida.h: archivo que contiene la cabecera de la clase UnidadSalida
 * @brief Contiene la cabecera de la clase UnidadSalida del programa que implementa una RAM.
 */

#include <queue>
#include <string>

#ifndef UNIDAD_SALIDA_H
#define UNIDAD_SALIDA_H

/**
 * @class UnidadSalida
 * @brief Clase que gestiona la salida de datos a un archivo.
 */
class UnidadSalida {
 public:
  UnidadSalida(const std::string& nombreFichero) : ficheroSalida_(nombreFichero) {}
  ~UnidadSalida() {}
  void guardarDatoSalida(int dato);
  void exportarCintaSalida();
 private:
  std::queue<int> unidadSalida_;
  std::string ficheroSalida_;
};

#endif