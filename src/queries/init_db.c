#include "sqlite3.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

int callback(void *str, int argc, char **argv, char **azColName) {
  char **result = (char **)str;

  if (argv[0]) {
    *result = strdup(argv[0]);
  }
  return 0;
}


