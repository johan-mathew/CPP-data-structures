#include <iostream>
#include <Stack>
#include<String>
using namespace std;
void printStack( stack<char> s){
    if(s.empty())
        return;
    char x;
    x = s.top();
    s.pop();
    printStack(s);
    cout<<x<<" ";
    s.push(x);
}
bool checkParanthesis(string expr){
    stack<char> s;
    char x;
    for (int i = 0; i<expr.length(); i++){
        if( expr[i] == '(' || expr[i] == '{ ' || expr[i] == '[' )
           {
           s.push(expr[i]);
           printStack(s);
           continue;
           }

        if(s.empty())
            return false;
        switch(expr[i]){
        case ')':
            x=s.top();
            s.pop();
            if( x != '(' )
                return false;
            break;
        case ']':
            x=s.top();
            s.pop();
            if( x != '[' )
                return false;
            break;
        case '}':
            x=s.top();
            s.pop();
            if( x!= '{' )
                return false;
            break;
        }
    }
    return (s.empty());
}


int main()
{
    string expr = "[ ]()";
    if(checkParanthesis(expr))
        cout<<"Parenthesis Balanced";
    else
        cout<<"Parenthesis Unbalanced";
    return 0;
}


