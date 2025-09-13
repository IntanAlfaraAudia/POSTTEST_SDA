#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[4];

cout << "\n+-----------------------------------+\n";
cout << "|       Masukkan Biodata Mhs        |\n";
cout << "+-----------------------------------+\n";

    for(int i=0; i<4; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama: "; cin >> mhs[i].nama;
        cout << "NIM : "; cin >> mhs[i].nim;
        cout << "IPK : "; cin >> mhs[i].ipk;
    }

    for(int i=0; i<3; i++) {
        for(int j=i+1; j<4; j++) {
            if(mhs[i].ipk > mhs[j].ipk) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }

    cout << "\n+-----------------------------------+\n";
    cout << "|   Hasil Urutan Data Mahasiswa     |\n";
    cout << "|         (IPK Ascending)           |\n";
    cout << "+-----------------------------------+\n";
    for(int i=0; i<4; i++) {
        cout << mhs[i].nama << " | "
             << mhs[i].nim << " | "
             << mhs[i].ipk << endl;
    }

    return 0;
}
