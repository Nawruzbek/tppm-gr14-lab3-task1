#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    rc = sqlite3_open("students.db", &db);
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    sql = "CREATE TABLE marks("
          "MarkId INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
          "Student_id INTEGER NOT NULL,"
          "Subject_id INTEGER NOT NULL,"
          "Date TEXT NOT NULL,"
          "Mark INTEGER NOT NULL);";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
    sqlite3_close(db);
    return 0;
}
