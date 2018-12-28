#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
#include "pila.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS


void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	Pila<char> pilas;
	Lista<char>::Iterator iter = mensaje.begin();
	Lista<char>::Iterator iterc = mensaje.begin();
	if (!mensaje.esVacia()){
		for (int i = 0; i < mensaje.longitud(); i++){
			if (iter.elem() == 'a' || iter.elem() == 'A' || iter.elem() == 'e' || iter.elem() == 'E' || iter.elem() == 'i' || iter.elem() == 'I' || iter.elem() == 'o' || iter.elem() == 'O' || iter.elem() == 'u' || iter.elem() == 'U'){
				while (!pilas.esVacia()){
					iterc.set(pilas.cima());
					pilas.desapila();
					iterc.next();
				}
				iterc.next();
			}
			else{
				pilas.apila(iter.elem());
			}
			iter.next();
		}
		while (!pilas.esVacia()){
			iterc.set(pilas.cima());
			pilas.desapila();
			iterc.next();
		}
	}
}

 
// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	l.print();
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main() {
	string linea;
	while(getline(cin,linea)) {
	   Lista<char> mensaje;
	   construyeMensaje(linea,mensaje);
       codifica(mensaje);
	   imprime(mensaje);
	}
	return 0;
}	
