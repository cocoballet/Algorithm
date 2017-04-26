#include <iostream>
#include <string>

using namespace std;

int main() {
//  char *str1 = "this is a char";  //convert string const to char*
    const char *str1 = "a const char*";
//  char str2 = "a char";  //error: invalid conversion from ‘const char*’ to ‘char’ [-fpermissive]
    char str3[] = "a char[]";
    string str4("a string");

    cout << str1 << endl;
//  cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;

    return 0;
}
