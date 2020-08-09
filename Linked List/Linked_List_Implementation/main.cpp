#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};
Node *head, *temp;
int count = 0;
//Initial Insertion in a Linked List
void insertNewNode( int newdata){
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
        cout<<p->data<<endl;
        p = p->next;
    }
}
//Insert At the Beginning
void insertAtBeginning( int newdata){
    Node *newnode = new Node();
    newnode->next = head;
    head = newnode;
    count++;
}
//Insert At the End
void insertAtEnd(int newdata){
    Node *p = head;
    while(p->next != nullptr)
        p=p->next;
    Node *newnode = new Node();
    newnode->data=newdata;
    p->next=newnode;
}
//Insert After a Position
void insertAfterPosition(int pos, int newdata){
    if(pos>count)
        cout<<"Invalid Position";
    else if (pos == 1)
        insertAtBeginning(newdata);
    else if (pos == count)
        insertAtEnd(newdata);
    else {
        Node *p = head;
        while (pos > 1){
            p=p->next;
            pos--;
        }
        Node *newnode = new Node();
        newnode->data = newdata;
        newnode->next = p->next;
        p->next=newnode;
        count++;
    }
}
//Delete from the beginning
void deleteAtBeginning(){
    Node *p = head;
    head = head->next;
    delete p;
    count--;
}
//Delete from the End
void deleteAtEnd(){
    Node *p,*r;
    p = head;
    while (p->next != nullptr){
        r = p;
        p = p->next;
    }
    r->next=nullptr;
    delete p;
    count--;
}
//Delete at a Position
void deleteAtPos(int pos){
    if(pos>count)
        cout<<"Invalid Pos";
    else if (pos == 1)
        deleteAtBeginning();
    else if (pos == count)
        deleteAtEnd();
    else{
            Node *p,*r;
            p = head;
            while (pos != 1){
                r = p;
                p = p->next;
                pos--;
            }
            r->next=p->next;
            delete p;
            count--;
    }

}
//Reverse Linked List
void ReverseList(){
    Node *currentnode, *prevnode, *nextnode;
    currentnode = nextnode = head;
    prevnode = nullptr;
    while(nextnode != nullptr){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}

int main()
{
    head = nullptr;
    int choice, data;
  /*  while(choice){
            cout << "Enter Data" << endl;
            cin>>data;
            insertNewNode(data);
            printList();
            cout<<"Do you want to continue :";
            cin>>choice;
    }*/
    insertNewNode(1);
    insertNewNode(2);
    insertNewNode(3);
    insertNewNode(4);
    insertNewNode(5);
    printList();
    cout<<endl;
    //insertAtBeginning(0);
    //insertAfterPosition(3,9);
    //insertAtEnd(6);
    //deleteAtBeginning();
    //deleteAtEnd();
    //deleteAtPos(3);
    ReverseList();
    printList();
    return 0;
}
