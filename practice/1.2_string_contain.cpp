//given long string A and short string B
//if all carather in B are all contian in A
//return true

#include <string>
#include <iostream>
#include <algorithm>

bool string_contain(std::string &a, std::string &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int pa = 0, pb = 0; pb < b.size(); pb++) {
        while((pa < a.size()) && (a[pa] < b[pb]))
            pa++;
        if((pa > a.size()) || (a[pa] > b[pb]))
            return false;
    }
    return true;
}

int main() {
    std::string a, b;
    std::cout << "string A: ";
    std::cin >> a;
    std::cout << "string B: ";
    std::cin >> b;
    std::cout << string_contain(a, b) << std::endl;
    return 0;
}
