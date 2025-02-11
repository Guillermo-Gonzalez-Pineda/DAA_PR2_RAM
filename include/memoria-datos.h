#include <vector>
#include <string>

class MemoriaDatos {
  public:
    MemoriaDatos(std::string nombreFichero);
    ~MemoriaDatos();
    void setDato(int direccion, int dato);
    int getDato(int direccion) const;
  private:
    std::vector<int> memoriaDatos_;
};