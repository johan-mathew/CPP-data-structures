#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
Node *head,*tail;
//Initialize List
void InsertNewNode(int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    if (head == nullptr)
        head = newnode;
    else
        tail->next = newnode;
    tail = newnode;
}
//Print List
void PrintList(){
Node *p {head};
while (p != nullptr){
    if(p->next == nullptr)
        cout<<p->data;
    else
        cout<<p->data<<" -> ";
    p=p->next;
}
cout<<endl;
}
//Insert New element into sorted list
void InsertIntoSortedList( int newdata)
{
    Node *newnode = new Node();
    newnode->data = newdata;
    Node *p {head};
    if(head->data > newdata){
        newnode->next = head;
        head = newnode;
    }
    else {
        while(p->next != nullptr){
            if(p->next->data > newdata){
                newnode->next = p->next;
                p->next = newnode;
                break;
            }
            p=p->next;
        }
        if(newdata > p->data){
            p->next = newnode;
        }
    }
}
//Check if a linked list is sorted
bool CheckIfSorted(){
int x = head->data;
Node *p = head;
while (p != nullptr){
    if( x   >   (p->data))
        return false;
    x=p->data;
    p=p->next;
}
return true;
}
//Remove duplicate elements in Sorted Linked List
void RemoveDuplicates(){
Node * p {head};
Node *q;
q=head->next;
while(q != nullptr)
    if(p->data == q->data)
    {
        p->next = q->next;
        delete q;
        q = p->next;
    }
    else{
        p=q;
        q=q->next;
    }

}

int main()
{
    InsertNewNode(5);
    InsertNewNode(10);
    InsertNewNode(15);
    //InsertNewNode(15);
    InsertNewNode(20);
    //InsertNewNode(25);
    //InsertNewNode(25);
    InsertNewNode(25);
    PrintList();
    //InsertIntoSortedList(1);
    //InsertIntoSortedList(30);
    //InsertIntoSortedList(35);
    //InsertIntoSortedList(17);
    RemoveDuplicates();
    PrintList();

    if(CheckIfSorted())
        cout<<"List is Sorted";
    else
        cout<<"List is not Sorted";
    return 0;
}
