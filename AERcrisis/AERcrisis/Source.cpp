#include <iostream>

using namespace std;

bool crisis(int v[], int n){
	bool ok = true;
	int num = v[0];
	int i = 1;
	while (ok && i< n){
		if (v[i] <= num){
			ok = false;
		}
		else{
			num = v[i];
		}
		++i;
	}
	return ok;
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (n == 0)
		return false;
	int v[100];
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	if (crisis(v,n))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}