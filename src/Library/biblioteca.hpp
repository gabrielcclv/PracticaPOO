#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "../Items/item.hpp"
#include "../Users/usuario.hpp"
#include <vector>

using namespace std;

class Biblioteca {
private:
  vector<Item *> items; // Was items in step 8, but step 47 showed only
                        // usuarios/prestamos? Wait.
  // Step 47 showed: vector<Usuario *> usuarios; vector<Prestamo *> prestamos;
  // Step 8 (original) showed: vector<Item *> items; vector<Usuario *> usuarios;
  // vector<Prestamo *> prestamos; Biblioteca needs items! addItem() takes
  // Item*. I should define items vector.
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

  void cargarDatos() {
    cargarUsuariosCSV("data/usuarios.csv");
    cargarMaterialesCSV("data/catalogo.csv");
    cargarPrestamosCSV("data/prestamos.csv");
  }

  void guardarUsuariosCSV(string ruta);
  void guardarMaterialesCSV(string ruta);
  void guardarPrestamosCSV(string ruta);
};
#endif