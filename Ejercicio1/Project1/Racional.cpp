#include "Racional.h"
#include <cmath>

  //Metodos publicos

  	//**** COMPLETAR
	//  Deben implementarse los metodos publicos de la clase
	//****
//CONSTRUCTORAS
Racional::Racional(){
	_numer = 0;
	_denom = 1;
}
Racional::Racional(long n, long d){
	if (d == 0)
		throw EDenominadorCero();
	_numer = n;
	_denom = d;
	reduce();
}
//METODOS
Racional Racional::suma(Racional r){
	long denominador = mcm(_denom, r._denom);
	_numer = _numer *(denominador / _denom) + r._numer*(denominador / r._denom);
	_denom = denominador;
	return Racional(_numer, _denom);
}
Racional Racional::operator-(Racional r){
	long denominador = mcm(_denom, r._denom);
	_numer = _numer *(denominador / _denom) - r._numer*(denominador / r._denom);
	_denom = denominador;
	return Racional(_numer, _denom);
}
void Racional::operator*=(Racional r){
	_numer = _numer * r._numer;
	_denom = _denom * r._denom;
	reduce();
}
void Racional::divideYActualiza(Racional r){
	if (r._numer == 0)
		throw EDivisionPorCero();
	_numer = _numer * r._denom;
	_denom = _denom * r._numer;
	reduce();
}
bool Racional::operator==(Racional r){
	r.reduce();
	return (r._numer == _numer && r._denom == _denom);
}


  
  // Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

