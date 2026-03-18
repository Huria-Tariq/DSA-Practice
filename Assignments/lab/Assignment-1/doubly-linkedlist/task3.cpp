#include <iostream>
using namespace std;

// Singly Linked List Node
class SNode {
public:
    int data;
    SNode* next;

    SNode(int val) {
        data = val;
        next = NULL;
    }
};

// Doubly Linked List Node
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

// Function to convert singly to doubly linked list
DNode* convertToDoubly(SNode* head) {
    if (head == NULL)
        return NULL;

    DNode* dHead = new DNode(head->data);
    DNode* dCurrent = dHead;
    SNode* sCurrent = head->next;

    while (sCurrent != NULL) {
        DNode* newNode = new DNode(sCurrent->data);
        dCurrent->next = newNode;
        newNode->prev = dCurrent;

        dCurrent = newNode;
        sCurrent = sCurrent->next;
    }

    return dHead;
}

void displayDoubly(DNode* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a singly linked list
    SNode* sHead = new SNode(10);
    sHead->next = new SNode(20);
    sHead->next->next = new SNode(30);
    sHead->next->next->next = new SNode(40);

    // Convert to doubly linked list
    DNode* dHead = convertToDoubly(sHead);

    cout << "Converted Doubly Linked List: ";
    displayDoubly(dHead);

    return 0;
}
