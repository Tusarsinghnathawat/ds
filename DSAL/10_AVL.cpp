// A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
// deleting keywords, updating values of any entry. Provide facility to display whole data sorted
// in ascending/ Descending order. Also find how many maximum comparisons may require for
// finding any keyword. Use Height balance tree and find the complexity for finding a keyword.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class AVLNode {
public:
    string keyword;
    string meaning;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(string keyword, string meaning) : keyword(keyword), meaning(meaning), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    AVLNode* insertUtil(AVLNode* node, string keyword, string meaning) {
        if (node == nullptr) return new AVLNode(keyword, meaning);

        if (keyword < node->keyword)
            node->left = insertUtil(node->left, keyword, meaning);
        else if (keyword > node->keyword)
            node->right = insertUtil(node->right, keyword, meaning);
        else
            node->meaning = meaning; // Update meaning if keyword already exists

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && keyword < node->left->keyword)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && keyword > node->right->keyword)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && keyword > node->left->keyword) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && keyword < node->right->keyword) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    AVLNode* deleteNodeUtil(AVLNode* root, string keyword) {
        if (root == nullptr) return root;

        if (keyword < root->keyword)
            root->left = deleteNodeUtil(root->left, keyword);
        else if (keyword > root->keyword)
            root->right = deleteNodeUtil(root->right, keyword);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                AVLNode* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->right = deleteNodeUtil(root->right, temp->keyword);
            }
        }

        if (root == nullptr) return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        // Left Left Case
        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrderUtil(AVLNode* root, bool ascending) {
        if (root == nullptr) return;
        if (ascending) {
            inOrderUtil(root->left, ascending);
            cout << root->keyword << ": " << root->meaning << endl;
            inOrderUtil(root->right, ascending);
        } else {
            inOrderUtil(root->right, ascending);
            cout << root->keyword << ": " << root->meaning << endl;
            inOrderUtil(root->left, ascending);
        }
    }

    AVLNode* searchUtil(AVLNode* root, string keyword, int& comparisons) {
        if (root == nullptr) {
            comparisons++;
            return nullptr;
        }

        if (root->keyword == keyword) {
            comparisons++;
            return root;
        }

        if (keyword < root->keyword) {
            comparisons++;
            return searchUtil(root->left, keyword, ++comparisons);
        }

        return searchUtil(root->right, keyword, ++comparisons);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(string keyword, string meaning) {
        root = insertUtil(root, keyword, meaning);
    }

    void remove(string keyword) {
        root = deleteNodeUtil(root, keyword);
    }

    void displaySorted(bool ascending = true) {
        cout << "Keywords and meanings (sorted ";
        if (ascending)
            cout << "ascending order):" << endl;
        else
            cout << "descending order):" << endl;
        inOrderUtil(root, ascending);
    }

    string search(string keyword, int& comparisons) {
        AVLNode* result = searchUtil(root, keyword, comparisons);
        if (result)
            return result->meaning;
        else
            return "Keyword not found";
    }
};

int main() {
    AVLTree avl;

    // Adding keywords and meanings
    avl.insert("apple", "a fruit");
    avl.insert("banana", "an edible fruit");
    avl.insert("cat", "a mammal");
    avl.insert("dog", "a domesticated carnivorous mammal");

    // Displaying sorted data
    avl.displaySorted(true); // Ascending order
    cout << endl;

    // Removing a keyword
    avl.remove("banana");

    // Displaying sorted data
    avl.displaySorted(false); // Descending order
    cout << endl;

    // Searching for a keyword
    int comparisons = 0;
    string meaning = avl.search("dog", comparisons);
    cout << "Meaning of 'dog': " << meaning << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
