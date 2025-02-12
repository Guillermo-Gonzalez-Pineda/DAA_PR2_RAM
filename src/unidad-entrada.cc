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
 * @file unidad-entrada.cc: archivo que contiene la implementacion de la clase UnidadEntrada
 * @brief Contiene la implementacion de la clase UnidadEntrada del programa que implementa una RAM.
 */

#include "../include/unidad-entrada.h"

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

/**
 * @brief Constructor que lee un archivo y almacena sus datos en una cola.
 * @param nombreFichero Nombre del archivo de entrada.
 * @throws std::runtime_error Si el archivo no se puede abrir.
 */
UnidadEntrada::UnidadEntrada(const std::string& nombreFichero) {
  std::ifstream fichero(nombreFichero, std::ios::in);
  if (!fichero) {
    throw std::runtime_error("Error: No se ha podido abrir el archivo de entrada.");
  }
  int dato;
  while (fichero >> dato) {
    unidadEntrada_.push(dato);
  }
  fichero.close();
  return;
}

/**
 * @brief Extrae y devuelve el primer dato de la cola de entrada.
 * @return El dato leído.
 * @throws std::runtime_error Si la cola está vacía.
 */
int UnidadEntrada::leerDatoEntrada() { 
  int dato = unidadEntrada_.front();
  unidadEntrada_.pop();           
  return dato;
}
