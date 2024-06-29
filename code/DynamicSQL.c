static char sqla_program_id[292] = 
{
 '\xac','\x0','\x41','\x45','\x41','\x56','\x41','\x49','\x35','\x41','\x38','\x74','\x55','\x61','\x47','\x6f','\x30','\x31','\x31','\x31',
 '\x31','\x20','\x32','\x20','\x20','\x20','\x20','\x20','\x20','\x20','\x20','\x20','\x8','\x0','\x50','\x43','\x20','\x20','\x20','\x20',
 '\x20','\x20','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x8','\x0','\x44','\x59','\x4e','\x41','\x4d','\x49','\x43','\x53','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0',
 '\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0','\x0'
};

#include "sqladef.h"

static struct sqla_runtime_info sqla_rtinfo = 
{{'S','Q','L','A','R','T','I','N'}, sizeof(wchar_t), 0, {' ',' ',' ',' '}};


static const short sqlIsLiteral   = SQL_IS_LITERAL;
static const short sqlIsInputHvar = SQL_IS_INPUT_HVAR;


#line 1 "DynamicSQL.sqc"
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <sqlca.h>
#include <sql.h>
#include <sqlenv.h>
#include <sqlda.h>

void printMenu() {
    printf("1. 查询\n");
    printf("2. 增加\n");
    printf("3. 修改\n");
    printf("4. 删除\n");
    printf("5. EXIT\n");
    printf("请输入操作序号：");
}

void executeQuery() {
    // Include the SQLCA data structure variable
    
/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 20 "DynamicSQL.sqc"

    // Define the SQL host variables needed
    
/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 22 "DynamicSQL.sqc"

        char     EmployeeNo[7];
        char     LastName[16];
        double   Salary;
        short    SalaryNI;
        char     JobType[10];
    
/*
EXEC SQL END DECLARE SECTION;
*/

#line 28 "DynamicSQL.sqc"


    // Connect to the appropriate database
    
/*
EXEC SQL CONNECT TO SAMPLE USER 'PC' USING '030929';
*/

{
#line 31 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 31 "DynamicSQL.sqc"
  sqlaaloc(2,3,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 31 "DynamicSQL.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 7;
#line 31 "DynamicSQL.sqc"
      sql_setdlist[0].sqldata = (void*)"SAMPLE";
#line 31 "DynamicSQL.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 31 "DynamicSQL.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 3;
#line 31 "DynamicSQL.sqc"
      sql_setdlist[1].sqldata = (void*)"PC";
#line 31 "DynamicSQL.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 31 "DynamicSQL.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 7;
#line 31 "DynamicSQL.sqc"
      sql_setdlist[2].sqldata = (void*)"030929";
#line 31 "DynamicSQL.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 31 "DynamicSQL.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 31 "DynamicSQL.sqc"
  sqlacall((unsigned short)29,5,2,0,0L);
#line 31 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 31 "DynamicSQL.sqc"


    // Prompt for job type
    printf("请输入职位类型：");
    scanf("%s", JobType);

    // Define a dynamic SELECT SQL statement
    char SQLStmt[80] = "SELECT EMPNO, LASTNAME, DOUBLE(SALARY) FROM THEORY.EMPLOYEE WHERE JOB = ? ";

    // Prepare the SQL statement
    
/*
EXEC SQL PREPARE SQL_STMT FROM :SQLStmt;
*/

{
#line 41 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 41 "DynamicSQL.sqc"
  sqlastls(0,SQLStmt,0L);
#line 41 "DynamicSQL.sqc"
  sqlacall((unsigned short)27,1,0,0,0L);
#line 41 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 41 "DynamicSQL.sqc"

   
    
/*
EXEC SQL DECLARE C1 CURSOR FOR SQL_STMT;
*/

#line 43 "DynamicSQL.sqc"

   
    
/*
EXEC SQL OPEN C1 USING :JobType;
*/

{
#line 45 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 45 "DynamicSQL.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 45 "DynamicSQL.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 45 "DynamicSQL.sqc"
      sql_setdlist[0].sqldata = (void*)JobType;
#line 45 "DynamicSQL.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 45 "DynamicSQL.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 45 "DynamicSQL.sqc"
  sqlacall((unsigned short)26,1,2,0,0L);
#line 45 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 45 "DynamicSQL.sqc"


    // If the cursor was opened successfully, retrieve and display all records available
    while (1) {
        // Retrieve the current record from the cursor
        
/*
EXEC SQL FETCH C1 INTO :EmployeeNo, :LastName, :Salary :SalaryNI;
*/

{
#line 50 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 50 "DynamicSQL.sqc"
  sqlaaloc(3,3,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 50 "DynamicSQL.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 7;
#line 50 "DynamicSQL.sqc"
      sql_setdlist[0].sqldata = (void*)EmployeeNo;
#line 50 "DynamicSQL.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 50 "DynamicSQL.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 16;
#line 50 "DynamicSQL.sqc"
      sql_setdlist[1].sqldata = (void*)LastName;
#line 50 "DynamicSQL.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 50 "DynamicSQL.sqc"
      sql_setdlist[2].sqltype = 481; sql_setdlist[2].sqllen = 8;
#line 50 "DynamicSQL.sqc"
      sql_setdlist[2].sqldata = (void*)&Salary;
#line 50 "DynamicSQL.sqc"
      sql_setdlist[2].sqlind = &SalaryNI;
#line 50 "DynamicSQL.sqc"
      sqlasetdata(3,0,3,sql_setdlist,0L,0L);
    }
#line 50 "DynamicSQL.sqc"
  sqlacall((unsigned short)25,1,0,3,0L);
#line 50 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 50 "DynamicSQL.sqc"


        // Display the record retrieved
        if (sqlca.sqlcode == SQL_RC_OK) {
            printf("%-8s %-16s ", EmployeeNo, LastName);
            if (SalaryNI == 0)
                printf("%lf\n", Salary);
            else
                printf("Unknown\n");
        }
        else {
            break;
        }
    }

    // Close the cursor
    
/*
EXEC SQL CLOSE C1;
*/

{
#line 66 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 66 "DynamicSQL.sqc"
  sqlacall((unsigned short)20,1,0,0,0L);
#line 66 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 66 "DynamicSQL.sqc"


    // Commit the transaction
    
/*
EXEC SQL COMMIT;
*/

{
#line 69 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 69 "DynamicSQL.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 69 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 69 "DynamicSQL.sqc"


    // Terminate the database connection
    
/*
EXEC SQL DISCONNECT CURRENT;
*/

{
#line 72 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 72 "DynamicSQL.sqc"
  sqlacall((unsigned short)40,24,0,0,0L);
#line 72 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 72 "DynamicSQL.sqc"

}

void executeInsert() {
    // Include the SQLCA data structure variable
    
/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 77 "DynamicSQL.sqc"

    // Define the SQL host variables needed
    
/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 79 "DynamicSQL.sqc"

        char     EmployeeNo[7];
        char     LastName[16];
        double Salary;
        char     JobType[10]; 
    
/*
EXEC SQL END DECLARE SECTION;
*/

#line 84 "DynamicSQL.sqc"


    // Connect to the appropriate database
    
/*
EXEC SQL CONNECT TO SAMPLE USER 'PC' USING '030929';
*/

{
#line 87 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 87 "DynamicSQL.sqc"
  sqlaaloc(2,3,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 87 "DynamicSQL.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 7;
#line 87 "DynamicSQL.sqc"
      sql_setdlist[0].sqldata = (void*)"SAMPLE";
#line 87 "DynamicSQL.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 87 "DynamicSQL.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 3;
#line 87 "DynamicSQL.sqc"
      sql_setdlist[1].sqldata = (void*)"PC";
#line 87 "DynamicSQL.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 87 "DynamicSQL.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 7;
#line 87 "DynamicSQL.sqc"
      sql_setdlist[2].sqldata = (void*)"030929";
#line 87 "DynamicSQL.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 87 "DynamicSQL.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 87 "DynamicSQL.sqc"
  sqlacall((unsigned short)29,5,2,0,0L);
#line 87 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 87 "DynamicSQL.sqc"


    // Prompt for employee details
    printf("请输入员工编号：");
    scanf("%s", EmployeeNo);
    printf("请输入员工姓氏：");
    scanf("%s", LastName);
    printf("请输入职位类型：");
    scanf("%s", JobType);
    printf("请输入员工薪水：");
    scanf("%lf", &Salary);

    // Define a dynamic INSERT SQL statement
    char SQLStmt[80] = "INSERT INTO THEORY.EMPLOYEE (EMPNO, LASTNAME, JOB, SALARY) VALUES (?, ?, ?, ?)";

    // Prepare the SQL statement
    
/*
EXEC SQL PREPARE SQL_STMT FROM :SQLStmt;
*/

{
#line 103 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 103 "DynamicSQL.sqc"
  sqlastls(0,SQLStmt,0L);
#line 103 "DynamicSQL.sqc"
  sqlacall((unsigned short)27,1,0,0,0L);
#line 103 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 103 "DynamicSQL.sqc"


    // Execute the SQL statement
    
/*
EXEC SQL EXECUTE SQL_STMT USING :EmployeeNo, :LastName, :JobType, :Salary;
*/

{
#line 106 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 106 "DynamicSQL.sqc"
  sqlaaloc(2,4,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 106 "DynamicSQL.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 7;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[0].sqldata = (void*)EmployeeNo;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 16;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[1].sqldata = (void*)LastName;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 10;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[2].sqldata = (void*)JobType;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[3].sqltype = 480; sql_setdlist[3].sqllen = 8;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[3].sqldata = (void*)&Salary;
#line 106 "DynamicSQL.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 106 "DynamicSQL.sqc"
      sqlasetdata(2,0,4,sql_setdlist,0L,0L);
    }
#line 106 "DynamicSQL.sqc"
  sqlacall((unsigned short)24,1,2,0,0L);
#line 106 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 106 "DynamicSQL.sqc"


    if (sqlca.sqlcode == SQL_RC_OK) {
        printf("成功插入记录\n");
    }
    else {
        printf("Error Code1: %d\n", sqlca.sqlcode);
    }

    // Commit the transaction
    
/*
EXEC SQL COMMIT;
*/

{
#line 116 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 116 "DynamicSQL.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 116 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 116 "DynamicSQL.sqc"


    // Terminate the database connection
    
/*
EXEC SQL DISCONNECT CURRENT;
*/

{
#line 119 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 119 "DynamicSQL.sqc"
  sqlacall((unsigned short)40,24,0,0,0L);
#line 119 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 119 "DynamicSQL.sqc"

}

void executeUpdate() {
    // Include the SQLCA data structure variable
    
/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 124 "DynamicSQL.sqc"

    // Define the SQL host variables needed
    
/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 126 "DynamicSQL.sqc"

        char     JobType[10];
    
/*
EXEC SQL END DECLARE SECTION;
*/

#line 128 "DynamicSQL.sqc"


    // Connect to the appropriate database
    
/*
EXEC SQL CONNECT TO SAMPLE USER 'PC' USING '030929';
*/

{
#line 131 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 131 "DynamicSQL.sqc"
  sqlaaloc(2,3,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 131 "DynamicSQL.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 7;
#line 131 "DynamicSQL.sqc"
      sql_setdlist[0].sqldata = (void*)"SAMPLE";
#line 131 "DynamicSQL.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 131 "DynamicSQL.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 3;
#line 131 "DynamicSQL.sqc"
      sql_setdlist[1].sqldata = (void*)"PC";
#line 131 "DynamicSQL.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 131 "DynamicSQL.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 7;
#line 131 "DynamicSQL.sqc"
      sql_setdlist[2].sqldata = (void*)"030929";
#line 131 "DynamicSQL.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 131 "DynamicSQL.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 131 "DynamicSQL.sqc"
  sqlacall((unsigned short)29,5,2,0,0L);
#line 131 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 131 "DynamicSQL.sqc"


    // Prompt for job type
    printf("请输入要修改的职位类型：");
    scanf("%s", JobType);

    // Define a dynamic UPDATE SQL statement
    char SQLStmt[80] = "UPDATE THEORY.EMPLOYEE SET JOB = ? WHERE JOB = 'MANAGER'";
  
    // Prepare the SQL statement
    
/*
EXEC SQL PREPARE SQL_STMT FROM :SQLStmt;
*/

{
#line 141 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 141 "DynamicSQL.sqc"
  sqlastls(0,SQLStmt,0L);
#line 141 "DynamicSQL.sqc"
  sqlacall((unsigned short)27,1,0,0,0L);
#line 141 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 141 "DynamicSQL.sqc"


    // Execute the SQL statement
    
/*
EXEC SQL EXECUTE SQL_STMT USING :JobType;
*/

{
#line 144 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 144 "DynamicSQL.sqc"
  sqlaaloc(2,1,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 144 "DynamicSQL.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 144 "DynamicSQL.sqc"
      sql_setdlist[0].sqldata = (void*)JobType;
#line 144 "DynamicSQL.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 144 "DynamicSQL.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 144 "DynamicSQL.sqc"
  sqlacall((unsigned short)24,1,2,0,0L);
#line 144 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 144 "DynamicSQL.sqc"


    if (sqlca.sqlcode == SQL_RC_OK) {
        printf("成功更新记录\n");
    }
    else {
        printf("Error Code1: %d\n", sqlca.sqlcode);
    }

    // Commit the transaction
    
/*
EXEC SQL COMMIT;
*/

{
#line 154 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 154 "DynamicSQL.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 154 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 154 "DynamicSQL.sqc"


    // Terminate the database connection
    
/*
EXEC SQL DISCONNECT CURRENT;
*/

{
#line 157 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 157 "DynamicSQL.sqc"
  sqlacall((unsigned short)40,24,0,0,0L);
#line 157 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 157 "DynamicSQL.sqc"

}

void executeDelete() {
    // Include the SQLCA data structure variable
    
/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 162 "DynamicSQL.sqc"

    // Define the SQL host variables needed
    
/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 164 "DynamicSQL.sqc"

        char     EmployeeNo[7];
    
/*
EXEC SQL END DECLARE SECTION;
*/

#line 166 "DynamicSQL.sqc"


    // Connect to the appropriate database
    
/*
EXEC SQL CONNECT TO SAMPLE USER 'PC' USING '030929';
*/

{
#line 169 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 169 "DynamicSQL.sqc"
  sqlaaloc(2,3,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 169 "DynamicSQL.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 7;
#line 169 "DynamicSQL.sqc"
      sql_setdlist[0].sqldata = (void*)"SAMPLE";
#line 169 "DynamicSQL.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 169 "DynamicSQL.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 3;
#line 169 "DynamicSQL.sqc"
      sql_setdlist[1].sqldata = (void*)"PC";
#line 169 "DynamicSQL.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 169 "DynamicSQL.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 7;
#line 169 "DynamicSQL.sqc"
      sql_setdlist[2].sqldata = (void*)"030929";
#line 169 "DynamicSQL.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 169 "DynamicSQL.sqc"
      sqlasetdata(2,0,3,sql_setdlist,0L,0L);
    }
#line 169 "DynamicSQL.sqc"
  sqlacall((unsigned short)29,5,2,0,0L);
#line 169 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 169 "DynamicSQL.sqc"


    // Prompt for employee number
    printf("请输入要删除的员工编号：");
    scanf("%s", EmployeeNo);

    // Define a dynamic DELETE SQL statement  
    char SQLStmt[80] = "DELETE FROM THEORY.EMPLOYEE WHERE EMPNO = ?";

    // Prepare the SQL statement
    
/*
EXEC SQL PREPARE SQL_STMT FROM :SQLStmt;
*/

{
#line 179 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 179 "DynamicSQL.sqc"
  sqlastls(0,SQLStmt,0L);
#line 179 "DynamicSQL.sqc"
  sqlacall((unsigned short)27,1,0,0,0L);
#line 179 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 179 "DynamicSQL.sqc"


    // Execute the SQL statement
    
/*
EXEC SQL EXECUTE SQL_STMT USING :EmployeeNo;
*/

{
#line 182 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 182 "DynamicSQL.sqc"
  sqlaaloc(2,1,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 182 "DynamicSQL.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 7;
#line 182 "DynamicSQL.sqc"
      sql_setdlist[0].sqldata = (void*)EmployeeNo;
#line 182 "DynamicSQL.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 182 "DynamicSQL.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 182 "DynamicSQL.sqc"
  sqlacall((unsigned short)24,1,2,0,0L);
#line 182 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 182 "DynamicSQL.sqc"


    if (sqlca.sqlcode == SQL_RC_OK) {
        printf("成功删除记录\n");
    }
    else {
        printf("Error Code1: %d\n", sqlca.sqlcode);
    }

    // Commit the transaction
    
/*
EXEC SQL COMMIT;
*/

{
#line 192 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 192 "DynamicSQL.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 192 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 192 "DynamicSQL.sqc"


    // Terminate the database connection
    
/*
EXEC SQL DISCONNECT CURRENT;
*/

{
#line 195 "DynamicSQL.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 195 "DynamicSQL.sqc"
  sqlacall((unsigned short)40,24,0,0,0L);
#line 195 "DynamicSQL.sqc"
  sqlastop(0L);
}

#line 195 "DynamicSQL.sqc"

}

int main()
{
    SetConsoleOutputCP(65001);
    while (1) {
        printMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                executeQuery();
                break;
            case 2:
                executeInsert();
                break;
            case 3:
                executeUpdate();
                break;
            case 4:
                executeDelete();
                break;
            case 5:
                printf("程序EXIT");
                return 0;
            default:
                printf("Invalid Input!");
                printf("\n");
                break;
        }
    }

    return 0;
}
