#include <stdbool.h>
#include <stdio.h>

bool isMatch(char *s, char *p) {
  int i = 0, j = 0;
  int matchidx = 0, startidx = -1;
  while (s[i] != '\0') {
    if (p[j] != '\0' && (p[j] == '?' || p[j] == s[i])) {
      i++;
      j++;
    } else if (p[j] != '\0' && p[j] == '*') {
      startidx = j;
      matchidx = i;
      j++;
    } else if (startidx != -1) {
      j = startidx + 1;
      matchidx++;
      i = matchidx;
    } else {
      return 0;
    }
  }

  while (p[j] == '*') {
    j++;
  }

  return (p[j] == '\0');
}

int main() {
  char *s = "aa";
  char *p = "*";
  printf("%s\n", isMatch(s, p) ? "true" : "false");
  return 0;
}