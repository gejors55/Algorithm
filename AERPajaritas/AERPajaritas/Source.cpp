#include <iostream>
using namespace std;


int pajaritas(int l, int h){
	int cont;
	if (l < 10 || h < 10){
		return 0;
	}
	else{
		if (l > h)
			cont = pajaritas(l - h, h);
		else
			cont = pajaritas(l, h - l);
		cont++;
	}
	return cont;
}

bool resuelveCaso(){
	int l, h;
	cin >> l >>h;
	if (l == 0 && h == 0)
		return false;
	cout << pajaritas(l, h) << endl;
}

int main(){
		while(resuelveCaso());
	return 0;
}