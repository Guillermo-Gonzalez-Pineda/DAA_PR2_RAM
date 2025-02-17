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
#include <cstdlib>
#include <iomanip>

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
  registros_ = 0;

  std::ifstream fichero(ficheroPrograma, std::ios::in);
  if (!fichero) {
    throw std::runtime_error("Error: No se ha podido abrir el archivo del programa.");
  }

  std::string linea = "", instruccion = "", etiqueta = "";
  int lineaActual = 0;

  while (std::getline(fichero, linea)) {
    // Ignoramos los comentarios
    if (linea[0] == '#') {
      continue;
    }

    linea.erase(std::remove(linea.begin(), linea.end(), '\t'), linea.end());
    if (!linea.empty()) {
      etiqueta = "";
      size_t pos = linea.find(":");

      if (pos != std::string::npos) {
        etiqueta = linea.substr(0, pos);
        etiquetas_[etiqueta] = lineaActual;
        linea = linea.substr(pos + 1);
      }

      if (!linea.empty()) {
        memoriaPrograma_.push_back(linea);
        
        // Buscamos el número de registros
        size_t pos = linea.find(" ");   // Buscamos el espacio
        if (pos != std::string::npos) {   // Si hay espacio, entonces
          std::string operando = linea.substr(pos + 1);  // Guardamos el operando
          if (std::all_of(operando.begin(), operando.end(), ::isdigit)) {  // Comprobamos que el operando sean solo digitos
            registros_ = std::max(registros_, std::stoi(operando)); // Guardamos el máximo de registros
          }
        }

        lineaActual++;
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
  if (programCounter_ >= memoriaPrograma_.size()) {
    throw std::runtime_error("Error: Fin del programa alcanzado.");
  }

  return memoriaPrograma_[programCounter_++];
}

/**
 * @brief Salta a la instrucción con la etiqueta dada.
 * 
 * @param etiqueta Nombre de la etiqueta a la que saltar.
 * @throw std::runtime_error Si la etiqueta no existe.
 */
void MemoriaPrograma::saltarEtiqueta(const std::string& etiqueta) {
  std::string etiqueta2 = etiqueta;
  etiqueta2.erase(std::remove(etiqueta2.begin(), etiqueta2.end(), '\r'), etiqueta2.end());
  etiqueta2.erase(std::remove(etiqueta2.begin(), etiqueta2.end(), '\n'), etiqueta2.end());
  if (etiquetas_.find(etiqueta2) == etiquetas_.end()) {
    throw std::runtime_error("Error: Etiqueta no encontrada.");
  }
  programCounter_ = etiquetas_[etiqueta2];
  return;
}