#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

ont isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')')
    {return 0;}
    return 1;
}

int outPre(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/')
    {
        return 3;
    }
    else if(x=='^')
    {
        return 6;
    }
    else if(x=='(')
    {
        return 7;
    }
    else if(x==')')
    {
        return 0;
    }
    return -1;
}

int inPre(char x)
{
    if(x=='+'||x=='-')
    {
        return 2;
    }
    else if(x=='*'||x=='/')
    {
        return 4;
    }
    else if(x=='^')
    {
        return 5;
    }
    else if(x=='(')
    {
        return 0;
    }
   
    return -1;
}

char* convert(char* infix)
{
    char* postfix = new char [strlen(infix)+1];

    stack<char> stk;

    int i=0;
    int j=0;

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(stk.empty()||outPre(infix[i])>inPre(stk.top()))
            {stk.push(infix[i++]);}
            else if(outPre(infix[i])==inPre(stk.top()))
            {stk.pop();}
            else
            {
                postfix[j++]=stk.top();
                stk.pop();
            }
        }

        while(!stk.empty() && stk.top() != ')')
        {
            postfix[j++]=stk.top();
            stk.pop();
        }
        postfix[j]='\0';
        stk.pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
  char infix[] = "((a+b)*c)-d^e^f";
 
    cout << convert(infix) << endl;
}
