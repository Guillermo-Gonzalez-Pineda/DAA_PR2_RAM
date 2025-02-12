#include <vector>
#include <string>

class MemoriaDatos {
 public:
  MemoriaDatos(std::string nombreFichero);
  ~MemoriaDatos();
  void setDatoMemoria(int direccion, int dato);
  int getDatoMemoria(int direccion) const;
 private:
  std::vector<int> memoriaDatos_;
};