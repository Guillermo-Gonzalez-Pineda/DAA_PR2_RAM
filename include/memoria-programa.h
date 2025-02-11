#include <vector>
#include <string>

class MemoriaPrograma {
  public:
    MemoriaPrograma(std::string nombreFichero);
    ~MemoriaPrograma();
    std::string instruccion(int direccion);
  private:
    std::vector<std::string> memoriaPrograma_;
};