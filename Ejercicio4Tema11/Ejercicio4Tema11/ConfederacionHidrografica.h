#ifndef __CONFEDERACION_HIDROGRAFICA_H
#define __CONFEDERACION_HIDROGRAFICA_H

#include "diccionarioHash.h"
#include "Rio.h"

class ERioDuplicado{};
class ERioNoExiste{};

// clase para representar la confederaci�n hidrogr�fica: diccionario de nombres de r�o (clave = string) 
// y colecci�n de los pantanos que contiene el r�o (valor = clase Rio = diccionario)

class ConfederacionHidrografica {
  public:
	  /**
	    Crea una confederaci�n vac�a, sin r�os.
	  */
	  ConfederacionHidrografica();

	  /**
	    Inserta un nuevo r�o en la confederaci�n.
		Si el r�o ya existe, levanta la excepci�n ERioDuplicado
		@param rio El r�o a insertar
	  */
	  void insertar_rio(const string& rio);

	  /**
  	    Inserta un nuevo pantano en un r�o.
	    Si el r�o no existe, levanta la excepci�n ERioNoExiste.
	    Si el pantano ya existe, levanta la excepci�n EPantanoDuplicado.
	    @param rio El nombre del r�o al que se va a a�adir del pantano.
	    @param pantano El nombre del pantano a a�adir
	    @cmax Capacidad m�xima del pantano
	    @vol Volumen inicial embalsado en el pantano
	  */
	  void insertar_pantano(const string& rio, const string& pantano, const float cmax, const float vol); 


	  /**
	    Embalsa un cierto volumen en un pantano de un rio
	    Si el r�o no existe, se levanta la excepci�n ERioNoExiste
	    Si el pantano no existe, se levanta la excepci�n EPantanoNoExiste
		Si no cabe todo el volumen de agua, el pantano se llena
		@param rio Nombre del rio
	    @param pantano Nombre del pantano
	    @param vol Volumen a embalsar
	  */
	  void embalsar(const string& rio, const string& pantano, const float vol);
	  
	  
	  /**
	    Consulta el volumen embalsado en un pantano de un r�o
	    Si el r�o no existe, se levanta la excepci�n ERioNoExiste
	    Si el pantano no existe, se levanta la excepci�n EPantanoNoExiste
	    @param rio Nombre del rio
	    @param pantano Nombre del pantano
	  */
	  float embalsado_pantano(const string& rio, const string& pantano) const; 

	  /**
	   Consulta el volumen total embalsado en un r�o
	   Si el r�o no existe, se levanta la excepci�n ERioNoExiste
	   @param rio Nombre del rio
	  */
	  float embalsado_cuenca(const string& rio) const; 

	  /**
	   Realiza un transvase de agua entre pantanos
	   Si alguno de los r�os no existe, se levanta la excepci�n ERioNoExiste
	   Si alguno de los pantanos no existe, se levanta la excepci�n EPantanoNoExiste
	   Si el volumen a transvasar es negativo, se cambia el sentido del transvase (es decir,
	   se pasa el agua del pantano destino al origen)
	   Solo se trasvasa la cantidad que quepa en el pantano destino, y, como 
	   mucho, la cantidad embalsada en el pantano de origen
	   @param rio_origen Nombre del r�o origen
	   @param pantano_origen Nombre del pantano origen
	   @param rio_destino Nombre del r�o destino
	   @param pantano_destino Nombre del pantano destino
	   @param vol Volumen a transvasar
	  */
	  void transvasar(const string& rio_origen, const string& pantano_origen, 
		              const string& rio_destino, const string& pantano_destino, 
		              float vol); 
  private:
	  DiccionarioHash<string, Rio> _rios;

	  /**
  	   Busca un r�o
	   Levanta la excepci�n ERioNoExiste en caso de que el r�o no exista.
	   @rio Nombre del rio a buscar
	   @return Referencia constante al r�o
	   */
	  const Rio& busca_rio(const string& rio) const;

};

#endif // !__CONFEDERACION_HIDROGRAFICA_H
