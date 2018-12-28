
#include <iostream>

using namespace std;

int parejas(int v[], int n){
	int parejas;


	return parejas;
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (!n) return false;
	int v[100000];
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	cout << parejas(v, n) << endl;
	return true;
}


int main(){
	while (resuelveCaso());
	return 0;
}