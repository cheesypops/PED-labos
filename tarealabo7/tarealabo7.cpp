#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *subLeft;
    nodo *subRight;
};

class BinarySearchTree{
    private:
        nodo *pBinarySearchTree;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertar(void);
    void insertarBST(nodo **, int);
    void showPreorder(nodo *);
    void showInorder(void);
    void showIn(nodo *);
    void showPost(nodo *);
    void showPostOrder(void);
    void showPreorder(void);
    void showPre(nodo *);
    //---------funciones extra del codigo--------------
    void search();
    void searchnode(nodo *, int);
    void deletenode();
    void delN(nodo **, int);
};

BinarySearchTree::BinarySearchTree(void)
{
    pBinarySearchTree = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    cout << "Program Execution" << endl;
}

void BinarySearchTree::insertar(void)
{
    int dato;
    char resp;

    do{
        cout << "Escriba y para continuar" << endl;
        cout << "Desea digitar un dato?";
        cin >> resp;
        if(resp == 'y'){
            cout << "Elemento que desea ingresar: ";
            cin >> dato;
            insertarBST(&pBinarySearchTree, dato);
        }

    }while(resp == 'y');
}

void BinarySearchTree::insertarBST(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->subLeft = NULL;
        (*p)->subRight = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->subLeft), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->subRight), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void BinarySearchTree::showInorder(void)
{
    showIn(pBinarySearchTree);
}

void BinarySearchTree::showIn(nodo *p)
{
    if(p){
        showIn(p->subLeft);
        cout << p->dato << " ";
        showIn(p->subRight);
    }
    cout << endl;
}

void BinarySearchTree::showPreorder(void)
{
    showPre(pBinarySearchTree);
}

void BinarySearchTree::showPre(nodo *p)
{
    if(p){
        cout << p->dato << " ";
        showPre(p->subLeft);
        showPre(p->subRight);
    }
    cout << endl;
}

void BinarySearchTree::showPostOrder(void)
{
    showPost(pBinarySearchTree);
}

void BinarySearchTree::showPost(nodo *p)
{
    if(p)
    {
        showPost(p->subLeft);
        showPost(p->subRight);
        cout << p->dato << " ";
    }
    cout << endl;
}

void BinarySearchTree::deletenode(){//viana
    int dato=0;
    cin.clear();
    cout << "Ingrese el dato a eliminar o ctrl-Z para terminar:";

    while(cin>>dato){
        delN(&pBinarySearchTree, dato);

        cout << "Ingrese otro dato a eliminar o Ctrl-Z para terminar: ";
    }
}

void BinarySearchTree::delN(nodo **t, int dato){
    nodo *p;

    if(!(*t)){
        cout << "El dato no esta en el arbol" << endl;
    }else{
        if(dato > (*t)->dato){
            delN(&((*t)->subRight), dato);
        }else if(dato < (*t)->dato){
            delN(&((*t)->subLeft), dato);
        }else{
            if(!(*t)->subLeft && !(*t)->subRight){//si es hoja
                p=*t;
                *t=NULL;
            }else if((*t)->subLeft && !(*t)->subRight){//si tiene solo hijo izq
                p=*t;
                *t=(*t)->subLeft;
            }else if(!(*t)->subLeft && (*t)->subRight){//si tiene solo hijo der
                p=*t;
                *t=(*t)->subRight;
            }else if((*t)->subLeft && (*t)->subRight){//si tiene ambos hijos
                p=(*t)->subRight;

                if(!p->subLeft){//es el menor de los mayores
                    (*t)->dato=p->dato;
                    (*t)->subRight=p->subRight;
                }else{//hay q buscar el menor de los mayores,
                    nodo *q;
                    while(p->subLeft){
                        q=p;
                        p=p->subLeft;
                    }
                    (*t)->dato=p->dato;
                    q->subLeft=p->subRight;
                }
            }
            delete p;
        }
    }
}

void BinarySearchTree::search(){//viana
    int dat=0;
    cin.clear();
    cout << "Ingrese el dato a buscar: ";
    cin >> dat;

    searchnode(pBinarySearchTree, dat);
}

void BinarySearchTree::searchnode(nodo *root, int dato){
    if(!root){
        cout << "el dato no esta en el arbol\n";
    }else{
        if(dato < root->dato){
            searchnode(root->subLeft, dato);
        }else if(dato > root->dato){
            searchnode(root->subRight, dato);
        }else{//es igual al dato
            cout << "El dato ha sido encontrado\n";
        }
    }
}

int main(void)
{
    cout << endl;
    cout << "Binary Search Tree :D" << endl;

    BinarySearchTree objBinarySearchTree;

    cout << "Insertar datos en el arbol:" <<  endl;
    objBinarySearchTree.insertar();

    cout << "\nMostrar Pre-orden: " << endl;
    objBinarySearchTree.showPostOrder();


    cout << "\nMostrar In-Orden: " << endl;
    objBinarySearchTree.showInorder();


    cout << "\nMostrar Post-Orden: " << endl;
    objBinarySearchTree.showPostOrder();

    cin.clear();
    cout << "\nBuscar dato en el arbol: \n";
    objBinarySearchTree.search();
    
    cin.clear();
    cout << "\nEliminacion de datos del arbol: \n";
    objBinarySearchTree.deletenode();

    cout << "\nComprobando que los datos se eliminaron: \n";
    objBinarySearchTree.showInorder();

    cout << "\nFin del programa";

    return 0;
}