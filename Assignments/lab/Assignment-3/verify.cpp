#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    int ht;
};

// Calculate height
int height(node *T) {
    if(T == NULL) return 0;
    
    int lh = (T->left == NULL) ? 0 : 1 + T->left->ht;
    int rh = (T->right == NULL) ? 0 : 1 + T->right->ht;
    
    return (lh > rh) ? lh : rh;
}

// Calculate balance factor
int BF(node *T) {
    if(T == NULL) return 0;
    
    int lh = (T->left == NULL) ? 0 : 1 + T->left->ht;
    int rh = (T->right == NULL) ? 0 : 1 + T->right->ht;
    
    return (lh - rh);
}

// Rotations
node* rotateright(node *x) {
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node* rotateleft(node *x) {
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

// Insert
node* insert(node *T, int x) {
    if(T == NULL) {
        T = new node;
        T->data = x;
        T->left = NULL;
        T->right = NULL;
        T->ht = 0;
        return T;
    }
    
    if(x < T->data) {
        T->left = insert(T->left, x);
        if(BF(T) == 2) {
            if(x < T->left->data)
                T = rotateright(T);  // LL
            else {
                T->left = rotateleft(T->left);  // LR
                T = rotateright(T);
            }
        }
    }
    else if(x > T->data) {
        T->right = insert(T->right, x);
        if(BF(T) == -2) {
            if(x > T->right->data)
                T = rotateleft(T);  // RR
            else {
                T->right = rotateright(T->right);  // RL
                T = rotateleft(T);
            }
        }
    }
    
    T->ht = height(T);
    return T;
}

// Inorder
void inorder(node *T) {
    if(T != NULL) {
        inorder(T->left);
        cout << T->data << " ";
        inorder(T->right);
    }
}

// ========== VERIFY AVL TREE ==========

bool verifyAVL(node* T, node* minNode, node* maxNode) {
    
    if (T == NULL) return true;
    
    // Check BST
    if (minNode != NULL && T->data <= minNode->data) {
        cout << "BST violated at " << T->data << endl;
        return false;
    }
    if (maxNode != NULL && T->data >= maxNode->data) {
        cout << "BST violated at " << T->data << endl;
        return false;
    }
    
    // Check left and right
    if (!verifyAVL(T->left, minNode, T)) return false;
    if (!verifyAVL(T->right, T, maxNode)) return false;
    
    // Check height
    int lh = (T->left == NULL) ? 0 : T->left->ht + 1;
    int rh = (T->right == NULL) ? 0 : T->right->ht + 1;
    int actualH = (lh > rh) ? lh : rh;
    
    if (T->ht != actualH) {
        cout << "Height wrong at " << T->data << endl;
        return false;
    }
    
    // Check balance
    int bf = lh - rh;
    if (bf < -1 || bf > 1) {
        cout << "Not balanced at " << T->data << endl;
        return false;
    }
    
    return true;
}

// ========== MAIN ==========

int main() {
    node *root = NULL;
    int values[] = {13, 8, 5, 9, 4, 6, 12, 2, 1, 3};
    
    cout << "\n=== Building AVL Tree ===" << endl;
    cout << "Values: 13, 8, 5, 9, 4, 6, 12, 2, 1, 3\n" << endl;
    
    for(int i = 0; i < 10; i++) {
        root = insert(root, values[i]);
    }
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Height: " << height(root) << endl;
    cout << "Balance Factor: " << BF(root) << endl;
    
    cout << "\n=== Verifying AVL Tree ===" << endl;
    
    if (verifyAVL(root, NULL, NULL)) {
        cout << "\n VALID AVL TREE" << endl;
        cout << "  BST: OK" << endl;
        cout << "  Height: OK" << endl;
        cout << "  Balance: OK" << endl;
    } else {
        cout << "\n INVALID AVL TREE" << endl;
    }
    
    cout << endl;
    return 0;
}