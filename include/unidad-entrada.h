#include <queue>
#include <string>

class UnidadEntrada {
 public:
  UnidadEntrada(const std::string& nombreFichero);
  ~UnidadEntrada() {}
  int leerDatoEntrada();
  bool entradaVacia() const { return unidadEntrada_.empty(); }
 private:
  std::queue<int> unidadEntrada_;
};