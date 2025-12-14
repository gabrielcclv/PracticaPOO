#include "catalog.hpp"
#include "Items/item.hpp"
#include "Items/book.hpp"
#include "Items/journal.hpp"
#include "Items/thesis.hpp"
#include "Library/biblioteca.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void Catalogo::cargarMaterialesCSV(string ruta) {
  ifstream file(ruta);
  if (!file.is_open()) {
    cerr << "Error al abrir " << ruta << endl;
    return;
  }

  string linea;
  while (getline(file, linea)) {
    auto campos = Biblioteca::splitCSV(linea);

    int id = stoi(campos[0]);
    string tipo = Biblioteca::unescapeCSV(campos[1]);
    string titulo = Biblioteca::unescapeCSV(campos[2]);
    string autor = Biblioteca::unescapeCSV(campos[3]);
    int year = stoi(campos[4]);
    string genero = Biblioteca::unescapeCSV(campos[5]);
    string editorial = Biblioteca::unescapeCSV(campos[6]);

    Item *i = nullptr;

    if (tipo == "Book") {
      int isbn = stoi(campos[7]);

      i = new Book(id, tipo, titulo, genero, autor, year, editorial, isbn);
    }

    else if (tipo == "Journal") {
      int issn = stoi(campos[7]);

      i = new Journal(id, tipo, titulo, genero, autor, year, editorial, issn);
    }

    else if (tipo == "Thesis") {
      string director = Biblioteca::unescapeCSV(campos[7]);

      if (year < 1980) {
        cerr << "ERROR: Tesis con año < 1980. ID=" << id << endl;
      }

      i = new Thesis(id, tipo, titulo, genero, autor, year, editorial, director);
    }

    else {
      cerr << "Tipo de item desconocido: " << tipo << endl;
    }

    // Añadir al catálogo
    addItem(i);
  }
};

void Catalogo::addItem(Item* item) {
    items.push_back(item);
}

void Catalogo::printCatalogo() {
    for (std::size_t i = 0; i < items.size(); ++i) {
        Item* it = items[i];
        if (it) {
            cout << i << ". " << it->getTitulo() << endl;
        } else {
            cout << i << ". " << "<item nulo>" << endl;
        }
    }
}

void Catalogo::removeItem(Item* item) {
    auto it = remove(items.begin(), items.end(), item);
    items.erase(it, items.end());
}

void Catalogo::removeItemPorLista(size_t i) {
    if (i >= items.size()) {
        cout << "Índice fuera de rango: " << i << endl;
        return;
    }
    Item* item = items[i];

    removeItem(item);

    delete item;
    cout << "Item eliminado." << endl;
}

void Catalogo::editItemPorLista(std::size_t index) {
    if (index >= items.size()) {
        cout << "Indice fuera de rango: " << index << endl;
        return;
    }
    cout << "Que campo desea editar?" << endl; 
    cout << "1. Titulo" << endl;
    cout << "2. Autor" << endl;
    cout << "3. Genero" << endl;
    cout << "4. Año" << endl;
    cout << "5. Editorial" << endl;
    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    Item* item = items[index];

    switch (opcion) {
        case 1: {
            string nuevoTitulo;
            cout << "Ingrese el nuevo titulo: ";
            cin.ignore();
            getline(cin, nuevoTitulo);
            item->Item::setTitulo() = nuevoTitulo;
            break;
        }
        case 2: {
            string nuevoAutor;
            cout << "Ingrese el nuevo autor: ";
            cin.ignore();
            getline(cin, nuevoAutor);
            item->Item::setAutor() = nuevoAutor;
            break;
        }
        case 3: {
            string nuevoGenero;
            cout << "Ingrese el nuevo genero: ";
            cin.ignore();
            getline(cin, nuevoGenero);
            item->Item::setGenero() = nuevoGenero;
            break;
        }
        case 4: {
            int nuevoYear;
            cout << "Ingrese el nuevo año: ";
            cin >> nuevoYear;
            item->Item::setYear() = nuevoYear;
            break;
        }
        case 5: {
            string nuevaEditorial;
            cout << "Ingrese la nueva editorial: ";
            cin.ignore();
            getline(cin, nuevaEditorial);
            item->Item::setEditorial() = nuevaEditorial;
            break;
        }
        default:
            cout << "Opcion invalida" << endl;
            return;
    }
    cout << "Item editado." << endl;
}

Item* Catalogo::getItemById(int id){
    auto it = find_if(items.begin(), items.end(), [id](Item* it) {
        return it->getId() == id;
    });

    if (it != items.end()) {
        return *it;
    } else {
        return nullptr;
    }
}