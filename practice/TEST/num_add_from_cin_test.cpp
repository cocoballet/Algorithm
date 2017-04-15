#include <iostream>

int main() {
    int a, b = 0;   //b must be init, otherwise will get an unexpective ret;
    while(std::cin >> a) 
//        a += a;  //for each cin, a will change its value;
        b += a;
    std::cout <<"\n" << b <<std::endl;
    return 0;
}
