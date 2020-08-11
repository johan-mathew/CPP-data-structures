#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;
void newedge(vector<list<int>> &G, int vertex1, int vertex2){
    G.at(vertex1).push_back(vertex2);
    G.at(vertex2).push_back(vertex1);
}
void PrintList(vector<list<int>> G){
    for(size_t i = 0; i < G.size(); i++){
        cout<<i<<" : ";
        for(auto l : G.at(i))
            cout<<l<<" ";
        cout<<endl;
    }
}
void DFS(vector<list<int>> G,int node){
    static vector<bool> visited(6,false);
    if(!visited.at(node)){
        visited.at(node) = true;
        cout<<node<<" ";
        for(auto l : G.at(node))
            DFS(G,l);
    }
}
void BFS(vector<list<int>> G, int node){
    vector<bool> visited(6,false);
    queue<int> q;
    int x;
        cout<<node<<" ";
        visited.at(node) = true;
        q.push(node);
        while(!q.empty()){
            x = q.front();
            q.pop();
            for(auto l : G.at(x)){
                if(!visited.at(l)){
                cout<<l<<" ";
                visited.at(l) = true;
                q.push(l);
                }
            }
        }
    }
int main()
{
    list<int> l;
    vector<list<int>> G(6,l);
    newedge(G,0,1);
    newedge(G,0,2);
    newedge(G,1,3);
    newedge(G,1,4);
    newedge(G,2,3);
    newedge(G,3,4);
    newedge(G,3,5);
    newedge(G,4,5);
    PrintList(G);
    cout<<"DFS : ";
    DFS(G,0);
    cout<<endl<<"BFS : ";
    BFS(G,0);
    return 0;
}
