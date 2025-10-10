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

// Fungsi buat hitung total node dalam BST
int countNodes(Node* root) {
    // 1. Kalo root kosong, kembalikan 0 (base case)
    if (root == nullptr) {
        return 0;
    }
    // 2. Hitung node saat ini (1) + node di subtree kiri + node di subtree kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Inisialisasi root dengan null, artinya pohon kosong
    Node* root = nullptr;
    // Masukin nilai ke BST: 50, 30, 70, 20
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    // Cetak jumlah total node
    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; // Output: 4
    return 0;
}