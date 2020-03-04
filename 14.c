#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0)
        return "";
    if (strsSize == 1)
        return strs[0];
    int maxlen = strlen(strs[0]), minmatch = 0, i, j;
    bool diff = false;
    char *ans = calloc(maxlen + 1, sizeof(char));
    // compare each char
    for (j = 0; j < maxlen; j++) {
        // use first string to compare
        for (i = 1; i < strsSize; i++) {
            if (strs[0][j] != strs[i][j]) {
                diff = true;
                break;
            }
        }
        if (diff)
            break;
        else
            minmatch++;
    }
    strncpy(ans, strs[0], minmatch);
    return ans;
}

int main() {
    char *strs[] = {"aa", "ab"};
    char *ans = longestCommonPrefix((char **)&strs, 2);
    printf("ans: %s\n", ans);
    if (ans)
        free(ans);
    return 0;
}
