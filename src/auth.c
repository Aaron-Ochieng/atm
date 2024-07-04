#include "header.h"
#include "queries/queries.h"
#include <stdio.h>
#include <termios.h>

void loginMenu(char a[50], char pass[50]) {
  struct termios oflags, nflags;

  system("clear");
  printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login:");
  scanf("%s", a);

  // disabling echo
  tcgetattr(fileno(stdin), &oflags);
  nflags = oflags;
  nflags.c_lflag &= ~ECHO;
  nflags.c_lflag |= ECHONL;

  if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0) {
    perror("tcsetattr");
    return exit(1);
  }
  printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
  scanf("%s", pass);

  // restore terminal
  if (tcsetattr(fileno(stdin), TCSANOW, &oflags) != 0) {
    perror("tcsetattr");
    return exit(1);
  }
};

const char *getPassword(struct User u) {
  char *password = get_user_pass(u.name);
  return password;
}
void registerMenu(char *a, char *pass) {
  printf("\n\t\tEnter name:\t");
  scanf("%s", a);
  printf("\n\n\t\tEnter password:\t");
  scanf("%s", pass);

  int rc = insert_user(a, pass);
  if (rc == SQLITE_CONSTRAINT) {
    printf("\n\t\tUser already exist");
    exit(0);
  }
}
