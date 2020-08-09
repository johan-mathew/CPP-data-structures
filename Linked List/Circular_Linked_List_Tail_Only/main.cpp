#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
Node *tail;
int count=0;
//Initialize List
void InsertNewNode( int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    if (tail == nullptr){
        tail = newnode;
        tail->next = newnode;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
    count++;
}
//Print List
void PrintList(){
    Node *p;
    p = tail->next;
    while (p->next != tail->next){
        cout<<p->data<<" -> ";
        p=p->next;
    }
    cout<<p->data<<endl;
}
//Insert At Beginning
void InsertAtBeginning(int newdata){

Node * newnode = new Node();
newnode->data = newdata;

if (tail == nullptr){
    tail = newnode;
    tail->next = tail;
}
else {
    newnode->next = tail->next;
    tail->next = newnode;
}
count++;
}
//Insert At End
void InsertAtEnd( int newdata){

Node *newnode = new Node();
newnode->data = newdata;
if (tail == nullptr){
    tail = newnode;
    tail->next = tail;
}
else {
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
}

count++;
}
//Insert At Pos
void InsertAtPos (int pos, int newdata){
Node *newnode = new Node();
Node *p = tail->next;
newnode->data = newdata;
if(pos > count+1 || pos <1)
    cout<<"Invalid Position"<<endl;
else if (pos == 1)
    InsertAtBeginning(newdata);
else if (pos == count +1)
    InsertAtEnd(newdata);
else {
    while (pos > 2){
        pos--;
        p = p->next;
    }
    newnode->next = p->next;
    p->next = newnode;
    count++;
}
}
//Delete At Beginning
void DeleteAtBeginning()
{
    Node *p = tail->next;
    tail->next = p->next;
    delete p;
    count--;
}
//Delete At End
void DeleteAtEnd(){
Node *current,*prev;
current = tail->next;
while(current->next != tail->next)
{
    prev = current;
    current = current->next;
}
tail = prev;
tail->next = current->next;
delete current;
count--;
}
//Delete At Pos
void DeleteAtPos(int pos){
if(pos > count || pos <1)
    cout<<"Invalid Position"<<endl;
else if (pos == 1)
    DeleteAtBeginning();
else if (pos == count +1)
    DeleteAtEnd();
else {
     Node *current,*prev;
    current = tail->next;
    while (pos > 1){
        pos--;
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    delete current;
    count--;
}
}
//Reverse List
void ReverseList(){
Node *prevnode,*current,*nextnode;
current = tail->next;
nextnode = current->next;
while(current != tail){
    prevnode = current;
    current = nextnode;;
    nextnode = current->next;
    current->next = prevnode;
}
nextnode->next = current;
tail = nextnode;

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
    //DeleteAtPos(4);
    ReverseList();
    PrintList();
}
