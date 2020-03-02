#include <stdio.h>
#include <stdlib.h>

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int removeElement(int *nums, int numsSize, int val) {
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0] == val ? 0 : 1;
    // push the invalid to the end of array
    // p1: invalid, p2: valid
    int *p1 = &nums[0], *p2 = &nums[numsSize - 1];
    while (p1 <= p2) {
        if (*p1 == val && *p2 != val) {
            swap(p1, p2);
            p1++;
            p2--;
        }
        // find the invalid
        else if (*p1 != val)
            p1++;
        // find the valid
        else if (*p2 == val)
            p2--;
    }
    return p1 - nums;
}

int main() {
    int nums[] = {3, 3};
    int ans = removeElement((int *)&nums, 2, 3);
    printf("ans: %d\n", ans);
    for (int i = 0; i < ans; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
