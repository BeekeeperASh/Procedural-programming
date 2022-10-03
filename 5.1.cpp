#include <iostream>
#include <cmath>
using namespace std;

double e(int a, int b){
		while(a != 0 and b!= 0){		
			if(a>b){
				a = a - b;
			}else{
				b = b - a;
			}
		}
		return a+b;
	}

double em(int a, int b){
	double x;
	while(a != 0 and b !=0){
		if(a > b){
			x = a % b;
			if(x > b / 2){
				a = abs(x - b);
			} else {
				a = x;
			}
		} else {
			x = b % a;
			if(x > a / 2){
				b = abs(x - a);
			} else {
				b = x;
			}
		}
	}
	return a+b;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << e(a, b) << endl;
	cout << em(a, b) << endl;
	return 0;
}
