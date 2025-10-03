#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};
    // 1. Kalo antrian kosong (front == nullptr), set front dan rear ke newNode
    if (front == nullptr) {
        front = newNode; // Jadikan newNode sebagai front
        rear = newNode;  // Jadikan newNode sebagai rear
    // 2. Kalo udah ada isi, sambungkan rear->next ke newNode, lalu update rear
    } else {
        rear->next = newNode; // Hubungin node lama ke node baru
        rear = newNode;       // Pindahin rear ke node baru
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        return "";
    }
    // 1. Simpan data dari node front
    string document = front->document; // Ambil dokumen dari front
    // 2. Geser front ke node berikutnya
    Node* temp = front; // Simpan front sementara
    front = front->next; // Pindah front ke next
    // 3. Kalo front jadi nullptr, set rear juga ke nullptr
    if (front == nullptr) {
        rear = nullptr; // Reset rear kalo antrian kosong
    }
    // 4. Hapus node lama dan kembalikan datanya
    delete temp; // delete temp
    return document; // Kembalikan dokumen yang diambil
}

void processAllDocuments(Node*& front, Node*& rear) {
    // Loop sampe antrian kosong, ambil dan cetak setiap dokumen
    while (front != nullptr) {
        string doc = dequeue(front, rear);  // Ambil dokumen dari antrian
        cout << "Memproses: " << doc << endl;  // Tampilkan dokumen yang diproses
    }
}

int main() {
    Node* front = nullptr;  
    Node* rear = nullptr;
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");
    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);
    return 0;
}