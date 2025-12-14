#ifndef CATALOGO_HPP
#define CATALOGO_HPP

#include "Items/item.hpp"
#include <vector>

class Catalogo {
private:
    vector<Item *> items;
public:
    Catalogo() {}
    ~Catalogo() {}

    void cargarMaterialesCSV(std::string ruta);

    void addItem(Item* item);
    void removeItem(Item* item);
    void editItemPorLista(std::size_t index);
    void removeItemPorLista(std::size_t index);

    void printCatalogo();
    void printListaItems(const vector<Item*>& lista);

    Item* getItemById(int id);
    vector<Item*>& getItems();

    vector<Item*> buscarPorTitulo(string titulo);
    vector<Item*> buscarAutorOrdenado(string autor);

};
#endif