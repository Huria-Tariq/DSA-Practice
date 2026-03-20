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

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert at end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete last node
    void deleteLast() {
        if (head == NULL) {   // Empty list
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == NULL) {  // Only one node
            delete head;
            head = tail = NULL;
            return;
        }

        // More than one node
        Node* temp = head;
        while (temp->next != tail) {  // Stop at second-last node
            temp = temp->next;
        }

        delete tail;   // Delete last node
        tail = temp;   // Update tail
        tail->next = NULL;
    }

    // Display list 
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Original List: ";
    list.display();

    list.deleteLast();
    cout << "After deleting last: ";
    list.display();

    list.deleteLast();
    cout << "After deleting last: ";
    list.display();

    list.deleteLast();
    cout << "After deleting last: ";
    list.display();

    list.deleteLast();
    cout << "After deleting last: ";
    list.display();

    return 0;
}
