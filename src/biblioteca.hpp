#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include "catalogo.hpp"
#include "usuario.hpp"
#include <vector>

class Biblioteca {
private:
  vector<Item *> items;
  vector<Usuario *> usuarios;
  vector<Prestamo *> prestamos;

public:
  // Constructor
  Biblioteca();
  // Destructor
  ~Biblioteca();
  // Metodos
  void addItem(Item *item);
  void removeItem(Item *item);
  void addUsuario(Usuario *usuario);
  void removeUsuario(Usuario *usuario);
  void addPrestamo(Prestamo *prestamo);
  void removePrestamo(Prestamo *prestamo);

// Metodos de datos
void cargarUsuariosCSV(string ruta);
void cargarMaterialesCSV(string ruta);
void cargarPrestamosCSV(string ruta);

void guardarUsuariosCSV(string ruta);
void guardarMaterialesCSV(string ruta);
void guardarPrestamosCSV(string ruta);

};
#endif