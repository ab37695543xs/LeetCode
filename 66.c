#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int *plusOne(int *digits, int digitsSize, int *returnSize) {
    // add 1 to the origin
    int num = 0;
    bool carry = true, extend = false;
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (carry) {
            if (digits[i] == 9) {
                digits[i] = 0;
                // come to 1st digit, not enough space
                if (i == 0)
                    extend = true;
            }
            else {
                digits[i]++;
                break;
            }
        }
    }
    int *ans = NULL;
    // alloc extra space for carry
    if (extend) {
        *returnSize = digitsSize + 1;
        ans = calloc(*returnSize, sizeof(int));
        ans[0] = 1;
        memcpy(ans + 1, digits, sizeof(int) * (*returnSize - 1));
    }
    else {
        *returnSize = digitsSize;
        ans = calloc(*returnSize, sizeof(int));
        memcpy(ans, digits, sizeof(int) * *returnSize);
    }
    return ans;
}

int main() {
    int digits[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int returnSize = 0;
    int *ans = plusOne((int *)&digits, 10, &returnSize);
    printf("ans: [ ");
    for (int i = 0; i < returnSize; i++)
        i != returnSize - 1 ? printf("%d, ", ans[i]): printf("%d ", ans[i]);
    printf("]\n");
    if (ans)
        free(ans);
    return 0;
}
