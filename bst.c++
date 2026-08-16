#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}};
class BST {
private:
    Node* root;
    Node* insert(Node* node, int val) {
        if (node == nullptr) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;}
    Node* findMin(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;}
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) return node;
        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;}
                else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;}
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);}
        return node;}
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);}
public:
    BST() : root(nullptr) {}
    void insert(int val) {
        root = insert(root, val);}
    void remove(int val) {
        root = deleteNode(root, val);}
    void display(){
        inorder(root);
        cout << endl;}};
int main() {
    BST tree;
    int choice, val;
    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display (Inorder)\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.remove(val);
                break;
            case 3:
                tree.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";}}}