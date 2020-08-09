#include <iostream>
#include <stack>
using namespace std;
void sortstack(stack<int> &s){
    int temp;
    stack<int> t;
    if(t.empty())
    {
        t.push(s.top());
        s.pop();
    }
    if(s.empty()){
        s.push(t.top());
        s.pop();
        return;
    }
    while(!s.empty()){
        if(s.top() < t.top()){
            temp = s.top();
            s.pop();
            while(!t.empty()){
                if(t.top()>temp){
                    s.push(t.top());
                    t.pop();
                }
                else
                    break;
            }
           //cout<<endl<<s.top()<<t.top();
            t.push(temp);
            while(!s.empty()){
                if(s.top()>t.top()){
                    t.push(s.top());
                    s.pop();
                }else
                break;
            }
        }
          else{
            t.push(s.top());
            s.pop();
          }
        }
       s = t;
    }
void display(stack<int> s){
    while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();}
    cout<<endl;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(4);
    s.push(3);
    s.push(5);
    s.push(5);
    display(s);
    sortstack(s);
    display(s);
    return 0;
}
