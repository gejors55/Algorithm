#include <iostream>

using namespace std;


bool polidivisibles(long long int n, int &digitos){
	if (n < 10){
		digitos = 2;
		return true;
	}
	if (!polidivisibles(n / 10, digitos))
		return false;
	if (n%digitos == 0){
		digitos++;
		return true;
	}
	else
		return false;
}

bool busqueda(long long int numero, int cifras, int contador, bool ok, int min, int &digitos){	
	if (digitos > cifras){
		return false;
	}
	if (polidivisibles(numero, digitos) && !ok){
		cout << numero << endl;
		digitos = digitos - 1;
	}

	if (cifras > digitos && !ok){
		busqueda(numero * 10, cifras, 0, ok, min, digitos);
		ok = false;
	}
	if (digitos <= min){
		return false;
	}
	if (contador < 9){
		ok = false;
		busqueda(numero + 1, cifras, contador + 1, ok, min, digitos);
	}
	else{
		ok = true;
		busqueda(numero /10, cifras, 0, ok, min, digitos);	
	}

}

bool resuelveCaso(){
	long long int n;
	cin >> n;
	if (!cin)
		return false;
	int cifras;
	cin >> cifras;
	int digitos;
	polidivisibles(n, digitos);
	digitos = digitos - 1;
	if (digitos == cifras){
		cout << n << endl;
	}
	else
		busqueda(n, cifras, 9, false, digitos, digitos);
	
	cout << "---" << endl;

	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}