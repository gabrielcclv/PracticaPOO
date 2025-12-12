#include "item.hpp"
#include "book.hpp"
#include "journal.hpp"
#include "thesis.hpp"
#include <iostream>
#include <string>

using namespace std;

// Item Implementation
Item::Item(int id, string tipo, string titulo, string autor, int year, string genero, string editorial)
    : id(id), tipo(tipo), titulo(titulo), autor(autor), year(year), genero(genero), editorial(editorial) {}

Item::~Item() {}

int Item::getId() {
  return id;
}

string Item::getTipo() {
  return tipo;
}

string Item::getTitulo() {
  return titulo;
}

string Item::getGenero() {
  return genero;
}

string Item::getAutor() {
  return autor;
}

int Item::getYear() {
  return year;
}

string Item::getEditorial() {
  return editorial;
}

// Setters
string& Item::setTitulo() {
  return titulo;
}

int &Item::setYear() {
  return year;
}

string& Item::setAutor() {
  return autor;
}

string& Item::setGenero() {
  return genero;
}

string& Item::setEditorial() {
  return editorial;
}