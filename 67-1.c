#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b) {
    int len_a = strlen(a), len_b = strlen(b);
    int maxlen = len_a >= len_b ? len_a : len_b;
    char *ans = calloc(maxlen + 1, sizeof(char));
    memset(ans, '0', maxlen);
    int aa, bb, sum, carry = 0;
    for (int i = 0; i < maxlen; i++) {
        // convert to int and sum, then convert back to char
        aa = i < len_a ? a[len_a - 1 - i] - '0' : 0;
        bb = i < len_b ? b[len_b - 1 - i] - '0' : 0;
        sum = aa + bb + carry;
        if (sum >= 2) {
            carry = 1;
            ans[maxlen - 1 - i] = sum - 2 + '0';
        }
        else {
            carry = 0;
            ans[maxlen - 1 - i] = sum + '0';
        }
    }
    // not enough space
    if (carry) {
        char *new_ans = calloc(maxlen + 2, sizeof(char));
        new_ans[0] = '1';
        memcpy(new_ans + 1, ans, maxlen);
        if (ans)
            free(ans);
        return new_ans;
    }
    else
        return ans;
}

int main() {
    char *a = "1111";
    char *b = "1111";
    char *ans = addBinary(a, b);
    printf("ans: %s\n", ans);
    if (ans)
        free(ans);
    return 0;
}
