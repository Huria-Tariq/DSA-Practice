#include<iostream>
using namespace std;

class Node{
   public:
      int data;
      Node*next;
      Node*prev;

    Node( int val){
        data=val;
        next=nullptr;
        prev=nullptr;

    }
};
class doublylinkedlist{
     public:
       Node*head;
       Node*tail;

    doublylinkedlist(){
        head=tail=nullptr;
    }
  void insertatstart(int val){
    Node*newnode=new Node(val);
      
    if(head==nullptr){
        head=tail=newnode;
    }
     else{
         newnode->next=head;
         head->prev=newnode;
          head=newnode;
    }

  }
 
  void display(){
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    
  }

     
};

int main(){
    doublylinkedlist ll;
   ll.insertatstart(3);
   ll. insertatstart(4);
  ll. insertatstart(5);

   ll.display();
    return 0;
}