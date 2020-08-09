#include <iostream>
using namespace std;
class Node{
public:
int data;
Node *left,*right;
}*root;

Node* create(){
    Node *newnode = new Node();
    int x;
    cout<<"Enter the data(press -1 for NULL) : ";
    cin>>x;
    if(x == -1)
        return nullptr;
    newnode->data = x;
    cout<<"Enter Left of "<<x<<endl;
    newnode->left = create();
    cout<<"Enter Right of "<<x<<endl;
    newnode->right = create();
    return newnode;
}

int main()
{
    root = create();
    return 0;
}
