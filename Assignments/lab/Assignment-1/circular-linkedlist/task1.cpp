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
public:
    Node* head;

    LinkedList() {
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
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete all even or odd nodes
    void deleteEvenOdd(bool deleteEven) {
        while (head != NULL && ((deleteEven && head->data % 2 == 0) || (!deleteEven && head->data % 2 != 0))) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if ((deleteEven && curr->next->data % 2 == 0) || (!deleteEven && curr->next->data % 2 != 0)) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);

    cout << "Original List: ";
    list.display();

    int choice;
    cout << "Delete (1) Even nodes or (2) Odd nodes? ";
    cin >> choice;

    if (choice == 1)
        list.deleteEvenOdd(true);
    else
        list.deleteEvenOdd(false);

    cout << "Updated List: ";
    list.display();

    return 0;
}
