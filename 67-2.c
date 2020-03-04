#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// calculate the sum and carry, then modify ans
bool sum(char *ans, char a, char b, bool carry) {
    // a + b = ans
    bool ab_carry = false;
    if (a == '1' && b == '1') // 1 + 1 = 10, default ans is 0
        ab_carry = true;
    else if (a == '1' || b == '1') { // 0 + 1 or 1 + 0 = 01
        *ans = '1';
    }
    // ans + prev carry
    if (carry) {
        if (*ans == '1') { // 01 + 1 = 10
            *ans = '0';
            ab_carry = true;
        }
        else
            *ans = '1';
    }
    return ab_carry;
}

char *addBinary(char *a, char *b) {
    int len_a = strlen(a), len_b = strlen(b);
    int maxlen = len_a >= len_b ? len_a : len_b;
    char *ans = calloc(maxlen + 1, sizeof(char));
    memset(ans, '0', maxlen);
    char aa, bb;
    bool carry = false;
    for (int i = 0; i < maxlen; i++) {
        aa = i < len_a ? a[len_a - 1 - i] : '0';
        bb = i < len_b ? b[len_b - 1 - i] : '0';
        carry = sum(&ans[maxlen - 1 - i], aa, bb, carry);
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
