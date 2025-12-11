#include "thesis.hpp"
#include <iostream>

using namespace std;

std::string Thesis::info() const {
  return "Thesis (ID: " + to_string(id) + "): " + titulo + " by " + autor +
         ", Genre: " + genero + ", Year: " + to_string(year) +
         ", Editorial: " + editorial + ", Director: " + director;
}

void Thesis::printThesis() {
 cout << info() << endl;
}

int Thesis::getYear() {
  return year;
}

string Thesis::getDirector() {
  return director;
}