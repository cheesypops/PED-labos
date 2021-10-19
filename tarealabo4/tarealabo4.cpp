#include <iostream>//lista doble con dos clases
#include <string.h>//00030821

using namespace std;

class Node{
    private:
        string id;
        string usuario;
        int perfil; // 1-admin, 2-trabajdor, 3-cliente

        Node *next;
        Node *prev;

        friend class LinkedList;
};

class LinkedList{
    public:
        LinkedList();//constructor
        ~LinkedList(); //destructor

        void getfront();
        void getback();

        void addfront(string, string, int);
        void addback(string, string, int);

        void removefront();
        void removeback();

        void printreverse();
        void printdorward();

    private:
        Node *header;
        Node *tail;
};

LinkedList::LinkedList(){
    header = new Node;
    tail = new Node;

    header->next=tail;
    tail->prev=header;

    header->prev=NULL;
    tail->next=NULL;
}

LinkedList::~LinkedList(){
    while(header->next != tail)
        removefront();
}

void LinkedList::getfront(){
    if(header->next==tail){
        cout << "No hay datos en la lista\n";
    }else{
        cout << "ID: " << header->next->id << endl;
        cout << "Usuario: " << header->next->usuario << endl;
        switch(header->next->perfil){
            case 1:
                cout << "Perfil: Administrador" << endl;
                break;
            case 3:
                cout << "Perfil: Cliente" << endl;
                break;
            case 2:
                cout << "Perfil: Trabajador" << endl;
                break;
        }
    }
}

void LinkedList::getback(){
    if(header->next==tail){
        cout << "No hay datos en la lista\n";
    }else{
        cout << "ID: " << tail->prev->id << endl;
        cout << "Usuario: " << tail->prev->usuario << endl;
        switch(tail->prev->perfil){
            case 1:
                cout << "Perfil: Administrador" << endl;
                break;
            case 3:
                cout << "Perfil: Cliente" << endl;
                break;
            case 2:
                cout << "Perfil: Trabajador" << endl;
                break;
        }
    }
}

void LinkedList::addfront(string id, string user, int perf){
    Node *New;

    New = new Node;
    New->id=id;
    New->usuario=user;
    New->perfil=perf;

    New->next=header->next;
    New->prev=header;

    header->next->prev=New;
    header->next=New;
}

void LinkedList::addback(string id, string user, int perf){
    Node *New;

    New = new Node;
    New->id=id;
    New->usuario=user;
    New->perfil=perf;

    New->next=tail;
    New->prev=tail->prev;

    tail->prev->next=New;
    tail->prev=New;
}

void LinkedList::removefront(){
    Node *p;
    p=header->next->next;

    if(p==NULL)
        cout << "No hay datos en la lista\n";
    else{
        delete header->next;

        header->next=p;
        p->prev=header;

        cout << "Elemento eliminado\n";
    }
}

void LinkedList::removeback(){
    Node *p;
    p=tail->prev->prev;

    if(p==NULL)
        cout << "No hay datos en la lista\n";
    else{
        delete tail->prev;

        tail->prev=p;
        p->next=tail;

        cout << "Elemento eliminado\n";
    }
}

void LinkedList::printreverse(){
    Node *printer;
    printer=tail->prev;

    if(printer==header)
        cout << "No hay datos en la lista\n";
    else{
        while(printer!=header){
            cout << "\nID: " << printer->id << endl;
            cout << "Usuario: " << printer->usuario << endl;
            switch(printer->perfil){
                case 1:
                    cout << "Perfil: Administrador" << endl;
                case 2:
                    cout << "Perfil: Trabajador" << endl;
                case 3:
                    cout << "Perfil: Cliente" << endl;
            }
            printer=printer->prev;
        }
    }
}

void LinkedList::printdorward(){
    Node *printer;
    printer=header->next;

    if(printer==tail)
        cout << "No hay datos en la lista\n";
    else{
        while(printer!=tail){
            cout << "\nID: " << printer->id << endl;
            cout << "Usuario: " << printer->usuario << endl;
            switch(printer->perfil){
                case 1:
                    cout << "Perfil: Administrador" << endl;
                case 2:
                    cout << "Perfil: Trabajador" << endl;
                case 3:
                    cout << "Perfil: Cliente" << endl;
            }
            printer=printer->next;
        }
    }
}

int main(){
    LinkedList List;
    bool cont=true, buc=true;
    int x=0, aux=0, per=0;
    string user, id;

    cout << "Listas dobles" << endl << endl;

    do{
        cin.clear();
        cout << "\n1) Insertar Datos al inicio\n";
        cout << "2) Insertar Datos al final\n";
        cout << "3) Obtener primer elemento\n";
        cout << "4) Obtener ultimo elemento\n";
        cout << "5) Eliminar primer elemento\n";
        cout << "6) Eliminar ultimo elemento\n";
        cout << "7) Imprimir lista\n";
        cout << "8) Imprimir lista inversa\n";
        cout << "9) Salir\n";
        cout << "Ingrese la opcion que desea realizar: ";
        cin >>x;

        switch(x){
            case 1:
                cout << "Ingrese el ID:";
                getline(cin>>ws, id);
                cin.clear();
                
                cout << "Ingrese el usuario: ";
                getline(cin, user);
                cin.clear();

                do{
                    cin.clear();
                    cout << "1) Administrador\n";
                    cout << "2) Trabajador\n";
                    cout << "3) Cliente\n";
                    cout << "Ingrese el numero de la opcion de perfil:";
                    cin >>aux;

                    switch(aux){
                        case 1:
                            per=1;
                            buc=false;
                            break;
                        case 2:
                            per=2;
                            buc=false;
                            break;
                        case 3:
                            per=3;
                            buc=false;
                            break;
                        default:
                            cout << "Opcion no disponible, ingrese una opcion valida.\n";
                    }
                }while(buc);
                List.addfront(id, user, per);
                cout << "Elemento agregado\n\n";
                break;
            case 2:
                cout << "Ingrese el ID:";
                getline(cin>>ws, id);
                cin.clear();
                
                cout << "Ingrese el usuario: ";
                getline(cin, user);
                cin.clear();

                do{
                    cin.clear();
                    cout << "1) Administrador\n";
                    cout << "2) Trabajador\n";
                    cout << "3) Cliente\n";
                    cout << "Ingrese el numero de la opcion de perfil:";
                    cin >>aux;

                    switch(aux){
                        case 1:
                            per=1;
                            buc=false;
                            break;
                        case 2:
                            per=2;
                            buc=false;
                            break;
                        case 3:
                            per=3;
                            buc=false;
                            break;
                        default:
                            cout << "Opcion no disponible, ingrese una opcion valida.\n";
                    }
                }while(buc);
                List.addback(id, user, per);
                cout << "Elemento agregado\n\n";
                break;
            case 3:
                List.getfront();
                break;
            case 4:
                List.getback();
                break;
            case 5:
                List.removefront();
                break;
            case 6:
                List.removeback();
                break;
            case 7:
                List.printdorward();
                break;
            case 8:
                List.printreverse();
                break;
            case 9:
                cont=false;
                break;
            default:
                cout << "Opcion no disponible, inserte una opcion valida\n";
                break;
        }
    }while(cont);

    cout << "\nFin del programa";

    return 0;
}