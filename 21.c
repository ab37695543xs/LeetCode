#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    // one is empty
    if (!l1) return l2;
    if (!l2) return l1;
    struct ListNode *head = NULL, *curr = NULL, *temp;
    // choose which to concat
    while (l1 && l2) {
        if (l1->val < l2->val) {
            temp = l1;
            l1 = l1->next;
        }
        else {
            temp = l2;
            l2 = l2->next;
        }
        if (!head) {
            head = temp;
            curr = temp;
        }
        else {
            curr->next = temp;
            curr = curr->next;
        }
    }
    // concat the remaining
    if (l1) {
        curr->next = l1;
    }
    else if (l2)
        curr->next = l2;
    return head;
}


int main() {
    int arr1[] = {5};
    int arr2[] = {1, 2, 4};
    struct ListNode *l1, *l2, *prev, *curr;
    for (int i = 0; i < 1; i++) {
        curr = calloc(1, sizeof(struct ListNode));
        curr->val = arr1[i];
        curr->next = NULL;
        if (i == 0)
            prev = l1 = curr;
        else
            prev = prev->next = curr;
    }
    for (int i = 0; i < 3; i++) {
        curr = calloc(1, sizeof(struct ListNode));
        curr->val = arr2[i];
        curr->next = NULL;
        if (i == 0)
            prev = l2 = curr;
        else
            prev = prev->next = curr;
    }
    printf("l1: ");
    curr = l1;
    while (curr) {
        printf("%d ", curr->val);
        prev = curr;
        curr = curr->next;
    }
    printf("\nl2: ");
    curr = l2;
    while (curr) {
        printf("%d ", curr->val);
        prev = curr;
        curr = curr->next;
    }
    printf("\n");

    struct ListNode *ans = mergeTwoLists(l1, l2);

    printf("ans: ");
    curr = ans;
    while (curr) {
        printf("%d ", curr->val);
        prev = curr;
        curr = curr->next;
        if (prev)
            free(prev);
    }
    printf("\n");
    return 0;
}
