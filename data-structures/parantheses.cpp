#include<iostream>
using namespace std;
class stack
{
  char *a;
  int size;
public:
  stack()
  {
    a=new char[100];
    size=-1;
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
  int isempty()
  {
    if(size==-1)
    return 0;
    else
    return 1;
  }
};
int main()
{
  stack s,r;
  string t;
  int on=0;
  cout<<"Enter the string to be evaluated\n";
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
      case '{':
      {
        s.push('{');
        break;
      }
      case '[':
      {
        s.push('[');
        break;
      }
      case ')':
      {
        if(s.top()!='(')
        {
          cout<<"Error matching parantheses\n";
          on=1;
        }
        else
        {
          s.pop();
        }
        break;
      }
      case '}':
      {
        if(s.top()!='{')
        {
          cout<<"Error matching parantheses\n";
          on=1;
        }
        else
        {
          s.pop();
        }
        break;
      }
      case ']':
      {
        if(s.top()!='[')
        {
          cout<<"Error matching parantheses\n";
          on=1;
        }
        else
        {
          s.pop();
        }
        break;
      }
    }
    if(on)
    break;
    i++;
  }
if(on==0)
{
  cout<<"No Error in matching paranthese\n";
}
}
