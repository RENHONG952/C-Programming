#include <stdio.h>

int trap(int *height, int heightSize) {
  int left = 0;
  int right = heightSize - 1;
  int left_max = height[left];
  int right_max = height[right];
  int total = 0;

  while (left < right) {
    if (left_max < right_max) {
      left++;
      left_max = left_max > height[left] ? left_max : height[left];
      total += left_max - height[left];
    } else {
      right--;
      right_max = right_max > height[right] ? right_max : height[right];
      total += right_max - height[right];
    }
  }

  return total;
}

int main() {
  int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int heightSize = sizeof(height) / sizeof(height[0]);
  int result = trap(height, heightSize);
  printf("%d\n", result);
  return 0;
}