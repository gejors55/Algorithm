#ifndef _RACIONAL_H
#define _RACIONAL_H

#include <iostream>
#include <string>

using namespace std;

class Racional {
public:
      //Excepcion que se lanza cuando se trata de crear
	  //una fraccion con denominador 0
	class EDenominadorCero {};
      //Excepcion que se lanza cuando se produce una division
      //por 0
	class EDivisionPorCero {};
	
	  // Funcion que permite escribir una fraccion en un 'stream'
	friend ostream& operator<<(ostream& out, const Racional& f);
	//CONSTRUCTORAS
	Racional();
	Racional(long n, long d);
	//METODOS
	Racional suma(Racional r);
	Racional operator-(Racional r);
	void operator*=(Racional r);
	void divideYActualiza(Racional r);
	bool operator==(Racional r);
	//**** COMPLETAR
	//  Deben declararse los metodos publicos de la clase
	//****
private:
	long _numer;     // El numerador
	long _denom;     // El denominador 
	void reduce();   // Transforma la fraccion en una equivalente irreducible (es decir, una en la que
	                 // el denominador es siempre positivo, y el unico divisor comun del numerador y el 
					 // denominador es 1)	
	static long mcm(long v1, long v2);     // Minimo comun multiplo de v1 y v2
	static long mcd(long v1, long v2);     // Maximo comun divisor de v1 y v2 
};

#endif