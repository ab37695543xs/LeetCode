#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 1)
        return numsSize;
    int ans = 1;
    for (int i = 1; i < numsSize; i++) {
        // duplicate
        if (nums[i] == nums[ans - 1])
            continue;
        // non-duplicate
        else {
            // modify only when different position
            if (ans != i)
                nums[ans] = nums[i];
            ans++;
        }
    }
    return ans;
}

int main() {
    int nums[] = {0, 0, 1, 2, 2, 5, 7, 7, 9};
    int ans = removeDuplicates((int *)&nums, 9);
    printf("ans: %d\n", ans);
    for (int i = 0; i < ans; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
