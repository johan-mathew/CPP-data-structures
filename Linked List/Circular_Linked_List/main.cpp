#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
Node *head,*temp;
int count {0};

//Initialize List
void InsertNewNode(int newdata){
    Node *newnode = new Node();
    newnode->data = newdata;
    if(head == nullptr)
        head = newnode;
    else{
        temp->next = newnode;
    }
    temp = newnode;
    temp->next = head;
    count++;
}
//PrintList
void PrintList(){
    Node *p {head};
    while(p->next != head){
        cout<<p->data<<" -> ";
        p = p->next;
    }
    cout<<p->data;
}



int main()
{
    InsertNewNode(1);
    InsertNewNode(2);
    InsertNewNode(3);
    InsertNewNode(4);
    InsertNewNode(5);
    PrintList();
}
