/**
  NOMBRE Y APELLIDOS:
  LABORATORIO:
  PUESTO:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/**
  COMPLEJIDAD: Explica aquí justificadamente cuál es la complejidad de 
               esta función
			   ***A COMPLETAR***
*/


unsigned int numero_singulares1(Arbin<int> a, int &singulares, int &suma, int sumaNueva) {
	
	if (a.esVacio()){
		return 0;
	}
	else{
		int sumaIzq=0, sumaDer=0;
		int singularesIz, singularesDer;
		singularesIz = numero_singulares1(a.hijoIz(), singulares, sumaIzq, sumaNueva +a.raiz());
		singularesDer = numero_singulares1(a.hijoDer(), singulares, sumaDer, sumaNueva + a.raiz());
		if (sumaIzq +sumaDer == sumaNueva){
			singulares++;
		}
		suma += a.raiz() + sumaIzq+sumaDer;
		return  singulares;
	}

}
//(([4]3[-3])1[-4])
/*unsigned int numero_singulares1(Arbin<int> a, int &cont, int &suma, int sumaNueva) {
	
	if (a.esVacio()){
		return 0;
	}
	else if (a.hijoDer().esVacio() && a.hijoIz().esVacio()){
		suma += a.raiz();
		if (suma - sumaNueva + a.raiz() == 0){
			cont++;
		}
		return 1;
	}
	else{
		sumaNueva += a.raiz();
		numero_singulares1(a.hijoIz(), cont, suma, sumaNueva);
		//sumaNueva = suma;
		numero_singulares1(a.hijoDer(), cont, suma, sumaNueva);
		if (suma - sumaNueva + a.raiz() == 0){
			cont++;
		}
		suma = suma + a.raiz();
		//sumaNueva = 0;
		return cont;
	}

}*/
/*unsigned int numero_singulares1(Arbin<int> a, int &cont, int &suma, int sumaNueva) {

if (a.esVacio()){
return 0;
}
/*else if (a.hijoDer().esVacio() && a.hijoIz().esVacio()){
suma += a.raiz();
if (suma - sumaNueva == 0){
cont++;
}
return 1;
}
else{

//sumaNueva += a.raiz();
numero_singulares1(a.hijoIz(), cont, suma, sumaNueva + a.raiz());
//sumaNueva = suma;
numero_singulares1(a.hijoDer(), cont, suma, sumaNueva + a.raiz());
if (suma - sumaNueva == 0){
cont++;
}
suma = suma + a.raiz();
//sumaNueva = 0;
return cont;
}

}*/
unsigned int numero_singulares(Arbin<int> a) {
	int singulares = 0;
	int suma = 0;
	int sumaNueva = 0;
 	singulares = numero_singulares1(a, singulares, suma, sumaNueva);

	return singulares;
}

Arbin<int> lee_arbol(istream& in) {
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
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

/**
Este programa lee árboles de la entrada estándar, 
codificados de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con  
    v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
    con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada árbol leído, escribe en la salida estádar
el número de nodos singulares de dicho árbol.
	
Algunos casos representativos:

#
[0]
[5]
(([4]3[-3])1[-4])

////(([-2]0[-2])1[3])
//(([-1]0[3])2[2])
///((([0]-3[1])0(([-3]4[2])1([2]0[0])))
//(([0]0[0])0[0])

-El primero representa el árbol vacío. Al no tener nodos,
un árbol vacío tiene 0 nodos sigulares.
-El segundo representa un árbol con un único nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene 
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0. 
-El tercero representa otro árbol con un único nodo, cuyo
valor es 5. Por la misma razón que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente árbol:
     
	       1
		  /  \
		  3  -4
         / \  
        4  -3 

Este árbol tiene 2 nodos sigulares: la raíz, y la raíz del hijo 
izquierdo. 

Por tanto, la salida del programa para estos casos será:

0
1
1
2

*/

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		cout << numero_singulares(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
