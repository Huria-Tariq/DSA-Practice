
#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node*next;

    Node(int val){
        data=val;
        next=nullptr;
    }

};

//1. Reverse Display Using Loop


void displayReverseloop(Node*head){
    Node*prev=nullptr;
    Node*curr=head;
    Node*next=nullptr;
   
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
//1. Reverse Display Using recurrsion

   Node* temp = prev;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

int main(){
    Node*head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
   
 cout << "Reverse using Loop: ";
    displayReverseloop(head);
}