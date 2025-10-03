#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node*& head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    // Kasus 1: Kalo list masih kosong
    if (head_ref == nullptr) {
        // Hubungin node baru ke dirinya sendiri buat jadi lingkaran
        newNode->next = newNode;
        newNode->prev = newNode;
        // Jadikan node ini sebagai head
        head_ref = newNode;
        return;
    }

    // Kasus 2: Kalo data baru lebih kecil dari head, masukin di awal
    if (data < head_ref->data) {
        // Sambungin node baru ke head yang lama
        newNode->next = head_ref;
        // Sambungin ke tail (prev dari head)
        newNode->prev = head_ref->prev;
        // Update tail supaya nyambung ke node baru
        head_ref->prev->next = newNode;
        // Update prev head jadi node baru
        head_ref->prev = newNode;
        // Pindahin head ke node baru
        head_ref = newNode;
        return; // Keluar dari fungsi
    }

    // Kasus 3: Cari posisi yang pas buat masukin di tengah/akhir
    // Mulai dari head
    Node* current = head_ref;
    // Loop sampe ketemu posisi yang bener atau balik ke head
    while (current->next != head_ref && current->next->data < data) {
        current = current->next; // Pindah ke node berikutnya
    }
    // Sambungin node baru ke next dari current
    newNode->next = current->next;
    // Sambungin node baru ke current sebagai prev
    newNode->prev = current;
    // Update prev dari node setelah current ke node baru
    current->next->prev = newNode;
    // Update next dari current ke node baru
    current->next = newNode;
}

void printList(Node* head_ref) {
    if (head_ref == nullptr) {
        return;
    }
    Node* current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);
    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);
    return 0;
}