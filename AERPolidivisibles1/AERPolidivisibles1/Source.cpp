#include <iostream>

using namespace std;

int calculaDigitos(long long int n){
	int cont = 0;
	while (n >= 10){
		cont++;
		n = n / 10;
	}
	return cont + 1;
}

bool polidivisibles(long long int n, int longi){
	if (longi == 0)
		return true;
	if (n % longi == 0)
		polidivisibles(n / 10, longi -1);
	else{
		return false;
	}
}

bool resuelveCaso(){
	long long int n;
	cin >> n;
	if (!cin)
		return false;
	if (polidivisibles(n, calculaDigitos(n)))
		cout << "POLIDIVISIBLE" << endl;
	else
		cout << "NO POLIDIVISIBLE" << endl;
	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}