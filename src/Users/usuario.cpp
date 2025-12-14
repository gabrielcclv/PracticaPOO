#include "usuario.hpp"

// Usuario Implementation
Usuario::Usuario(int id, string nombre, string rol, double sancion,
                 bool bloqueado)
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