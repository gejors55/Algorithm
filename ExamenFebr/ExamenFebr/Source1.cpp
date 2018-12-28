#include <iostream>

using namespace std;

/*
coste O(n/2)
*/
bool creciente(int numero, int v[], int ini, int fin){
	bool oki,okd;
	int mitad = (ini + fin) / 2;
	if (ini >= fin){
		return true;
	}
	oki =creciente(numero, v, ini, mitad );
	okd =creciente(numero, v, mitad+1, fin);
	//hasta aqui lo unico que hemos hecho es quedarnos en 1 elemento


	if (oki && okd &&(v[mitad + 1] - v[mitad] == 1 || v[mitad + 1] - v[mitad] == 0))
		return true;
	else
		return false;
}

void resuelveCaso(){
	int v[100000];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	if (creciente(n, v, 0, n - 1))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
}

int main(){
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i)
		resuelveCaso();
}