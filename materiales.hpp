#include <string>

class Item{
    private:

    public:

    //Constructor
    Item();

    //Destructor virtual
    virtual ~Item();
    
    //Metodos
    virtual std::string info() const = 0;
};