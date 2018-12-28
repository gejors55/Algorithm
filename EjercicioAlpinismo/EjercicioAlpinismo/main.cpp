#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int alpinista(const Arbin<char>& a, int nivel){
	if (a.esVacio()){
		return 0;
	}
	else{
		int suma = alpinista(a.hijoIz(), nivel + 1) + alpinista(a.hijoDer(), nivel + 1);
		if (a.raiz() == 'X'){
			suma += 2 * nivel;
		}
		return suma;
	}
}

int tiempoAyuda(const Arbin<char>& falda) {
	// A IMPLEMENTAR
	int suma = alpinista(falda, 0);
	return suma;
}

Arbin<char> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = leeArbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = leeArbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}

int main() {
	Arbin<char> falda;
	while (cin.peek() != EOF)  {
		cout << tiempoAyuda(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}