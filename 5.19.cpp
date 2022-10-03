#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream p;
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

    int m[255];
    for(int i; i < 255; i++){
        m[i] = 0;
    }

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
            //cout << (int)x << endl;
            m[(int)x] += 1;
            //cout << m[(int)x] << endl;
        }
    }
    f.close();
    cout << "\n";
    int mx=0, mi;
    //int *max = max_element(begin(m),end(m));
    //cout << "The max element is " << *max << endl;
    for(int i=1; i < 255; i++){
        if(m[i]>mx){
            mx = m[i];
            mi = i;
        }
    }
    cout << "<<" << (char)mi << ">>";
    return 0;
}
