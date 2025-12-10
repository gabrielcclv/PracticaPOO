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

    void addItem(Item* item);
    void removeItem(Item* item);
    void printCatalog();

    vector<Item*> getItems();
};
#endif