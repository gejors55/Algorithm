#ifndef ___PANTANO_H
#define ___PANTANO_H

// clase con la informaci�n relativa a un pantano: capacidad m�xima y volumen embalsado

class Pantano {
public:
	Pantano(float cmax = 0, float vol = 0) : _cmax(cmax), _vol(vol) {}
	float cmax() const; 
	float vol() const; 
	void pon_vol(float vol); 
private:
	float _cmax; // Capacidad m�xima
	float _vol;  // Volumen embalsado
};

#endif // !___PANTANO_H


