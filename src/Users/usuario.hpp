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

  // Metodos
  void blockUser();
  void unblockUser();
  void blockUserPorLista();
  void unblockUserPorLista();
};

class Prestamo {
private:
  int id;
  int idUsuario;
  int idItem;
  chrono::system_clock::time_point fechaLimite;
  chrono::system_clock::time_point fechaInicio;
  chrono::system_clock::time_point fechaDevolucion;
  int sancionAcumulada;
  bool devuelto;

public:
  // Constructor
  Prestamo(int id, int idUsuario, int idItem, chrono::system_clock::time_point fechaInicio, chrono::system_clock::time_point fechaLimite, chrono::system_clock::time_point fechaDevolucion, int sancionAcumulada, bool devuelto);

  // Destructor
  ~Prestamo();

  // Metodos
  void returnItem();
  void loanItem();

  chrono::system_clock::time_point getFechaLimite() { return fechaLimite; }
  chrono::system_clock::time_point getFechaDevolucion() { return fechaDevolucion; }
  chrono::system_clock::time_point getFechaInicio() { return fechaInicio; }
  int getSancionAcumulada() { return sancionAcumulada; }
  int getIdPrestamo() { return id; }
  int getIdUsuario() { return idUsuario; }
  int getIdItem() { return idItem; }
  bool getDevuelto() { return devuelto; }
};

#endif