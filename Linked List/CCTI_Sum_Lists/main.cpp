#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
Node *head1, *temp1,*head2,*temp2;
//Initial Insertion in a Linked List
void insertNewNode1( int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->next = nullptr;
    if(head1 == nullptr)
        head1  = newnode;
    else
        temp1->next = newnode;
    temp1 = newnode;
}

void insertNewNode2( int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->next = nullptr;
    if(head2 == nullptr)
        head2  = newnode;
    else
        temp2->next = newnode;
    temp2 = newnode;
}
void printList(Node *p){
    while(p != nullptr){
        cout<<p->data<<" -> ";
        p = p->next;
    }
    cout<<endl;
}
Node* SumList(Node *p, Node *q){
    Node *r,*t;
    r = nullptr;
    int carry = 0;
    int sum;
    while(p && q){
        Node *newnode = new Node();
        sum = carry + p->data + q->data;
        newnode->data = sum%10;
        carry = sum/10;
        if(r == nullptr)
         r = newnode;
        else
            t->next = newnode;
        t = newnode;
        p=p->next;
        q=q->next;
    }
    while(p){
        Node *newnode = new Node();
        sum = carry + p->data;
        newnode->data = sum%10;
        carry = sum/10;
        t->next = newnode;
        t = newnode;
        p=p->next;
    }
    while(q){
        Node *newnode = new Node();
        sum = carry + q->data;
        newnode->data = sum%10;
        carry = sum/10;
        t->next = newnode;
        t = newnode;
        q=q->next;
    }
    if(carry){
        Node *newnode = new Node();
        newnode->data = carry;
        t->next = newnode;
        t = newnode;
    }
    return r;
}
int main()
{
    insertNewNode1(2);
    insertNewNode1(6);
    insertNewNode1(9);
    printList(head1);
    insertNewNode2(3);
    insertNewNode2(7);
    printList(head2);
    Node *head3;
    head3 = SumList(head1,head2);
    printList(head3);
    return 0;
}
