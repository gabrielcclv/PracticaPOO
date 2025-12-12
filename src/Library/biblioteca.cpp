#include "biblioteca.hpp"
#include "../Items/book.hpp"
#include "../Items/journal.hpp"
#include "../Items/thesis.hpp"
#include "../Users/usuario.hpp"
#include "../catalog.hpp"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> Biblioteca::splitCSV(const string &linea) {
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

string Biblioteca::unescapeCSV(string campo) {
  if (campo.size() >= 2 && campo.front() == '"' && campo.back() == '"') {
    return campo.substr(1, campo.size() - 2);
  }
  return campo;
}

Biblioteca::Biblioteca() {
  cargarUsuariosCSV("data/usuarios.csv");
  catalogo.cargarMaterialesCSV("data/catalogo.csv");
  cargarPrestamosCSV("data/prestamos.csv");
}

Biblioteca::~Biblioteca() {
  for (auto u : usuarios)
    delete u;
  for (auto p : prestamos)
    delete p;

  usuarios.clear();
  prestamos.clear();

}

void Biblioteca::cargarUsuariosCSV(string ruta) {
  ifstream file(ruta);
  if (!file.is_open()) {
    cerr << "Error al abrir " << ruta << endl;
    return;
  }

  string linea;
  // No skipping header as file seems to have data on line 1

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
}

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
    auto safe = [&](size_t idx) -> string {
      if (idx < campos.size())
        return unescapeCSV(campos[idx]);
      return string();
    };

    auto parseDate = [&](const string &s) -> chrono::system_clock::time_point {
      if (s.empty())
        return chrono::system_clock::time_point();
      std::tm tm = {};
      std::istringstream ss(s);
      ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
      if (ss.fail())
        return chrono::system_clock::time_point();
      time_t tt = mktime(&tm);
      return chrono::system_clock::from_time_t(tt);
    };

    try {
      int id = safe(0).empty() ? 0 : stoi(safe(0));
      int idUsuario = safe(1).empty() ? 0 : stoi(safe(1));
      int idItem = safe(2).empty() ? 0 : stoi(safe(2));

      chrono::system_clock::time_point fechaInicio = parseDate(safe(3));
      chrono::system_clock::time_point fechaLimite = parseDate(safe(4));
      chrono::system_clock::time_point fechaDevolucion = parseDate(safe(5));

      int sancionAcumulada = safe(6).empty() ? 0 : stoi(safe(6));
      bool devuelto = (safe(7) == "true");

      Prestamo *p = new Prestamo(id, idUsuario, idItem, fechaInicio, fechaLimite,
                                 fechaDevolucion, sancionAcumulada, devuelto);
      prestamos.push_back(p);
    } catch (const std::exception &e) {
      cerr << "Error parsing prestamos.csv linea: '" << linea << "' -> "
           << e.what() << endl;
    }
  }
}

void Biblioteca::addUser(Usuario *usuario) { 
  usuarios.push_back(usuario); 
}

void Biblioteca::removeUser(Usuario *usuario) {
  usuarios.erase(remove(usuarios.begin(), usuarios.end(), usuario), usuarios.end());
}

void Biblioteca::addPrestamo(Prestamo *prestamo) {
  prestamos.push_back(prestamo);
}

void Biblioteca::removePrestamo(Prestamo *prestamo) {
  prestamos.erase(remove(prestamos.begin(), prestamos.end(), prestamo), prestamos.end());
}

Catalogo &Biblioteca::getCatalogo() {
    return catalogo;
}

vector<Usuario *> &Biblioteca::getUsuarios() {
    return usuarios;
}

vector<Prestamo *> &Biblioteca::getPrestamos() {
    return prestamos;
}

void Biblioteca::printUsuarios(){
  for(size_t i = 0; i < usuarios.size(); i++){
    Usuario* u = usuarios[i];
    cout << i << ". " << u->getNombre() << endl;
  }
}

// Politica de sanciones, A1
/*
void retrasoDevolucion(Prestamo *prestamo) {
  if (prestamo->getFechaDevolucion() > prestamo->getFechaLimite()) {
    cout << "El prestamo " << prestamo->getIdPrestamo() << "ha sido retrasado"
         << endl;
    chrono::system_clock::time_point diasRetrasados =
prestamo->getFechaDevolucion() - prestamo->getFechaLimite(); int dinero =
diasRetrasados * 0.1; // Como operar y comparar chrono if (dinero >= 15) {
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
*/
