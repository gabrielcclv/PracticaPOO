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

    void printCatalogo();

    void removeItemPorLista(std::size_t index);

};
#endif