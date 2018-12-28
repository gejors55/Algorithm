#include "GestionAdmisiones.h"

/** 
Implementación de las operaciones de la clase Paciente 
*/

Paciente::Paciente(const string& nombre, unsigned int edad, const string& sintomas):
    _nombre(nombre),  _sintomas(sintomas), _edad(edad) {}	

unsigned int Paciente::edad() const {
   return _edad;	
}
const string& Paciente::nombre() const {
   return _nombre;	
}
const string& Paciente::sintomas() const {
   return _sintomas;	
}

tPaciente::tPaciente(Gravedad grav, CodigoPaciente cod){
	_gravedad = grav;
	_codig = cod;
}

const Gravedad& tPaciente::gravedad() const{
	return _gravedad;
}
const CodigoPaciente& tPaciente::codigos() const{
	return _codig;
}
/**
Implementa aquí los métodos de las clases adicionales
*/

 
/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de los mismos.
*/ 


/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	DiccionarioHash<CodigoPaciente, Paciente> dic = DiccionarioHash<CodigoPaciente, Paciente>();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas, Gravedad gravedad) {
	// A IMPLEMENATR
	if (dic.contiene(codigo)){
		throw EPacienteDuplicado();
	}
	Paciente pa = Paciente(nombre, edad, sintomas);
	dic.inserta(codigo, pa);
	tPaciente pac = tPaciente(gravedad, codigo);
	//if (pac.gravedad() == 0)
		//list.pon_final(pac);
	///else{
		Lista<tPaciente>::Iterator it = list.begin();
		Lista<tPaciente>::Iterator fin = list.end();
		while ((it != fin) &&(pac.gravedad() <= it.elem().gravedad())){
			it.next();
		}
		list.insertar(pac, it);
	//}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENATR
	if (!dic.contiene(codigo)){
		throw EPacienteNoExiste();
	}
	nombre = dic.valorPara(codigo).nombre();
	edad = dic.valorPara(codigo).edad();
	sintomas = dic.valorPara(codigo).sintomas();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {
	// A IMPLEMENATR
	if (dic.esVacio()){
		throw ENoHayPacientes();
	}
	codigo = list.primero().codigos();
	gravedad = list.primero().gravedad();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
bool GestionAdmisiones::hay_pacientes() const {  
  // A IMPLEMENATR
	return (!dic.esVacio());
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
  // A IMPLEMENATR
	if (dic.contiene(codigo)){
		dic.borra(codigo);
		Lista<tPaciente>::Iterator it = list.begin();
		while (it.elem().codigos() != codigo){
			it.next();
		}
		list.eliminar(it);
	}
}
   
