#include <iostream>
#include <string>
using namespace std;
#include "pila.h"


bool esEquilibradaPila(const string& cadena) {
	int cont = cadena.size();
	Pila<char> pila;
	int i = 0;
	if (cont == 0)
		return true;
		while( i < cont){
			if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{'){
				pila.apila(cadena[i]);
			}
			else if (cadena[i] == ')'){
				if (pila.esVacia()){
					return false;
				}
				if (pila.cima() != '('){
					return false;
				}
				pila.desapila();
			}
			else if (cadena[i] == ']'){
				if (pila.esVacia()){
					return false;
				}
				if (pila.cima() != '['){
					return false;
				}
				pila.desapila();
			}
			else if (cadena[i] == '}'){
				if (pila.esVacia()){
					return false;
				}
				if (pila.cima() != '{'){
					return false;
				}
				pila.desapila();
			}
			i++;
		}
		return pila.esVacia();
}


int main() {
	string cadena;
    while(getline(cin, cadena)) {
      if(esEquilibradaPila(cadena))
	//if (esEquilibradaCola(cadena))
        cout << "EQUILIBRADA" << endl;
      else
        cout << "NO_EQUILIBRADA" << endl;		  
	}
	return 0;
}	
