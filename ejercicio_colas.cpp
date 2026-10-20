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