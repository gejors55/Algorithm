#include<iostream>

using namespace std;


int cajas( int ini, int fin){
	int mitad = (ini + fin) / 2;
	int r;
	if (ini == fin){
		return 1;
	}
	else{
		if (fin % 2 == 0){
			r = cajas(mitad +1, fin);
		}
		else{
			r = cajas(ini, mitad - 1);
		}
		
		return r + 1;
	}
}

bool resuelveCaso(){
	int n; 
	cin >> n;
	if (!cin)
		return false;
	cout << cajas( 1, n) << endl;
	return true;
}
int main(){

	while (resuelveCaso());
	return 0;
}