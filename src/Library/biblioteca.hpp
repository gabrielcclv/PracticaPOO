#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "../Items/item.hpp"
#include "../Users/usuario.hpp"
#include "../catalog.hpp"
#include "../Users/prestamos.hpp"
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

  void addUser(Usuario *usuario);
  void removeUser(Usuario *usuario);
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
  vector<Usuario *> &getUsuarios();
  vector<Prestamo *> &getPrestamos();

  void printUsuarios();

  void loanItem(int idUsuario, int idItem);
  void returnItem(int idUsuario, int idItem);
};
#endif