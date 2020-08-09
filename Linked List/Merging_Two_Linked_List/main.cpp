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
    insertNewNode1(2);
    insertNewNode1(6);
    insertNewNode1(9);
    insertNewNode1(13);
    insertNewNode1(15);
    printList(head1);
    insertNewNode2(3);
    insertNewNode2(7);
    insertNewNode2(8);
    insertNewNode2(11);
    insertNewNode2(19);
    printList(head2);
    Node *head3,*last;
    if(head1->data < head2->data)
        {
        head3 = head1;
        last = head1;
        head1 = head1->next;
        }
    else {
        head3 = head2;
        last = head2;
        head2 = head2->next;
    }
    last->next = nullptr;
    while( head1!=nullptr && head2!=nullptr){
        if(head1->data < head2->data){
            last->next = head1;
            last = head1;
            head1 = head1->next;
        }
        else {
            last->next = head2;
            last = head2;
            head2 = head2->next;
        }
        last->next = nullptr;
    }
    if(head1!=nullptr)
        last->next=head1;
    else
        last->next=head2;
    printList(head3);
        return 0;
}
