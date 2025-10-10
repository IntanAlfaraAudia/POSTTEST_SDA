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

// Fungsi buat lakukan post-order traversal (kiri, kanan, root)
void postOrderTraversal(Node* root) {
    // 1. Kalo node kosong, keluar (base case)
    if (root == nullptr) {
        return;
    }
    // 2. Rekursif ke subtree kiri
    postOrderTraversal(root->left);
    // 3. Rekursif ke subtree kanan
    postOrderTraversal(root->right);
    // 4. Cetak data node saat ini
    cout << root->data << " ";
}

int main() {
    // Inisialisasi root dengan null, artinya pohon kosong
    Node* root = nullptr;
    // Masukin nilai ke BST: 50, 30, 70, 20, 40, 60, 80
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    // Cetak label traversal
    cout << "Post-order traversal dari tree adalah: ";
    // Lakukan post-order traversal
    postOrderTraversal(root); // Output: 20 40 30 60 80 70 50
    cout << endl;
    return 0;
}