#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    // Hanya berjalan jika ada 2 node atau lebih
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref; // Simpan head saat ini
    Node* tail = head_ref->prev;  // Simpan tail saat ini (prev dari head)
    Node* head_next = head->next; // Simpan tetangga next dari head
    Node* tail_prev = tail->prev; // Simpan tetangga prev dari tail

    // Kondisi khusus jika hanya 2 node
    if (head_next == tail) {
        head->next = head; // Head jadi lingkaran sendiri
        head->prev = head; // Head jadi lingkaran sendiri
        tail->next = tail; // Tail jadi lingkaran sendiri
        tail->prev = tail; // Tail jadi lingkaran sendiri
        head_ref = tail;   // Update head_ref ke tail
        return;
    }

    // Update koneksi untuk tail
    tail_prev->next = tail; // Sambungkan tetangga sebelum tail ke tail
    tail->prev = tail_prev; // Update prev tail ke tetangga sebelumnya

    // Update koneksi untuk head
    head->prev = head_next->prev; // Sambungkan prev head ke tetangga sebelum head_next
    head->next = head_ref;        // Sambungkan next head ke head_ref asli

    // Hubungkan head_next dan tail
    tail->next = head_next; // Sambungkan tail ke tetangga berikutnya head
    head_next->prev = tail; // Update prev head_next ke tail

    // Update koneksi circular
    head_ref->prev = head; // Update prev head_ref asli ke head
    head_ref = tail;       // Update head_ref ke tail asli
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);

    return 0;
}