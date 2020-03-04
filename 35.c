#include <stdio.h>
#include <stdlib.h>

int searchInsert(int *nums, int numsSize, int target) {
    if (numsSize == 0)
        return 0;
    for (int i = 0; i < numsSize; i++) {
        if (target <= nums[i])
            return i;
    }
    // not found
    return numsSize;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    printf("ans: %d\n", searchInsert((int *)&nums, 4, 0));
    return 0;
}
