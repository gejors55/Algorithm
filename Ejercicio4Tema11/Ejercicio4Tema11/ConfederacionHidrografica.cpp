#include "ConfederacionHidrografica.h"

ConfederacionHidrografica::ConfederacionHidrografica() {}  

void ConfederacionHidrografica::insertar_rio(const string&rio ) {
    if (_rios.contiene(rio)) throw ERioDuplicado();
    _rios.inserta(rio,Rio());	// insertamos r�o con una colecci�n vac�a de pantanos	 
} 

void ConfederacionHidrografica::insertar_pantano(const string& rio, const string& pantano, const float cmax, const float vol ) {
	if (!_rios.contiene(rio)) throw ERioNoExiste();
	DiccionarioHash<string, Rio>::Iterator it = _rios.busca(rio);
	Pantano pa = it.valor().busca(pantano);
	
}
     
void ConfederacionHidrografica::embalsar(const string& rio, const string& pantano, const float vol) {
	
}

float ConfederacionHidrografica::embalsado_pantano(const string& rio, const string& pantano) const {
	return busca_rio(rio).embalsado_pantano(pantano);  
}

float ConfederacionHidrografica::embalsado_cuenca(const string& rio) const {
	return busca_rio(rio).embalsado_total();  
}

void ConfederacionHidrografica::transvasar(const string& rio_origen, const string& pantano_origen, 
	                                       const string& rio_destino, const string& pantano_destino, float vol) {
   // a implementar
}


const Rio& ConfederacionHidrografica::busca_rio(const string& rio) const {
	DiccionarioHash<string, Rio>::ConstIterator irio = _rios.cbusca(rio);
	DiccionarioHash<string, Rio>::ConstIterator ifin = _rios.cend();
	if (irio != ifin) {
		return irio.valor();
	}
	throw ERioNoExiste();
}

