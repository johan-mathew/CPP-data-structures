//Idea : For every visited vertex 'v', if there is an adjacent 'u'
//such that u is already visited and u is not parent of v, then
//there is a cycle in graph
#include <iostream>
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
bool DetectCycle(vector<list<int>> G,int node,int parent = -1){
    static vector<bool> visited(6,false);
        visited.at(node) = true;
        for(auto l : G.at(node))
            if(!visited.at(l))
                DetectCycle(G,l,node);
            else if(l != parent)
                return true;
    return false;
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
    if(DetectCycle(G,0))
        cout<<"Cycle Detected";
    else
        cout<<"No Cycle Present";
    return 0;
}
