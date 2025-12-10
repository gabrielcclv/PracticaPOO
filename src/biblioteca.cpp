#include "biblioteca.hpp"
#include "usuario.hpp"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<string> splitCSV(const string &linea) {
  vector<string> campos;
  string campo;
  bool enComillas = false;

  for (char c : linea) {
    if (c == '"') {
      enComillas = !enComillas;
    } else if (c == ',' && !enComillas) {
      campos.push_back(campo);
      campo.clear();
    } else {
      campo += c;
    }
  }
  campos.push_back(campo);
  return campos;
}

string unescapeCSV(string campo) {
  if (campo.size() >= 2 && campo.front() == '"' && campo.back() == '"') {
    return campo.substr(1, campo.size() - 2);
  }
  return campo;
};

void Biblioteca::cargarUsuariosCSV(string ruta) {
  ifstream file(ruta);

  string linea;
  getline(file, linea);

  while (getline(file, linea)) {
    auto campos = splitCSV(linea);

    int id = stoi(campos[0]);
    string nombre = unescapeCSV(campos[1]);
    string rol = unescapeCSV(campos[2]);
    double sancion = stod(campos[3]);
    bool bloqueado = (campos[4] == "true");

    Usuario *u = new Usuario(id, nombre, rol, sancion, bloqueado);
    usuarios.push_back(u);
  }
};

void Biblioteca::cargarMaterialesCSV(string ruta) {
    ifstream file(ruta);
    if (!file.is_open()) {
        cerr << "Error al abrir " << ruta << endl;
        return;
    }

    string linea;
    getline(file, linea); // Saltar cabecera

  while (getline(file, linea)) {
    auto campos = splitCSV(linea);

    int id = stoi(campos[0]);
    string tipo = unescapeCSV(campos[1]);
    string titulo = unescapeCSV(campos[2]);
    string autor = unescapeCSV(campos[3]);
    int year = stoi(campos[4]);
    string genero    = unescapeCSV(campos[5]);
    string editorial  = unescapeCSV(campos[6]);

    Item* i = nullptr;

    if (tipo == "Book") {
      int isbn = stoi(campos[7]);

      i = new Libro(id, tipo, titulo, genero, autor, year, editorial, isbn);
    }

    else if (tipo == "Journal") {
      int issn = stoi(campos[7]);

      i = new Revista(id, tipo, titulo, genero, autor, year, editorial, issn);
    }

    else if (tipo == "Thesis") {
      string director = unescapeCSV(campos[7]);

      if (year < 1980) {
        cerr << "ERROR: Tesis con año < 1980. ID=" << id << endl;
        continue;
      }

      i = new Thesis(id, tipo, titulo, genero, autor, year, editorial, director);
    }

    else {
      cerr << "Tipo de item desconocido: " << tipo << endl;
      continue;
    }

    // Añadir al catálogo
    items.push_back(i);
  }
};

void Biblioteca::cargarPrestamosCSV(string ruta) {
    ifstream file(ruta);
    if (!file.is_open()) {
        cerr << "Error al abrir " << ruta << endl;
        return;
    }

    string linea;
    getline(file, linea); // Saltar cabecera

    while (getline(file, linea)) {
        auto campos = splitCSV(linea);

        int id = stoi(campos[0]);
        int idUsuario = stoi(campos[1]);
        int idItem = stoi(campos[2]);
        chrono::system_clock::time_point fechaInicio =
            chrono::system_clock::from_time_t(stoi(campos[3]));
        chrono::system_clock::time_point fechaLimite =
            chrono::system_clock::from_time_t(stoi(campos[4]));
        chrono::system_clock::time_point fechaDevolucion =
            chrono::system_clock::from_time_t(stoi(campos[5]));
        int sancionAcumulada = stoi(campos[6]);
        bool devuelto = (campos[7] == "true");

        Prestamo *p = new Prestamo(id, idUsuario, idItem, fechaInicio, fechaLimite, fechaDevolucion, sancionAcumulada, devuelto);
        prestamos.push_back(p);
    }
}

void Biblioteca::addItem(Item *item) { items.push_back(item); };

void Biblioteca::removeItem(Item *item) {
  items.erase(remove(items.begin(), items.end(), item), items.end());
};

void Biblioteca::addUsuario(Usuario *usuario) { usuarios.push_back(usuario); };

void Biblioteca::removeUsuario(Usuario *usuario) {
  usuarios.erase(remove(usuarios.begin(), usuarios.end(), usuario),
                 usuarios.end());
};

void Biblioteca::addPrestamo(Prestamo *prestamo) {
  prestamos.push_back(prestamo);
};

void Biblioteca::removePrestamo(Prestamo *prestamo) {
  prestamos.erase(remove(prestamos.begin(), prestamos.end(), prestamo),
                  prestamos.end());
};

// Politica de sanciones, A1
void retrasoDevolucion(Prestamo *prestamo) {
  if (prestamo->getFechaDevolucion() > prestamo->getFechaLimite()) {
    cout << "El prestamo " << prestamo->getIdPrestamo() << "ha sido retrasado"
         << endl;
    chrono::system_clock::time_point diasRetrasados =
        prestamo->getFechaDevolucion() - prestamo->getFechaLimite();
    int dinero = diasRetrasados * 0.1; // Como operar y comparar chrono
    if (dinero >= 15) {
      dinero = 15;
    }
    cout << "El usuario debe pagar " << dinero << " por el retraso" << endl;
    bool pagar;
    cout << "Desea pagar la sancion? (s/n): ";
    cin >> pagar;
    if (pagar) {
      cout << "El usuario ha pagado la sancion" << endl;
      removePrestamo(prestamo);
    } else {
      cout << "El usuario no ha pagado la sancion" << endl;
      dinero += prestamo->getSancionAcumulada(dinero);
    }
  } else {
    cout << "El prestamo " << prestamo->getIdPrestamo()
         << "ha sido devuelto con éxito" << endl;
    removePrestamo(prestamo);
  }
};

// Restricciones de prestamos, C3
void restriccionPrestamo(Prestamo *prestamo) {
  if (prestamo->getSancionAcumulada() >= 10) {
    cout << "El usuario " << prestamo->getNombre() << "ha sido restringido"
         << "con Id: " << prestamo->getIdUsuario() << endl;
  }
};
