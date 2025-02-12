 # Universidad de La Laguna
 # Escuela Superior de Ingeniería y Tecnología
 # Grado en Ingeniería Informática
 # Informática Básica
 #
 # @author Daniel Carbonell González de Chaves
 # @email alu0101578064@ull.edu.es
 # @author Guillermo González Pineda
 # @email alu0101574899@ull.edu.es
 # @date 12/02/2025
 # @brief Archivo make que compila el programa presente en el directorio. 

# Nombre del archivo ejecutable
TARGET = RAM

# Compilador de C++
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -w

# Archivos fuente
SOURCES = src/main.cc src/unidad-entrada.cc src/unidad-salida.cc

# Archivos objeto generados durante la compilación
OBJECTS = $(SOURCES:.cc=.o)

# Reglas para la construcción del programa
$(TARGET): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "El programa ha sido compilado con éxito."	

# Reglas para la generación de archivos objeto
%.o: %.cc
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados durante la compilación
clean:
	@rm -f $(TARGET) $(OBJECTS) fileout.txt
	@echo "El programa y los archivos objeto han sido borrados con éxito."