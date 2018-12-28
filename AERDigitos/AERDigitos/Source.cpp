#include <iostream>
#include <string>
using namespace std;

int digitos(int num, string &r){
	if (num < 10){
		r = to_string(num)+r;
		return num;
	}
	else{
		r = to_string(num % 10) +r;
		r = " " + r;
		r = "+" + r;
		r = " " + r;
		return (num%10 + digitos(num / 10, r));
		
	}
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (n < 0)
		return false;
	string r;
	int num = digitos(n, r);
	cout << r << " " << "=" << " "<< num << endl;
	return true;
}
int main(){
	while (resuelveCaso());
	return 0;
}