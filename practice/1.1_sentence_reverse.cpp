// given "I am a student.", return "student. a am I".

#include <iostream>
#include <string>
#include <cctype>

void reverse_string(std::string &s, int from, int to) {
    while(from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

/*
int main() {
    std::string s("I am a Student. ");
    std::string &str = s;
    int tmp = 0;
    for(int i = 0; i <= s.size(); i++) {
        if(isspace(s[i])) {
            reverse_string(str, tmp, i-1);
            tmp = i;
        }
    }  
    reverse_string(str, 0, str.size()-1);
    std::cout << str << std::endl;
    return 0;
}
*/

int main() {
    std::string s, str = " ";
    while(std::cin >> s)
        str += (s + " ");
    int tmp = 0;
    for(int i = 0; i < str.size(); i++) {
        if(isspace(str[i])) {
            reverse_string(str, tmp, i-1);
            tmp = i;
        }
    }  
    reverse_string(str, 0, str.size()-1);
    std::cout << str << std::endl;
    return 0;
}

