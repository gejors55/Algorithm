#include <iostream>

using namespace std;

/*



coste o(n)
*/
int orden(int numero, int v[]){
	bool ok=true;
	int i = 0;
	int j = numero - 1;
	int aux;
	int pos;
	while (ok){
		if (i > j){
			ok = false;
			pos = i;
		}
		else if (v[i] >= 0 && v[j] < 0){
			i++;
			j--;
		}
		else if (v[i] < 0 && v[j] >= 0){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
		}
		else if (v[i] >= 0 && v[j] >= 0){
			i++;
		}

		else if (v[i] < 0 && v[j] < 0){
			j--;
		}
	}
	return pos;
}

void resuelveCaso(){
	int v[100000];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int pos = orden(n, v);
	cout << v[0];
	for (int i = 1; i < n; ++i)
		cout << " " << v[i];
	cout << endl;
	cout << pos << endl;
}

int main(){
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i)
		resuelveCaso();
}