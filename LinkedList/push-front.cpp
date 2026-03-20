#include <iostream>
using namespace std;

// individual node class
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {                 // constructor
        data = val;
        next = NULL;
     }
};

class List
{
    Node *head;
    Node *tail;
public:
    List()
    {
        head = tail = NULL;
    }
    //push_front

 void push_front(int val){

    Node*newNode= new Node(val);
    if (head==NULL){
        head=tail=newNode;
        return;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
 }

   //pop_front
void pop_front(int val){
    if(head==nullptr){
        cout<< "list is empty";
        return;
    }
    
        Node*temp=head;
        head=head->next;
        temp->next=nullptr;
        
        delete temp;
    
}
 void printLL(){

    Node*temp=head;
    while(temp !=nullptr){
       cout<<temp->data<<" ";
       temp= temp->next;
      
    }
     cout<<endl;

   }
};


 int main()
{   List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    
    ll.pop_front(3);
    ll.printLL();

    
    return 0;
}
