#include "usuario.hpp"
#include <iostream>

// Usuario Implementation
Usuario::Usuario(int id, string nombre, string rol, double sancion, bool bloqueado)
    : id(id), nombre(nombre), rol(rol), sancion(sancion), bloqueado(bloqueado) {
}

Usuario::~Usuario() {}

int Usuario::getIdUsuario() {
  return id;
}

string Usuario::getNombre() {
  return nombre;
}

string Usuario::getRol() {
  return rol;
}

void Usuario::blockUser() {
    bloqueado = true;
}

void Usuario::unblockUser() {
    bloqueado = false;
}

int Usuario::getSancion() {
  return sancion;
}

bool Usuario::isBloqueado() {
  return bloqueado;
}

void Usuario::sumarSancion(double monto) {
  sancion += monto;

  // C3: Si la sancion supera 10, bloquear al usuario
  if (sancion > 10.0) {
        blockUser();
        cout << "Usuario " << nombre << " ha sido bloqueado por sancion mayor a 10." << endl;
}
}