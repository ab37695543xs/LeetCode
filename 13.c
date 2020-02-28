#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char *s) {
    int len = strlen (s), ans = 0;
    for (int i = 0, prev = 0, curr = 0; i < len; i++) {
        // roman
        switch (s[i]) {
            case 'I':
                curr = 1;
                break;
            case 'V':
                curr = 5;
                break;
            case 'X':
                curr = 10;
                break;
            case 'L':
                curr = 50;
                break;
            case 'C':
                curr = 100;
                break;
            case 'D':
                curr = 500;
                break;
            case 'M':
                curr = 1000;
                break;
        }
        ans += curr;
        if (prev == 1 && (curr == 5 || curr == 10)) {
            ans -= 2 * prev; // have to sub twice, because we add prev last time
        }
        else if (prev == 10 && (curr == 50 || curr == 100)) {
            ans -= 2 * prev;
        }
        else if (prev == 100 && (curr == 500 || curr == 1000)) {
            ans -= 2 * prev;
        }
        prev = curr;
    }
    return ans;
}

int main() {
    printf("ans: %d\n", romanToInt("MCMXCIV"));
    return 0;
}
