#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    cout << "\n+-----------------------------------+\n";
    cout << "|        Program Tukar Nilai        |\n";
    cout << "+-----------------------------------+\n";

    cout << "Masukkan nilai x: "; cin >> x;
    cout << "Masukkan nilai y: "; cin >> y;

    cout << "\n+-----------------------------------+\n";
    cout << "|        Nilai Sebelum Tukar        |\n";
    cout << "+-----------------------------------+\n";
    cout << "x = " << x << " | y = " << y << endl;

    tukar(x, y);

    cout << "\n+-----------------------------------+\n";
    cout << "|        Nilai Sesudah Tukar        |\n";
    cout << "+-----------------------------------+\n";
    cout << "x = " << x << " | y = " << y << endl;

    return 0;
}
