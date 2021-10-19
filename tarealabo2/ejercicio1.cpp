#include <iostream>//00030821, Diego Viana
#include <cmath>

using namespace std;

int mcd(int *mayor, int *menor){
    int *aux;
    int residuo;
    if(*menor > *mayor){
        *aux = *menor;
        *menor = *mayor;
        *mayor = *aux;
    }

    if(*mayor % *menor == 0){
        return *menor;
    }else{
        residuo = *mayor%*menor;
        return mcd(menor, &residuo);
    }
}

int main(){
    int a, b;
    cout << "Ingrese los numeros para calcular su mcd: \n"; 
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;

    if(a==0 || b == 0){
        cout << "Valores ingresados no validos. ";
    }else{
        cout << "El valor del mcd es " << mcd(&a, &b) << "." << endl;
    }
    cout << "Fin del programa.";

    return 0;
}