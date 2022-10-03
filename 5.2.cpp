#include <iostream>;
using namespace std;
int p(int n){
	for(int i = 2; i*i < n; i = i + 1){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	cin >> n;
	cout << 2 << " ";
	for(int i = 3; i <= n; i = i + 2){
		if(p(i)==1){
			cout << i << " ";
		}
	}
}
