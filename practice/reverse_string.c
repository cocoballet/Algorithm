// reverse specific length charaters to the end of a string
// eg. given string "abcdef", reverse"abc" to the end, return "defabc"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void reverse_string(char *s, int from, int to) {
    while(from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void rotate_string(char *s, int n, int m) {
    m %= n;
    reverse_string(s, 0, m-1);
    reverse_string(s, m, n-1);
    reverse_string(s, 0, n-1);
//    printf("%s", s);

}

int main(int argc, char *argv[]) {
    char *s = argv[1];
    int n = strlen(s);
    int m = atoi(argv[2]);
    rotate_string(s, n, m);
    printf("%s\n", s);
    return 0;
}
