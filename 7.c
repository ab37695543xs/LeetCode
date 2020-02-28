#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int x) {
    int ans = 0;
    while (x != 0) {
        // test overflow
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
            ans = 0;
            break;
        }
        ans = 10 * ans + x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    int x = 1234567;
    printf("ans: %d\n", reverse(x));
    return 0;
}
