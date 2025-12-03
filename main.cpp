#include <iostream>
#include <string>
using namespace std;
//Menu:
// i. add-item / remove-item / edit-item
// ii. add-user / block-user / unblock-user (si aplica)
// iii. loan / return
// iv. search <criterio> y list
// v. report (estadísticas del bloque F: ver variantes)
// vi. exit

void Menu(){

    cout << "Menu" << endl;
    cout << "1. Add/Remove/Edit-item" << endl;
    cout << "2. Add-user/Block-user/Unblock-user" << endl;
    cout << "3. Loan/Return" << endl;
    cout << "4. Search/List" << endl;
    cout << "5. Report" << endl;
    cout << "6. Exit" << endl;

    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion){
        case 1: {
            cout << "1. Add Item" << endl;
            cout << "2. Remove Item" << endl;
            cout << "3. Edit Item" << endl;

            int opcion2;
            cout << "Ingrese una opcion: ";
            cin >> opcion2;

            switch (opcion2){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    cout << "Opcion invalida" << endl;
                    break;
            }
            break;
        }
        case 2: {
            cout << "1. Add User" << endl;
            cout << "2. Block User" << endl;
            cout << "3. Unblock User" << endl;

            int opcion2;
            cout << "Ingrese una opcion: ";
            cin >> opcion2;

            switch (opcion2){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    cout << "Opcion invalida" << endl;
                    break;
            }
            break;
        }
        case 3: {
            cout << "1. Loan" << endl;
            cout << "2. Return" << endl;

            int opcion2;
            cout << "Ingrese una opcion: ";
            cin >> opcion2;

            switch (opcion2){
                case 1:
                    break;
                case 2:
                    break;
                default:
                    cout << "Opcion invalida" << endl;
                    break;
            }
            break;
        }
        case 4: {
            cout << "1. Search" << endl;
            cout << "2. List" << endl;

            int opcion2;
            cout << "Ingrese una opcion: ";
            cin >> opcion2;

            switch (opcion2){
                case 1:
                    break;
                case 2:
                    break;
                default:
                    cout << "Opcion invalida" << endl;
                    break;
            }
            break;
        }
        case 5:
            break;
        case 6:
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

int main(){
    Menu();
}
