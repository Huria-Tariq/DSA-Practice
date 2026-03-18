#include <iostream>
using namespace std;

//  Node class 
class Node
{
public:
    string data; 
    Node *next;  

    Node(string value)
    {
        data = value;
        next = nullptr;
    }
};

//  Queue class 
class CustomerServiceQueue
{
    Node *head; 
    Node *tail; 

public:
    // Constructor 
    CustomerServiceQueue()
    {
        head = tail = nullptr;
    }

    // Check if the queue is empty
    bool isempty()
    {
        return head == nullptr;
    }

    //  Enqueue
    void enqueue(string customerName)
    {
        Node *newnode = new Node(customerName);
        if (isempty())
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cout << customerName << " joined the queue." << endl;
    }

    // Peek
    string peek()
    {
        if (isempty())
        {
            cout << "No customers in line." << endl;
            return "";
        }
        return head->data;
    }

    // Dequeue
    string dequeue()
    {
        if (isempty())
        {
            cout << "No customers in line." << endl;
            return "";
        }

        string x = head->data;
        Node *temp = head;
        head = head->next;

        if (head == nullptr)
        {
            tail = nullptr; 
        }

        delete temp;
        cout << x << " has been served." << endl;
        return x;
    }

    //  Display
    void display()
    {
        if (isempty())
        {
            cout << "No customers in line." << endl;
            return;
        }

        Node *temp = head;
        cout << "Current Queue:" << endl;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};


int main()
{
    
    CustomerServiceQueue q;

    // Enqueue customers into the queue
    q.enqueue("Huria");
    q.enqueue("Saba");
    q.enqueue("Iman");

    // Display the next customer to be served
    cout << "\nNext customer: " << q.peek() << endl;

    
    q.dequeue();
    q.display();

    
    q.dequeue();
    q.dequeue();

    // Try to serve when queue is empty (to test empty case)
    q.dequeue();

    return 0;
}


