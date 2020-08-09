#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
};

Node* create(){
    int x;
    cout<<"Enter the data (press -1 to exit): ";
    cin>>x;
    if(x == -1)
        return nullptr;
    Node *newnode = new Node();
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
int countnodes(Node *root){
    if(root == nullptr)
        return 0;
    return countnodes(root->left)+countnodes(root->right)+1;
}
int countnodes2childs(Node *root){
    int rc,lc;
    if(root == nullptr)
        return 0;
    else{
        lc = countnodes2childs(root->left);
        rc = countnodes2childs(root->right);
        if(root->left && root->right)
            return lc + rc +1;
        else
            return lc + rc;
    }
}

int countleaves(Node *root){
    if(root == nullptr)
        return 0;
    else if (!root->left && !root->right)
        return 1;
    else
        return countleaves(root->left) + countleaves(root->right);
}
int main()
{   Node *root;
    root = create();
    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;
    cout<<"No of nodes : "<<countnodes(root)<<endl;
    cout<<"No of nodes having two child : "<<countnodes2childs(root)<<endl;
    cout<<"No of leaves : "<<countleaves(root);
    return 0;
}
