   #include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int val)
  {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};
class doublylinkedlist
{
public:
  Node *head;
  Node *tail;

  doublylinkedlist()
  {
    head = tail = nullptr;
  }
  void insertatend(int val)
  {
    Node *newnode = new Node(val);

    if (head == nullptr)
    {
      head = tail = newnode;
    }
    else
    {
      newnode->prev = tail;
      tail->next = newnode;
      tail = newnode;
    }
  }

  void deleteAtstart()
  {
    if (head == nullptr)
    {
      cout << "list is empty"<<endl;
       return;
    }
    else
    {
      Node *temp = head;
      head = head->next;

      if (head != nullptr)
      {
        head->prev = nullptr;
      }

      temp->next = nullptr;

      delete temp;
    }
  }


void display()
{
  Node *temp =head;
  while (temp != nullptr)
  {
    cout << temp->data << endl;
    temp = temp->next;
  }
}
};

int main()
{
  doublylinkedlist ll;
  ll.insertatend(3);
  ll.insertatend(4);
  ll.insertatend(5);
  ll.deleteAtstart();

  ll.display();
  return 0;
}