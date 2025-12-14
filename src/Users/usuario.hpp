#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <chrono>
#include <string>

using namespace std;

class Usuario {
private:
  int id;
  string nombre;
  string rol;
  double sancion;
  bool bloqueado;

public:
  // Constructor
  Usuario(int id, string nombre, string rol, double sancion, bool bloqueado);

  // Destructor
  ~Usuario();

  // Atributos
  int getIdUsuario();
  string getNombre();
  string getRol();
  int getSancion();
  bool isBloqueado();
  // Metodos
  void blockUser();
  void unblockUser();
  void blockUserPorLista();
  void unblockUserPorLista();

  void sumarSancion(double monto);
};

#endif