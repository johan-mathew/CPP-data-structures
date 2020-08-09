#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};
Node *head, *temp;
int count = 0;
//Initial Insertion in a Linked List
void insertNewNode( int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->next = nullptr;
    if(head == nullptr)
        head  = newnode;
    else
        temp->next = newnode;
    temp = newnode;
    count++;
}
//Print Linked List
void printList(){
    Node *p = head;
    while(p != nullptr){
        cout<<p->data<<" -> ";
        p = p->next;
    }
    cout<<endl;
}
void MiddleElement(){
    Node *p,*q;
    p = q = head;
    while(q!=nullptr){
        if(q->next)
            q = q->next->next;
        else
            break;
        p = p->next;
    }
    cout<<"Middle Element is "<<p->data<<endl;
}
int main()
{
    insertNewNode(1);
    insertNewNode(2);
    insertNewNode(3);
    insertNewNode(4);
    insertNewNode(5);
    insertNewNode(6);
    insertNewNode(7);
    printList();
    MiddleElement();
    return 0;
}
