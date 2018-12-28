#include <iostream>

using namespace std;

int elevame(int n, int u){
	int r;
	if (u == 0)
	return 1;
	else{
		r = elevame(n, u - 1);
		return (((n % 31543) * r) % 31543);
	}
}

bool resuelveCaso(){
	int n;
	int u;
	cin >> n >> u;
	if (n == 0 && u == 0)
		return false;
	cout << elevame(n, u) << endl;
}


int main(){

	while (resuelveCaso());

	return 0;
}