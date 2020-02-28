#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) // negative
        return false;
    if (x / 10 == 0) // 0 ~ 9
        return true;
    if (x % 10 == 0) // last digit = 0 (except 0)
        return false;
    // count digits
    int num = 0, temp = x;
    bool ans = true;
    while (temp != 0) {
        temp /= 10;
        num++;
    }
    int arr[num], i;
    for (i = 0, temp = x; i < num; i++, temp /= 10) {
        arr[num - 1 - i] = temp % 10;
    }
    // compare until middle
    for (i = 0; i <= num / 2; i++) {
        if (arr[i] != arr[num - 1 - i]) {
            ans = false;
            break;
        }
    }
    return ans;
}

int main() {
    int x = -123454321;
    isPalindrome(x) ? printf("ans: true\n") : printf("ans: false\n");
    return 0;
}
