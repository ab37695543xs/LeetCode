#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    int len1, len2;
    if ((len2 = strlen(needle)) == 0)
        return 0;
    if ((len1 = strlen(haystack)) == 0)
        return -1;

    // use *check as i, until the minimum length to compare
    for (char *check = haystack; check - haystack <= len1 - len2; check++) {
        if (strncmp(check, needle, len2) == 0)
            return check - haystack;
    }
    return -1;
}


int main() {
    printf("ans: %d\n", strStr("mississippi", "pi"));
    return 0;
}
