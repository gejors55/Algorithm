/*
p: 0<n<= long(v)
q: suma = (sumatorio v[g]: 0<= g < n: g = mirador);
mirador = (para todo w: g<w<n: v[w]< v[g])
I:0 <= i < n-1 && suma = v[n-1] +  (sumatorio v[i]: 0<= i < n-1: i = mirador);
mirador = (para todo w: i<w<n: v[w]< v[i])
Cota: n - i
*/
#include <iostream>

using namespace std;

int miradores(int v[], int n){
	int cont = 1;
	int max = v[n - 1];
	for (int i = n - 2; i >= 0; --i){
		if (v[i] > max){
			++cont;
			max = v[i];
		}
	}

	return cont;
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (!n) return false;
	int v[100000];
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	cout << miradores(v, n) << endl;
	return true;
}


int main(){
	while (resuelveCaso());
	return 0;
}