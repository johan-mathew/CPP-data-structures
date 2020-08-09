#include <iostream>
using namespace std;
class Node{
public:
    char data;
    Node *next;
};
Node *head, *temp;
int count = 0;
//Initial Insertion in a Linked List
void insertNewNode( char newdata){
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
        cout<<p->data;
        p = p->next;
    }
}
bool CheckPalindrome(){
Node *p,*q,*r,*s;
    p=head;
    q=head;
    s=nullptr;
    if(!head->next)
        return true;
    while(p && p->next){
        s=q;
        p=p->next->next;
        q=q->next;
    }
    if(p){
        s=s->next;
        q=q->next;
    }
    s->next=nullptr;
    p=q;
    r=p;
    q=nullptr;
    while(p){
        r=r->next;
        p->next=q;
        q=p;
        p=r;
    }
    p=head;
    while(q){
        if(q->data != p->data)
            return false;
        p=p->next;
        q=q->next;
    }
    return true;
}
int main()
{
    insertNewNode('R');
    insertNewNode('A');
    insertNewNode('D');
    insertNewNode('A');
    insertNewNode('R');
    printList();
    cout<<endl<<CheckPalindrome();
    return 0;
}
