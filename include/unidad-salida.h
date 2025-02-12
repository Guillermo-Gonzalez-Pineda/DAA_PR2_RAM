#include <queue>
#include <string>

class UnidadSalida {
 public:
  UnidadSalida(const std::string& nombreFichero) : ficheroSalida_(nombreFichero) {}
  ~UnidadSalida() {}
  void guardarDatoSalida(int dato);
  void exportarCintaSalida();
 private:
  std::queue<int> unidadSalida_;
  std::string ficheroSalida_;
};