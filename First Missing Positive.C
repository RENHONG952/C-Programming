#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;
    while (i < numsSize) {
        if (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            swap(&nums[i], &nums[nums[i] - 1]);
        } else {
            i++;
        }
    }
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    return numsSize + 1;
}

int main() {
    int nums[] = {3,4,-1,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = firstMissingPositive(nums, numsSize);
    printf("%d", result);
    return 0;
}