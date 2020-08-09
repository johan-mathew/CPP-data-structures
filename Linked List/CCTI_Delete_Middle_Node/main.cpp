#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
}*head,*temp;
void InsertNewNode(int newdata){

    Node *newnode = new Node();
    if(head == nullptr)
        head = newnode;
    else
        temp->next=newnode;
    temp=newnode;
    newnode->data = newdata;
}
void PrintList(){
    Node *p;
    p = head;
    while(p){
        cout<<p->data<<" -> ";
        p=p->next;
    }
    cout<<endl;
}
void DeleteMiddleNode(){
    Node *p,*q;
    p =head;
    q =head;
    while(p && p->next){
        p = p->next->next;
        q= q->next;
    }
    q->data = q->next->data;
    p = q->next;
    q->next = q->next->next;
    delete p;

}
int main()
{
    InsertNewNode(1);
    InsertNewNode(2);
    InsertNewNode(3);
    InsertNewNode(4);
    InsertNewNode(5);
    PrintList();
    DeleteMiddleNode();
    PrintList();
    return 0;
}
