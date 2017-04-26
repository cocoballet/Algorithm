// given String = "abc"
// return "abc","bac","cab","bca","cba","acb"

#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

static int count = 0;
void permutation(char *str, int from, int to) {
	if(to <= 1)
		return;
    if(from == to) {
//        cout << str << endl;
//        printf("%s\n", str);
        for(int j = 0; j <= to; ++j)
            cout << str[j];
        cout << endl;
        ++count;
	} else {
	    for(int i=from; i<=to; i++) {
        	swap(str[i], str[from]);
           	permutation(str, from+1, to);
    	    swap(str[i], str[from]);
        }
	}
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        cout << "app & str" << endl;
        return 1;
    }
    char *str = argv[1];
    int to = strlen(str);
    permutation(str, 0, to);
    cout << "count is: " << count <<endl;
    return 0;
}
