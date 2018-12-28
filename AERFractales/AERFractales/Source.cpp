#include <iostream>

using namespace std;

int fractales(int num){
	
	if (num <= 1){
		return num * 4;
	}
	if (num > 1){
		
		return num *4 + 4*(fractales(num / 2));
	}
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (!cin){
		return false;
	}
	cout << fractales(n) << endl;

}

int main(){
	while (resuelveCaso());
	return 0;
}