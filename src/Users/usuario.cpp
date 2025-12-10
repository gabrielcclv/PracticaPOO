#include "usuario.hpp"

// Usuario Implementation
Usuario::Usuario(int id, string nombre, string rol, double sancion,
                 bool bloqueado)
    : id(id), nombre(nombre), rol(rol), sancion(sancion), bloqueado(bloqueado) {
}

Usuario::~Usuario() {}

// Prestamo Implementation
Prestamo::Prestamo(int id, int idUsuario, int idItem,
                   chrono::system_clock::time_point fechaInicio,
                   chrono::system_clock::time_point fechaLimite,
                   chrono::system_clock::time_point fechaDevolucion,
                   int sancionAcumulada, bool devuelto)
    : id(id), idUsuario(idUsuario), idItem(idItem), fechaInicio(fechaInicio),
      fechaLimite(fechaLimite), fechaDevolucion(fechaDevolucion),
      sancionAcumulada(sancionAcumulada), devuelto(devuelto) {}

Prestamo::~Prestamo() {}

void Prestamo::returnItem() {
  // Basic implementation
  devuelto = true;
  fechaDevolucion = chrono::system_clock::now();
}

void Prestamo::loanItem() {
  // Basic implementation
  devuelto = false;
  fechaInicio = chrono::system_clock::now();
}
