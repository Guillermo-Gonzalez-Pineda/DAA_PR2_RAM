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

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Error en la ejecución. Uso: ./ram <fichero_programa> <fichero_entrada> <fichero_salida>" << std::endl;
    return 1;
  }

  std::string ficheroPrograma = argv[1];
  std::string ficheroEntrada = argv[2];
  std::string ficheroSalida = argv[3];

  MemoriaPrograma memoriaPrograma(ficheroPrograma);
  UnidadEntrada unidadEntrada(ficheroEntrada);
  UnidadSalida unidadSalida(ficheroSalida);
  int numRegistros = memoriaPrograma.getMaxRegistros();

  MemoriaDatos memoriaDatos(50);

  std::string cadenaInstruccion = "";
  while (true) {
    cadenaInstruccion = memoriaPrograma.leerInstruccion();
    if (cadenaInstruccion == "halt" || cadenaInstruccion == "HALT" || cadenaInstruccion == "HALT\r" || cadenaInstruccion == "HALT\n") {
      break;
    }
    ElegirInstruccion instruccion(cadenaInstruccion, &memoriaDatos, &unidadEntrada, &unidadSalida, &memoriaPrograma);
    instruccion.ejecutar();
  }
  unidadSalida.exportarCintaSalida();
  return 0;
}