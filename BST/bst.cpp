
#include <iostream>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left = nullptr;
    TreeNode<T>* right = nullptr;
};

template <typename T>
class BST {
private:
    TreeNode<T>* root = nullptr;

    void destroyNodes(TreeNode<T>* node) {
        if (node == nullptr)
            return;

        destroyNodes(node->left);
        destroyNodes(node->right);
        delete node;
    }

    TreeNode<T>* remove(TreeNode<T>* node, T value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->data) {
            node->left = remove(node->left, value);
        }
        else if (value > node->data) {
            node->right = remove(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }

            node->data = getMax(node->left);
            node->left = remove(node->left, node->data);
        }

        return node;
    }

    T getMax(TreeNode<T>* node) {
        while (node->right != nullptr) {
            node = node->right;
        }

        return node->data;
    }

    void print(TreeNode<T>* node) const {
        if (node == nullptr)
            return;

        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }

public:
    BST() {
    }

    ~BST() {
        destroyNodes(root);
    }

    void insert(T value) {
        TreeNode<T>* newNode = new TreeNode<T>;
        newNode->data = value;

        if (root == nullptr) {
            root = newNode;
            return;
        }

        TreeNode<T>* current = root;
        TreeNode<T>* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (value < current->data) {
                current = current->left;
            }
            else if (value > current->data) {
                current = current->right;
            }
            else {
                delete newNode;
                return;
            }
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    void removeRecursive(T value) {
        root = remove(root, value);
    }

    void printInorder() const {
        cout << "BST elements: ";
        print(root);
        cout << endl;
    }
};

int main() {
    BST<int> tree;

    tree.insert(18);
    tree.insert(9);
    tree.insert(27);
    tree.insert(4);
    tree.insert(13);
    tree.insert(22);
    tree.insert(31);

    cout << "Before removing:\n";
    tree.printInorder();

    tree.removeRecursive(9);

    cout << "After removing:\n";
    tree.printInorder();

    return 0;
}
