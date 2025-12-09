#ifndef USUARIO_HPP
#define USUARIO_HPP
#include "catalogo.hpp"
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
  int getIdUsuario() { return id; }
  string getNombre() { return nombre; }
  string getRol() { return rol; }

  // Metodos
};

class Prestamo : public Usuario, public Item {
private:
  int id;
  chrono::system_clock::time_point fechaLimite;
  chrono::system_clock::time_point fechaInicio;
  chrono::system_clock::time_point fechaDevolucion;
  int sancionAcumulada;
  bool devuelto;

public:
  void returnItem();
  void loanItem();

  chrono::system_clock::time_point getFechaLimite() { return fechaLimite; }
  chrono::system_clock::time_point getFechaDevolucion() { return fechaDevolucion; }
  chrono::system_clock::time_point getFechaInicio() { return fechaInicio; }
  int getSancionAcumulada() { return sancionAcumulada; }
  int getIdPrestamo() { return id; }
  bool getDevuelto() { return devuelto; }
};

#endif