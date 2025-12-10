#ifndef PRESTAMOS_HPP
#define PRESTAMOS_HPP

#include <chrono>

using namespace std;

class Prestamos {
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
  Prestamos(int id, int idUsuario, int idItem, chrono::system_clock::time_point fechaInicio, chrono::system_clock::time_point fechaLimite, chrono::system_clock::time_point fechaDevolucion, int sancionAcumulada, bool devuelto);

  // Destructor
  ~Prestamos();

  // Metodos
  void returnItem();
  void loanItem();

  chrono::system_clock::time_point getFechaLimite();
  chrono::system_clock::time_point getFechaDevolucion();
  chrono::system_clock::time_point getFechaInicio();
  int getSancionAcumulada();
  int getIdPrestamo();
  int getIdUsuario();
  int getIdItem();
  bool getDevuelto();
};

#endif