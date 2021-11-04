#include <iostream>//00030821, Diego Viana
#include <string.h>

using namespace std;

struct node{
    string id;
    /*con lo del dueño y el id no estaba seguro si el id indicaba todas las mascotas de una misma persona
    ya que como tambien se pide el nombre del dueño serian basicamente lo mismo*/
    string owner;
    string race;
    float weight;
    int age;
    node *next;
    node *prev;
};

class circle{
    private:
        node *head;
        node *tail;
    public:
        circle();
        void addpet();
        void addpetafter(string, string, string, float, int);//para ir insertando los nodos del mismo id juntos
        void showid();
        void deletenode();
};

circle::circle(){
    head=NULL;
    tail=NULL;
}

void circle::addpet(){
    string id, dueno, raza;
    int edad;
    float peso;
    cout << "Digite el id: ";
    cin.clear();
    while(getline(cin>>ws, id)){
        cout << "Digite el nombre del dueño: ";
        getline(cin>>ws, dueno);

        cout << "Digite la raza: ";
        getline(cin>>ws, raza);
        cin.clear();

        cout << "Ingrese la edad de la mascota: ";
        cin >> edad;

        cout << "Ingrese el peso: ";
        cin >> peso;
        
        addpetafter(id, dueno, raza, peso, edad);

        cout << "Digite otro id o Ctrl-Z para terminar: ";
    }
}

void circle::addpetafter(string id, string dueno, string raza, float peso, int edad){
    node *nuevo, *aux;
    nuevo= new node;

    nuevo->id = id;
    nuevo->owner = dueno;
    nuevo->race = raza;
    nuevo->weight = peso;
    nuevo->age = edad;

    if(head==NULL){
        head=nuevo;
        tail=nuevo;
        nuevo->next=head;
        nuevo->prev=tail;
    }else{
        node *aux;
        aux=head;

        while(aux->next != head){// o aux != tail
            aux=aux->next;
        }

        nuevo->next=aux->next; //o podria ser =head ya que se inserta al final
        aux->next=nuevo;
        tail=nuevo;
        nuevo->prev=aux;
        head->prev=tail;
    }
}

void circle::deletenode(){
    string del;
    bool y=true;
    node *search=head, *search2=NULL, *bye, *aux;

    cin.clear();
    cout << "Ingrese el id de el o los elementos a eliminar: ";
    getline(cin>>ws, del);

    if(!head){
        cout << "No hay datos ingresados\n";
    }else{
        do{
            if(search->id.compare(del)==0){//encuentra un nodo para eliminar
                if(search==head && search->next==head){//hay un solo nodo
                    bye=search;
                    head=NULL;
                    tail=NULL;
                    delete bye;
                }else{//hay mas de un nodo
                    if(!search2){//el primer nodo hay q eliminarlo (es el primero de la lista, o head)

                        bye = search;
                        search=search->next;

                        aux=search;
                        //encontrar el ultimo elemento de la lista para no perder referencia y luego
                        //poder enlazarlo otra vez con head, q cambiara de ubicacion a la que apuntaba
                        while(aux->next!=head){
                            aux=aux->next;
                        }
                        head=search;
                        aux->next=head;
                        head->prev=tail;

                        delete bye;
                    }else{//no es el primero de la lista
                        bye=search;
                        search=search->next;
                        search2->next=search;
                        search->prev=search2;
                        delete bye;
                    }
                }
            }else{//cuando search no apunta a un nodo q hay q eliminar
                search2=search;
                search=search->next;
                y=false;
            }
        }while(head != NULL && (search != head || y));
        //al momento de eliminar nodo por id hay un problema, si se da el caso de q hayan dos nodos
        //con el mismo id y q se tengan q eliminar, por q por la funcion y bucles, siempre head
        //va a terminar siendo igual a search y por ello se salia sin eliminar todos los nodos de la lista
        //por eso agrege una variable booleana "y", para que si se da el caso ya mencionado el while siga siendo
        //true, y q al momento en q o la lista tenga head=null o pase a un dato con un id q no sea el buscado
        //el valor de "y" se vuelve falso y asi la condicional solo dependeria q search!=head se cumpla
    }
}

void circle::showid(){
    node *s;
    bool x=true;
    string id;

    s=head;

    cin.clear();
    cout << "Ingrese el id de los datos que quiere mostrar: ";
    getline(cin>>ws, id);

    if(!head){
        cout << "La lista esta vacía\n\n";
    }else{
        cout << "ID: " << id << " \n";
        do{
            if(s->id.compare(id)==0){
                cout << "Dueño: " << s->owner << endl;
                cout << "Raza: " << s->race << endl;
                cout << "Peso: " << s->weight << endl;
                cout << "Edad: " << s->age << endl << endl;
                x=false;
            }
            s=s->next;
        }while(s != head);
        if(x)
            cout << "No existe el id ingresado\n";
    }
}

int main(){
    circle admin;
    int opc=0;
    bool cont=true;

    cout << "~~~~ADMINISTRACION DE VETERINARIA~~~~" << endl;

    do{
        cin.clear();
        cout << "\n1) Agregar datos\n";
        cout << "2) Mostrar por id\n";//muestra todos los nodos con el mismo id
        cout << "3) Eliminar datos por id\n";//elimina todos los nodos con el mismo id
        cout << "4) Salir\n";
        cout << "Ingrese la opcion que desea realizar: ";
        cin >> opc;

        switch(opc){
            case 1:
                admin.addpet();
                break;
            case 2:
                admin.showid();
                break;
            case 3:
                admin.deletenode();
                cout << "Funcion ejecutada\n";
                break;
            case 4:
                cont=false;
                break;
            default:
                cout << "Opción no valida\n";
                break;
        }
    }while(cont);

    cout << "Fin del programa.\n";
    return 0;
}