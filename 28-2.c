#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    int len1, len2;
    if ((len2 = strlen(needle)) == 0)
        return 0;
    if ((len1 = strlen(haystack)) == 0)
        return -1;

    int i = 0, j = 0;
    while (i < len1) {
        // match
        if (haystack[i] == needle[j]) {
            // all match
            if (j == len2 - 1)
                return i - j; // the first position of word
            else {
                i++;
                j++;
            }
        }
        // not match
        else {
            // compare next i
            if (j == 0)
                i++;
            // rewind to the first position + 1 of word
            else
                i = i - j + 1;
            j = 0;
        }
    }
    return -1;
}

int main() {
    printf("ans: %d\n", strStr("mississippi", "pi"));
    return 0;
}
