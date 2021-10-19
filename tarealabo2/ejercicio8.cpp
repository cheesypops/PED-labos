#include <iostream>//00030821, Diego Viana
#include <cmath>

using namespace std;

/*int conteo(int a){
    for(int i=1; i<=a; i++){
        cout << i << endl;
    }
    for(int j=a-1; j >= 1; j--){
        cout << j << endl;
    }No recursiva, y facil ;-;
}*/
//------------------------------------------
/*void conteoauxA(int, int);
void conteoauxB(int, int);

void conteo(int a, int b){
    conteoauxA(a, b);
    conteoauxB(a, b);
}
void conteoauxB(int x, int y){
    if(y < x){
        conteoauxB(x, y+1);
        cout << y << endl;
    }
}
void conteoauxA(int x, int y){
    if(x>1){
        conteoauxA(x-1, y);
        cout << x << endl;
    }else{
        cout << y << endl;
    }
}*/
/*Me base en la funcion para mostrar la lista inversa que habian dado como ejemplo
solo q cree 2 funciones diviendo la impresion en pantalla como el conteo de 1 a x, y luego de x-1 a 1.
La funcion conteoauxA, recibe el numero ingresado x, y el valor de y q seria 1 o sea el tope o minimo del conteo,
en esta funcion la variable a alterar seria x, mientras x sea mayor a 1 (no mayor o igual por algo que expklicare
mas adelante), se entra en la condicional y manda a llamar a la misma funcion, dejando en pausa la funcion actual
q esta a punto de imprimer el valor de x, q en la primera llamada seria el valor del usuario, al llamarse
asi misma la funcion e ir pausando procesos, el valor a imprimir de x se va volviendo menor hasta llegar
a cuando x vale 1, donde se imprime su valor, o el valor de y q igual seria 1. Luego va volviendo a donde
se habia llamado de manera recursiva la funcion leyendo la linea del cout e imprimiendo el valor q se tenia en
ese momento, de esta forma podesmos contar del 1 al valor de x, luego de que la funcion acaba se llama
a conteoauxB, donde vuelven a recibir los valores de a (valor dado por el usuario) y b q e sigual a 1,
en esta funcion lo q se quiere es contar desde x-1 hasta 1 (x-1 por q el valor de x ya ha sido impreso);
asi q mientras "y" sea menor a x entra en la condicional donde se hace otra llamada recursiva a la misma
funcion, poniendo en pausa ese proceso donde se imprimiria el valor de y q en principio es 1, pero en la
llamada recursiva se envia el valor normal de x para mantener el mismo limite y el valor de "y" se sube en 1
para conseguir valores de "y" de forma 1-2-3-...-(x-1), los cuales por la forma recursiva en que las
funciones han sido llamadas se iran imprimiendo al revez: (x-1)-...-3-2-1; y juntando esta impresion
con la ya explicada, se realiza el conteo solicitado.
*/
//--------------------------------------------------------------------------------------------------------
void conteo(int a, int b){
    if(b==a){
        cout << b << endl;
    }else{
        cout << b << endl;
        conteo(a, b+1);
        cout << b << endl;
    }
}
/*despues al volver a leer el enunciado me fije que decia que tenia que ser una funcion, asi que trate de hacer una 
combinacion de las dos funciones que habia creado. Pudiendo mandar el valor maximo y el inicial o sea 1, y un cout
antes y despues de la llamada recursiva, ya que primero al no cumplirse que a==b, significa que a es un numero diferente 
a 1, entra en el else, y muestra el valor inicial de b, o sea 1, luego se llama asi misma la funcion pero mandando el 
dato de b+1 para irlo subiendo, y escribiendo otro cout de b q imprimiria 1, pero como hay una llamada recursiva antes
quedaria en pausa hasta q la funcion que se llamo termine, y este proceso se repite hasta que a==b, luego
al ir retornando la funcion va devolviendo los numeros pero al revez (3-2-1 por ejemplo, y no 1-2-3) ya que el cout
despues de llamar a la funcion no se habia realizado en ninguna de las llamadas.
*/

int main(){
    int x;
    bool q=true;
    do{
    cout << "Ingrese un numero para realizar el conteo: "; cin >> x;
    if(x==0){
        cout << 0;
        q=false;
    }else if(x<0){
        cout << "No se permiten valores negativos." << endl;
    }else{
        conteo(x, 1);
        q=false;
    }
    }while(q);

    cout << "\nFin del conteo.";

    return 0;
}