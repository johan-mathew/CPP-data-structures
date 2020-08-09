#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Node{
public:
    int vertex;
    Node* link;
};
void newedge(vector<Node*> &G, int vertex1, int vertex2){
Node *p;
Node* newedge1 = new Node();
newedge1->vertex = vertex1;
newedge1->link = nullptr;
p = G.at(vertex2);
if(G.at(vertex2) == nullptr){
    G.at(vertex2) = newedge1;
}

else{
    while(p->link)
        p=p->link;
    p->link = newedge1;
}
Node* newedge2 = new Node();
newedge2->vertex = vertex2;
newedge2->link = nullptr;
p = G.at(vertex1);
if(G.at(vertex1) == nullptr)
    G.at(vertex1) = newedge2;
else{
    while(p->link)
        p=p->link;
    p->link = newedge2;
}
}

void PrintList(vector<Node*> G){
Node* p;
for(size_t i = 0; i<G.size(); i++){
    p = G.at(i);
    cout<<i<<": ";
    while(p)
    {
        cout<<p->vertex<<" ";
        p = p->link;
    }
    cout<<endl;
}
}
void DFS(vector<Node*> G,int node){
Node* s;
static vector<bool> visited(7,false);
            cout<<node<<" ";
            visited.at(node) = true;
            s = G.at(node);
            while(s){
                if(!visited.at(s->vertex))
                    DFS(G,s->vertex);
                s=s->link;
            }
}
void BFS(vector<Node*> &G, int node){

Node *s;
queue<int> q;
vector<bool> visited(7,false);
cout<<node<<" ";
visited.at(node) = true;
q.push(node);
while(!q.empty()){
    s = G.at(q.front());
    q.pop();
    while(s){
        if(!visited.at(s->vertex))
        {
            visited.at(s->vertex) = true;
            cout<<s->vertex<<" ";
            q.push(s->vertex);
        }
        s=s->link;
    }
}


}
int main()
{
    vector<Node*> G;
    Node* g;
    g = nullptr;
    for (int i = 1; i< 8; i++){
        G.push_back(g);
    }
    newedge(G,1,2);
    newedge(G,1,3);
    newedge(G,2,4);
    newedge(G,2,5);
    newedge(G,3,4);
    newedge(G,4,5);
    newedge(G,4,6);
    newedge(G,5,6);
    PrintList(G);
    cout<<endl<<"DFS :";
    DFS(G,1);
    cout<<endl<<"BFS :";
    BFS(G,1);
}
