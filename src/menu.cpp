#include <iostream>
#include "Library/biblioteca.hpp"
#include "Items/book.hpp"
#include "Items/journal.hpp"
#include "Items/thesis.hpp"
#include "Users/usuario.hpp"
#include "Users/prestamos.hpp"
#include "menu.hpp"
#include <cstdlib>

using namespace std;

void addBook(Biblioteca &biblio) {
    int id, year, isbn;
    string titulo, autor, genero, editorial;

    cout << "Ingrese el ID: ";
    cin >> id;
    cout << "Ingrese el titulo: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Ingrese el autor: ";
    getline(cin, autor);
    cout << "Ingrese el año: ";
    cin >> year;
    cout << "Ingrese el genero: ";
    cin.ignore();
    getline(cin, genero);
    cout << "Ingrese la editorial: ";
    getline(cin, editorial);
    cout << "Ingrese el isbn: ";
    cin >> isbn;
    string tipo = "Libro";

    Item *newItem =
        new Book(id, tipo, titulo, genero, autor, year, editorial, isbn);
    biblio.getCatalogo().addItem(newItem);
}
void addJournal(Biblioteca &biblio) {
    int id, year, issn;
    string titulo, autor, genero, editorial;
    
    cout << "Ingrese el ID: ";
    cin >> id;
    cout << "Ingrese el titulo: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Ingrese el autor: ";
    getline(cin, autor);
    cout << "Ingrese el año: ";
    cin >> year;
    cout << "Ingrese el genero: ";
    cin.ignore();
    getline(cin, genero);
    cout << "Ingrese la editorial: ";
    getline(cin, editorial);;
    cout << "Ingrese el issn: ";
    cin >> issn;
    string tipo = "Revista";

    Item *newItem =
        new Journal(id, tipo, titulo, genero, autor, year, editorial, issn);
    biblio.getCatalogo().addItem(newItem);
}

void addThesis(Biblioteca &biblio) {
    int id, year;
    string titulo, autor, genero, editorial, director;

    cout << "Ingrese el ID: ";
    cin >> id;
    cout << "Ingrese el titulo: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Ingrese el autor: ";
    getline(cin, autor);
    cout << "Ingrese el año: ";
    cin >> year;
    cout << "Ingrese el genero: ";
    cin.ignore();
    getline(cin, genero);
    cout << "Ingrese la editorial: ";
    getline(cin, editorial);
    cout << "Ingrese el director: ";
    getline(cin, director);
    string tipo = "Tesis";

    Item *newItem =
        new Thesis(id, tipo, titulo, genero, autor, year, editorial, director);
    biblio.getCatalogo().addItem(newItem);
}



void Menu(Biblioteca &biblio) {

bool salir = false;
do {

  cout << "========== Biblioteca Universitaria ========== " << endl;
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
    case 1: { // Add Item

      int opcion3;
      cout << "1. Add Book" << endl;
      cout << "2. Add Journal" << endl;
      cout << "3. Add Thesis" << endl;
      cout << "Ingrese una opcion: ";
      cin >> opcion3;
      switch (opcion3) {
      case 1: {
        addBook(biblio);
      } break;
      case 2: {
        addJournal(biblio);
      } break;
      case 3: {
        addThesis(biblio);
      } break;
      default:
        cout << "Opcion invalida" << endl;
        break;
      }
      break;
    }
    case 2:{  // Remove Item

        biblio.Biblioteca::getCatalogo().printCatalogo();
        size_t i;
        cout << "Ingrese el numero del item a eliminar: ";
        cin >> i;
        biblio.Biblioteca::getCatalogo().removeItemPorLista(i);
    }  break;
    case 3:{ // Edit Item

        biblio.Biblioteca::getCatalogo().printCatalogo();
        size_t i;
        cout << "Ingrese el numero del item a editar: ";
        cin >> i;
        biblio.Biblioteca::getCatalogo().editItemPorLista(i);
    }
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
    case 1: { //Add User

        string nombre, rol;
        int id;

        cout << "Nombre del usuario: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Rol del usuario: ";
        getline(cin, rol);
        cout << "ID del usuario: ";
        cin >> id;

        Usuario* nuevoUsuario = new Usuario(id, nombre, rol, 0.0, false);
        biblio.addUser(nuevoUsuario);
    }
      break;
    case 2: { // Block User
        cout << "Usuarios: " << endl;
        biblio.printUsuarios();
        size_t i;
        cout << "Ingrese el numero del usuario a bloquear: ";
        cin >> i;

        Usuario* u = biblio.getUsuarios()[i];
        u->blockUser();
        cout << "Usuario bloqueado: " << biblio.getUsuarios()[i]->getNombre() << endl;
    }
      break;
    case 3:{ // Unblock User

        cout << "Usuarios: " << endl;
        biblio.printUsuarios();
        size_t i;
        cout << "Ingrese el numero del usuario a desbloquear: ";
        cin >> i;

        Usuario* u = biblio.getUsuarios()[i];
        u->unblockUser();
        cout << "Usuario desbloqueado: " << biblio.getUsuarios()[i]->getNombre() << endl;
    }
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

    int idUsuario, idItem;
    
      cout << "ID del item: ";
      cin >> idItem;
      cout << "ID del usuario: ";
      cin >> idUsuario;
    
      biblio.loanItem(idUsuario, idItem);

      break;
    case 2:

        cout << "ID del item: ";
        cin >> idItem;
        cout << "ID del usuario: ";
        cin >> idUsuario;

        biblio.returnItem(idUsuario, idItem);

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
    case 1:{ // Search
        string autorBuscado;
        cout << "Ingrese el autor a buscar: ";
        cin.ignore();
        getline(cin, autorBuscado);

        vector<Item*> resultados = biblio.getCatalogo().buscarAutorOrdenado(autorBuscado);

        if(resultados.empty()) {
            cout << "No se encontraron items para el autor: " << autorBuscado << endl;
        } else {
            biblio.getCatalogo().printListaItems(resultados);
        }
    }
      break;
    case 2:{ // List

        biblio.getCatalogo().printCatalogo();
    }
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
    break;
  }
  case 5: // Report

    biblio.generarReportePorRol();
    break;
  case 6: // Exit

  salir = true;
    cout << "Saliendo del programa..." << endl;

    break;
  default:
    cout << "Opcion invalida" << endl;
    break;
  }
}while (!salir);
}