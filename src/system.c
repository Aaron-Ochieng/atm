#include "header.h"
#include "queries/sqlite3.h"
#include "stdbool.h"
#include <stdio.h>

bool valid_date(int month, int day, int year) {
  if (month < 1 || month > 12) {
    return false;
  }
  if (day < 1 || day > 30) {
    return false;
  }

  if (year < 1900 || year > 2100) {
    return false;
  }
  return true;
}

void createNewAcc(struct User u) {
  struct Record r;
  struct Record cr;
  char userName[50];

noAccount:
  system("clear");
  printf("\t\t\t===== New record =====\n");

  printf("\nEnter today's date(mm/dd/yyyy):");
  scanf("%d/%d/%d", &r.deposit.month, &r.deposit.day, &r.deposit.year);
  if (!valid_date(r.deposit.month, r.deposit.day, r.deposit.year)) {
    goto noAccount;
  }
  printf("\nEnter the account number:");
  scanf("%d", &r.accountNbr);
  printf("\nEnter the country:");
  read_string(r.country, sizeof(r.country));

  printf("\nEnter the phone number:");
  scanf("%d", &r.phone);
  printf("\nEnter amount to deposit: $");
  scanf("%lf", &r.amount);
  printf("\nChoose the type of account:\n\t-> saving\n\t-> current\n\t-> "
         "fixed01(for 1 year)\n\t-> fixed02(for 2 years)\n\t-> fixed03(for 3 "
         "years)\n\n\tEnter your choice:");

  read_string(r.accountType, sizeof(r.accountType));
  if (strcmp(r.accountType, "fixed01") != 0 &&
      strcmp(r.accountType, "fixed02") != 0 &&
      strcmp(r.accountType, "fixed03") != 0 &&
      strcmp(r.accountType, "saving") != 0 &&
      strcmp(r.accountType, "current") != 0) {
    printf("Invalid account type!.\n");
    choose_exit_or_menu(u);
  }

  int result = new_record(r, u.name);
  if (result == SQLITE_CONSTRAINT) {
    printf("✖ This Account already exists for this user\n\n");
    goto noAccount;
  }
  printf("\n✔ Success!\n\n");
  choose_exit_or_menu(u);
}
