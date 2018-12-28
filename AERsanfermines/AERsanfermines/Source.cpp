#include <iostream>

using namespace std;


void velocidad( int n, int & max){
	if (n > max){
		max = n;
	}
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (!cin)
		return false;
	int max = 0;
	for (int i = 0; i < n; ++i){
		int numero;
		cin >> numero;
		 velocidad(numero, max);
	}
	cout << max << endl;
	return true;
}

int main(){
	while (resuelveCaso())
		;
	return 0;
}