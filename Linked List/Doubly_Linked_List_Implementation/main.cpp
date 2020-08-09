#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;
};
Node *head,*tail;
int count {0};
//Initialize List
void InsertNewData(int newdata){

    Node *newnode = new Node();
    newnode->data = newdata;
    if(head == nullptr)
        head=newnode;
    else{
        tail->next = newnode;
        newnode->prev = tail;
    }
    tail=newnode;
    count++;
}
//Print Doubly Linked List
void PrintList()
{
    Node *p {head};
    while( p!= nullptr ){

        cout<<p->data;
        if(p->next != nullptr)
            cout<<" -> ";
        p=p->next;
    }
    cout<<endl;
}
//Insert At beginning
void InsertAtBeginning(int newdata){
    Node *newnode = new Node();
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    count++;
}
//Insert At End
void InsertAtEnd(int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    tail->next=newnode;
    newnode->prev=tail;
    tail = newnode;
    count++;
}
//Insert At Position
void InsertAtPosiiton(int pos,int newdata){
if(pos>count+1)
    cout<<"Invalid Data";
else if(pos==1)
    InsertAtBeginning(newdata);
else if (pos==count+1)
    InsertAtEnd(newdata);
else
{
    Node *p {head};
    Node *newnode = new Node();
    newnode->data = newdata;
    while(pos>2){
        p=p->next;
        pos--;
    }
    newnode->next = p->next;
    newnode->prev = p;
    p->next=newnode;
    newnode -> next -> prev = newnode;
    count++;

}
}
//IDelete At Beginning
void DeleteAtBeginning (){
    Node *p;
    p = head;
    head = head -> next;
    head -> prev = nullptr;
    delete p;
    count--;
}
//Delete At End
void DeleteAtEnd(){
    Node *p {tail};
    tail = tail -> prev;
    tail->next = nullptr;
    delete p;
    count--;
}
//Delete At Pos
void DeleteAtPos(int pos){
    if(pos == 1)
        DeleteAtBeginning();
    else if (pos == count)
        DeleteAtEnd();
    else {
        Node *p {head};
        while (pos>1){
            p = p->next;
            pos--;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }
}
//Reverse Doubly Linked List
void ReverseList(){
Node *current {head};
Node *nextnode;
while(current!=nullptr){
    nextnode = current->next;
    current->next = current->prev;
    current->prev=nextnode;
    current=nextnode;
}
current = head;
head = tail;
tail = current;
}


int main()
{
    head = nullptr;
    InsertNewData(1);
    InsertNewData(2);
    InsertNewData(3);
    InsertNewData(4);
    InsertNewData(5);
    InsertNewData(6);
    PrintList();
    //InsertAtBeginning(0);
    //InsertAtEnd(7);
    //InsertAtPosiiton(5,9);
    //DeleteAtBeginning();
    //DeleteAtEnd();
    //DeleteAtPos(2);
    ReverseList();
    PrintList();
    return 0;
}
