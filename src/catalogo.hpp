#ifndef CATALOGO_HPP
#define CATALOGO_HPP

#include <string>

using namespace std;

class Item {
private:
  int id;
  string tipo;
  string titulo;
  string genero;
  string autor;
  int year;
  string editorial;

public:
  // Constructor
  Item(int id, string tipo, string titulo, string autor, int year, string genero, string editorial, string director);

  // Destructor virtual
  virtual ~Item();

  // Metodos
  virtual std::string info() const = 0;

  // Getters
  int getId() { return id; }
  string getTitulo() { return titulo; }
  string getGenero() { return genero; }
  string getAutor() { return autor; }
  int getYear() { return year; }
  string getEditorial() { return editorial; }
};

class Libro : public Item {
private:
  int isbn;

public:
  // Constructor
  Libro(int id, string tipo, string titulo, string genero, string autor, int year, string editorial, int isbn);
  // Destructor
  ~Libro();
  // Metodos
  std::string info() const;
  // Getters
  int getIsbn() { return isbn; }
};

class Revista : public Item {
private:
  int issn;

public:
  // Constructor
  Revista(int id, string tipo, string titulo, string genero, string autor, int year, string editorial, int issn);
  // Destructor
  ~Revista();
  // Metodos
  std::string info() const;
  // Getters
  int getIssn() { return issn; }
};

class Thesis : public Item {
private:
  string director;
  int year;

public:
  // Constructor
  Thesis(int id, string tipo, string titulo, string genero, string autor, int year, string editorial, string director);
  // Destructor
  ~Thesis();
  // Metodos
  std::string info() const;

  // Getters
  int getYear() {
    if (year < 1980) {

      return 0;
    } else {
      return year;
    }
  }
  string getDirector() { return director; }
};
#endif