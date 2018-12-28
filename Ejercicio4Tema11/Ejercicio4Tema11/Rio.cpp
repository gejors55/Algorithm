#include "Rio.h"


Rio::Rio() {}

float Rio::embalsado_pantano(const string& pantano) const {
	return buscar_pantano(pantano).vol();  
}

float Rio::embalsado_total() const {
	DiccionarioHash<string, Pantano>::ConstIterator ipantano = _pantanos.cbegin();
	DiccionarioHash<string, Pantano>::ConstIterator ifin = _pantanos.cend();
	int suma =0;
	while (ipantano != ifin){
		suma += ipantano.valor().vol();
		ipantano.next();
	}
	return suma;
}


const Pantano& Rio::buscar_pantano(const string& pantano) const {
	DiccionarioHash<string, Pantano>::ConstIterator ipantano = _pantanos.cbusca(pantano);
	DiccionarioHash<string, Pantano>::ConstIterator ifin = _pantanos.cend();
	if (ipantano == ifin) throw EPantanoNoExiste();
	return ipantano.valor();
}


 Pantano Rio::busca( string pantano)  {
	DiccionarioHash<string, Pantano>::Iterator ipantano = _pantanos.busca(pantano);
	DiccionarioHash<string, Pantano>::Iterator ifin = _pantanos.end();
	if (ipantano == ifin) throw EPantanoNoExiste();
	return ipantano.valor();
}