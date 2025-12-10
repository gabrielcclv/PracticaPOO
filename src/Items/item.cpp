#include "item.hpp"
#include "book.hpp"
#include "journal.hpp"
#include "thesis.hpp"
#include <iostream>
#include <string>

using namespace std;

// Item Implementation
Item::Item(int id, string tipo, string titulo, string autor, int year,
           string genero, string editorial)
    : id(id), tipo(tipo), titulo(titulo), autor(autor), year(year),
      genero(genero), editorial(editorial) {}

Item::~Item() {}

// Book Implementation
std::string Book::info() const {
  return "Book (ID: " + to_string(id) + "): " + titulo + " by " + autor;
}

void Book::printBook() { cout << info() << endl; }

// Journal Implementation
std::string Journal::info() const {
  return "Journal (ID: " + to_string(id) + "): " + titulo + " by " + autor;
}

// Thesis Implementation
std::string Thesis::info() const {
  return "Thesis (ID: " + to_string(id) + "): " + titulo + " by " + autor;
}
