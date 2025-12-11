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