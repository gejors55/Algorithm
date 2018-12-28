#include <iostream>

using namespace std;

int moda(int v[], int n){
	int contador =1;
	int moda = v[0];
	int numeroAnt = v[0];
	int max =0;
	for (int i = 1; i < n; i++){
		if (numeroAnt == v[i]){
			contador++;
			if (max < contador){
				moda = v[i];
				max = contador;
			}
			
		}
		else{
			
			numeroAnt = v[i];
			contador = 1;
		}
	}
	return moda;
}

void ordenar(int  v[], int num, int n){
	bool ok = false;
	int i = n;
	while (i>=0 && !ok) {
		if (num < v[i-1]){
			v[i] = v[i - 1];
		}
		else{
			v[i] = num;
			ok = true;
		}
			i--;
	}
	
}


bool resuelveCaso(){
	int n;
	cin >> n;
	if (!n) return false;
	int v[25000];
	int numero;
	for (int i = 0; i < n; i++){
		cin >> numero;
		ordenar(v, numero, i);
	}
	cout << moda(v, n) << endl;
	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}
