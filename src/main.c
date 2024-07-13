#include "header.h"
#include "queries/queries.h"

void mainMenu(struct User u) {
  int option;
  system("clear");
  printf("\n\n\t\t======= ATM =======\n\n");
  printf("\n\t\t-->> Feel free to choose one of the options below <<--\n");
  printf("\n\t\t[1]- Create a new account\n");
  printf("\n\t\t[2]- Update account information\n");
  printf("\n\t\t[3]- Check accounts\n");
  printf("\n\t\t[4]- Check list of owned account\n");
  printf("\n\t\t[5]- Make Transaction\n");
  printf("\n\t\t[6]- Remove existing account\n");
  printf("\n\t\t[7]- Transfer ownership\n");
  printf("\n\t\t[8]- Exit\n");
  scanf("%d", &option);

  switch (option) {
  case 1:
    createNewAcc(u);
    break;
  case 2:
    // student TODO : add your **Update account information** function
    // here
    updateAccountInfo(u);
    break;
  case 3:
    // student TODO : add your **Check the details of existing accounts**
    // function here
    checkAccount(u);
    break;
  case 4:
    checkAllAccounts(u);
    break;
  case 5:
    // student TODO : add your **Make transaction** function
    // here
    makeTransaction(u);
    break;
  case 6:
    // student TODO : add your **Remove existing account** function
    // here
    deleteAccount(u);
    break;
  case 7:
    // student TODO : add your **Transfer owner** function
    // here
    break;
  case 8:
    exit(1);
    break;
  default:
    printf("Invalid operation!\n");
  }
};

void initMenu(struct User *u) {
  int r = 0;
  int option;
  char option_string[1];

  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\t-->> Feel free to login / register :\n");
  printf("\n\t\t[1]- login\n");
  printf("\n\t\t[2]- register\n");
  printf("\n\t\t[3]- exit\n");
  while (!r) {
    scanf("%s", option_string);
    option = atoi(option_string);
    switch (option) {
    case 1:
      loginMenu(u->name, u->password);
      if (strcmp(u->password, getPassword(*u)) != 0) {
        printf("\nWrong password!! or User Name\n");
        exit(1);
      }
      int user_id = get_user_id(u->name);
      u->id = user_id;
      r = 1;
      break;
    case 2:
      // student TODO : add your **Registration** function
      // here
      registerMenu(u->name, u->password);
      r = 1;
      break;
    case 3:
      exit(1);
      break;
    default:
      printf("Insert a valid operation!\n");
    }
  }
};

int main() {
  struct User u;

  initialize_all_databases();
  initMenu(&u);
  mainMenu(u);
  return 0;
}
