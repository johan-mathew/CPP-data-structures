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
        cout<<p->data<<endl;
        p = p->next;
    }
}

int main()
{   Node *p,*q;
    insertNewNode(1);
    insertNewNode(2);
    p = temp;//Looping Element
    insertNewNode(3);
    insertNewNode(4);
    insertNewNode(5);
    temp->next = p;//Pointing to Looping element
    p=head;
    q=head;
    while(p && q)
    {
        p=p->next;
        if(q->next && q->next->next)
            q=q->next->next;
        else
            q=nullptr;
        if(p == q){
            cout<<"Loop is Present"<<endl;
            break;
    }
    }
    if(q == nullptr)
        cout<<"No Loop is Present";
    return 0;
}
