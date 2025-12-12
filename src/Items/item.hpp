#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item {
protected:
  int id;
  string tipo;
  string titulo;
  string genero;
  string autor;
  int year;
  string editorial;

public:
  // Constructor
  Item(int id, string tipo, string titulo, string autor, int year, string genero, string editorial);

  // Destructor virtual
  virtual ~Item();

  // Metodos
  virtual std::string info() const = 0;

  // Getters
  int getId();
  string getTipo();
  string getTitulo();
  string getGenero();
  string getAutor();
  int getYear();
  string getEditorial();

  // Setters
  string& setTitulo();
  int &setYear();
  string& setAutor();
  string& setGenero();
  string& setEditorial();
  
};

#endif