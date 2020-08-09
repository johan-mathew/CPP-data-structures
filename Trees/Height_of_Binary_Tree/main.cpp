#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
};
Node* create(){
    int x;
    cout<<"Enter data (Enter -1 to exit): ";
    cin>>x;
    if(x == -1)
        return nullptr;
    Node* newnode = new Node();
    newnode->data = x;
    cout<<"Enter Left of "<<x<<endl;
    newnode->left = create();
    cout<<"Enter Right of "<<x<<endl;
    newnode->right = create();
    return newnode;
}
void inorder(Node *root){
    if(root == nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int height(Node *root){
    int lh,rh;
    if(root == nullptr)
        return 0;
    lh = height(root->left);
    rh = height(root->right);
    if(lh > rh)
        return lh+1;
    else
        return rh+1;

}
int main()
{
    Node *root;
    root = create();
    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;
    cout<<"Height :"<<height(root);
    return 0;
}
