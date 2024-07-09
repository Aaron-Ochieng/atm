#include <stdio.h>

// Function to read a string from standard input
void read_string(char *buffer, size_t size) {
  int c;
  // Clear any remaining newline characters from input buffer
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  fgets(buffer, size, stdin); // Read the entire line, including spaces
}
