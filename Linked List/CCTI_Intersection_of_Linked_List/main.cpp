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
     Node *p,*q;
    insertNewNode1(0);
    insertNewNode1(2);
    insertNewNode1(4);
    insertNewNode1(6);
    p = temp1;  //Intersection Point
    insertNewNode1(7);
    insertNewNode1(8);
    insertNewNode1(9);
    printList(head1);
    insertNewNode2(1);
    insertNewNode2(3);
    insertNewNode2(5);
    temp2->next = p; //Point to intersection point f
    temp2 = p;
    printList(head2);
    int length1=0, length2=0;
    p=head1;
    q=head2;
    while(p){
        p=p->next;
        length1++;
    }
    while(q){
        q=q->next;
        length2++;
    }
    p=head1;
    q=head2;
    int i;
    if(length1>length2){
        i=length1-length2;
        while(i>0){
            p=p->next;
            i--;
        }
    }
    else if (length1<length2){
        i = length2-length1;
        while(i>0){
            q=q->next;
            i--;
        }
    }
    while(p!=q){
        p=p->next;
        q=q->next;
    }
    cout<<p->data<<" is the intersecting node ";
    return 0;
}
