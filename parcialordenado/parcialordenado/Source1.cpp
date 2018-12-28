#include<iostream>
using namespace std;


bool parcialordenado(int v[], int ini, int fin, int &min, int &max){
	int min1, min2, max1, max2;
	if (ini == fin){
		return true;
	}
	else{
		int mitad = (ini + fin) / 2;
		if (parcialordenado(v, ini, mitad, min1, max1) && parcialordenado(v, mitad + 1, fin, min2, max2)){
			if (fin - ini == 1 && v[ini] <= v[fin]){
				min = v[ini];
				max = v[fin];
				return true;
			}
			else if (min1 <= min2 && max1 <= max2 &&fin - ini != 1){
				min = min1;
				max = max2;
				return true;
			}
			else {
				return false;
			}
		}
		else return false;
	}
}

bool resuelveCaso(){
	int numero;
	cin >> numero;
	if (numero == 0){
		return false;
	}
	int v[100000];
	int i = 0;
	while (numero != 0){
		v[i] = numero;
		i++;
		cin >> numero;
	}
	int ini = 0;
	int fin = i - 1;
	int min, max;
	bool ok = parcialordenado(v, ini, fin, min, max);
	if (ok)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}