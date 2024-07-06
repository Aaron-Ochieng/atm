
int atm_atoi(const char *input) {
  int val = 0;
  int i = 0;
  while (input[i] != '\0') {
    if (input[i] >= '0' && input[i] <= '9') {
      val = val * 10 + (input[i] - '0');
    } else {
      return -1;
    }
    i++;
  }
  return val;
}
