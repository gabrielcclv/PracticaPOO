#include "book.hpp"
#include <iostream>

using namespace std;

string Book::info() const {
  return "Book (ID: " + to_string(id) + "): " + titulo + " by " + autor +
         ", Genre: " + genero + ", Year: " + to_string(year) +
         ", Editorial: " + editorial + ", ISBN: " + to_string(isbn);
}

int Book::getIsbn() { return isbn; }

void Book::setIsbn(int isbn) { this->isbn = isbn; }
