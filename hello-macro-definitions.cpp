/*
* This program was written by Alexander John for educational purposes.
* 
* Function like macros
* 
* A function like macro definition declares the name of formal parameters
* within parentheses, separated by commas. An empty format parameter list
* is legal: such a macro can be used to simulate a function that takes
* no arguments.
* 
* Example:
* 
* #define SUM(a, b, c) a + b + c
* 
*/

#include <iostream>
using namespace std;

#define SUM(a, b, c) a + b + c;

int main()
{
    cout << SUM(1, 2, 4);

    cout << endl;

    return 0;
}