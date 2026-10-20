#include <iostream>
#include <string>
using namespace std;

struct NodoRuta {
    int ciudad;
    int distancia;
    NodoRuta* siguiente;
};

void Recorrido(NodoRuta* cabeza){
    if (cabeza == nullptr){
        cout<<"La lista esta vacia."<< endl;
        return;
    
}
NodoRuta* actual = cabeza;
int distanciaTotal = 0;
cout<< "Se inicia el recorrido" <<endl;

do{
    cout<<"Ciudad visitada: "<< actual->ciudad << " / Distancia a la siguiente: " << actual -> distancia << " km << endl";

    distanciaTotal = distanciaTotal + actual -> distancia;

    actual = actual -> siguiente;
}

while (actual != cabeza);

cout << "-----------------------" << endl;
cout << "Distancia total del recorrido: " << distanciaTotal << "km" << endl;
}


int main(){

NodoRuta* n2 = new NodoRuta{2,10,nullptr};
NodoRuta* n3 = new NodoRuta{3, 15, nullptr};
NodoRuta* n9 = new NodoRuta{9,20,nullptr};
NodoRuta* n4 = new NodoRuta{4, 8,nullptr};
NodoRuta* n6 = new NodoRuta{6, 12, nullptr};

n2->siguiente = n3;
n3->siguiente = n9;
n9->siguiente = n4;
n4->siguiente = n6;
n6->siguiente = n2;

Recorrido(n2);



    return 0;
}