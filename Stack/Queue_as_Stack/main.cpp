#include <iostream>
#include <stack>
using namespace std;
void pop(stack<int> &s1){
stack<int> s2;
while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
}
s2.pop();
while(!s2.empty()){
    s1.push(s2.top());
    s2.pop();
}
}
void display(stack<int> s1){
    int x;
    x = s1.top();
    cout<<x<<" ";
    s1.pop();
    if(!s1.empty())
        display(s1);
    s1.push(x);
}
int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    display(s1);
    cout<<endl;
    pop(s1);
    display(s1);
    cout<<endl;
    pop(s1);
    display(s1);
    return 0;
}
