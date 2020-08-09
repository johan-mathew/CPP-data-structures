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
void Partition(int x){
Node *head1, *head2,*temp1,*temp2,*p;
head1 = nullptr;
head2 = nullptr;
p = head;
Node *newnode;
while(p)
{
    if((p->data) < x){
        if(head1 == nullptr)
            head1 = p;
        else
            temp1->next = p;
        temp1 = p;
    }
    else{
        if(head2 == nullptr)
            head2 = p;
        else
            temp2->next = p;
        temp2 = p;
    }
    p = p->next;
}
    temp1->next = head2;
    head = head1;
}
int main()
{
    InsertNewNode(10);
    InsertNewNode(2);
    InsertNewNode(5);
    InsertNewNode(3);
    InsertNewNode(8);
    PrintList();
    Partition(5);
    PrintList();
    return 0;
}
