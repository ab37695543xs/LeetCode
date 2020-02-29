#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s) {
    int len = strlen(s), i, j = 0;
    if (len == 0)
        return true;
    else if (len == 1)
        return false;
    char left[len], c; // keep the left parentheses in array

    for (i = 0; i < len; i++) {
        c = s[i];
        if (c  == '(' || c == '{' || c == '[') {
            left[j] = c;
            j++;
            continue;
        }
        else {
            if (j < 1)
                return false;
            else if ((c == ')' && left[j - 1] == '(') ||
                (c == '}' && left[j - 1] == '{') ||
                (c == ']' && left[j - 1] == '[')) {
                left[j - 1] = '\0';
                j--;
            }
            else
                return false;
        }
    }
    return left[0] == '\0' ? true : false;
}

int main() {
    char *s = "{[]}";
    isValid(s) ? printf("ans: true\n") : printf("ans: false\n");
    return 0;
}
