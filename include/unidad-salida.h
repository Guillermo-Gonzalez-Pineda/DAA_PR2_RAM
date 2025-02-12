#include <vector>
#include <string>

class UnidadSalida {
 public:
  UnidadSalida(std::string nombreFichero);
  ~UnidadSalida();
  void setDatoSalida(int dato);
 private:
  std::vector<int> unidadSalida_;
};