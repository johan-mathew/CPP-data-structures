#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void DisplayQueue(vector<queue<char>> Q){
    char ch;
    for(size_t i=0; i<Q.size();i++){
         cout<<"Queue "<<i+1<<" : ";
        while(!Q.at(i).empty()){
             ch = Q.at(i).front();
            cout<<ch<<" ";
            Q.at(i).pop();
        }
        cout<<endl;
    }
}
void pushQueue(vector<queue<char>> &Q,char ch, int p){
    Q.at(p).push(ch);
}
void popQueue (vector<queue<char>> &Q){
    for(int i=0;i<Q.size();i++)
    if(!Q.at(i).empty()){
        Q.at(i).pop();
        break;
    }

}
int main()
{
    vector<queue<char>> Q;
    queue<char> q;
    int n;
    cout<<"Enter the no of priorities ";
    cin>>n;
    for(int i=0;i<n;i++)
        Q.push_back(q);
    pushQueue(Q,'A',0);
    pushQueue(Q,'B',1);
    pushQueue(Q,'C',2);
    pushQueue(Q,'D',2);
    DisplayQueue(Q);
    popQueue(Q);
    DisplayQueue(Q);
    popQueue(Q);
    DisplayQueue(Q);
    return 0;
}
