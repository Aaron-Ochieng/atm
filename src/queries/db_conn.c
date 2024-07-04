#include "queries.h"
#include "stdio.h"

sqlite3 *db = NULL; /*Initialized database pointer */

int initialize_db_conn() {
  int rc = sqlite3_open("atm.db", &db);
  if (rc != SQLITE_OK) {
    log_error(sqlite3_errmsg(db));
    return SQLITE_ERROR;
  }
  return rc;
}

