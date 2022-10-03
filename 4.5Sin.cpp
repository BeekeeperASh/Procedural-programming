#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    setlocale(0, "");
    char m[50][50];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            if (i == 10) {
                m[i][j] == '|';
            }
            else if (j == 15) {
                m[i][j] == '_';
            }
            else if (((i-10)) == ceil(sin((j-15))*3)) {
                m[i][j] = '*';

            }else {
                m[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            cout << m[i][j];
        }
        cout << "\n";
    }
}
