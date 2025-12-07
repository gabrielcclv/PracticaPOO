#include <string>
#include <vector>

class Biblioteca{
    private:
    vector <Item*> items;
    vector <Usuario*> usuarios;
    vector <Prestamo*> prestamos;
    public:
    //Constructor
    Biblioteca();
    //Destructor
    ~Biblioteca();
    //Metodos
    void addItem(Item* item);
    void removeItem(Item* item);
    void addUsuario(Usuario* usuario);
    void removeUsuario(Usuario* usuario);
    void addPrestamo(Prestamo* prestamo);
    void removePrestamo(Prestamo* prestamo);
}
