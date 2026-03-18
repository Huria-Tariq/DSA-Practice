#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to swap two nodes (not values)
    void swapNodes(int x, int y) {
        if (x == y) return; // No need to swap same values

        Node *node1 = NULL, *node2 = NULL, *temp = head;

        // Find both nodes
        while (temp != NULL) {
            if (temp->data == x)
                node1 = temp;
            else if (temp->data == y)
                node2 = temp;
            temp = temp->next;
        }

        if (node1 == NULL || node2 == NULL) {
            cout << "One or both values not found!\n";
            return;
        }

        // Swapping pointers
        if (node1->prev)
            node1->prev->next = node2;
        else
            head = node2;

        if (node2->prev)
            node2->prev->next = node1;
        else
            head = node1;

        swap(node1->prev, node2->prev);
        swap(node1->next, node2->next);

        if (node1->next)
            node1->next->prev = node1;
        if (node2->next)
            node2->next->prev = node2;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    dll.insertAtEnd(50);

    cout << "Original List: ";
    dll.display();

    int val1, val2;
    cout << "Enter two values to swap: ";
    cin >> val1 >> val2;

    dll.swapNodes(val1, val2);

    cout << "List after swapping: ";
    dll.display();

    return 0;
}
