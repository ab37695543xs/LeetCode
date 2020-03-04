#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int len = strlen(s), count = 0;
    bool isSpace = false;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ')
            isSpace = true;
        // arbitrary len of space + non space
        // reset the count
        else if (isSpace) {
            isSpace = false;
            count = 1;
        }
        // non space chars
        else
            count++;
    }
    return count;
}


int main() {
    printf("ans: %d\n", lengthOfLastWord(" hello   "));
    return 0;
}
