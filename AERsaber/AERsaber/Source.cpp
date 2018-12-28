#include <iostream>

using namespace std;

bool solve(int ini, int fin, int n, int intentos, int v[], int &cont){
	if (ini == fin)
		return true;
	if (intentos <= cont)
		return false;
	if (v[cont] < ini || v[cont] > fin)
		return solve(ini, fin, n, intentos, v, ++cont);
	int aux = v[cont];
	if (v[cont] <= n)
		return solve(aux, fin, n, intentos, v, ++cont);
	else
		return solve(ini, aux -1, n, intentos, v, ++cont);
}

bool resuelveCaso(){
	int ini, fin, n;
	cin >> ini >> fin >> n;
	if (!ini && !fin && !n)
		return false;
	int intentos;
	cin >> intentos;
	int v[250000];
	for (int i = 0; i < intentos; i++){
		cin >> v[i];
	}
	int contador = 0;
	if (solve(ini, fin, n, intentos, v, contador))
		cout << "LO SABE" << endl;
	else{
		cout << "NO LO SABE" << endl;
	}
	return true;
}

int main(){

	while(resuelveCaso());
}