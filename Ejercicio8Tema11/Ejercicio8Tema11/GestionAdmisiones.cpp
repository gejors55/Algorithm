/**
  NOMBRE Y APELLIDOS:
  LABORATORIO:
  PUESTO:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "GestionAdmisiones.h"
#include "DiccionarioHash.h"
#include <iostream>
/** 
Implementación de las operaciones de la clase Paciente 
*/

Paciente::Paciente(const string& nombre, unsigned int edad, const string& sintomas):
    _nombre(nombre), _sintomas(sintomas), _edad(edad) {}	

unsigned int Paciente::edad() const {
   return _edad;	
}
const string& Paciente::nombre() const {
   return _nombre;	
}
const string& Paciente::sintomas() const {
   return _sintomas;	
}

/**
Implementa aquí los métodos de las clases adicionales
*/

 
/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de las mismas.
*/ 

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR
	DiccionarioHash<CodigoPaciente, Paciente> dic = DiccionarioHash<CodigoPaciente, Paciente>();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas) {
	// A IMPLEMENTAR
	if(dic.contiene(codigo)){ 
		throw EPacienteDuplicado();
	}
	Paciente pa = Paciente(nombre, edad, sintomas);
	list.pon_final(codigo);
	dic.inserta(codigo, pa);
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENTAR
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
void GestionAdmisiones::siguiente(CodigoPaciente& codigo) const {
  // A IMPLEMENTAR
	if (dic.esVacio()){
		throw ENoHayPacientes();
	}
	codigo = list.primero();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
bool GestionAdmisiones::hay_pacientes() const {  
  // A IMPLEMENTAR
	return (!dic.esVacio());
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	// A IMPLEMENTAR
	if (dic.contiene(codigo)){
		dic.borra(codigo);
		Lista<CodigoPaciente>::Iterator it = list.begin();
		while (it.elem() != codigo){
			it.next();
		}
		list.eliminar(it);
	}
}
   
