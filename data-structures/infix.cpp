#include<iostream>
using namespace std;
class stack{
  char *a;
  int size;
  int priority;
public:
  stack()
  {
    a=new char[100];
    size=0;
    a[size]='(';
  }
  void push(char c)
  {
    size++;
    a[size]=c;
  }
  char pop()
  {
    size--;
    return a[size+1];
  }
  char top()
  {
    return a[size];
  }
  int shopr()
  {

    if(a[size]=='*')
    return 2;
    else
    if(a[size]=='/')
    return 1;
    else
    if(a[size]=='-')
    return 3;
    else
    if(a[size]=='+')
    return 4;
    else
    if(a[size]=='(')
    return 5;
    else
    if(a[size]=='^')
    return 0;
  }
  int isempty()
  {
    if(size==0)
    return 0;
    else
    return 1;
  }
};
int main()
{
  string t;
  stack s;
  cout<<"Enter the expression to be converted to postfix from infix\n";
  cin>>t;
  int i=0;
  while(t[i])
  {
    switch(t[i])
    {
      case '(':
      {
        s.push('(');
        break;
      }
      case '*':
      {
        while(s.shopr()<=2)
        {
          cout<<s.pop();
        }
        s.push('*');
        break;
      }
      case '/':
      {
        while(s.shopr()<=1)
        {
          cout<<s.pop();
        }
        s.push('/');
        break;
      }
      case '^':
      {
        s.push('^');
        break;
      }
      case '-':
      {
        while(s.shopr()<=3)
        {
          cout<<s.pop();
        }
        s.push('-');
        break;
      }
      case '+':
      {
        while(s.shopr()<=4)
        {
          cout<<s.pop();
        }
        s.push('+');
        break;
      }
      case ')':
      {
        while(s.top()!='(')
        {
          cout<<s.pop();
        }
        s.pop();
        break;
      }
      default:
      cout<<t[i];
    }
    i++;
  }
  while(s.isempty())
  {
    cout<<s.pop();
  }

}
