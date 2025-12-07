#include <string>
using namespace std;

class Usuario
{ 
    private:

    int id;
    string nombre;
    string rol;

    public:
    
    //Constructor
    Usuario(int id, string nombre, string rol);
    
    //Destructor
    ~Usuario();

    //Atributos
    int getId(){
        return id;
    }
    string getNombre(){
        return nombre;
    }
    string getRol(){
        return rol;
    }
    
    //Metodos

    
};

class Prestamo : public Usuario{
    private:
    
    public: 
    void returnItem;
    void loanItem;
    
}