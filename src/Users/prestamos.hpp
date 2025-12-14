#ifndef PRESTAMOS_HPP
#define PRESTAMOS_HPP

#include <chrono>
#include "usuario.hpp"

using namespace std;

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
  Usuario* usuario;
public:
  // Constructor
  Prestamo(int id, int idUsuario, int idItem, chrono::system_clock::time_point fechaInicio, chrono::system_clock::time_point fechaLimite, chrono::system_clock::time_point fechaDevolucion, int sancionAcumulada, bool devuelto);

  // Destructor
  ~Prestamo();


  chrono::system_clock::time_point getFechaLimite();
  chrono::system_clock::time_point getFechaDevolucion();
  chrono::system_clock::time_point getFechaInicio();
  int getSancionAcumulada();
  int getIdPrestamo();
  int getIdUsuario();
  int getIdItem();
  bool getDevuelto();

  void setDevuelto(bool estado);
  void setFechaDevolucion(chrono::system_clock::time_point fecha);
  void setSancionAcumulada(int sancion);
};

#endif