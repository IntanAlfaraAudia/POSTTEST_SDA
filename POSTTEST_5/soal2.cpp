#include <iostream>
using namespace std;

// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor 
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi buat cari nilai terkecil dalam BST
int findMinValue(Node* root) {
    // 1. Kalo tree kosong, kembalikan -1
    if (root == nullptr) {
        return -1;
    }
    // 2. Telusuri ke kiri selama masih ada anak kiri
    while (root->left != nullptr) {
        root = root->left; // Pindah ke node kiri
    }
    // 3. Node paling kiri punya nilai terkecil
    return root->data;
}

int main() {
    // Inisialisasi root dengan null, artinya pohon kosong
    Node* root = nullptr;
    // Masukin nilai ke BST: 50, 30, 70, 20, 40
    root = insert(root, 50);
    insert(root, 30); 
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    // Cetak nilai terkecil
    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; // Output: 20
    return 0;
}