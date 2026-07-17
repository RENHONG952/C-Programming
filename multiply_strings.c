#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *num) {
  int left = 0;
  int right = strlen(num) - 1;
  while (left < right) {
    char temp = num[left];
    num[left] = num[right];
    num[right] = temp;
    left++;
    right--;
  }
}

char *multiply(char *num1, char *num2) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);

  if (len1 == 0 || len2 == 0 || strcmp(num1, "0") == 0 ||
      strcmp(num2, "0") == 0) {
    char *ans = (char *)malloc(2 * sizeof(char));
    if (ans == NULL) {
      return NULL;
    }
    ans[0] = '0';
    ans[1] = '\0';
    return ans;
  }

  char *n1 = strdup(num1);
  char *n2 = strdup(num2);
  reverse(n1);
  reverse(n2);
  int len = len1 + len2;
  char *ans = (char *)malloc((len + 1) * sizeof(char));
  if (ans == NULL) {
    free(n1);
    free(n2);
    return NULL;
  }

  int *result = (int *)calloc(len, sizeof(int));
  if (result == NULL) {
    free(n1);
    free(n2);
    free(ans);
    return NULL;
  }

  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      int num1_int = n1[i] - '0';
      int num2_int = n2[j] - '0';
      result[i + j] += num1_int * num2_int;
    }
  }

  for (int j = 0; j < len - 1; j++) {
    result[j + 1] += result[j] / 10;
    result[j] %= 10;
  }

  int i = len - 1;
  while (i > 0 && result[i] == 0) {
    i--;
  }

  int pos = 0;
  while (i >= 0) {
    ans[pos++] = result[i--] + '0';
  }
  ans[pos] = '\0';

  free(n1);
  free(n2);
  free(result);
  return ans;
}

int main() {
  char num1[] = "123";
  char num2[] = "456";
  char *ans = multiply(num1, num2);
  printf("%s\n", ans);
  free(ans);
  return 0;
}