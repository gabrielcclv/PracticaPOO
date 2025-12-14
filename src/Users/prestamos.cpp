#include "prestamos.hpp"

using namespace std;

Prestamo::~Prestamo() {}

chrono::system_clock::time_point Prestamo::getFechaLimite() {
  return fechaLimite;
}

chrono::system_clock::time_point Prestamo::getFechaDevolucion() {
  return fechaDevolucion;
}

chrono::system_clock::time_point Prestamo::getFechaInicio() {
  return fechaInicio;
}

int Prestamo::getSancionAcumulada() {
  return sancionAcumulada;
}

int Prestamo::getIdPrestamo() {
  return id;
}

int Prestamo::getIdUsuario() {
  return idUsuario;
}

int Prestamo::getIdItem() {
  return idItem;
}

bool Prestamo::getDevuelto() {
  return devuelto;
}

Prestamo::Prestamo(int id, int idUsuario, int idItem, chrono::system_clock::time_point fechaInicio, chrono::system_clock::time_point fechaLimite, chrono::system_clock::time_point fechaDevolucion, int sancionAcumulada, bool devuelto)
    : id(id), idUsuario(idUsuario), idItem(idItem), fechaInicio(fechaInicio), fechaLimite(fechaLimite), fechaDevolucion(fechaDevolucion), sancionAcumulada(sancionAcumulada), devuelto(devuelto) {}

void Prestamo::setDevuelto(bool estado) {
  devuelto = estado;
}

void Prestamo::setFechaDevolucion(chrono::system_clock::time_point fecha) {
  fechaDevolucion = fecha;
}

void Prestamo::setSancionAcumulada(int sancion) {
  sancionAcumulada = sancion;
}