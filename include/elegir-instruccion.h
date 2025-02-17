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
 * @file elegir-instruccion.h: archivo que contiene la cabecera de la clase ElegirInstruccion
 * @brief Contiene la cabecera de la clase ElegirInstruccion del programa que implementa una RAM.
 */

#include "alu/unidad-alu.h"
#include "../include/memoria-datos.h"
#include "../include/unidad-entrada.h"
#include "../include/unidad-salida.h"

#ifndef ELEGIR_INSTRUCCION_H
#define ELEGIR_INSTRUCCION_H

/**
 * @class ElegirInstruccion
 * @brief Clase que implementa la elección de la instrucción a ejecutar.
 */
class ElegirInstruccion {
 public: 
  ElegirInstruccion(const std::string& instruccion, 
                    MemoriaDatos* memoria, 
                    UnidadEntrada* unidadEntrada = nullptr, 
                    UnidadSalida* unidadSalida = nullptr, 
                    MemoriaPrograma* memoriaPrograma = nullptr);
  void ejecutar();
 private:
  UnidadALU* instruccion_ = nullptr;
};

#endif