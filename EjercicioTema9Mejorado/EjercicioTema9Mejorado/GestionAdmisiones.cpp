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

tPaciente::tPaciente(const Paciente paciente, const Gravedad grav, Lista<CodigoPaciente>::Iterator it) :
_paciente(paciente), _gravedad(grav), _it(it) {}

const Gravedad& tPaciente::gravedad() const{
	return _gravedad;
}

const Lista<CodigoPaciente>::Iterator & tPaciente::iteradores() const{
	return _it;
}
const Paciente tPaciente::paciente() const{
	return _paciente;
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
	DiccionarioHash<CodigoPaciente, tPaciente> dic = DiccionarioHash<CodigoPaciente, tPaciente>();
	Lista<CodigoPaciente> listaGraves = Lista<CodigoPaciente>();
	Lista<CodigoPaciente> listaNormal = Lista<CodigoPaciente>();
	Lista<CodigoPaciente> listaLeves = Lista<CodigoPaciente>();
}
/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas, Gravedad gravedad) {
	// A IMPLEMENATR

	if (dic.contiene(codigo))
		throw EPacienteDuplicado();
	else{
		Paciente pac = Paciente(nombre, edad, sintomas);
		Lista<CodigoPaciente>::Iterator it = listaGraves.end();
		if (gravedad == GRAVE){
			listaGraves.pon_ppio(codigo);
			it = listaGraves.begin();
		}
		else if (gravedad == NORMAL){
			listaNormal.pon_ppio(codigo);
			it = listaNormal.begin();

		}
		else if (gravedad == LEVE){
			listaLeves.pon_ppio(codigo);
			it = listaLeves.begin();
		}

		tPaciente tPac = tPaciente(pac, gravedad, it);
		dic.inserta(codigo, tPac);
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENATR
	if (!dic.contiene(codigo))
		throw EPacienteNoExiste();
	else{
		nombre = dic.valorPara(codigo).paciente().nombre();
		edad = dic.valorPara(codigo).paciente().edad();
		sintomas = dic.valorPara(codigo).paciente().sintomas();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {
	// A IMPLEMENATR
	if (!listaGraves.esVacia()){
		codigo = listaGraves.ultimo();
		gravedad = GRAVE;
	}
	else if (!listaNormal.esVacia()){
		codigo = listaNormal.ultimo();
		gravedad = NORMAL;
	}
	else if (!listaLeves.esVacia()){
		codigo = listaLeves.ultimo();
		gravedad = LEVE;
	}
	else
		throw ENoHayPacientes();
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
		Gravedad grav = dic.valorPara(codigo).gravedad();

		if (grav == GRAVE){
			listaGraves.eliminar(dic.valorPara(codigo).iteradores());
		}
		else if (grav == NORMAL){
			listaNormal.eliminar(dic.valorPara(codigo).iteradores());
		}
		else if (grav == LEVE){
			listaLeves.eliminar(dic.valorPara(codigo).iteradores());
		}
		dic.borra(codigo);
	}
}
   
