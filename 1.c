#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *arr = malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                break;
            }
        }
    }
    return arr;
}

int main() {
    int returnSize = 4;
    int nums[4] = {2, 7, 11, 15};
    int *ans = twoSum((int *)&nums, 4, 9, &returnSize);
    printf("ans: [ ");
    for (int i = 0; i < returnSize; i++)
        i == returnSize - 1 ? printf("%d", ans[i]) : printf("%d, ", ans[i]);
    printf(" ]\n");
    free(ans);
    return 0;
}
