#include <iostream>
using namespace std;
class Node{
    public:
    int data,count;
    Node *left,*right;
    Node(){
        count = 1;
        left = nullptr;
        right = nullptr;
    }
}*root;

void insertNewNode(int newdata){
        Node *p {root};
        Node *r;
        Node *newnode = new Node();
        newnode->data = newdata;
        if(root == nullptr)
            root = newnode;
        else
            {
                while(p){
                    r=p;
                    if( newdata > p->data)
                        p=p->right;
                    else if(newdata < p->data)
                        p=p->left;
                    else{
                        (p->count)++;
                        break;
                    }
                }
                if(p)
                    return;
                else
                {
                    if( newdata > r->data)
                        r->right = newnode;
                    else
                        r->left = newnode;
                }
      }
}
void Inorder(Node *root){
    if(root == nullptr)
        return;
    Inorder(root->left);
    cout<<root->data<<"("<<root->count<<")"<<" ";
    Inorder(root->right);
}

Node *deletenode(Node *root, int key){

if(key > root->data)
    root->right = deletenode(root->right,key);
else if (key < root ->data)
    root->left = deletenode(root->left,key);
else{
    //if root has no child
    if(!root->left && !root->right)
    {
        delete root;
        return nullptr;
    }
    // if root has one child
    else if(root->left == nullptr){
        Node *temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == nullptr){
        Node *temp = root->left;
        delete root;
        return temp;
    }
    //if root has children
    else{
        Node *successorparent = root;//parent of inorder successor
        Node *successor = successorparent->right;
        while(successor->left)//inorder successor
            {
                successorparent = successor;
                successor = successor->left;
            }
        if(successorparent == root)
            successorparent->right = successor->right;
        else
            successorparent->left = successor->right;
        root->data = successor->data;
        delete successor;
        return root;
    }


}


}
int main()
{
    insertNewNode(5);
    insertNewNode(4);
    insertNewNode(3);
    insertNewNode(3);
    insertNewNode(1);
    Inorder(root);
    cout<<endl;
    deletenode(root,1);
    Inorder(root);
    return 0;
}
