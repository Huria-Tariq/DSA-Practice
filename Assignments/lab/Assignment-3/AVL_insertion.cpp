#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    int ht;
};
//height
int height(node *T) {
    int lh, rh;
    if(T == NULL) 
    return 0;
    
    if(T->left == NULL)
     lh = 0;
    else lh = 1 + T->left->ht;
    
    if(T->right == NULL)
     rh = 0;
    else rh = 1 + T->right->ht;
    
    if(lh > rh)
     return lh;
    return rh;
}
//balance factor
int BF(node *T) {
    int lh, rh;
    if(T == NULL)
     return 0;
    
    if(T->left == NULL) 
    lh = 0;
    else lh = 1 + T->left->ht;
    
    if(T->right == NULL)
     rh = 0;
    else rh = 1 + T->right->ht;
    
    return (lh - rh);
}

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
//LL case
node* LL(node *T) {
    cout << "Imbalance at " << T->data << " : Applying RIGHT ROTATION (LL Case)" << endl;
    T = rotateright(T);
    return T;
}
//RR case
node* RR(node *T) {
    cout << "Imbalance at " << T->data << " : Applying LEFT ROTATION (RR Case)" << endl;
    T = rotateleft(T);
    return T;
}
//LR case
node* LR(node *T) {
    cout << "Imbalance at " << T->data << " : Applying LEFT-RIGHT ROTATION (LR Case)" << endl;
    T->left = rotateleft(T->left);
    T = rotateright(T);
    return T;
}
//RL case
node* RL(node *T) {
    cout << "Imbalance at " << T->data << " : Applying RIGHT-LEFT ROTATION (RL Case)" << endl;
    T->right = rotateright(T->right);
    T = rotateleft(T);
    return T;
}

// Display all nodes with their balance factors
void displayBF(node *T) {
    if(T != NULL) {
        displayBF(T->left);
        cout << "Node " << T->data << " | BF = " << BF(T) << endl;
        displayBF(T->right);
    }
}
// insertion
node* insert(node *T, int x) {
    if(T == NULL) {
        T = new node;
        T->data = x;
        T->left = NULL;
        T->right = NULL;
        T->ht = 0;
        cout << "Inserted " << x << " (new node)" << endl;
    }
    else if(x > T->data) {
        T->right = insert(T->right, x);
        if(BF(T) == -2) {
            if(x > T->right->data)
                T = RR(T);
            else
                T = RL(T);
        }
    }
    else if(x < T->data) {
        T->left = insert(T->left, x);
        if(BF(T) == 2) {
            if(x < T->left->data)
                T = LL(T);
            else
                T = LR(T);
        }
    }
    T->ht = height(T);
    return T;
}

void inorder(node *T) {
    if(T != NULL) {
        inorder(T->left);
        cout << T->data << " ";
        inorder(T->right);
    }
}

int main() {
    node *root = NULL;
    int values[] = {13, 8, 5, 9, 4, 6, 12, 2, 1, 3};
    int n = 10;
    
    for(int i = 0; i < n; i++) {
        cout << "\n=== Inserting " << values[i] << " ===" << endl;
        root = insert(root, values[i]);
        displayBF(root);
        cout << "----------------------------------------" << endl;
    }
    
    cout << "\nInorder traversal: ";
    inorder(root);
    cout << endl;
    cout << "Hight: " << height(root) << endl;
    cout << "Balance Factor: " << BF(root) << endl;
    
    return 0;
}