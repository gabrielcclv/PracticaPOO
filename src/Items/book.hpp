#ifndef BOOK_HPP
#define BOOK_HPP

#include "item.hpp"

class Book : public Item {
private:
  int isbn;

public:
  Book(int id, string tipo, string titulo, string genero, string autor,
       int year, string editorial, int isbn)
      : Item(id, tipo, titulo, autor, year, genero, editorial), isbn(isbn) {}
  ~Book() {}

  void printBook();
  string info() const;

  int getIsbn();
  void setIsbn(int isbn);
};
#endif