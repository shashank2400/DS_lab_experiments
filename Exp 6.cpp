/*
A program to demonstrate the use of stack in converting arithmetic expression from infix notation to postfix notation
 and in evaluating arithmetic postfix expression.
*/
#include <iostream>
using namespace std;
class stack1
{
    char a[20];
    int top;
public:
    stack1()
    {

        top=-1;
    }
    void push(int num)
    {
        a[++top]=num;
    }
    char pop()
    {

        return a[top--];
    }
    int priority(char);
    void infix_postfix(char *);
void eval(char *);

};
int stack1::priority(char p)
{

    if(p=='(')
        return 0;
    else if(p=='+'|| p=='-')
        return 1;
    else if(p=='*'|| p=='/')
        return 2;
     else if(p=='^')
        return 3;
}
void stack1::eval(char ex[20])
{
    char *e;
    e=ex;
    int a,b,c;
    while(*e!='\0')
    {


    if(isalnum(*e))
    {
        push(*e-'0');
        }

    else
    {

        a=pop();
        b=pop();


        if(*e=='+')
        {
            c=a+b;

            push(c);
        }
        if(*e=='-')
        {
            c=b-a;

            push(c);
        }
        if(*e=='*')
        {
            c=a*b;
            push(c);
        }
        if(*e=='/')
        {
            c=a/b;
            push(c);
        }

    }
    e++;
    }
    cout<<c;
}
void stack1::infix_postfix(char expr[20])
{
    char *e,x;
    int i=0;
    char q[20];
    e=expr;
    while(*e!='\0')
    {

        if(isalnum(*e))
        {


            cout<<*e;q[i]=*e;i++;
        }
        else if(*e=='(')
                    push(*e);
        else if(*e==')')
        {

            while(((q[i]=pop())!='('))
            {


                    cout<<q[i];
                   i++;
            }
        }
        else{
            while(priority(a[top])>=priority(*e))
            {

            q[i]=pop();
                cout<<q[i];
                i++;
            }
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        q[i]=pop();
        cout<<q[i];
        i++;
    }
    cout<<endl;
    cout<<"postfix evaluation is:"<<endl;
    eval(q);
}
int main()
{
    stack1 s;
    char p[20];
    cin>>p;
s.infix_postfix(p);
    return 0;
}
