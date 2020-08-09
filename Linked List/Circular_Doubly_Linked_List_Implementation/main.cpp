#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
};
Node *head,*tail;
int count = 0;
//Initialize LIst
void InsertNewNode(int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    if ( head == nullptr){
        head = newnode;
        tail = head;
        head->next = head;
        head->prev = head;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
    count++;
}
//Print List
void PrintList(){
    Node *p {head};
    while (p->next != head){
        cout<<p->data<<" -> ";
        p=p->next;
    }
    cout<<p->data<<endl;
}

//Insert at Beginning
void InsertAtBeginning(int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->next = head;
    newnode->prev = tail;
    head->prev = newnode;
    tail->next = newnode;
    head = newnode;
    count++;
}
//Insert At End
void InsertAtEnd(int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->prev = tail;
    newnode->next = head;
    tail->next =newnode;
    head->prev = newnode;
    tail = newnode;
    count++;
}
//Insert At Pos
void InsertAtPos(int pos, int newdata){
if(pos == 1)
    InsertAtBeginning(newdata);
else if (pos == count+1)
    InsertAtEnd(newdata);
else if (pos < 1 || pos > count+1)
    cout<<"Invalid Position"<<endl;
else   {
    Node *p {head};
    while (pos>2){
        pos--;
        p=p->next;
    }
    Node *newnode = new Node();
    newnode->data = newdata;
    newnode->next = p->next;
    newnode->prev = p;
    p->next->prev = newnode;
    p->next = newnode;
    count++;
}

}
//Delete At Beginning
void DeleteAtBeginning(){
Node *p {head};
head = head->next;
head->prev = tail;
tail->next = head;
delete p;
count--;
}
//Delete At End
void DeleteAtEnd(){
Node *p {tail};
tail=tail->prev;
tail->next = head;
head->prev = tail;
delete p;
count--;
}
//Deleta At Pos
void DeleteAtPos(int pos){
if(pos == 1)
    DeleteAtBeginning();
else if (pos == count)
    DeleteAtEnd();
else if (pos <1 || pos > count)
    cout<<"Invalid Pos"<<endl;
else {
     Node *p {head};
     while (pos>1){
        pos--;
        p=p->next;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}
}

int main()
{
    InsertNewNode(1);
    InsertNewNode(2);
    InsertNewNode(3);
    InsertNewNode(4);
    InsertNewNode(5);
    PrintList();
    //InsertAtBeginning(0);
    //InsertAtEnd(6);
    //InsertAtPos(2,8);
    //DeleteAtBeginning();
    //DeleteAtEnd();
    DeleteAtPos(3);
    PrintList();
    return 0;
}
