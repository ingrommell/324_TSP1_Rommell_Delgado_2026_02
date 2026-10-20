#include <iostream>
#include <string>
using namespace std;

class CadenaBinaria{
private:
    int bits[8];

public:
    // Constructor
    CadenaBinaria() {
        for(int i = 0; i < 8; i++){
            bits[i] = 0;
        }
    }

    // MÃ©todo INSERTAR
    void insertar(string cadena){
        if (cadena.length() != 8){
            cout << "Error: la cadena tiene una longitud distinta a 8 bits" << endl;
            return;
        }
        
        for (int i = 0; i < 8; i++) {
            if(cadena[i] != '0' && cadena[i] != '1'){
                cout << "Error: La cadena solo puede recibir 0 o 1" << endl;
                return; 
            }
            bits[i] = cadena[i] - '0';  // Convertir char a int
        }
        cout << "Cadena insertada correctamente" << endl;
    }
    
    // MÃ©todo IMPRIMIR
    void imprimir() {
        for (int i = 0; i < 8; i++) {
            cout << bits[i];
        }
        cout << endl;
    }


    //MÃ©todo NEGACIÃ“N
    void negacion() {
        for (int i = 0; i < 8 ; i++)
        {
            if (bits[i] == 0) {
                bits[i] = 1;
            }
            else {
                bits[i]=0;
            }
        };
        
        cout << endl;
    };

    //metodo Gray

      void MetodoGray() {
    int original[8];
    for (int i = 0; i < 8; i++) {
        original[i] = bits[i];       // guardamos copia del binario original
    }

    for (int i = 1; i < 8; i++) {
        if (original[i] == original[i-1]) {
            bits[i] = 0;
        } else {
            bits[i] = 1;
        }
    }
}
};

// FUNCIÃ“N MAIN
int main(){
    CadenaBinaria cb1;
    cout << "=== Ejercicio de TAD Cadena Binaria ===" << endl;
    cout << "Por favor ingrese una cadena de 8 dÃ­gitos que solo comprenda 0 y 1:" << endl;
    
    cb1.insertar("10110011");
    cout << "Cadena almacenada: ";
    cb1.imprimir();
    cb1.negacion();
    cout<< "Cadena almacenada en negacion: ";
    cb1.imprimir();
    cout<< "Cadena con metodoGray: ";
    cb1.MetodoGray();
    cb1.imprimir();

    return 0;
}