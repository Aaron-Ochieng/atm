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

int initialize_records_database(sqlite3 *db) {
  char *err_msg; /* To store any error messages that may occur when execting sql
                    query */

  /* sql query itself which creates the Records table in the sqlite database */
  char *sql = "CREATE TABLE IF NOT EXISTS Records ("
              "userId INTEGER NOT NULL,"
              "country TEXT NOT NULL,"
              "phone INTEGER NOT NULL,"
              "accountType TEXT NOT NULL,"
              "accountNbr INTEGER PRIMARY KEY NOT NULL,"
              "amount REAL NOT NULL,"
              "depositMonth INTEGER NOT NULL,"
              "depositDay INTEGER NOT NULL,"
              "depositYear INTEGER NOT NULL,"
              "withdrawMonth INTEGER,"
              "withdrawDay INTEGER,"
              "withdrawYear INTEGER,"
              "FOREIGN KEY (userId) REFERENCES Users(id)"
              ");";

  int rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

  /* checks if the above function returns an error */
  if (rc != SQLITE_OK) {
    printf("records error: %s", err_msg);

    /* closes the database connection if there was an error */
    sqlite3_close(db);
    return SQLITE_ERROR;
  }
  /* Return status if the whole function executes without errors*/
  return SQLITE_OK;
}
int initialize_users_database(sqlite3 *db) {
  char *err_msg;
  char *sql =
      "CREATE TABLE IF NOT EXISTS Users (id INTEGER PRIMARY KEY AUTOINCREMENT "
      "NOT NULL,name VARCHAR(50) NOT NULL UNIQUE,password VARCHAR(50) NOT "
      "NULL);";
  int rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

  if (rc != SQLITE_OK) {
    printf("sqlite error: %s", err_msg);
    sqlite3_close(db);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

