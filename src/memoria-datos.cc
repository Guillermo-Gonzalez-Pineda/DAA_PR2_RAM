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
 * @file memoria-programa.cc: archivo que contiene la implementacion de la clase MemoriaDatos
 * @brief Contiene la implementacion de la clase MemoriaDatos del programa que implementa una RAM.
 */

#include "../include/memoria-datos.h"

#include <iostream>

/**
 * @brief Establece un valor en una dirección específica de la memoria de datos.
 *
 * @param direccion La dirección de memoria donde se almacenará el dato.
 * @param dato El valor que se almacenará en la dirección especificada.
 * @throws std::out_of_range Si la dirección está fuera del rango de la memoria.
 */
void MemoriaDatos::setDatoMemoria(int direccion, int dato) {
  if (direccion < 0 || direccion >= memoriaDatos_.size()) {
    throw std::out_of_range("Error: Dirección de memoria fuera de rango.");
  }
  memoriaDatos_[direccion] = dato;
}

/**
 * @brief Obtiene el valor almacenado en una dirección específica de la memoria de datos.
 *
 * @param direccion La dirección de memoria de donde se obtendrá el dato.
 * @return El valor almacenado en la dirección especificada.
 * @throws std::out_of_range Si la dirección está fuera del rango de la memoria.
 */
int MemoriaDatos::getDatoMemoria(int direccion) const {
  if (direccion < 0 || direccion >= memoriaDatos_.size()) {
    throw std::out_of_range("Error: Dirección de memoria fuera de rango.");
  }
  return memoriaDatos_[direccion];
}