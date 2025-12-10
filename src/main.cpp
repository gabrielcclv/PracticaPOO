#include "Items/book.hpp"
#include "Items/item.hpp"
#include "Items/journal.hpp"
#include "Items/thesis.hpp"
#include "Library/biblioteca.hpp"
#include "Users/usuario.hpp"
#include "catalog.hpp"

#include <iostream>
#include <string>

using namespace std;

void Menu(Biblioteca &biblio) {

  cout << "Menu" << endl;
  cout << "1. Add/Remove/Edit-item" << endl;
  cout << "2. Add-user/Block-user/Unblock-user" << endl;
  cout << "3. Loan/Return" << endl;
  cout << "4. Search/List" << endl;
  cout << "5. Report" << endl;
  cout << "6. Exit" << endl;

  int opcion;
  cout << "Ingrese una opcion: ";
  cin >> opcion;

  switch (opcion) {
  case 1: {
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Edit Item" << endl;

    int opcion2;
    cout << "Ingrese una opcion: ";
    cin >> opcion2;

    switch (opcion2) {
    case 1: {
      int opcion3;
      cout << "1. Add Book" << endl;
      cout << "2. Add Journal" << endl;
      cout << "3. Add Thesis" << endl;
      cout << "Ingrese una opcion: ";
      cin >> opcion3;
      switch (opcion3) {
      case 1: {
        int id;
        string titulo;
        string autor;
        int year;
        string genero;
        string editorial;
        int isbn;
        cout << "Ingrese el ID: ";
        cin >> id;
        cout << "Ingrese el titulo: ";
        cin >> titulo;
        cout << "Ingrese el autor: ";
        cin >> autor;
        cout << "Ingrese el año: ";
        cin >> year;
        cout << "Ingrese el genero: ";
        cin >> genero;
        cout << "Ingrese la editorial: ";
        cin >> editorial;
        cout << "Ingrese el isbn: ";
        cin >> isbn;
        string tipo = "Libro";
        // Constructor: id, tipo, titulo, genero, autor, year, editorial, isbn
        Item *item =
            new Book(id, tipo, titulo, genero, autor, year, editorial, isbn);
        biblio.addItem(item);
      } break;
      case 2: {
        int id;
        string titulo;
        string autor;
        int year;
        string genero;
        string editorial;
        int issn;
        cout << "Ingrese el ID: ";
        cin >> id;
        cout << "Ingrese el titulo: ";
        cin >> titulo;
        cout << "Ingrese el autor: ";
        cin >> autor;
        cout << "Ingrese el año: ";
        cin >> year;
        cout << "Ingrese el genero: ";
        cin >> genero;
        cout << "Ingrese la editorial: ";
        cin >> editorial;
        cout << "Ingrese el issn: ";
        cin >> issn;
        string tipo = "Revista";
        // Constructor: id, tipo, titulo, genero, autor, year, editorial, issn
        Item *item =
            new Journal(id, tipo, titulo, genero, autor, year, editorial, issn);
        biblio.addItem(item);
      } break;
      case 3: {
        int id;
        string titulo;
        string autor;
        int year;
        string genero;
        string editorial;
        string director;
        cout << "Ingrese el ID: ";
        cin >> id;
        cout << "Ingrese el titulo: ";
        cin >> titulo;
        cout << "Ingrese el autor: ";
        cin >> autor;
        cout << "Ingrese el año: ";
        cin >> year;
        cout << "Ingrese el genero: ";
        cin >> genero;
        cout << "Ingrese la editorial: ";
        cin >> editorial;
        cout << "Ingrese el director: ";
        cin >> director;
        string tipo = "Tesis";
        // Constructor: id, tipo, titulo, genero, autor, year, editorial,
        // director
        Item *item = new Thesis(id, tipo, titulo, genero, autor, year,
                                editorial, director);
        biblio.addItem(item);
      } break;
      default:
        cout << "Opcion invalida" << endl;
        break;
      }
      break;
    }
    case 2:
      break;
    case 3:
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
    break;
  }
  case 2: {
    cout << "1. Add User" << endl;
    cout << "2. Block User" << endl;
    cout << "3. Unblock User" << endl;

    int opcion2;
    cout << "Ingrese una opcion: ";
    cin >> opcion2;

    switch (opcion2) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
    break;
  }
  case 3: {
    cout << "1. Loan" << endl;
    cout << "2. Return" << endl;

    int opcion2;
    cout << "Ingrese una opcion: ";
    cin >> opcion2;

    switch (opcion2) {
    case 1:
      break;
    case 2:
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
    break;
  }
  case 4: {
    cout << "1. Search" << endl;
    cout << "2. List" << endl;

    int opcion2;
    cout << "Ingrese una opcion: ";
    cin >> opcion2;

    switch (opcion2) {
    case 1:
      break;
    case 2:
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
    break;
  }
  case 5:
    break;
  case 6:
    break;
  default:
    cout << "Opcion invalida" << endl;
    break;
  }
}

int main() {

  Biblioteca biblio;
  biblio.cargarDatos();

  Menu(biblio);
}
