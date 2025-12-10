#ifndef THESIS_HPP
#define THESIS_HPP

#include "item.hpp"

class Thesis : public Item {
protected:
  string director;

public:
  Thesis(int id, string tipo, string titulo, string genero, string autor,
         int year, string editorial, string director)
      : Item(id, tipo, titulo, autor, year, genero, editorial),
        director(director) {}
  ~Thesis() {}

  std::string info() const;

  int getYear() { return year; }
  string getDirector() { return director; }
};
#endif
