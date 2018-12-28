#ifndef __RIO_H
#define __RIO_H

#include "Pantano.h"
#include "DiccionarioHash.h"
#include <string>

using namespace std;
/**
 Excepci�n que se levanta cuando se trata de acceder
 a un pantano que no existe.
*/
class EPantanoNoExiste {};

/**
Excepci�n que se levanta cuando se trata de dar de
alta un pantano que ya existe
*/
class EPantanoDuplicado {};


// clase para la colecci�n de pantanos que contiene un r�o: diccionario de nombres de pantano 
// (clave = string) e info de pantano (valor = clase Pantano)

class Rio {
public:

	/**
	 Crea un r�o sin ning�n pantano
	*/
	Rio();
	
	/**
	Consulta el volumen embalsado en un pantano.
	Si el pantano no existe, se levanta la excepci�n EPantanoNoExiste
	@param pantano Nombre del pantano
	@return Volumen embalsado en el pantano
	*/
	float embalsado_pantano(const string& pantano) const;
	Pantano busca(string pantano);
	/**
	Consulta el total del volumen embalsado en el r�o.
	@return Volumen total embalsado (suma de los vol�menes embalsados en los embalses)
	*/
	float embalsado_total() const;


	/**
	Permite acceder por nombre a un pantano del r�o.
	Si el pantano no existe, se levanta la excepci�n EPantanoNoExiste
	@param pantano Nombre del pantano
	@return Una referencia constante al pantano
	*/
	const Pantano& buscar_pantano(const string& pantano) const;

private:
	DiccionarioHash<string, Pantano> _pantanos;

};



#endif // !__RIO_H
