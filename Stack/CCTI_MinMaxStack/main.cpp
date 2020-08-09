#include <iostream>
#include <stack>
using namespace std;
class StackInt{
    stack<int> s;
    int minimum;
public:
    void Push(int p){
    if(s.empty()){
        minimum = p;
        s.push(minimum);
    }
    else if(p<minimum){
        s.push(2*p-minimum);
        minimum = p;
    }
    else
        s.push(p);
    }
    int Pop(){
        int x = s.top();
        s.pop();
        if(x<minimum){
            minimum = 2*minimum - x;
            return minimum;
        }
        else
            return x;
    }
    int getminimum(){
        return minimum;
    }

}S;
int main()
{
    S.Push(1);
    cout<<S.getminimum()<<endl;
    S.Push(2);
    S.Push(3);
    S.Push(0);
    cout<<S.getminimum()<<endl;
    S.Push(4);
    cout<<S.Pop()<<endl;
    cout<<S.Pop()<<endl;
    cout<<"Min "<<S.getminimum()<<endl;
    cout<<S.Pop()<<endl;
    cout<<S.Pop()<<endl;
    cout<<S.Pop()<<endl;
    return 0;
}
