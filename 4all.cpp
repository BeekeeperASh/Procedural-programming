Домашнее задание 4.txt

4.1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	setlocale(0, "");

	string a = "4.1.txt";
	ofstream fout;
	ifstream fin;

	fout.open(a);
	cout << "Введите 10 вещественных чисел в строчку через пробел" << endl;
		string b;
		getline (cin, b);
		fout << b;
	fout.close();
	fin.open(a);
	if (!fin.is_open()) {
		cout << "Ошибка" << endl;
	}
	else {
		float S1, S2 = 0;
		while (fin >> S1)
		{
			S2 = S2 + S1;
		}
		fin.close();
		cout << S2;
	}
	return 0;
}



4.2

#include <iostream>
#include <cmath>
using namespace std;


int sign(float a) {
	if (a > 0) { cout << 1; }
	if (a < 0) { cout << -1; }
	if (a == 0) { cout << 0; }
	return 0;
}
int main() {
	setlocale(0, "");
	float x;
	cout << "Введите число:" << endl;
		cin >> x;
	sign(x);
	return 0;
}



4.3

#include <iostream>
#include <cmath>
using namespace std;

float length(float a1, float a2, float b1, float b2) {
	float len;
	len = sqrt(pow((a1 - b1), 2) + pow((a2 - b2), 2));
	return (len);
}
float circle() {
	float r1 = 0, r2 = 0, O1 = 0, O2 = 0, R = 0;
	double S = 0;
	cout << "Введите координаты центра (x, y)" << endl;
	cin >> O1 >> O2;
	cout << "Введите координаты любой точки круга (x, y)" << endl;
	cin >> r1 >> r2;
	R = length(O1, O2, r1, r2);
	if (R > 0) {
		S = 3.14 * R * R;
		cout << "S = pi * r^2" << endl << "S = " << "3.14" << "*" << R << "*" << R << " = " << S;
	}
	else { cout << "Круг не существует"; }
	return 0;
}
float rectangle() {
	float S, a1, a2, b1, b2, c1, c2, R1, R2, R3;
	cout << "Введите координаты первой вершины вашего прямоугольника (x, y)" << endl;
	cin >> a1 >> a2;
	cout << "Введите координаты второй вершины вашего прямоугольника (x, y)" << endl;
	cin >> b1 >> b2;
	cout << "Введите координаты третьей вершины вашего прямоугольника (x, y)" << endl;
	cin >> c1 >> c2;
	R1 = length(a1, a2, b1, b2);
	R2 = length(a1, a2, c1, c2);
	R3 = length(b1, b2, c1, c2);
	if (R1 > 0 && R2 > 0 && R3 > 0) {
		float minimum = min(min(R1, R2), R3);
		float maximum = max(max(R1, R2), R3);
		float L = R1 + R2 + R3 - (minimum + maximum);
		S = minimum * L;
		cout << "S = a * b" << endl << "S = " << minimum << "*" << L << " = " << S;
	}
	else { cout << "Прямоугольник не существует"; }
	return 0;
}
float triangle() {
	float S, a1, a2, b1, b2, c1, c2, L1, L2, L3, p;
	cout << "Введите координаты первой вершины вашего треугольника (x, y)" << endl;
	cin >> a1 >> a2;
	cout << "Введите координаты второй вершины вашего треугольника (x, y)" << endl;
	cin >> b1 >> b2;
	cout << "Введите координаты третьей вершины вашего треугольника (x, y)" << endl;
	cin >> c1 >> c2;
	L1 = length(a1, a1, b1, b2);
	L2 = length(a1, a2, c1, c2);
	L3 = length(b1, b2, c1, c2);
	if ((L1 + L2 > L3) and (L1 + L3 > L2) and (L2 + L3 > L1)) {
		p = (L1 + L2 + L3) * 0.5;
		S = sqrt(p * (p - L1) * (p - L2) * (p - L3));
		cout << "S = sqrt(p * (p - a) * (p - b) * (p - c))" << endl;
		cout << "p = " << p << endl;
		cout << "S = sqrt(" << p << " * (" << p << "-" << L1 << ")" << " * (" << p << "-" << L2 << ")" << " * (" << p << "-" << L3 << "))" << " = " << S;
	}
	else { cout << "Треугольника не существует"; }
	return 0;
}
int main() {
	setlocale(0, "");
	char x;
	cout << "Введите первую букву вашей фигуры:" << "\n" "О - окружность" << "\n" "П - прямоугольник" << "\n" "Т - треугольник" << endl;
	cin >> x;
	switch (x) {
	case -114: circle(); break;
	case -113: rectangle(); break;
	case -110: triangle(); break;
	}
	return 0;
}



4.4

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <Windows.h> 
using namespace std;


int underline(int i) {
	for (int j = 0; j < i; j++) {
		cout << " ";
	}
	cout << endl;
	return 0;
}
int star() {
	for (int j = 0; j < 8; j++) {
		cout << "*";
	}
	return 0;
}
int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	setlocale(0, "");
	int k = 0;
	for (int j = 0; j < 6; j++) {
		SetConsoleTextAttribute(hConsole, (WORD)((3 << 4) | 15)); 
		star();
		if (k % 2 == 0) {
			SetConsoleTextAttribute(hConsole, 64);
			underline(42);
		}
		else {
			SetConsoleTextAttribute(hConsole, 112);
			underline(42);
		}
		k += 1;
	}
	for (int j = 0; j < 7; j++) {
		if (k % 2 == 0) {
			SetConsoleTextAttribute(hConsole, 64);
			underline(50);
		}
		else {
			SetConsoleTextAttribute(hConsole, 112);
			underline(50);
		}
		k += 1;
	}
	SetConsoleTextAttribute(hConsole, 7);
	return 0;
}



4.5

#include <windows.h>
#include <conio.h>
#include <math.h>
const double pi = 3.1415;
int main () {
	HDC hdc = GetDC(GetConsoleWindow());
 COLORREF penColor = RGB(255, 255, 255);
 double y;
 HPEN pen = CreatePen(PS_SOLID, 4, penColor);
 SelectObject(hdc, pen);
 MoveToEx(hdc, 0, 250, NULL);
 LineTo(hdc, 1500, 250);
 MoveToEx(hdc, 500, 0, NULL);
 LineTo(hdc, 500, 1000);

 for (int i = -1000; i < 1000; ++i) {
	 y = sin(pi * i / 100);
	 LineTo(hdc, 100 + i, 250 + int(50 * y));
	 MoveToEx(hdc, 100 + i, 250 + int(50 * y), NULL);
 }
 while (!_kbhit());
}



4.6

#include <iostream>
#include <string>
using namespace std;

int Decoder(string a) {
	int j = a.length();
	a += "000";
	int NUMBER = 0;
	int x = 0, y = 0, z = 0, t = 0,
		kv = 0, kl = 0, kd = 0, 
		k2 = 0, 
		k3 = 1001; 
	for (int i = 0; i < j; i++) {
		switch (a[i]) {
		case 48: y = 0; break;
		case 73: x = 1; break; 
		case 86: x = 5; kv = kv + 1;  break; 
		case 88: x = 10; break; 
		case 76: x = 50; kl = kl + 1; break; 
		case 67: x = 100; break; 
		case 68: x = 500; kd = kd + 1; break; 
		case 77: x = 1000; break; 
		}
		switch (a[i + 1]) {
		case 48: y = 0; break; 
		case 73: y = 1; break; 
		case 86: y = 5; break; 
		case 88: y = 10; break; 
		case 76: y = 50; break; 
		case 67: y = 100; break; 
		case 68: y = 500; break; 
		case 77: y = 1000; break; 
		}
		switch (a[i + 2]) {
		case 48: z = 0; break; 
		case 73: z = 1; break; 
		case 86: z = 5; break; 
		case 88: z = 10; break; 
		case 76: z = 50; break; 
		case 67: z = 100; break; 
		case 68: z = 500; break; 
		case 77: z = 1000; break; 
		}
		switch (a[i + 3]) {
		case 48: t = 0; break; 
		case 73: t = 1; break; 
		case 86: t = 5; break; 
		case 88: t = 10; break; 
		case 76: t = 50; break; 
		case 67: t = 100; break; 
		case 68: t = 500; break; 
		case 77: t = 1000; break; 
		}
		if (x < y) {
			NUMBER = NUMBER - x;
			k3 = x;
		}
		else if (y < k3) { NUMBER = NUMBER + x; 
		else { k2 = k2 + 1; }
		if (y - x == x) { k2 = k2 + 1; } 
		if ((x < z && y < z) 
			or (kl > 1) or (kd > 1) or (kv >1)
			or ((x == y) && (y == z) && (z == t) && (t == x)) 
		    or (k2>0)) {
			cout << "Некорректная запись числа" << endl;
			return (0);
		}
	}
	return (NUMBER);
}

int main() {
	setlocale(0, "");

	string b;
	cout << "Введите число:" << endl;
	getline(cin, b);
	cout << Decoder(b);
	return 0;
}



4.7

#include <iostream>
#include <time.h>
using namespace std;

void main() {
	setlocale(0, "");
	int m, i, c, S0, S1;
	cout << "Введите m, i, c" << endl;
	cin >> m >> i >> c;
	S0 = time(0);
	for (int j = 0; j < i; j++) {
		S1 = (m * S0 + j) % c;
		cout << S1 << " ";
		S0 = S1;
	}
}



4.8

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
				arr[N][M] = arr[N][M] + SellerAndQuantity[i][k] * Price[k][j] * (pow(-1, j));
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
	double comissionmin = -1000, comissionmax = 0;
	string temp = "Продавец №";
	for (int i = 0; i < 3; i++) { 
		fixed; setprecision(1);
		if ((arr[i][0] + arr[i][1]) > Smax) {
			Smax = arr[i][0] + arr[i][1];
			jmax = i + 1;
		}
		if ((arr[i][0] + arr[i][1]) < Smin) {
			Smin = arr[i][0] + arr[i][1];
			jmin = i + 1;
		}
		if (arr[i][1] < comissionmax) {
			comissionmax = arr[i][1];
			jcomissmax = i + 1;
		}
		if (arr[i][1] > comissionmin) {
			comissionmin = arr[i][1];
			jcomissmin = i + 1;
		}
	}
	cout << "1) " << fixed << setprecision(1) << Smax << " " << temp << jmax << endl << Smin << " " << temp << jmin << endl;
	cout << "2) " << arr[jcomissmax - 1][1] << " " << temp << jcomissmax << endl << arr[jcomissmin - 1][1] << " " << temp << jcomissmin << endl;
	cout << "3) "; for (int i = 0; i < 3; i++) { S_all += (arr[i][0] + arr[i][1]); }; cout << S_all << endl;
	cout << "4) "; for (int i = 0; i < 3; i++) { comission_all += arr[i][1]; }; cout << comission_all << endl;
	cout << "5) "; for (int i = 0; i < 3; i++) { S_all_without_comission += arr[i][0]; }; cout << S_all_without_comission;
	return 0;
}



4.9

#include <iostream>
#include <string>
using namespace std;

int DigitsCounter(int Z, int r) {
	int k = 0;
	while (r > 0) {
		k = k + 1;
		r = r / Z;
	}
	return (k);
}
int FromYto10(int Y, string x) {
	int RESULT = 0, k = 0;
	int j = (int)x.length(); 
	int* arr = new int[j]; 
	for (int i = 0; i < j; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < j; i++) {
		switch (x[i]) {
		case '0': arr[i] = 0; break;
		case '1': arr[i] = 1; break;
		case '2': arr[i] = 2; break;
		case '3': arr[i] = 3; break;
		case '4': arr[i] = 4; break;
		case '5': arr[i] = 5; break;
		case '6': arr[i] = 6; break;
		case '7': arr[i] = 7; break;
		case '8': arr[i] = 8; break;
		case '9': arr[i] = 9; break;
		case 'A': arr[i] = 10; break;
		case 'B': arr[i] = 11; break;
		case 'C': arr[i] = 12; break;
		case 'D': arr[i] = 13; break;
		case 'E': arr[i] = 14; break;
		case 'F': arr[i] = 15; break;
		}
	}
	for (j = j - 1; j >= 0; j--) { 
		RESULT = RESULT + arr[j] * int(pow(Y, k));
		k = k + 1;
		if (arr[j] >= Y || arr[0] == 0) {
			cout << endl; system("PAUSE"); exit(0);
		}
	}
	delete[] arr; 
	return(RESULT);
}
string From10toZ(int Z, int x) {
	if (Z < 2 || Z > 16) {
		cout << endl; system("PAUSE"); exit(0);
	}
	int i = DigitsCounter(Z, x), num = 0;
	const int j = i;
	string arr, RESULT;
	for (i; i > 0; i--) {
		arr = arr + "0";
	}
	i = j;
	while (i > 0) {
		num = x % Z;
		switch (num) {
		case 0: arr[i] = '0'; break;
		case 1: arr[i] = '1'; break;
		case 2: arr[i] = '2'; break;
		case 3: arr[i] = '3'; break;
		case 4: arr[i] = '4'; break;
		case 5: arr[i] = '5'; break;
		case 6: arr[i] = '6'; break;
		case 7: arr[i] = '7'; break;
		case 8: arr[i] = '8'; break;
		case 9: arr[i] = '9'; break;
		case 10: arr[i] = 'A'; break;
		case 11: arr[i] = 'B'; break;
		case 12: arr[i] = 'C'; break;
		case 13: arr[i] = 'D'; break;
		case 14: arr[i] = 'E'; break;
		case 15: arr[i] = 'F'; break;
		}
		i -= 1;
		x = x / Z;
	}
	for (int i = 1; i <= j; i++) {
		RESULT = RESULT + arr[i];
	}
	return (RESULT);
}

int main() {
	setlocale(0, "");
	cout << "Введите основание и фактический номер" << endl;
	int Y, Z;
	string x;
	cin >> Y >> x;
	int TEMP = FromYto10(Y, x);
	cout << "Введите основание, в которую вы хотите преобразовать свой номер" << endl;
	cin >> Z;
	cout << From10toZ(Z, TEMP) << "\n";
	system("PAUSE");
}
