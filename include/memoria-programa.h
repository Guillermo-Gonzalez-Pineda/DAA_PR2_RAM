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
 * @file memoria-programa.h: archivo que contiene la cabecera de la clase MemoriaPrograma
 * @brief Contiene la cabecera de la clase MemoriaPrograma del programa que implementa una RAM.
 */

#include <vector>
#include <string>

#ifndef MEMORIA_PROGRAMA_H
#define MEMORIA_PROGRAMA_H

/**
 * @brief Clase que representa la memoria de un programa almacenado en un archivo.
 * 
 * Esta clase permite cargar un programa desde un archivo de texto y leer sus 
 * instrucciones secuencialmente.
 */
class MemoriaPrograma {
 public:
  MemoriaPrograma(const std::string& nombreFichero);
  ~MemoriaPrograma() {}
  std::string leerInstruccion();
 private:
  std::vector<std::string> memoriaPrograma_;
  int programCounter_;
};

#endif