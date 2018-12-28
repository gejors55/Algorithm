#include <iostream>

using namespace std;

/*

*/
int pareja(int numero, int v[], int ini, int fin){
	int mitad = (ini + fin) / 2;
	int pos;
	if (ini >=fin)
		return ini;
	else if (v[mitad] != v[mitad + 1] && v[mitad] != v[mitad - 1]){
		return mitad;
	}
	else if (v[mitad] != v[mitad + 1])
		pos = pareja(numero, v, mitad + 1, ini);
	else
		pos = pareja(numero, v, ini, mitad);
	return pos;
}

void resuelveCaso(){
	int v[100000];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cout <<pareja(n, v, 0, n - 1) << endl;
}

int main(){
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i)
		resuelveCaso();
}