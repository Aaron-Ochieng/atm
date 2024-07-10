#include "queries.h"

double check_amount(int account_number, int user_id) {
  /*Initialize amount*/
  double amount = -1;

  sqlite3_stmt *stmt;

  /*sql query*/
  char *sql = "SELECT amount FROM Records WHERE accountNbr = ? AND userID = ?";

  int rc = initialize_db_conn();
  if (rc != SQLITE_OK) {
    log_error(sqlite3_errmsg(db));
    close_db_con();
    return -1;
  }

  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
  if (rc != SQLITE_OK) {
    log_error(sqlite3_errmsg(db));
    close_db_con();
    return -1;
  }

  //
  sqlite3_bind_int(stmt, 1, account_number);
  sqlite3_bind_int(stmt, 2, user_id);
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    amount = sqlite3_column_double(stmt, 0);
  }

  if (rc != SQLITE_DONE) {
    log_error(sqlite3_errmsg(db));
    close_db_con();
    return -1;
  }
  sqlite3_finalize(stmt);
  sqlite3_close(db);
  return amount;
}
