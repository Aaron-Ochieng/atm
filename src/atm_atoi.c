#include "string.h"

int atm_atoi(char *input) {
  int val;
  int len = strlen(input);
  for (int i = 0; i < len; i++) {
    if (input[i] >= '1' && input[i] <= '9') {
      val = val * 10 + input[i] - '0';
    } else {
      return -1;
    }
  }
  return val;
}
