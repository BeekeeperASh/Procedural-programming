#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int n = 0;
    ofstream p;
    cout << "Заполните файл" << endl;
    p.open("test.txt", ofstream::trunc);
    if (!p.is_open()) {
        cout << "Error";
        p.close();
    }
    else {
        char a[256];
        cin.getline(a, 256);
        p << a;
    }
    p.close();

    cout << "Искомомое сочетание слов" << endl;
    char e[64];
    cin.getline(e, 64);

    int j=0;
    int s = 0;
    while ((int)e[j] != 0)
    {
        s ++;
        j ++;
    }
    cout << s << endl;
    bool w = true;
    ifstream f("test.txt");
    if (!f.is_open())
    {
        cout << "Error" << endl;
        f.close();
    }
    else
    {
        char x;
        while (f.get(x))
        {
            if (e[n] == x) {
                n++;
                if (s == n) {
                    cout << "Сочетание слов найдено" << endl;
                    cout << "Found" << endl;
                    w = false;
                }
            } else {
                n = 0;
            }
        }
    }
    f.close();


    if(w) {
        cout << "Сочетание слов не найдено" << endl;
        cout << "Not found" << endl;
    }
    return 0;
}
