#include <iostream>
using namespace std;

class CustomerServiceQueue {
    int front;
    int rear;
    int size;
    string arr[5];

public:
    // Constructor 
    CustomerServiceQueue() {
        front = rear = -1;
        size = 5;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Function to check if the queue is empty
    bool isempty() {
        return (front == -1);
    }

    // Function to add  a new customer to the queue
    void enqueue(string customerName) {
        if (isFull()) {
            cout << "Queue is full. Cannot add " << customerName << endl;
            return;
        }

        if (isempty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = customerName;
        cout << customerName << " joined the queue." << endl;
    }

    // Function to see the first customer without removing them
    string peek() {
        if (isempty()) {
            cout << "No customers in line." << endl;
            return "";
        }
        return arr[front];
    }

    // Function to remove (dequeue) a customer after serving
    string dequeue() {
        if (isempty()) {
            cout << "No customers in line." << endl;
            return "";
        } else {
            string x = arr[front];
            if (front == rear) {
                front = rear = -1; // Reset queue when last customer is served
            } else {
                front++;
            }
            cout << x << " has been served." << endl;
            return x;
        }
    }
};

//MAIN FUNCTION
int main() {

    
    CustomerServiceQueue q;

    q.enqueue("huria");
    q.enqueue("huma");
    q.enqueue("saba");

    cout << "Next customer: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Extra dequeue to show empty queue message

    return 0;
}

