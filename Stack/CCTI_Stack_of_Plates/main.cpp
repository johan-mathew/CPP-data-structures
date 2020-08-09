#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void display(stack<stack<int>> S){
int i =1;
while(!S.empty()){
    while(!S.top().empty()){
        cout<<S.top().top()<<" ";
        S.top().pop();
    }
    if(S.top().empty())
        S.pop();
}
cout<<endl;
}
void vpush(stack<stack<int>> &S, int x){
if(S.top().size() <= 5)
    S.top().push(x);
else {
    stack<int> s;
    S.push(s);
    S.top().push(x);
}
}
void vpop(stack<stack<int>> &S){
if(!S.top().empty()){
    S.top().pop();
    if(S.top().empty()){
        S.pop();
    }
}
}

int main()
{
    stack<stack<int>> S;
    stack<int> s;
    S.push(s);
    for(int i = 0; i<10;i++)
        vpush(S,i);
    display(S);
    vpop(S);
    vpop(S);
    vpop(S);
    vpop(S);
    vpop(S);
    display(S);
    return 0;
}
