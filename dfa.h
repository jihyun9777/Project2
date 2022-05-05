#ifndef DFA_H
#define DFA_H
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

double q0(string input);
double q1(string input, double num, int index);
double q2(string input, double num, int d, int index);
double q3(string input, double num, int d, int index);
double q4(string input, double num, int index);
double q5(string input, double num, int index);
double q6(string input, double num, int p, int index, bool minus);
double q7(string input, double num, int p, int index, bool minus);
double q8(string input, double num, int index);
double q9(string input, double num, int index);
double q10(string input, double num, int index);
double q11(string input, double num, int index);
double q12(string input, double num, int index);
double q13();

double q0(string input)
{
    switch (input[0])
    {
    case '.':
        return q1(input, 0, 1);
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'd':
    case 'D':
    case '-':
    case '_':
        return q13();
    case '0':
        return q12(input, 0, 1);
    case '1':
        return q9(input, 1, 1);
    case '2':
        return q9(input, 2, 1);
    case '3':
        return q9(input, 3, 1);
    case '4':
        return q9(input, 4, 1);
    case '5':
        return q9(input, 5, 1);
    case '6':
        return q4(input, 6, 1);
    case '7':
        return q9(input, 7, 1);
    case '8':
        return q9(input, 8, 1);
    case '9':
        return q9(input, 9, 1);
    case 'q':
    case 'Q':
        exit(0);
    default:
        return q13();
    }
}

double q1(string input, double num, int index)
{
    switch(input[index])
    {
    case '.':
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'd':
    case 'D':
    case '-':
    case '_':
        return q13();
    case '0':
        return q2(input, num, 1, index + 1);
    case '1':
        return q2(input, num + 0.1, 1, index + 1);
    case '2':
        return q2(input, num + 0.2, 1, index + 1);
    case '3':
        return q2(input, num + 0.3, 1, index + 1);
    case '4':
        return q2(input, num + 0.4, 1, index + 1);
    case '5':
        return q2(input, num + 0.5, 1, index + 1);
    case '6':
        return q2(input, num + 0.6, 1, index + 1);
    case '7':
        return q2(input, num + 0.7, 1, index + 1);
    case '8':
        return q2(input, num + 0.8, 1, index + 1);
    case '9':
        return q2(input, num + 0.9, 1, index + 1);
    default:
        return q13();
    }
}

double q2(string input, double num, int d, int index)
{
    if(input.length() == index)
    {
        //cout << num << "\n";
        return num;
    }

    switch (input[index])
    {
    case '.':
    case '-':
        return q13();
    case 'e':
    case 'E':
        return q4(input, num, index + 1);
    case 'f':
    case 'F':
        return q8(input, num, index + 1);
    case '_':
        return q3(input, num, d, index + 1);
    case '0':
        return q2(input, num, d + 1, index + 1);
    case '1':
        num += pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '2':
        num += 2 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '3':
        num += 3 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '4':
        num += 4 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '5':
        num += 5 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '6':
        num += 6 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '7':
        num += 7 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '8':
        num += 8 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '9':
        num += 9 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    default:
        return q13();
    }
}

double q3(string input, double num, int d, int index)
{
    switch (input[index])
    {
    case '.':
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case '-':
        return q13();
    case '_':
        return q3(input, num, d, index + 1);
    case '0':
        return q2(input, num, d + 1, index + 1);
    case '1':
        num += pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '2':
        num += 2 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '3':
        num += 3 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '4':
        num += 4 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '5':
        num += 5 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '6':
        num += 6 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '7':
        num += 7 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '8':
        num += 8 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    case '9':
        num += 9 * pow(0.1, d + 1);
        return q2(input, num, d + 1, index + 1);
    default:
        return q13();
    }
}

double q4(string input, double num, int index)
{
    switch (input[index])
    {
    case '.':
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'd':
    case 'D':
    case '_':
        return q13();
    case '-':
        return q5(input, num, index + 1);
    case '0':
        return q6(input, num, 0, index + 1, false);
    case '1':
        return q6(input, num, 1, index + 1, false);
    case '2':
        return q6(input, num, 2, index + 1, false);
    case '3':
        return q6(input, num, 3, index + 1, false);
    case '4':
        return q6(input, num, 4, index + 1, false);
    case '5':
        return q6(input, num, 5, index + 1, false);
    case '6':
        return q6(input, num, 6, index + 1, false);
    case '7':
        return q6(input, num, 7, index + 1, false);
    case '8':
        return q6(input, num, 8, index + 1, false);
    case '9':
        return q6(input, num, 9, index + 1, false);
    default:
        return q13();
    }
}

double q5(string input, double num, int index)
{
    switch (input[index])
    {
    case '.':
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'd':
    case 'D':
    case '-':
    case '_':
        return q13();
    case '0':
        return q6(input, num, 0, index + 1, true);
    case '1':
        return q6(input, num, 1, index + 1, true);
    case '2':
        return q6(input, num, 2, index + 1, true);
    case '3':
        return q6(input, num, 3, index + 1, true);
    case '4':
        return q6(input, num, 4, index + 1, true);
    case '5':
        return q6(input, num, 5, index + 1, true);
    case '6':
        return q6(input, num, 6, index + 1, true);
    case '7':
        return q6(input, num, 7, index + 1, true);
    case '8':
        return q6(input, num, 8, index + 1, true);
    case '9':
        return q6(input, num, 9, index + 1, true);
    default:
        return q13();
    }
}

double q6(string input, double num, int p, int index, bool minus)
{
    if(input.length() == index)
    {
        if(minus)
            num *= pow(0.1, p);
        else
            num *= pow(10, p);
        //cout << num << "\n";
        return num;
    }

    switch (input[index])
    {
    case '.':
    case 'e':
    case 'E':
    case '-':
        return q13();
    case 'f':
    case 'F':
    case 'd':
    case 'D':
        if(minus)
            num *= pow(0.1, p);
        else
            num *= pow(10, p);
        return q8(input, num, index + 1);
    case '_':
        return q7(input, num, p, index, minus);
    case '0':
        return q6(input, num, 0, index + 1, minus);
    case '1':
        p *= 10;
        p += 1;
        return q6(input, num, p, index + 1, minus);
    case '2':
        p *= 10;
        p += 2;
        return q6(input, num, p, index + 1, minus);
    case '3':
        p *= 10;
        p += 3;
        return q6(input, num, p, index + 1, minus);
    case '4':
        p *= 10;
        p += 4;
        return q6(input, num, p, index + 1, minus);
    case '5':
        p *= 10;
        p += 5;
        return q6(input, num, p, index + 1, minus);
    case '6':
        p *= 10;
        p += 6;
        return q6(input, num, p, index + 1, minus);
    case '7':
        p *= 10;
        p += 7;
        return q6(input, num, p, index + 1, minus);
    case '8':
        p *= 10;
        p += 8;
        return q6(input, num, p, index + 1, minus);
    case '9':
        p *= 10;
        p += 9;
        return q6(input, num, p, index + 1, minus);
    default:
        return q13();
    }
}

double q7(string input, double num, int p, int index, bool minus)
{
    switch (input[index])
    {
    case '.':
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'd':
    case 'D':
    case '-':
        return q13();
    case '_':
        return q6(input, num, p, index + 1, minus);
    case '0':
        return q6(input, num, 0, index + 1, minus);
    case '1':
        p *= 10;
        p += 1;
        return q6(input, num, p, index + 1, minus);
    case '2':
        p *= 10;
        p += 2;
        return q6(input, num, p, index + 1, minus);
    case '3':
        p *= 10;
        p += 3;
        return q6(input, num, p, index + 1, minus);
    case '4':
        p *= 10;
        p += 4;
        return q6(input, num, p, index + 1, minus);
    case '5':
        p *= 10;
        p += 5;
        return q6(input, num, p, index + 1, minus);
    case '6':
        p *= 10;
        p += 6;
        return q6(input, num, p, index + 1, minus);
    case '7':
        p *= 10;
        p += 7;
        return q6(input, num, p, index + 1, minus);
    case '8':
        p *= 10;
        p += 8;
        return q6(input, num, p, index + 1, minus);
    case '9':
        p *= 10;
        p += 9;
        return q6(input, num, p, index + 1, minus);
    default:
        return q13();
    }
}

double q8(string input, double num, int index)
{
    if(input.length() == index)
    {
        //cout << num << "\n";
        return num;
    }

    return q13();
}

double q9(string input, double num, int index)
{
    switch (input[index])
    {
    case '.':
        return q11(input, num, index + 1);
    case '-':
        return q13();
    case 'e':
    case 'E':
        return q4(input, num, index + 1);
    case 'f':
    case 'F':
    case 'd':
    case 'D':
        return q8(input, num, index + 1);
    case '_':
        return q10(input, num, index + 1);
    case '0':
        num *= 10;
        return q9(input, num, index + 1);
    case '1':
        num *= 10;
        num += 1;
        return q9(input, num, index + 1);
    case '2':
        num *= 10;
        num += 2;
        return q9(input, num, index + 1);
    case '3':
        num *= 10;
        num += 3;
        return q9(input, num, index + 1);
    case '4':
        num *= 10;
        num += 4;
        return q9(input, num, index + 1);
    case '5':
        num *= 10;
        num += 5;
        return q9(input, num, index + 1);
    case '6':
        num *= 10;
        num += 6;
        return q9(input, num, index + 1);
    case '7':
        num *= 10;
        num += 7;
        return q9(input, num, index + 1);
    case '8':
        num *= 10;
        num += 8;
        return q9(input, num, index + 1);
    case '9':
        num *= 10;
        num += 9;
        return q9(input, num, index + 1);
    default:
        return q13();
    }
}

double q10(string input, double num, int index)
{
    switch (input[index])
    {
    case '.':
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'd':
    case 'D':
    case '-':
        return q13();
    case '_':
        return q10(input, num, index + 1);
    case '0':
        num *= 10;
        return q9(input, num, index + 1);
    case '1':
        num *= 10;
        num += 1;
        return q9(input, num, index + 1);
    case '2':
        num *= 10;
        num += 2;
        return q9(input, num, index + 1);
    case '3':
        num *= 10;
        num += 3;
        return q9(input, num, index + 1);
    case '4':
        num *= 10;
        num += 4;
        return q9(input, num, index + 1);
    case '5':
        num *= 10;
        num += 5;
        return q9(input, num, index + 1);
    case '6':
        num *= 10;
        num += 6;
        return q9(input, num, index + 1);
    case '7':
        num *= 10;
        num += 7;
        return q9(input, num, index + 1);
    case '8':
        num *= 10;
        num += 8;
        return q9(input, num, index + 1);
    case '9':
        num *= 10;
        num += 9;
        return q9(input, num, index + 1);
    default:
        return q13();
    }
}

double q11(string input, double num, int index)
{
    if(input.length() == index)
    {
        //cout << num << "\n";
        return num;
    }

    switch (input[index])
    {
    case '.':
    case '-':
    case '_':
        return q13();
    case 'e':
    case 'E':
        return q4(input, num, index + 1);
    case 'f':
    case 'F':
    case 'd':
    case 'D':
        return q8(input, num, index + 1);
    case '0':
        return q2(input, num, 1, index + 1);
    case '1':
        return q2(input, num + 0.1, 1, index + 1);
    case '2':
        return q2(input, num + 0.2, 1, index + 1);
    case '3':
        return q2(input, num + 0.3, 1, index + 1);
    case '4':
        return q2(input, num + 0.4, 1, index + 1);
    case '5':
        return q2(input, num + 0.5, 1, index + 1);
    case '6':
        return q2(input, num + 0.6, 1, index + 1);
    case '7':
        return q2(input, num + 0.7, 1, index + 1);
    case '8':
        return q2(input, num + 0.8, 1, index + 1);
    case '9':
        return q2(input, num + 0.9, 1, index + 1);
    default:
        return q13();
    }
}

double q12(string input, double num, int index)
{
    switch (input[index])
    {
    case '.':
        return q11(input, num, index + 1);
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'd':
    case 'D':
    case '-':
    case '_':
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
    default:
        return q13();
    }
}

double q13()
{
    cout << "Input is not a decimal. \n";
    return -1;
}


#endif // DFA_H
