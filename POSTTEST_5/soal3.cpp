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

// Fungsi buat cari nilai terbesar dalam BST
int findMaxValue(Node* root) {
    // 1. Kalo tree kosong, kembalikan -1
    if (root == nullptr) {
        return -1;
    }
    // 2. Telusuri ke kanan selama masih ada anak kanan
    while (root->right != nullptr) {
        root = root->right; // Pindah ke node kanan
    }
    // 3. Node paling kanan punya nilai terbesar
    return root->data;
}

int main() {
    // Inisialisasi root dengan null, artinya pohon kosong
    Node* root = nullptr;
    // Masukin nilai ke BST: 50, 30, 70, 20, 80
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);
    // Cetak nilai terbesar
    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; // Output: 80
    return 0;
}