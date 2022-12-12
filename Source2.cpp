#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double function(double x, double absError, int maxNumber);
int Foo(double d);
int ma1231232in()
{
    int maxnumber = 0;
    double absError = 0.0;
    double step = 0.0;
    double to = 0.0;
    double from = 0.0;
    double result = 0.0;
    int dec=0;
    int b = 0;
    try
    {
        cout << "Enter absError: ";
        cin >> absError;
        if (!cin || absError > 1 || absError < 0)
        {
            throw "The value absError is incorrect";
        }
        b = Foo(absError);
        cout << "Enter from: ";
        cin >> from;
        if (!cin)
        {
            throw "The value from is incorrect";
        }
        cout << "Enter to: ";
        cin >> to;
        if (!cin || to <= from)
        {
            throw "The value to is incorrect";
        }
        cout << "Enter step: ";
        cin >> step;
        if (!cin || step > to - from || step <= 0)
        {
            throw "The value step is incorrect";
        }
        dec=Foo(step);
        cout << "Enter maxnumber: ";
        cin >> maxnumber;
        if (!cin || cin.peek() != '\n' || maxnumber < 1)
        {
            throw "The value maxnumber is incorrect";
        }
        cout << "   x  | Taylor 's Row |      e^x      |\n";
        cout << "=======================================\n";
        for (double i = from; i <= to; i += step)
        {
            i = round(i * pow(10,dec)) / pow(10, dec);
            result = function(i, absError, maxnumber);
            if (result == -1)
            {
                throw "The value is incorrect ";
            }
            if (result == -2.0)
            {
                throw "Accuracy not achieved";
            }
            cout.width(5);
            cout.precision(dec+1);
            cout << i << " | ";
            cout.width(13);
            cout.precision(b+1);
            cout << result << " | ";
            cout.width(13);
            cout.precision(b+1);
            cout << pow(2.718281828,i) << " |  \n";
        }
    }
    catch (const char* error)
    {
        cerr << "\nError: " << error << "\n";
        exit(-1);
    }
    return 0;
}

double function(double x, double absError, int maxNumber)
{
    if (x <= -1.0 || x >= 1.0)
    {
        return -1.0;
    }
    double term = 1, result = 1;
    int i = 1;
    while (abs(term) > absError && i < maxNumber)
    {
        term = term *x/i;
        result += term;
        ++i;
    }
    if (i == maxNumber && term > absError)
    {
        return -2.0;
    }
    return result;
}
int Foo(double d) 
{
    int test = (int)d;
    int count = 0;
    while (test != d) {
        count++;
        d *= 10;
        test = (int)d;
    }
    return count;
}
