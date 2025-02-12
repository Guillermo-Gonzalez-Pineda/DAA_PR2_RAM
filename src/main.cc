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
 * @file main.cc: archivo main
 * @brief Contiene el main del programa que implementa una RAM
 */

#include "../include/unidad-entrada.h"
#include "../include/unidad-salida.h"

#include <iostream>

int main() {
  UnidadEntrada entrada("input/entrada.txt");
  UnidadSalida salida("output/salida.txt");
  while (!entrada.entradaVacia()) {
    salida.guardarDatoSalida(entrada.leerDatoEntrada());
  }
  salida.exportarCintaSalida();
  return 0;
}