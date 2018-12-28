#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//(([0]0([0]0[0]))0(#-2(([0]-1[0])0([0]0[0]))))
//(([0]0([0]0[0]))0(#-2((([0]-4[0])0[0])0(([0]-2[0])0[0]))))
//[0]
//(([0]0([0]0[0]))0(#-2((([0]-4[0])0[0])0(([0]-1[0])0[0]))))



int contarTramosNavegables (const Arbin<int>& cuenca, int & contador){
	int suma;
	if (cuenca.esVacio()){
		return 0;
	}
	if (cuenca.hijoIz().esVacio() && cuenca.hijoDer().esVacio()){
		return 1;
	}
	if (cuenca.hijoIz().esVacio())
		suma = contarTramosNavegables(cuenca.hijoDer(), contador)+ cuenca.raiz();
	else if(cuenca.hijoDer().esVacio()){
		suma=  contarTramosNavegables(cuenca.hijoIz(), contador)+ cuenca.raiz();
	}
	else{
		suma = contarTramosNavegables(cuenca.hijoIz(), contador) + contarTramosNavegables(cuenca.hijoDer(), contador) + cuenca.raiz();
	}
	if (suma >= 3)
		++contador;
	else if (suma < 0)
		suma = 0;
	return suma;
}
int numeroTramosNavegables(const Arbin<int>& cuenca) {
	int contador = 0;
	int suma = contarTramosNavegables(cuenca, contador);
	if (suma >= 3){
		contador--;
	}
	return contador;
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