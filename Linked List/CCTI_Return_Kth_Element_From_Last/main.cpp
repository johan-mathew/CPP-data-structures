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
int ReturnFromLast(int k){
Node *p,*q;
p = head;
q = head;
for(int i =0; i<k;i++)
    p=p->next;
while(p){
    p=p->next;
    q=q->next;
}
return q->data;
}

int main()
{
    InsertNewNode(1);
    InsertNewNode(2);
    InsertNewNode(3);
    InsertNewNode(4);
    InsertNewNode(5);
    PrintList();
    cout<<"4th element from last : "<<ReturnFromLast(4);
    return 0;
}
