#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to create a circular linked list
Node* createCircularList(int n) {
    Node* head = new Node(1);
    Node* prev = head;

    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head; // make it circular
    return head;
}

// Josephus function
int josephus(int n, int k) {
    Node* head = createCircularList(n);
    Node* ptr1 = head;
    Node* ptr2 = head;

    while (ptr1->next != ptr1) { // more than one node left
        // move (k-1) steps
        for (int i = 1; i < k; i++) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }

        // remove the k-th node
        ptr2->next = ptr1->next;
        cout << "Person " << ptr1->data << " is eliminated.\n";
        delete ptr1;
        ptr1 = ptr2->next;
    }

    int survivor = ptr1->data;
    delete ptr1;
    return survivor;
}

int main() {
    int n, k;
    cout << "Enter total number of people: ";
    cin >> n;
    cout << "Enter step count (k): ";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "The survivor is person #" << survivor << endl;

    return 0;
}
