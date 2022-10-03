#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
	setlocale(0, "");
	int SellerAndQuantity[3][4] = { 5, 2, 0, 10, 3, 5, 2, 5, 20, 0, 0, 0 };
	double Price[4][2] = { 1.20, 0.50, 2.80, 0.40, 5.00, 1.00, 2.00, 1.50 };
	int N = 0, M = 0, k = 0;
	double arr[3][2] = { 0,0,0,0,0,0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				arr[N][M] = arr[N][M] + SellerAndQuantity[i][k] * Price[k][j];
			}
			if (M < 1) { M += 1; }
			else { N += 1; M = 0; }
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << arr[i][j] << " ";
			if (j == 1) { cout << endl; }
		}
	}
	double Smin = 1000, Smax = 0, S_all = 0, S_all_without_comission = 0, comission_all = 0;
	int jmin = 0, jmax = 0, jcomissmax = 0, jcomissmin = 0;
	double comissionmin = 1000, comissionmax = 0;
	string temp = "Продавец №";
	for (int i = 0; i < 3; i++) {
		if ((arr[i][0] + arr[i][1]) > Smax) {
			Smax = arr[i][0] + arr[i][1];
			jmax = i + 1;
		}
		if ((arr[i][0] + arr[i][1]) < Smin) {
			Smin = arr[i][0] + arr[i][1];
			jmin = i + 1;
		}
		if (arr[i][1] > comissionmax) {
			comissionmax = arr[i][1];
			jcomissmax = i + 1;
		}
		if (arr[i][1] < comissionmin) {
			comissionmin = arr[i][1];
			jcomissmin = i + 1;
		}
	}
	cout << "1) " << Smax << " " << temp << jmax << endl << Smin << " " << temp << jmin << endl;
	cout << "2) " << arr[jcomissmax - 1][1] << " " << temp << jcomissmax << endl << arr[jcomissmin - 1][1] << " " << temp << jcomissmin << endl;
	cout << "3) "; for (int i = 0; i < 3; i++) { S_all += (arr[i][0] + arr[i][1]); }; cout << S_all << endl;
	cout << "4) "; for (int i = 0; i < 3; i++) { comission_all += arr[i][1]; }; cout << comission_all << endl;
	cout << "5) "; cout << S_all- comission_all;
	return 0;
}


