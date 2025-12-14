#include "biblioteca.hpp"
#include "../Items/book.hpp"
#include "../Items/journal.hpp"
#include "../Items/thesis.hpp"
#include "../Users/usuario.hpp"
#include "../catalog.hpp"
#include "../Users/prestamos.hpp"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Divide una linea CSV en campos individuales
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

// Elimina comillas de un campo CSV si existen
string Biblioteca::unescapeCSV(string campo) {
  if (campo.size() >= 2 && campo.front() == '"' && campo.back() == '"') {
    return campo.substr(1, campo.size() - 2);
  }
  return campo;
}

Biblioteca::Biblioteca() {}

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

      Prestamo *p = new Prestamo(id, idUsuario, idItem, fechaInicio, fechaLimite, fechaDevolucion, sancionAcumulada, devuelto);
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

void Biblioteca::loanItem(int idUsuario, int idItem){
  auto it = find_if(usuarios.begin(), usuarios.end(), [idUsuario](Usuario* u) {
    return u->getIdUsuario() == idUsuario;
  });

  Item* itemPrestado = catalogo.getItemById(idItem);

  if (itemPrestado == nullptr) {
    cout << "Item con ID " << idItem << " no encontrado en el catalogo." << endl;
    return;
  }

  auto itPrestamo = find_if(prestamos.begin(), prestamos.end(), [idItem](Prestamo* p) {
            // Buscamos si coincide el ID del item y si no ha sido devuelto
            return p->getIdItem() == idItem && !p->getDevuelto();
        });

    if (itPrestamo != prestamos.end()) {
        cout << "Error: El item '" << itemPrestado->getTitulo() << "' ya se encuentra prestado." << endl;
        return;
    }

  if (it != usuarios.end()) {
    Usuario* usuario = *it;

    // Crear nuevo prestamo
    auto ahora = chrono::system_clock::now();
    auto limite = ahora + chrono::hours(24 * 15); // 15 días

    Prestamo* nuevoPrestamo = new Prestamo( prestamos.size() + 1, idUsuario, idItem, ahora, limite, chrono::system_clock::time_point(), 0, false);

    addPrestamo(nuevoPrestamo);

    time_t tiempoLimite = chrono::system_clock::to_time_t(limite);
    cout << "Item '" << itemPrestado->getTitulo() << "' prestado a '"
         << usuario->getNombre() << "' hasta "
         << ctime(&tiempoLimite) << endl;
  } else {
    cout << "Usuario con ID " << idUsuario << " no encontrado." << endl;
  }
}


void Biblioteca::returnItem(int idUsuario, int idItem){
    // Buscar el préstamo activo para el item
  auto itPrestamo = find_if(prestamos.begin(), prestamos.end(), 
        [idItem](Prestamo* p) { 
            return p->getIdItem() == idItem && !p->getDevuelto(); 
        });

    if (itPrestamo == prestamos.end()) {
        cout << "No se encontró un préstamo activo para el item ID " << idItem << endl;
        return;
    }

    Prestamo* prestamo = *itPrestamo;

    // Establecer fecha de devolución
    auto ahora = chrono::system_clock::now();
    prestamo->setFechaDevolucion(ahora);
    prestamo->setDevuelto(true);

    // Calcular retraso y sanción
    if (ahora > prestamo->getFechaLimite()) {
        auto duracion = ahora - prestamo->getFechaLimite();
        
        // Convertir la duración a horas y dividir por 24 para sacar días enteros
        long diasRetraso = chrono::duration_cast<chrono::hours>(duracion).count() / 24;
        
        // Si ha pasado menos de un día completo pero ya pasó la hora, cuenta como 1 día
        if (diasRetraso == 0) diasRetraso = 1; 

        // Calcular multa (Variante A1: 0.10 por día, tope 15)
        double multa = diasRetraso * 0.10;
        if (multa > 15.0) multa = 15.0;

        cout << "Item devuelto con " << diasRetraso << " dias de retraso." << endl;
        cout << "Sancion aplicada: " << multa << " euros." << endl;

        // 4. Buscar al usuario para cobrarle la multa
        int idUsuario = prestamo->getIdUsuario();
        auto itUsuario = find_if(usuarios.begin(), usuarios.end(), [idUsuario](Usuario* u) { 
          return u->getIdUsuario() == idUsuario; 
        });

        if (itUsuario != usuarios.end()) {
            (*itUsuario)->sumarSancion(multa);
            // Guardar sanción en el historial del préstamo también
            prestamo->setSancionAcumulada(multa);
        }

    } else {
        cout << "Item devuelto a tiempo. Gracias." << endl;
    }


}

Usuario* Biblioteca::getUsuarioById(int idUsuario) {
    auto it = find_if(usuarios.begin(), usuarios.end(), [idUsuario](Usuario* u) {
        return u->getIdUsuario() == idUsuario;
    });

    if (it != usuarios.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

void Biblioteca::generarReportePorRol() {
    // 1. Inicializar contadores para los 3 roles
    // Estructura: [0]=Estudiante, [1]=PDI, [2]=PAS
    int activos[3] = {0, 0, 0};
    int retrasos[3] = {0, 0, 0};
    double sanciones[3] = {0.0, 0.0, 0.0};

    auto ahora = chrono::system_clock::now();

    // 2. Procesar PRÉSTAMOS (Activos y Retrasos)
    // Asumimos que tienes un vector<Prestamo*> prestamos; en Biblioteca
    for (Prestamo* p : prestamos) {
        if (!p->getDevuelto()) {
            // Buscar el rol del usuario dueño del préstamo
            // Nota: Esto sería más rápido con un mapa de ID->Usuario, 
            // pero lo haremos con búsqueda lineal simple por ahora.
            Usuario* u = getUsuarioById(p->getIdUsuario()); 
            
            if (u) {
                int index = -1;
                string rol = u->getRol();
                
                if (rol == "Estudiante") index = 0;
                else if (rol == "PDI") index = 1;
                else if (rol == "PAS") index = 2;

                if (index != -1) {
                    // Contar préstamo activo
                    activos[index]++;

                    // Verificar retraso (si fecha limite < ahora)
                    if (p->getFechaLimite() < ahora) {
                        retrasos[index]++;
                    }
                }
            }
        }
    }

    // 3. Procesar USUARIOS (Sanciones acumuladas)
    // Asumimos vector<Usuario*> usuarios;
    for (Usuario* u : usuarios) {
        int index = -1;
        string rol = u->getRol();

        if (rol == "Estudiante") index = 0;
        else if (rol == "PDI") index = 1;
        else if (rol == "PAS") index = 2;

        if (index != -1) {
            sanciones[index] += u->getSancion();
        }
    }
    
    // 4. Imprimir el reporte
    cout << "----- Reporte de Prestamos por Rol -----" << endl;
    cout << "Rol       | Activos | Retrasos | Sanciones Acumuladas" << endl;
    cout << "-----------------------------------------" << endl;
    string roles[3] = {"Estudiante", "PDI", "PAS"};
    for (int i = 0; i < 3; ++i) {
        cout << setw(10) << roles[i] << " | "
             << setw(7) << activos[i] << " | "
             << setw(8) << retrasos[i] << " | "
             << setw(20) << fixed << setprecision(2) << sanciones[i] << " euros" << endl;
    }
    cout << "-----------------------------------------" << endl;
}
