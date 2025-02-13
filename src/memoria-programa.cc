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
 * @file memoria-programa.cc: archivo que contiene la implementacion de la clase MemoriaPrograma
 * @brief Contiene la implementacion de la clase MemoriaPrograma del programa que implementa una RAM.
 */

#include "../include/memoria-programa.h"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief Constructor de la clase MemoriaPrograma.
 * 
 * Inicializa el contador de programa y carga las instrucciones desde un fichero.
 * 
 * @param ficheroPrograma Nombre del archivo que contiene el programa a cargar.
 * @throw std::runtime_error Si no se puede abrir el archivo.
 */
MemoriaPrograma::MemoriaPrograma(const std::string& ficheroPrograma) {
  programCounter_ = 0;
  std::ifstream fichero(ficheroPrograma, std::ios::in);
  if (!fichero) {
    throw std::runtime_error("Error: No se ha podido abrir el archivo del programa.");
  }
  std::string linea = "", instruccion = "", etiqueta = "";
  while (std::getline(fichero, linea)) {
    if (linea[0] != '#') {
      linea.erase(std::remove(linea.begin(), linea.end(), '\t'), linea.end());
      if (linea != "") {
        instruccion = "";
        etiqueta = "";
        for (int i = 0; i < linea.size(); i++) {
          instruccion += linea[i];
          if (linea[i] == ':') {
            etiqueta = instruccion;
            instruccion = "";
          }
        }
        if (etiqueta != "") {
          memoriaPrograma_.push_back(etiqueta);
        }
        memoriaPrograma_.push_back(instruccion);
      }
    }
  }
  fichero.close();
  return;
}

/**
 * @brief Lee la siguiente instrucción del programa.
 * 
 * Avanza el contador del programa hasta encontrar una instrucción válida.
 * 
 * @return La instrucción leída como una cadena de texto.
 */
std::string MemoriaPrograma::leerInstruccion(){ 
  std::string instruccion = ":";
  while (instruccion[instruccion.size() - 1] == ':') {
    instruccion = memoriaPrograma_[programCounter_];
    programCounter_++;
  }
  return instruccion; 
}