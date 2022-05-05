#include <iostream>
#include <dfa.h>
#include <stack>

using namespace std;

double calculate(double a, double b, char op);
bool check(stack<char>* op, stack<double>* dig, char c);
string sp(string input, unsigned long long index);
double s0(string input, stack<char>* op, stack<double>* dig, unsigned long long index);
double s1(string input, stack<char>* op, stack<double>* dig, unsigned long long index);
double s2(string input, stack<char>* op, stack<double>* dig, unsigned long long index);
double s3(string input, stack<char>* op, stack<double>* dig, unsigned long long index);
double s4(string input, stack<char>* op, stack<double>* dig, unsigned long long index);
double x();

int main()
{
    string input;
    stack<char> op;
    stack<double> dig;

    while (true)
    {
        cout << "Enter an equation (q to exit): ";
        cin >> input;

        if(!input.empty())
        {
            s0(input, &op, &dig, 0);
        }

        while(!op.empty())
        {
            if(op.top() == '(')
                break;
            else if(!dig.empty())
            {
                double b = dig.top();
                dig.pop();

                if(!dig.empty())
                {
                    double a = dig.top();
                    dig.pop();
                    dig.push(calculate(a, b, op.top()));

                    //cout << dig.top() << endl;

                    op.pop();
                }
                else
                    break;
            }
            else
                break;
        }

        if(op.empty() && !dig.empty())
        {
            cout << dig.top() << endl;
            dig.pop();
        }
        else if(!op.empty())
        {
            if(op.top() == '(')
                x();
        }
    }
}

double calculate(double a, double b, char op)
{
    if(op == '+')
        return a + b;
    if(op == '-')
        return a - b;
    if(op == '*')
        return a * b;
    if(op == '/')
        return a / b;
}

bool check(stack<char>* op, stack<double>* dig, char c)
{
    if(!op->empty())
    {
        if((*op).top() == ')')
            return false;
        else if((*op).top() != '(')
        {
            if(c == ')')
            {
                while((*op).top() != '(' && !op->empty())
                {
                    double b = (*dig).top();
                    (*dig).pop();
                    double a = (*dig).top();
                    (*dig).pop();

                    (*dig).push(calculate(a, b, (*op).top()));

                    //cout << (*dig).top() << endl;

                    (*op).pop();
                }

                if(op->empty())
                    return false;
                else if((*op).top() == '(')
                {
                    (*op).pop();
                    return true;
                }
            }
            else if(c == '+' || c == '-')
            {
                double b = (*dig).top();
                (*dig).pop();
                double a = (*dig).top();
                (*dig).pop();

                (*dig).push(calculate(a, b, (*op).top()));

                //cout << (*dig).top() << endl;

                (*op).pop();
                (*op).push(c);
                return true;
            }
            else if(c == '*' || c == '/')
            {
                if((*op).top() == '+' || (*op).top() == '-')
                {
                    (*op).push(c);

                    //cout << (*dig).top() << endl;

                    return true;
                }
                else if ((*op).top() == '*' || (*op).top() == '/')
                {
                    double b = (*dig).top();
                    (*dig).pop();
                    double a = (*dig).top();
                    (*dig).pop();

                    (*dig).push(calculate(a, b, (*op).top()));

                    //cout << (*dig).top() << endl;

                    (*op).pop();
                    (*op).push(c);
                    return true;
                }
            }
        }

        else if((*op).top() == '(' && c != ')')
        {
            //cout << (*dig).top() << endl;

            (*op).push(c);
            return true;
        }
        else if((*op).top() == '(' && c == ')')
        {
            (*op).pop();
            return true;
        }
        else if((*op).top() == ')')
            return false;
    }
    else
    {
        //cout << (*dig).top() << endl;
        (*op).push(c);
    }
}

string sp(string input, unsigned long long index)
{
    unsigned long long end = index;
    string num;

    while(input[end] != '+' && input[end] != '-' && input[end] != '*' &&
          input[end] != '/' && input[end] != '(' && input[end] != ')')
    {
        end ++;
        if(input.length() == end)
            break;
    }

    end -= index;
    num = input.substr(index, end);
    //cout << num << "\n";
    return num;
}

double s0(string input, stack<char>* op, stack<double>* dig, unsigned long long index)
{
    switch (input[index])
    {
    case '(':
        (*op).push('(');
        return s1(input, op, dig, index + 1);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        string num = sp(input, index);
        double digit = q0(num);
        if(digit != -1)
        {
            (*dig).push(digit);
            return s2(input, op, dig, index + num.length());
        }
        return x();
    }
    case 'q':
        exit(0);
    default:
        return x();
    }
}

double s1(string input, stack<char>* op, stack<double>* dig, unsigned long long index)
{
    switch (input[index])
    {
    case '(':
        (*op).push('(');
        return s1(input, op, dig, index + 1);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        string num = sp(input, index);
        double digit = q0(num);
        if(digit != -1)
        {
            (*dig).push(digit);
            return s3(input, op, dig, index + num.length());
        }
        return x();
    }
    default:
        return x();
    }
}

double s2(string input, stack<char>* op, stack<double>* dig, unsigned long long index)
{
    if(input.length() == index)
        return 0;

    switch (input[index])
    {
    case '+':
        if(check(op, dig, '+'))
            return s0(input, op, dig, index + 1);
        else
            return x();
    case '-':
        if(check(op, dig, '-'))
            return s0(input, op, dig, index + 1);
        else
            return x();
    case '*':
        if(check(op, dig, '*'))
            return s0(input, op, dig, index + 1);
        else
            return x();
    case '/':
        if(check(op, dig, '/'))
            return s0(input, op, dig, index + 1);
        else
            return x();
    default:
        return x();
    }
}

double s3(string input, stack<char>* op, stack<double>* dig, unsigned long long index)
{
    if(input.length() == index)
        return 0;

    switch (input[index])
    {
    case ')':
        if(check(op, dig, ')'))
            return s4(input, op, dig, index + 1);
        else
            return x();
    case '+':
        if(check(op, dig, '+'))
            return s1(input, op, dig, index + 1);
        else
            return x();
    case '-':
        if(check(op, dig, '-'))
            return s1(input, op, dig, index + 1);
        else
            return x();
    case '*':
        if(check(op, dig, '*'))
            return s1(input, op, dig, index + 1);
        else
            return x();
    case '/':
        if(check(op, dig, '/'))
            return s1(input, op, dig, index + 1);
        else
            return x();
    default:
        return x();
    }
}

double s4(string input, stack<char>* op, stack<double>* dig, unsigned long long index)
{
    if(input.length() == index)
        return 0;

    switch (input[index])
    {
    case ')':
        if(check(op, dig, ')'))
            return s4(input, op, dig, index + 1);
        else
            return x();
    case '+':
        if(check(op, dig, '+'))
            return s1(input, op, dig, index + 1);
        else
            return x();
    case '-':
        if(check(op, dig, '-'))
            return s1(input, op, dig, index + 1);
        else
            return x();
    case '*':
        if(check(op, dig, '*'))
            return s1(input, op, dig, index + 1);
        else
            return x();
    case '/':
        if(check(op, dig, '/'))
            return s1(input, op, dig, index + 1);
        else
            return x();
    default:
        return x();
    }
}

double x()
{
    cout << "Invalid equation. \n";
    return -1;
}

