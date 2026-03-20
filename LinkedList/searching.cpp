#include <iostream>
using namespace std;

class Node {
public:
    int rollNo;
    string name;
    int marks;
    Node* next;

    Node(int r, string n, int m) {
        rollNo = r;
        name = n;
        marks = m;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert new student at end
    void insert(int r, string n, int m) {
        Node* newNode = new Node(r, n, m);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Search student by name
    void searchByName(string n) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == n) {
                cout << "Found: Roll=" << temp->rollNo 
                     << ", Name=" << temp->name 
                     << ", Marks=" << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!" << endl;
    }

    // Display all students
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Roll=" << temp->rollNo 
                 << ", Name=" << temp->name 
                 << ", Marks=" << temp->marks << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    
    list.insert(1, "Ali", 85);
    list.insert(2, "Sara", 92);
    list.insert(3, "Ahmed", 78);

    cout << "All Students:" << endl;
    list.display();

    cout << "\nSearching for Sara:" << endl;
    list.searchByName("Sara");

    cout << "\nSearching for Usman:" << endl;
    list.searchByName("Usman");

    return 0;
}
