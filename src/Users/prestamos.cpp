#include "prestamos.hpp"

void Prestamos::returnItem() {
    devuelto = true;
    fechaDevolucion = chrono::system_clock::now(); 
}

void Prestamos::loanItem() {
    devuelto = false;
    fechaInicio = chrono::system_clock::now();
}

chrono::system_clock::time_point Prestamos::getFechaLimite() {
  return fechaLimite;
}

chrono::system_clock::time_point Prestamos::getFechaDevolucion() {
  return fechaDevolucion;
}

chrono::system_clock::time_point Prestamos::getFechaInicio() {
  return fechaInicio;
}

int Prestamos::getSancionAcumulada() {
  return sancionAcumulada;
}

int Prestamos::getIdPrestamo() {
  return id;
}

int Prestamos::getIdUsuario() {
  return idUsuario;
}

int Prestamos::getIdItem() {
  return idItem;
}

bool Prestamos::getDevuelto() {
  return devuelto;
}

Prestamos::Prestamos(int id, int idUsuario, int idItem, chrono::system_clock::time_point fechaInicio, chrono::system_clock::time_point fechaLimite, chrono::system_clock::time_point fechaDevolucion, int sancionAcumulada, bool devuelto)
    : id(id), idUsuario(idUsuario), idItem(idItem), fechaInicio(fechaInicio), fechaLimite(fechaLimite), fechaDevolucion(fechaDevolucion), sancionAcumulada(sancionAcumulada), devuelto(devuelto) {}