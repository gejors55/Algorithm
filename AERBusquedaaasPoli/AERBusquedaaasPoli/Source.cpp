#include <iostream>
#include <cmath>

using namespace std;
bool polidivisibles(long long int n, int &digitos){
	if (n < 10){
		digitos = 2;
		return true;
	}
	if (!polidivisibles(n / 10, digitos)){
		digitos++;
		return false;
	}
	if (n%digitos == 0){
		digitos++;
		return true;
	}
	else{
		digitos++;
		return false;
	}
}

void busqueda(long long int n, int cifras, int & cont){
	int digitos;
	if (polidivisibles(n, digitos)){
		cout << n << endl;
	}
	if (cifras ==digitos && n >)
	if (cifras > digitos - 1){
		busqueda(n * 10, cifras, cont);
		if (cont == 9){
		cont = 0;
		}
		else{
			cont++;
		}
	}
	if (cont < 9){
		cont++;
		busqueda(n+1, cifras, cont);
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
	if (cifras <= digitos -1){
		cout << n << endl;
	}
	else{
		int cont = 0;
		busqueda(n, cifras, cont);
	}
	cout << "---" << endl;

	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}