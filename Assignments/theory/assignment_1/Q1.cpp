#include <iostream>
#include <string>
using namespace std;

// Node to represent a student
class Node {
public:
    int rollNo;
    string name;
    float marks;
    Node* next;

    Node(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
        next = NULL;
    }
};

// Singly linked list for Student Records
class StudentList {
    Node* head;
    Node* tail;

public:
    StudentList() {
        head = tail = NULL;
    }

    // Add at beginning
    void addFront(int r, string n, float m) {
        Node* newNode = new Node(r, n, m);
        newNode->next = head;
        head = newNode;
        if (tail == NULL) tail = newNode;
    }

    // Add at end
    void addEnd(int r, string n, float m) {
        Node* newNode = new Node(r, n, m);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    // Add at specific position (0-based index)
    void addAtPos(int r, string n, float m, int pos) {
        if (pos == 0) {
            addFront(r, n, m);
            return;
        }

        Node* newNode = new Node(r, n, m);
        Node* temp = head;

        int count;
        for (count = 0; temp != NULL && count < pos - 1; count++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) tail = newNode;
    }

    // Delete student by roll number
    void deleteByRoll(int r) {
        if (head == NULL) { cout << "List empty!" << endl; return; }

        // if first node matches
        if (head->rollNo == r) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == NULL) tail = NULL; // list became empty
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->rollNo != r) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Roll number not found!" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (temp->next == NULL) tail = temp;
        delete toDelete;
    }

    // Search by name
    void searchByName(string n) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == n) {
                cout << "Found: Roll=" << temp->rollNo << ", Name=" << temp->name << ", Marks=" << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!" << endl;
    }

    // Display all
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->rollNo << " - " << temp->name << " - " << temp->marks << endl;
            temp = temp->next;
        }
    }
};

int main() {
    StudentList sl;

    // Insert 3 students
    sl.addFront(101, "huria", 85.5);
    sl.addEnd(102, "Sara", 90.0);
    sl.addAtPos(103, "huma", 78.0, 1);

    cout << "Student Records after insertion:\n";
    sl.display();

    // Delete 1 student
    sl.deleteByRoll(102);

    cout << "\nAfter deleting roll 102:\n";
    sl.display();

    // Search
    sl.searchByName("huria");

    return 0;
}
