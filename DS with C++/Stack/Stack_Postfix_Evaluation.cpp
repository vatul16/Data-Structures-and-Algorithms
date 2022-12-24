// Implementation of Stack application: Postfix Evaluation

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
using namespace std;
const int MAX = 50;

class postfix
{
    private:
        int stack[MAX];
        int top, nn;
        char *s;

    public:
        postfix();
        void setexpr(char *str);
        void push(int item);
        int pop();
        void calculate();
        void show();
};

// initialises data members
postfix :: postfix()
{
    top = -1;
}

// sets s to point to the given expr.
void postfix :: setexpr(char *str)
{
    s = str;
}

//adds digit to the stack
void postfix :: push(int item)
{
    if(top == MAX - 1)
    {
        cout<<"Stack is full."<<endl;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

// pop digit from the stack
int postfix :: pop()
{
    if(top == -1)
    {
        cout<<"Stack is empty."<<endl;
        return NULL;
    }
    int data = stack[top];
    top--;
    return data;
}

// evaluates the postfix expression
void postfix :: calculate()
{
    int n1, n2, n3;
    while(*s)
    {
        // skip whitespace, if any
        if(*s == ' ' || *s == '\t')
        {
            s++;
            continue;
        }

        // if digit is encountered
        if(isdigit(*s))
        {
            nn = *s - '0';
            push(nn);
        }
        else
        {
            // if operator is encountered
            n1 = pop();
            n2 = pop();
            switch(*s)
            {
                case '+':
                    n3 = n2 + n1;
                    break;

                case '-':
                    n3 = n2 - n1;
                    break;

                case '/':
                    n3 = n2 / n1;
                    break;

                case '*':
                    n3 = n2 * n1;
                    break;

                case '%':
                    n3 = n2 % n1;
                    break;

                case '$':
                    n3 = (int)pow((double)n2, (double)n1);
                    break;

                default:
                    cout<<"Unknown operator"<<endl;
                    exit(1);
            }

            push(n3);
        }
        s++;
    }
}

// displays the result
void postfix :: show()
{
    nn = pop();
    cout<<"Result is: "<<nn<<endl;
}

int main()
{
    char expr[MAX];

    cout<<"Enter Postfix expression to be evaluated: "<<endl;
    cin.getline(expr, MAX);


    postfix q;

    q.setexpr(expr);
    q.calculate();
    q.show();

    return 0;
}