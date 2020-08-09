#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isOperand(char ch){
switch(ch){
       case '+':case '-':case '*':case '/': case '^':case '(': case ')':return false;
       default:return true;
    }
}
int EvaluatePostfix( string expr){
    stack<int> s;
    int  x1,x2,x3;
    for(auto i : expr){
        if(isOperand(i))
        {
            x3 = i - '0';
            s.push(x3);
        }

        else{
            x2 = s.top();
            s.pop();
            x1 = s.top();
            s.pop();
            switch(i){
            case '+': x3 = x1+x2;break;
            case '-': x3 = x1-x2;break;
            case '*': x3 = x1*x2;break;
            case '/': x3 = x1/x2;break;
            case '^':x3 = x1^x2;break;
            }
            s.push(x3);
        }
    }
 return s.top();
}

int main()
{
    string postfix= "62+7+";
    cout<<EvaluatePostfix(postfix);
}
