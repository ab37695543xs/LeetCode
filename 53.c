#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int *nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];
    int max = nums[0], sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        // add only when non negative
        if (sum >= 0)
            sum += nums[i];
        else
            sum = nums[i];
        if (sum > max)
            max = sum;
    }
    return max;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("ans: %d\n", maxSubArray((int *)&nums, 9));
    return 0;
}
