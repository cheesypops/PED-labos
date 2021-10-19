#include <iostream>//00030821
#include <cmath>
#include <string.h>

using namespace std;

struct nodo{
    //int puxas;
    string masa; // 1 arroz, 2 maiz
    bool coca;
    string flav;
    nodo *sig;
};

class listapux{
    private:
        nodo *pini;
    public:
        listapux();
        ~listapux();
        void insertarorden();
        void insinicio(int, bool, string);
        void mostrarorden();
};

listapux::listapux(void){
    pini = NULL;
}
listapux::~listapux(void){
    nodo *p;

    while(pini){
        p = pini;
        pini = pini->sig;
        delete p;
    }
}

void listapux::insertarorden(void){
    int pux, masa, coke;
    bool x=true,y=true, cokeb;
    string sabor;
    cout << "Ingrese el numero de pupusas que desea: "; cin >> pux;

    for(int i=1; i <= pux; i++){
        do{
            cin.clear();
            cout << "1)Maiz\n2)Arroz\nIngrese el tipo de harina: "; cin >> masa;
            if(masa==1 || masa==2)
                x=false;
            else{
                cout << "Opcion no valida\n";
            }
        }while(x);

        do{
            cin.clear();
            cout << "¿Desea Coca-cola?\n1) Si\n2) No\n"; cin >> coke;
            if(coke==1){
                cokeb=true;
                y=false;
            }else if (coke==2){
                cokeb=false;
                y=false;
            }else{
                cout << "Opcion no valida\n";
            }
        }while(y);
        cout << "Ingrese el ingrediente del que desea la pupusa: "; cin >> sabor;

        insinicio(masa, cokeb, sabor);
    }
}

void listapux::insinicio(int masa, bool coca, string flav){
    string mas2="Arroz", mas1="Maiz";
    nodo *nuevo;

    nuevo = new nodo;

    if(masa==1)
        nuevo->masa=mas1;
    else
        nuevo->masa=mas2;
    
    nuevo->coca=coca;
    nuevo->flav=flav;
    nuevo->sig=pini;
    pini = nuevo;
}

void listapux::mostrarorden(void){
    nodo *actu;
    int numpux=0;
    actu=pini;

    while(actu!=NULL){
        cout << "Masa: " << actu->masa << endl;
        if(actu->coca)
            cout << "Con Coca-cola" << endl;
        else
            cout << "Sin Coca-cola" << endl;
        cout << "Ingredientes: " << actu->flav << endl << endl;

        numpux++;
        actu=actu->sig;
    }
    cout << "Total de pupusas: " << numpux << endl;
}

int main(){

    listapux orden;

    orden.insertarorden();

    cout << "\nOrden recibida: \n";
    orden.mostrarorden();

    orden.~listapux();
    cout << "Fin." << endl;

    return 0; 
}