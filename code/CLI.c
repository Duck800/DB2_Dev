#include <stdio.h>
#include <string.h>
#include <sqlcli1.h>
#include <stdbool.h>

static bool checkEmployeeExists(SQLHANDLE conHandle, SQLCHAR* EmpNo) {
    SQLHANDLE stmtHandle;
    SQLRETURN retCode = SQL_SUCCESS;
    bool exists = false;

    // Allocate an SQL Statement Handle
    SQLAllocHandle(SQL_HANDLE_STMT, conHandle, &stmtHandle);

    // Define a SELECT SQL Statement
    SQLCHAR SQLStmt[255];
    sprintf((char*)SQLStmt, "SELECT COUNT(*) FROM THEORY.EMPLOYEE WHERE EMPNO = '%s'", EmpNo);

    // Execute the SQL Statement
    retCode = SQLExecDirect(stmtHandle, SQLStmt, SQL_NTS);

    if (retCode == SQL_SUCCESS) {
        SQLINTEGER count;
        SQLLEN indicator;

        // Fetch the result
        retCode = SQLFetch(stmtHandle);
        if (retCode == SQL_SUCCESS) {
            retCode = SQLGetData(stmtHandle, 1, SQL_C_SLONG, &count, sizeof(count), &indicator);
            if (retCode == SQL_SUCCESS && count > 0) {
                exists = true;
            }
        }
    }
    else {
        SQLCHAR     SqlState[6];
        SQLINTEGER  NativeError;
        SQLCHAR     MessageText[SQL_MAX_MESSAGE_LENGTH];
        SQLSMALLINT TextLength;

        SQLGetDiagRec(SQL_HANDLE_STMT, stmtHandle, 1, SqlState, &NativeError, MessageText, sizeof(MessageText), &TextLength);
        printf("Failed to check employee existence. SQL Error: %s, Native Error: %d\n", MessageText, NativeError);
    }

    // Free the SQL Statement Handle
    SQLFreeHandle(SQL_HANDLE_STMT, stmtHandle);

    return exists;
}

// Helper function to check if a string is numeric
bool isNumeric(const SQLCHAR* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void insertEmployee(SQLHANDLE conHandle) {
    SQLCHAR EmpNo[10];
    SQLCHAR LastName[25];
    SQLRETURN  retCode = SQL_SUCCESS;

    printf("Enter employee number: ");
    scanf("%s", EmpNo);

    // Check if employee number is numeric
    if (!isNumeric(EmpNo)) {
        printf("Employee number must be a numeric value. Insert failed.\n");
        return;
    }

    // Check if employee number already exists
    if (checkEmployeeExists(conHandle, EmpNo)) {
        printf("Employee with number %s already exists. Insert failed.\n", EmpNo);
        return;
    }

    printf("Enter employee last name: ");
    scanf("%s", LastName);

    // Allocate an SQL Statement Handle
    SQLHANDLE stmtHandle;
    SQLAllocHandle(SQL_HANDLE_STMT, conHandle, &stmtHandle);

    // Define an INSERT SQL Statement
    SQLCHAR SQLStmt[255];
    sprintf((char*)SQLStmt, "INSERT INTO THEORY.EMPLOYEE (EMPNO, LASTNAME) VALUES ('%s', '%s')", EmpNo, LastName);

    // Execute the SQL Statement
    retCode = SQLExecDirect(stmtHandle, SQLStmt, SQL_NTS);

    if (retCode == SQL_SUCCESS) {
        // Commit The Transaction
        retCode = SQLEndTran(SQL_HANDLE_DBC, conHandle, SQL_COMMIT);

        printf("Employee inserted successfully.\n");
    }
    else {
        SQLCHAR     SqlState[6];
        SQLINTEGER  NativeError;
        SQLCHAR     MessageText[SQL_MAX_MESSAGE_LENGTH];
        SQLSMALLINT TextLength;

        SQLGetDiagRec(SQL_HANDLE_STMT, stmtHandle, 1, SqlState, &NativeError, MessageText, sizeof(MessageText), &TextLength);
        printf("Failed to insert employee. SQL Error: %s, Native Error: %d\n", MessageText, NativeError);
    }

    // Free the SQL Statement Handle
    SQLFreeHandle(SQL_HANDLE_STMT, stmtHandle);
}

void deleteEmployee(SQLHANDLE conHandle) {
    SQLCHAR EmpNo[10];
    SQLRETURN  retCode = SQL_SUCCESS;
    printf("Enter employee number to delete: ");
    scanf("%s", EmpNo);

    // Allocate an SQL Statement Handle
    SQLHANDLE stmtHandle;
    SQLAllocHandle(SQL_HANDLE_STMT, conHandle, &stmtHandle);

    // Define a DELETE SQL Statement
    SQLCHAR SQLStmt[255];
    sprintf((char*)SQLStmt, "DELETE FROM THEORY.EMPLOYEE WHERE EMPNO = '%s'", EmpNo);

    // Execute the SQL Statement
    SQLExecDirect(stmtHandle, SQLStmt, SQL_NTS);

 // Commit The Transaction
    retCode = SQLEndTran(SQL_HANDLE_DBC, conHandle,  SQL_COMMIT);
    printf("Employee deleted successfully.\n");

    // Free the SQL Statement Handle
    SQLFreeHandle(SQL_HANDLE_STMT, stmtHandle);
}

void updateEmployee(SQLHANDLE conHandle) {
    SQLCHAR EmpNo[10];
    SQLCHAR LastName[25];
    SQLRETURN  retCode = SQL_SUCCESS;
    printf("Enter employee number to update: ");
    scanf("%s", EmpNo);

    printf("Enter new last name: ");
    scanf("%s", LastName);

    // Allocate an SQL Statement Handle
    SQLHANDLE stmtHandle;
    SQLAllocHandle(SQL_HANDLE_STMT, conHandle, &stmtHandle);

    // Define an UPDATE SQL Statement
    SQLCHAR SQLStmt[255];
    sprintf((char*)SQLStmt, "UPDATE THEORY.EMPLOYEE SET LASTNAME = '%s' WHERE EMPNO = '%s'", LastName, EmpNo);

    // Execute the SQL Statement
    SQLExecDirect(stmtHandle, SQLStmt, SQL_NTS);

    // Commit The Transaction
    retCode = SQLEndTran(SQL_HANDLE_DBC, conHandle, SQL_COMMIT);

    printf("Employee updated successfully.\n");

    // Free the SQL Statement Handle
    SQLFreeHandle(SQL_HANDLE_STMT, stmtHandle);
}

void searchAllEmployees(SQLHANDLE conHandle, SQLHANDLE* stmtHandle) {
    // Allocate a new statement handle
    SQLAllocHandle(SQL_HANDLE_STMT, conHandle, stmtHandle);

    SQLCHAR SQLStmt[255] = "SELECT EMPNO, LASTNAME FROM THEORY.EMPLOYEE";
    SQLExecDirect(*stmtHandle, SQLStmt, SQL_NTS);

    printf("+----------+-------------------------+\n");
    printf("| EmpNo    | Last Name               |\n");
    printf("+----------+-------------------------+\n");

    SQLCHAR EmpNo[10];
    SQLCHAR LastName[25];
    SQLBindCol(*stmtHandle, 1, SQL_C_CHAR, (SQLPOINTER)EmpNo, sizeof(EmpNo), NULL);
    SQLBindCol(*stmtHandle, 2, SQL_C_CHAR, (SQLPOINTER)LastName, sizeof(LastName), NULL);

    while (SQLFetch(*stmtHandle) == SQL_SUCCESS) {
        printf("| %-8s | %-23s |\n", EmpNo, LastName);
    }

    printf("+----------+-------------------------+\n");

    // Free the statement handle
    SQLFreeHandle(SQL_HANDLE_STMT, *stmtHandle);
}

void searchByLastName(SQLHANDLE conHandle, SQLHANDLE* stmtHandle) {
    // Allocate a new statement handle
    SQLAllocHandle(SQL_HANDLE_STMT, conHandle, stmtHandle);

    SQLCHAR EmpNo[10];
    SQLCHAR LastName[25] = "";
    printf("Enter employee last name: ");
    if (scanf("%24s", LastName) != 1) {
        printf("Error reading input. Please try again.\n");
        // Free the statement handle
        SQLFreeHandle(SQL_HANDLE_STMT, *stmtHandle);
        return;
    }

    SQLCHAR SQLStmt[255];
    snprintf(SQLStmt, sizeof(SQLStmt), "SELECT EMPNO, LASTNAME FROM THEORY.EMPLOYEE WHERE LASTNAME LIKE ?");

    SQLBindParameter(*stmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 0, 0, LastName, 0, NULL);
    SQLExecDirect(*stmtHandle, SQLStmt, SQL_NTS);

    printf("+----------+-------------------------+\n");
    printf("| EmpNo    | Last Name               |\n");
    printf("+----------+-------------------------+\n");

    SQLBindCol(*stmtHandle, 1, SQL_C_CHAR, (SQLPOINTER)EmpNo, sizeof(EmpNo), NULL);
    SQLBindCol(*stmtHandle, 2, SQL_C_CHAR, (SQLPOINTER)LastName, sizeof(LastName), NULL);

    while (SQLFetch(*stmtHandle) == SQL_SUCCESS) {
        printf("| %-8s | %-23s |\n", EmpNo, LastName);
    }

    printf("+----------+-------------------------+\n");

    // Free the statement handle
    SQLFreeHandle(SQL_HANDLE_STMT, *stmtHandle);
}

void searchEmployee(SQLHANDLE conHandle) {
    SQLHANDLE stmtHandle;
    int choice;
    do {
        printf("\n--- Search Employee Menu ---\n");
        printf("1. Search all employees\n");
        printf("2. Search by last name\n");
        printf("0. Back to main menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please try again.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            // Search all employees
            searchAllEmployees(conHandle, &stmtHandle);
            break;
        case 2:
            // Search by last name
            searchByLastName(conHandle, &stmtHandle);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int main() {
    SQLHANDLE envHandle = 0;
    SQLHANDLE conHandle = 0;
    SQLRETURN retCode = SQL_SUCCESS;

    // Allocate an environment handle
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &envHandle);

    // Set the ODBC application version to 3.8
    if (envHandle != 0)
        SQLSetEnvAttr(envHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3_80, SQL_IS_UINTEGER);

    // Allocate a connection handle
    if (envHandle != 0)
        SQLAllocHandle(SQL_HANDLE_DBC, envHandle, &conHandle);

    // Connect to the appropriate data source
    if (conHandle != 0)
        retCode = SQLConnect(conHandle, (SQLCHAR*)"SAMP1", SQL_NTS, (SQLCHAR*)"pc", SQL_NTS, (SQLCHAR*)"030929", SQL_NTS);

    if (conHandle == 0 || retCode != SQL_SUCCESS) {
        printf("Failed to connect to the database.\n");
        return 1;
    }

    SQLSetConnectAttr(conHandle, SQL_ATTR_AUTOCOMMIT, SQL_AUTOCOMMIT_OFF, 0);

    // Main menu loop
    int choice = -1;
    while (choice != 0) {
        printf("\n\n\n--- Employee Database ---\n");
        printf("1. Insert Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Update Employee\n");
        printf("4. Search Employees\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertEmployee(conHandle);
            break;
        case 2:
            deleteEmployee(conHandle);
            break;
        case 3:
            updateEmployee(conHandle);
            break;
        case 4:
            searchEmployee(conHandle);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    // Terminate the data source connection
    if (conHandle != 0)
        retCode = SQLDisconnect(conHandle);

    // Free the connection handle
    if (conHandle != 0)
        SQLFreeHandle(SQL_HANDLE_DBC, conHandle);

    // Free the environment handle
    if (envHandle != 0)
        SQLFreeHandle(SQL_HANDLE_ENV, envHandle);

    return 0;
}