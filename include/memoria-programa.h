#include <vector>
#include <string>

class MemoriaPrograma {
 public:
  MemoriaPrograma(std::string nombreFichero);
  ~MemoriaPrograma();
  std::string leerInstruccion(int direccion);
 private:
  std::vector<std::string> memoriaPrograma_;
  int programCounter_;
};