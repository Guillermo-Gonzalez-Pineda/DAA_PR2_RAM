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
 * @file unidad-salida.cc: archivo que contiene la implementacion de la clase UnidadSalida
 * @brief Contiene la implementacion de la clase UnidadSalida del programa que implementa una RAM.
 */

#include "../include/unidad-salida.h"

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

/**
 * @brief Almacena un dato en la cola de salida.
 * @param dato Dato que se agregará a la cola.
 */
void UnidadSalida::guardarDatoSalida(int dato) { 
  unidadSalida_.push(dato);
  return;
}

/**
 * @brief Exporta los datos almacenados en la cola al archivo de salida.
 * @throws std::runtime_error Si no se puede abrir el archivo de salida.
 */
void UnidadSalida::exportarCintaSalida() { 
  std::ofstream fichero(ficheroSalida_);
  if (!fichero) {
    throw std::runtime_error("Error: No se ha podido abrir el archivo de salida.");
  }
  while (!unidadSalida_.empty()) {
    fichero << unidadSalida_.front() << " ";
    unidadSalida_.pop();
  }
  fichero.close();
  return;
}

/**
 * @brief Escribe en el fichero de salida el dato que se le pasa.
 * @param dato Dato que se agregará a la cola.
 */
void UnidadSalida::escribirDatoSalida(int dato) {
  std::ofstream fichero(ficheroSalida_, std::ios::app);
  if (!fichero) {
    throw std::runtime_error("Error: No se ha podido abrir el archivo de salida.");
  }
  fichero << dato << " ";
  fichero.close();
  return;
}
