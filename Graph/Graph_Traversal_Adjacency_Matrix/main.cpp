#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
void DFS(vector<vector<int>> G, int start){
    static vector<int> visited (G.at(0).size(),0);
    if(visited.at(start) == 0){
        cout<<start<<" ";
        visited.at(start) = 1;
        for(size_t i = 0;  i < G.at(start).size() ; i++)
            if(G.at(start).at(i) == 1)
                DFS(G,i);
    }
}
void BFS(vector<vector<int>> G, int start){
    vector<int> visited (G.at(0).size(),0);
    cout<<start<<" ";
    visited.at(start) = 1;
    queue<int> q;
    q.push(start);
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(size_t i = 0; i<G.at(u).size();i++){
            if(visited.at(i) == 0 && G.at(u).at(i) == 1){
                cout<<i<<" ";
                q.push(i);
                visited.at(i) = 1;
            }
        }
    }

}
int main()
{                                                //1,2,3,4,5,6
    vector<vector<int>> G = { { 0,0,0,0,0,0,0},
                                               { 0,0,1,1,0,0,0},//1
                                               { 0,1,0,0,1,1,0},//2
                                               { 0,1,0,0,1,0,0},//3
                                               { 0,0,1,1,0,1,1},//4
                                               { 0,0,1,0,1,0,1},//5
                                               { 0,0,0,0,1,1,0} //6
                                            };
    cout<<"DFS Traversal ";
    DFS(G,1);
    cout<<endl;
    cout<<"BFS Traversal ";
    BFS(G,1);
}
