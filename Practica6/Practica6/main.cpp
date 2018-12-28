#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/*int numeroNavegable(const Arbin<int>& cuenca, int &cont){
	int suma;
	if (cuenca.hijoDer().esVacio() && cuenca.hijoIz().esVacio()){
		return 1;
	}
	else if (cuenca.hijoDer().esVacio())
		suma = numeroNavegable(cuenca.hijoIz(), cont);
	else if (cuenca.hijoIz().esVacio())
		suma = numeroNavegable(cuenca.hijoDer(), cont);
	else
		suma =  numeroNavegable(cuenca.hijoIz(), cont) + numeroNavegable(cuenca.hijoDer(), cont);
	suma += cuenca.raiz();
	if (suma > 2)
		++cont;
	if (suma < 0)
		suma = 0;
	return suma;
}

int numeroTramosNavegables(const Arbin<int>& cuenca) {
	// A IMPLEMENTAR
	if (cuenca.esVacio())
		return 0;
	int cont = 0;
	int suma =  numeroNavegable(cuenca, cont);
	if (suma > 2)
		--cont;
	return cont;
}*/

int numeroNavegable(const Arbin<int>& cuenca, int &cont){
	int suma;
	if (cuenca.esVacio()){
		return 0;
	}
	suma =  numeroNavegable(cuenca.hijoIz(), cont) + numeroNavegable(cuenca.hijoDer(), cont);
	if (cuenca.hijoDer().esVacio() && cuenca.hijoIz().esVacio()){
		suma++;
	}
	suma += cuenca.raiz();
	if (suma > 2)
		++cont;
	if (suma < 0)
		suma = 0;
	return suma;
}
int numeroTramosNavegables(const Arbin<int>& cuenca) {
	int cont = 0;
	int suma = numeroNavegable(cuenca, cont);
	if (suma > 2)
		--cont;
	return cont;
}



Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF)  {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}