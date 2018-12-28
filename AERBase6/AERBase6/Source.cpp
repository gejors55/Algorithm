#include <iostream>
using namespace std;


int base(int n){
	if (n < 6){
		return n;
	}
	else{
		int r = base(n / 6);
		return ((r * 10) + (n % 6));
	}
}

void resuelveCaso(){
	int n;
	cin >> n;
	 int num = base(n);
	 cout << num << endl;
	
}

int main(){
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		resuelveCaso();
	return 0;
}