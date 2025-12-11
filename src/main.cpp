#include "Items/book.hpp"
#include "Items/item.hpp"
#include "Items/journal.hpp"
#include "Items/thesis.hpp"
#include "Library/biblioteca.hpp"
#include "menu.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {

  Biblioteca biblio;
  biblio.cargarDatos();

  Menu(biblio);

  return 0;
}
