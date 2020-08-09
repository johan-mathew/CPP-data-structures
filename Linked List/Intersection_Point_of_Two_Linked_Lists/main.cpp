#include <iostream>
#include <stack>
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
    stack<Node*> s1;
    stack<Node*> s2;
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

    p = head1;
    while(p)
        {
            s1.push(p);
            p=p->next;
        }
    p = head2;
    while(p)
        {
            s2.push(p);
            p=p->next;
        }

    p = s1.top();
    q = s2.top();
    while(p == q)
    {
        s1.pop();
        s2.pop();
        p = s1.top();
        q = s2.top();
    }
    cout<<"Intersecting Node is "<<p->next->data;
        return 0;
}
