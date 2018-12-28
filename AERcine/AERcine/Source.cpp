#include <iostream>

using namespace std;
bool colaCine(int v[], int n, int &g){
	bool impar = false;
	g = 0;
	for (int i = 0; i < n; ++i){
		if (v[i] % 2 == 1){
			impar = true;
		}
		else if (v[i] % 2 == 0 && impar){
			return false;
		}
		else{
			++g;
		}
	}
	return true;
}
void resuelveCaso(){
	int n, g;
	cin >> n;
	int v[10000];
	bool ok;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	ok = colaCine(v, n, g);
	if (!ok)
		cout << "NO" << endl;
	else
		cout << "SI " << g << endl;
}
int main(){
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i)
		resuelveCaso();
	return 0;
}