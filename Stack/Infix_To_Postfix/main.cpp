#include <iostream>
#include <Stack>
#include <String>

/*
| Symbol | Out Stack Precedence | In Stack Precedence |
-------------|---------------------------------|------------------------------|
      +,-     |                  1                  |                 2                |
      *,/      |                  3                  |                 4                |
      ^        |                  6                  |                 5                |
      (        |                  7                  |                 0                 |
       )       |                  0                  |                 -                  |

*/
using namespace std;
int OutPrecedence(char ch){
    switch(ch){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
        return 6;
    case '(':
        return 7;
    case ')':
        return 0;
}
}
int InPrecedence(char ch){
    switch(ch){
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
        return 5;
    case '(':
        return 0;
    }

}
bool isOperand(char ch){
switch(ch){
       case '+':case '-':case '*':case '/': case '^':case '(': case ')':return false;
       default:return true;
}
}
string PostfixExpr(string infix){
    stack<char> s;
    string postfix = "";
    for (auto i: infix){
        if(isOperand(i))
        postfix+=i;
        else
        {
            if(s.empty())
                s.push(i);
            else if( InPrecedence(s.top()) < OutPrecedence(i))
                s.push(i);
            else
            {
                while(OutPrecedence(i) <= InPrecedence(s.top())){
                    if(s.top()!='(')
                    postfix+=s.top();
                    s.pop();
                    if(s.empty())
                        break;
                }
                if(i!=')')
                s.push(i);
            }
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}


int main()
{
    string infix = "((a+b)*c)-d^e^f";
    cout << PostfixExpr(infix);
    return 0;
}
