#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("students.db", &db);
    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Opened database successfully\n");
    }
    sqlite3_close(db);
    return 0;
}
