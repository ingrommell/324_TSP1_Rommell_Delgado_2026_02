#include <iostream>
#include <string>
using namespace std;

struct NodoPersona{
    int numeroPersona;
    int tipoOperacion;
    NodoPersona* siguiente;
};

struct Cola {
    NodoPersona* frente;
    NodoPersona* fin;
};

void InicializarCola(Cola &c){
    c.frente = nullptr;
    c.fin = nullptr;
};

void Encolar(Cola &c, int numPersona,int operacion){
    NodoPersona* nuevo = new NodoPersona;
    nuevo->numeroPersona = numPersona;
    nuevo->tipoOperacion = operacion;
    nuevo->siguiente = nullptr;

    if (c.frente==nullptr) {
        c.frente = nuevo;
        c.fin= nuevo;
    }
    else {
        c.fin->siguiente = nuevo;
        c.fin = nuevo;
    }
}

bool Desencolar(Cola &c,int &numPersona, int &operacion){
    if (c.frente == nullptr){
        return false;
    }

    NodoPersona* aux = c.frente;
    numPersona = aux->numeroPersona;
    operacion = aux->tipoOperacion;

    c.frente = c.frente->siguiente;

    if (c.frente == nullptr){
        c.fin = nullptr;
    }

    delete aux;
    return true;


}

void Distribuir (Cola &general, Cola &cola1, Cola &cola2, Cola &cola3){
    int persona, operacion;

    while(general.frente != nullptr){

        Desencolar(general, persona, operacion);

        if (operacion >= 1 && operacion <= 3){
            Encolar(cola1, persona, operacion);
        }
        else if (operacion >=4 && operacion <= 6){
            Encolar(cola2, persona, operacion);
        }
        else if (operacion >= 7 && operacion <= 9){
            Encolar(cola3, persona, operacion);
        }
    }
}

void ImprimirCola(Cola &c) {
    // 1. Verificamos si la cola está vacía
    if (c.frente == nullptr) {
        cout << "[Cola Vacia]" << endl;
        return;
    }

    // 2. Creamos un puntero auxiliar para no perder el frente original
    NodoPersona* actual = c.frente;

    cout << "Frente -> ";
    
    // 3. Recorremos la cola hasta llegar al final (nullptr)
    while (actual != nullptr) {
        cout << "[Persona: " << actual->numeroPersona 
             << " | Op: " << actual->tipoOperacion << "] -> ";
        
        // 4. Avanzamos al siguiente nodo
        actual = actual->siguiente;
    }
    
    cout << "NULL (Fin)" << endl;
}

int main(){

    Cola general, cola1, cola2, cola3;

    InicializarCola(general);
    InicializarCola(cola1);
    InicializarCola(cola2);
    InicializarCola(cola3);

    cout << "Distribuyendo personas..." << endl;

    Distribuir(general, cola1, cola2, cola3);

    //verificacion que la cola esta vacia 
    if (general.frente == nullptr) {
        cout << "La cola general quedo vacia." << endl;
    }

    ImprimirCola(general);

    return 0;
}