#include <iostream>//usar std::cout <<...
#include <string.h>
//Diego José Viana Landaverde; #00030821

struct nodo{
    std::string carnet;//si lo ponia en double, los carnets iniciados en 0s perdian dichos numeros
    std::string nombre;
    std::string apellido;
    int edad;
    std::string telefono;//si lo ponia double me retornaba un numero en valor hexadecimal :b
    std::string correo;
    nodo *sig;
};

class listamenu{
    private:
        nodo *puninicial;
    public:
        listamenu();
        //~listamenu();
        void llenarlis(void);
        void insini(std::string, std::string, std::string, int, std::string, std::string);//recibe las variables o datos del nodo
        bool eliminarpersona(std::string);//nuevo
        void mostrarlis(void);
};

listamenu::listamenu(){
    puninicial = NULL;
}

void listamenu::llenarlis(void){
    std::string nombre, apellido, correo, telefono, carnet;
    int edad, opc;

    /*Para el bucle que viene intente varias formas para q no hubiese error en el output por los cin y getline
    que basicamente se saltaba espacios para escribir; intente con un bucle dentro del bucle para cada getline
    para que el getline se active solo si el tamaño de la variable es 0, o sea sin espacio; pero el error 
    persistia a partir del segundo elemento o nodo de la lista.

    Y segui buscando sobre el cin.clear(), aunq tampoco funcionaba con los getline y segui buscando hasta que en
    una pagina hacia mencion a la funcion std::ws, o mas bien cin>>std::ws, que basicamente eliminaba los espacios
    en blanco o saltos de linea, o mas bien, extrae los espacios en blanco despues de un cin, asi que con eso
    queda solucionado el problema que se da entre cin y getlines seguidos.

    Buscando despues encontre que utilizando un cin.ignore(); luego de cada cin limpia el espacio para que el 
    getline no llegue a leerlo y por tanto "finalizar" el getline.
    */

    std::cout << "Ingrese el numero de carnet:";
    std::cin.ignore();//por si acaso, elimino o ignoro algun espacio en blanco q pueda haber
    while(std::getline(std::cin, carnet)){
        std::cin.clear();//luego de cada getline limpio el cin para evitar problemas de saltos

        std::cout << "Ingrese el nombre:";
        std::getline(std::cin>>std::ws, nombre);
        std::cin.clear();

        std::cout << "Ingrese el apellido:";
        std::getline(std::cin, apellido);
        std::cin.clear();

        std::cout << "Ingrese la edad:";
        std::cin>>edad; 
        std::cin.ignore();//ignoro \n
        std::cin.clear();

        std::cout << "Ingrese el numero de telefono (sin guiones):";
        std::getline(std::cin>>std::ws, telefono);
        std::cin.clear();

        std::cout << "Ingrese el correo electronico:";
        std::getline(std::cin>>std::ws, correo);//cin>>std::ws
        std::cin.clear();//limpiar por si el bucle vuelve a iniciar

        insini(carnet, nombre, apellido, edad, telefono, correo);

        std::cout<< "Ingrese otro numero de carnet o Ctrl Z para finalizar:";
    }
}
void listamenu::insini(std::string carnet, std::string nombre, std::string apellido, int edad, std::string telefono, std::string correo){
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->carnet=carnet;
    nuevo->nombre=nombre;
    nuevo->apellido=apellido;
    nuevo->edad=edad;
    nuevo->telefono=telefono;
    nuevo->correo=correo;//ingresar todos los datos en lso diferemtes campos
    nuevo->sig=puninicial;//hacer q el puntero sig apunte donde originalmente apuntaba puninicial
    puninicial=nuevo;//cambiar el valor de puninicial para q apunte al primer nodo
}

bool listamenu::eliminarpersona(std::string datoB){//cambie a string ya que el carnet es un dato de tipo string

    if(!puninicial)
        return false;//si retorna false significa que no hay un nodo creado, ya q puninicial apunta a NULL
    else{
        nodo *s = puninicial, *p;

        if(s->carnet == datoB){
            puninicial = puninicial->sig;
            delete s;
            /*Si el dato al que el puntero esta apuntando es igual a datoB, que es el dato que se busca eliminar
            se cambia la direccion de puninicial a la de siguiente para asi eliminar la direccion de memoria s
            y por tanto el nodo completo sin perder el puntero dirigido a la cabeza de la lista.
            */

            return true;
        }
        else{
            while(s->sig && s->sig->carnet != datoB)
                s = s-> sig;
            /*Si s->sig apunta a NULL sale de una vez del bucle, y termia en el siguiente if y retornando un
            false, ya que si s->sig apunta a NULL significa que hay un solo nodo y no es el del dato buscado;
            pero si se entra en el bucle al menos una vez significa que s->sig no apunta a NULL y si apunta a otro nodo
            el cual luego se verifica si el puntero sig de ese nodo apunta hacia el dato buscado, y si no se cumple
            entra en el bucle hasta recorrer toda la lista y que s->sig apunte a NULL o que s->sig->dato apunte 
            al dato que se busca eliminar.
            */

            if(!s->sig)
                return false;

            else{
                p = s->sig;

                s->sig = s->sig->sig;

                delete p;
                /*Al entrar en este else significa que se encontro el dato, se crea un puntero auxiliar (p) que contiene
                la direccion de s->sig; esto por que "s" ya tomo el valor del puntero cuyo s->sig apunta al dato buscado
                por ello se iguala el puntero p al puntero s->sig, para mantener la direccion de memoria del nodo que se
                quiere eliminar. Luego para no afectar la lista, se cambia la direccion a la que apunta s->sig por
                la direccion a la que apuntaba el puntero sig del nodo apuntado por s->sig y posteriormente se elimina la direccion
                de memoria almacenada en p, y sus datos.
                */

                return true;
            }
        }
    }
}

void listamenu::mostrarlis(void){
    nodo *actu;
    actu=puninicial;//puntero auxiliar para pasar por toda la lista

    while(actu!=NULL){
        std::cout << "\nCarnet: " << actu->carnet << "\n";
        std::cout << "Nombre: " << actu->nombre << "\n";
        std::cout << "Apellido: " << actu->apellido << "\n";
        std::cout << "Edad: " << actu->edad << "\n";
        std::cout << "Telefono: " << actu->telefono << "\n";
        std::cout << "Correo: " << actu->correo << "\n";//imprimiendo datos
        actu=actu->sig;//cambiar dirrecion a la q apunta el puntero auxiliar
    }
}


int main(){

    int opcion;
    bool menu = true;
    std::string datoeliminar;
    listamenu lista1;

    do{
        std::cout << "\nLista simple con menu\n\n";

        std::cout << "1) Llenar la lista\n";
        std::cout << "2) Eliminar a una persona\n";
        std::cout << "3) Mostrar a todas las personas\n";
        std::cout << "4) Salir\n";
        std::cout << "Seleccione la opcion que desea realizar:";
        std::cin.clear();/*limpiar el cin para evitar crear un bucle infinito, ya que sin esta opcion
        luego del ctrl z al ingresar datos, el menu se repetia infinitamente ya que no dejaba escribir
        la nueva opcion en el cin, ya que de una vez tomaba la opcion que anteriormente se habia escrito
        o sea el 1*/
        std::cin >> opcion;

        switch (opcion){
            case 1:
                lista1.llenarlis(); 
                break;
            case 2:
                std::cout<< "Ingrese el numero de carnet de la persona que desea eliminar de la lista:";
                getline(std::cin>>std::ws, datoeliminar);
                if(lista1.eliminarpersona(datoeliminar)){
                    std::cin.clear();
                    std::cout << "\nLa informacion de la persona ha sido eliminada.\n";
                }else{
                    std::cin.clear();//limpiar cin para evitar otra vez el problema del bucle infinito
                    std::cout << "\nEl numero de carnet ingresado no existe en la lista\n";
                }
                break;
            case 3:
                lista1.mostrarlis();
                break;
            case 4:
                menu=false;
                break;
            default:
                std::cout<< "\nEsa opcion no esta disponible.";
                break;
        }
    }while(menu);

    std::cout << "\nEl menu a finalizado.\n";

    return 0;
}