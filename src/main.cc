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
#include "../include/memoria-datos.h"
#include "../include/memoria-programa.h"
#include "../include/elegir-instruccion.h"

#include <iostream>

int main() {
  UnidadEntrada entrada("input/entrada.txt");
  UnidadSalida salida("output/salida.txt");
  MemoriaPrograma programa("input/programa2.ram");
  while (!entrada.entradaVacia()) {
    salida.guardarDatoSalida(entrada.leerDatoEntrada());
  }
  std::string cadenaInstruccion;
  while (true) {
    cadenaInstruccion = programa.leerInstruccion();
    if (cadenaInstruccion == "halt") {
      break;
    }
    ElegirInstruccion instruccion(cadenaInstruccion);
    instruccion.ejecutar();
  }
  salida.exportarCintaSalida();
  return 0;
}