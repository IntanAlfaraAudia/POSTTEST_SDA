#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};


void push(Node*& top, char data) {
    // Buat node baru, next-nya ke top lama, trus top diganti ke node baru
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    // Kalo stack kosong, kembalikan karakter null
    if (top == nullptr) { 
        return '\0';
    }
    Node* temp = top;
    char poppedValue = temp->data;
    // Pindahin top ke next, hapus node lama, kembalikan datanya
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // 1. Loop setiap karakter dalam `expr`
    for (char c : expr) {
        // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c); // Taruh kurung buka ke tumpukan
        }
        // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek:
        else if (c == ')' || c == '}' || c == ']') {
            // a. Apakah stack kosong? Jika ya, return false
            if (stackTop == nullptr) {
                return false;   // Stack kosong berarti kurung tutup ga ada pasangannya
            }
            // b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka. Jika tidak, return false
            char topBracket = pop(stackTop);    // Ambil kurung buka dari atas
            if ((c == ')' && topBracket != '(') || // Cek pasangan ()
                (c == '}' && topBracket != '{') || // Cek pasangan {}
                (c == ']' && topBracket != '[')) { // Cek pasangan []
                return false;   // Kalo ga cocok, berarti ga seimbang
            }
        }
    }

    // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false
    bool isBalanced = (stackTop == nullptr); // Kalo stack kosong, berarti seimbang
    // Bersihkan sisa node di stack
    while (stackTop != nullptr) {
        pop(stackTop);    // Hapus semua node yang tersisa biar ga nyangkut
    }
    return isBalanced; // Kembalikan hasil apakah seimbang
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output : Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    return 0;
}