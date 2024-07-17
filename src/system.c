#include "header.h"
#include "queries/sqlite3.h"
#include "stdbool.h"
#include <stdio.h>

void stayOrReturn(int notGood, void f(struct User u), struct User u) {
  int option;
  if (notGood == 0) {
    system("clear");
    printf("\n✖ Record not found!!\n");
  invalid:
    printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit:");
    scanf("%d", &option);
    if (option == 0)
      f(u);
    else if (option == 1)
      mainMenu(u);
    else if (option == 2)
      exit(0);
    else {
      printf("Insert a valid operation!\n");
      goto invalid;
    }
  } else {
    printf("\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &option);
  }
  if (option == 1) {
    system("clear");
    mainMenu(u);
  } else {
    system("clear");
    exit(1);
  }
}

void success(struct User u) {
  int option;
  printf("\n✔ Success!\n\n");
invalid:
  printf("Enter 1 to go to the main menu and 0 to exit!\n");
  scanf("%d", &option);
  system("clear");
  if (option == 1) {
    mainMenu(u);
  } else if (option == 0) {
    exit(1);
  } else {
    printf("Insert a valid operation!\n");
    goto invalid;
  }
}

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
  success(u);
}
