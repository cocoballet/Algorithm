#include <iostream>
#include <string>
#include <string.h>

using namespace std;
 
int main() {
    const char *str1 = "a const char*";
    char str3[] = "a char[]";
    string str4("a string");

    cout << str1 << " sizeof() is: " << sizeof(str1) << endl;
    cout << str1 << " strlen is: " << strlen(str1) <<endl;
    cout << str3 << " sizeof() is: " << sizeof(str3) << endl;
    cout << str4 << " string.size() is: " << str4.size() << endl;

    return 0;
}

