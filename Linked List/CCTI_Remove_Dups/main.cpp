#include <iostream>
#include <unordered_set>
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
void RemoveDups(){
    unordered_set<int> s;
    Node *p {head};
    Node *q {head};
    while(p){
        if(s.find(p->data) != s.end()){
            q->next = p->next;
            delete p;
        }
        else
        {
            s.insert(p->data);
            q=p;
        }
        p=q->next;
    }
}
int main()
{
    InsertNewNode(1);
    InsertNewNode(2);
    InsertNewNode(3);
    InsertNewNode(4);
    InsertNewNode(2);
    InsertNewNode(4);
    PrintList();
    RemoveDups();
    PrintList();
    return 0;
}
