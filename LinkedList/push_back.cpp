#include<iostream>
using namespace std;

class Node{
  
  public:
    int data;
    Node*next;

    Node( int val){
        data=val;
        next= NULL;

    }
};

class List{
    Node*head=NULL;
    Node*tail=nullptr;


public:
    List()
    {
      head=tail=NULL;  
    }
   
  void push_back(int val){
    Node*newNode=new Node( val);
    if(head==NULL){
        head=tail=newNode;
        return;
    }

    else{
        tail->next=newNode;
        tail=newNode;
    }
  }
  

  void printLL(){
      Node*temp=head;
      while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
      }


  }

};

int main(){
    
    List ll;
   ll. push_back(0);
    ll.push_back(1);
    ll.push_back(2);
  ll.printLL();
    
    return 0;
}