#include <iostream>

using namespace std;


/*
P: 0 <= numero<=long(v) && d>0
Q: creciente && divertido
creciente= para todo w: 0<w <n: 0 <= v[w+1]- v[w] < 1
divertido = (#w: 0<=w <n: v[w+1] = v[w]) < d
I: 0< i<n creciente, divertido. 0< contador < d
Cota = n -i -1
*/
bool divertido(int d, int numero, int v[]){
	int aux = v[0];
	int cont = 1;
	for (int i = 1; i < numero; i++){
		if (aux > v[i] || (v[i]-aux != 1 && v[i] -aux !=0))
			return false;
		else if (aux == v[i])
			if (cont == d)
				return false;
			else
				cont++;
		else{
			aux = v[i];
			cont = 1;
		}
	}
	return true;
}

void resuelveCaso(){
	int v[10000];
	int d, n;
	cin >> d >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	if (divertido(d,n,v))
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