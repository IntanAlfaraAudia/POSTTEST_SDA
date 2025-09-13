#include <iostream>
using namespace std;

void balikArray(int *arr, int jumlah) {
    int *start = arr;
    int *end = arr + jumlah - 1;
    
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}

void tampilkanArray(int *arr, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << *(arr + i);
        if (i < jumlah - 1) cout << ", ";
    }
}

int main() {
    const int jumlah = 7;
    int arrPrima[jumlah] = {2, 3, 5, 7, 11, 13, 17}; 
    
    cout << "Array bilangan prima sebelum dibalik: ";
    tampilkanArray(arrPrima, jumlah);
    
    balikArray(arrPrima, jumlah);
    
    cout << "\nArray bilangan prima setelah dibalik: ";
    tampilkanArray(arrPrima, jumlah);
    
    return 0;
}