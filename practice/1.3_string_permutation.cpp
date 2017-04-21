// given String = "abc"
// return "abc","bac","cab","bca","cba","acb"

#include <string>;
#include <iostream>;

using namespace std;

static int count = 0;
static void Permutation(char[] s, int from, int to) {
	if(to <= 1)
		return;
    if(from == to) {
        cout << s << endl;
		++count;
	} else {
		for(int i=from;i<=to;i++){
		swap(s,i,from);
		Permutation(s,from+1,to);
		swap(s,from,i);
	}
}

public static void swap(char[] s, int i, int j) {
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}
