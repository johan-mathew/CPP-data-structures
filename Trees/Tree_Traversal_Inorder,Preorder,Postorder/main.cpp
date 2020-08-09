#include <iostream>
using namespace std;
class Node{
public:
int data;
Node *left,*right;
};

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
void preorder(Node *root){
    if(root == nullptr)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root){
    if(root == nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node *root){
    if(root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{   Node *root;
    root = create();
    cout<<"Preorder : ";
    preorder(root);
    cout<<endl<<"Inorder : ";
    inorder(root);
    cout<<endl<<"Postorder : ";
    postorder(root);
    return 0;
}
