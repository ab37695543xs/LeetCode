#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// count the contiguous digit and return the convertion
// also return the last position
char *convert(char *prev, int len, int *pos) {
    int count = 1; // c
    char c = prev[*pos];
    for (int i = *pos + 1; i < len; i++) {
        if (c == prev[i])
            count++;
        else
            break;
    }
    *pos = *pos + count;
    // count, digit, \0, need 3 char
    char *result = calloc(3, sizeof(char));
    result[0] = count + '0';
    result[1] = c;
    return result;
}

char *countAndSay(int n) {
    char *ans = calloc(2, sizeof(char)), *prev = NULL, *convertion = NULL;
    strcpy(ans, "1");
    // conver (n-1)th word to (n)th word
    for (int i = 2; i <= n; i++) {
        int pos = 0;
        int len = strlen(ans);
        // copy ans as prev then clear it
        if (prev)
            free(prev);
        prev = calloc(len + 1, sizeof(char));
        strncpy(prev, ans, len);
        memset(ans, 0, len);
        // conver prev to new ans
        while (pos < len) {
            convertion = convert(prev, len, &pos);
            ans = realloc(ans, strlen(ans) + 3);
            strncat(ans, convertion, 3);
            if (convertion)
                free(convertion);
        }
    }
    return ans;
}

int main() {
    char *ans = countAndSay(10);
    printf("ans: %s\n", ans);
    if (ans)
        free(ans);
    return 0;
}
