#include "biblioteca.hpp"
#include <chrono>
#include <algorithm>

void Biblioteca::addItem(Item* item){
    items.push_back(item);
}

void Biblioteca::removeItem(Item* item){
    items.remove(item);
}

void Biblioteca::addUsuario(Usuario* usuario){
    usuarios.push_back(usuario);
}

void Biblioteca::removeUsuario(Usuario* usuario){
    usuarios.remove(usuario);
}

void Biblioteca::addPrestamo(Prestamo* prestamo){
    prestamos.push_back(prestamo);
}

void Biblioteca::removePrestamo(Prestamo* prestamo){
    prestamos.remove(prestamo);
}