#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;	
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};


void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	Lista<string>::ConstIterator bieniter = bien.cbegin();
	Lista<string>::ConstIterator maliter = mal.cbegin();
	Lista<string>::ConstIterator bienfin= bien.cend();
	Lista<string>::ConstIterator malfin = mal.cend();
	Diccionario<string, int> dic;
	Diccionario<string, int>::Iterator iter = dic.begin();
	while (bieniter != bienfin){
		if (dic.contiene(bieniter.elem())){
			iter = dic.busca(bieniter.elem());
			iter.valor()++;
		}
		else{
			dic.inserta(bieniter.elem(), 1);
		}
		bieniter.next();
	}
	while (maliter != malfin){
		if (dic.contiene(maliter.elem())){
			iter = dic.busca(maliter.elem());
			iter.valor()--;
		}
		else{
			dic.inserta(maliter.elem(), -1);
		}
		maliter.next();
	}
	Lista<Puntuacion>::Iterator iterador = listado.begin();
	Diccionario<string, int>::ConstIterator iter2 = dic.cbegin();
	Diccionario<string, int>::ConstIterator iterfinal = dic.cend();
	while (iter2 != iterfinal){
		if (iter2.valor() != 0){
			listado.insertar(Puntuacion(iter2.clave(), iter2.valor()), iterador);
			//listado.pon_final(Puntuacion(iter2.clave(), iter2.valor()));
		}
		iter2.next();

	}


}


void imprimePuntuaciones(Lista<Puntuacion>& listado) {
  Lista<Puntuacion>::ConstIterator i = listado.cbegin();
  Lista<Puntuacion>::ConstIterator e = listado.cend();
  while (i != e) {
	  cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
      i.next();	  
  }  
  cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
  string comienzo;
  while (cin >> comienzo) {
	 Lista<string> bien;
	 Lista<string> mal;
	 Lista<Puntuacion> listado;
	 leeResultados(bien, mal);
	 califica(bien, mal,listado);
	 imprimePuntuaciones(listado);
  }
  return 0;   
}