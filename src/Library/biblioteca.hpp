#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "../Items/item.hpp"
#include "../Users/usuario.hpp"
#include "../catalog.hpp"
#include <vector>
#include <string>

using namespace std;

class Biblioteca {
private:
  vector<Usuario *> usuarios;
  vector<Prestamo *> prestamos;

  Catalogo catalogo;

public:
  // Constructor
  Biblioteca();
  // Destructor
  ~Biblioteca();
  // Metodos

  void addUsuario(Usuario *usuario);
  void removeUsuario(Usuario *usuario);
  void addPrestamo(Prestamo *prestamo);
  void removePrestamo(Prestamo *prestamo);

  // Metodos de datos
  void cargarUsuariosCSV(string ruta);
  void cargarPrestamosCSV(string ruta);

  static vector <string>splitCSV(const string &linea);
  static string unescapeCSV(string campo);

  void cargarDatos() {
    cargarUsuariosCSV("data/usuarios.csv");
    catalogo.cargarMaterialesCSV("data/catalogo.csv");
    cargarPrestamosCSV("data/prestamos.csv");
  }

  void guardarUsuariosCSV(string ruta);
  void guardarMaterialesCSV(string ruta);
  void guardarPrestamosCSV(string ruta);
  
  Catalogo &getCatalogo();
};
#endif