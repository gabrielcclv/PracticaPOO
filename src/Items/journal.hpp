#ifndef JOURNAL_HPP
#define JOURNAL_HPP

#include <iostream>
#include "item.hpp"

class Journal : public Item {
protected:
  int issn;

public:
  Journal(int id, string tipo, string titulo, string genero, string autor, int year, string editorial, int issn)
      : Item(id, tipo, titulo, autor, year, genero, editorial), issn(issn) {}
  ~Journal() {}

  std::string info() const;

  int getIssn() { return issn; }
};
#endif