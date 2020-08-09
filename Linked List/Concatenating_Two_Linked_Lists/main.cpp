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
int main()
{
    insertNewNode1(1);
    insertNewNode1(2);
    insertNewNode1(3);
    insertNewNode1(4);
    insertNewNode1(5);
    printList(head1);
    insertNewNode2(6);
    insertNewNode2(7);
    insertNewNode2(8);
    insertNewNode2(9);
    insertNewNode2(10);
    printList(head2);

    Node *p {head1};
    while(p->next != nullptr)
        p=p->next;
    p->next=head2;
    printList(head1);
    return 0;
}
