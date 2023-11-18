/*
* What you need:
* Windows 10
* Visual Studio 2022 or later
* 
* Step 1:
* Download Zip
* 
* Step 2:
* Unzip
* 
* Step 3:
* Double click the .sln file
* 
* Step 4
* Done!
* 
* The purpose of this program is to demonstrate how to define preprocessor macros.
* 
* To define preprocessor macros we can use #define.
* 
* Syntax:
* 
* #define identifier replacement
* 
* When the preprocessor encounters this directive, it replaces any occurrence of identifier
* in the rest of the code by replacment. This replacement can be an expression, a statement,
* a block or simply anything. The preprocessor does not understand C++ proper, it simply
* replaces any occurrence of identifier by replacement.
* 
* Example:
* 
* #define TABLE_SIZE 100
* int table1[TABLE_SIZE];
* int table2[TABLE_SIZE];
* 
* After the preprocessor has replaced TABLE_SIZE, the code becomes equivalent to:
* 
* int table1[100];
* int table2[100];
* 
* #define can work also with parameters to define function macros:
* 
* #define getmax(a, b) a>b?a:b
* 
* This would replace any occurrence of getmax followed by two arguments by the replacement expression,
* but also replacing each argument by its identifier, exactly as you would expect if it was a function
* 
* This program has been "rewritten" by Alexander John, but the original information was obtained
* by studying the source below.
* 
* Source: https://cplusplus.com/doc/tutorial/preprocessor/
*/

#include <iostream>
using namespace std;

#define getmax(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int x = 5, y;
    y = getmax(x, 2);
    cout << y << endl;
    cout << getmax(7, x) << endl;

    return 0;
}

/*
* Defined macros are not affected by bloack structure. A macro lasts until it is undefined with the #undef preoricessor
* directive:
* 
* #define TABLE_SIZE 100
* int table1[TABLE_SIZE];
* #undef TABLE_SIZE
* #define TABLE_SIZE 200
* int table2[TABLE_SIZE];
* 
* This would generate the same code as:
* 
* int table1[100];
* int table2[200];
* 
* Function macro definitions accept two special operators (# and ##) in the replacemtn sequence:
* 
* The operator #, followed by a parameter name, is replaced by a string literal that contains the
* argument passed (as if enclosed between double quotes):
* 
* #define str(x) #x
* cout << str(test);
* 
* This would be translated into:
* 
* cout << "test";
* 
* The operator ## concatenates two arguments leaving no blank spaces between them:
* 
* #define glue(a, b) a ## b
* glue(c, out) << "test";
* 
* This would also be translated into:
* 
* cout << "test";
* 
* Because preprocessor replacements happen before any C++ syntax check, macro definitions can be a tricky feature.
* But, be careful: code that relies heavily on complicated macros becomes less readable, since the syntax
* expected is on many occasions different from the normal expressions programmers expect in C++.
*/