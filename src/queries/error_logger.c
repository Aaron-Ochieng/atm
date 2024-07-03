#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <stdio.h>
#include <time.h>

void log_error(const char *error) {
  // Open a file in append mode
  FILE *file = fopen("./logs/errors.log", "a");

  // check if the file is not null | can be opened
  if (file == NULL) {
    printf("Error opening log file");
    fclose(file); // close the file stream
    exit(0);      // exit status code
  }

  time_t now; /* Initialize time */
  fprintf(file, "%s Error: %s \n", ctime(&now), error);
  fclose(file); /* close file stream */
}
