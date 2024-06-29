/*@lineinfo:filename=Iter*//*@lineinfo:user-code*//*@lineinfo:1^1*/import java.sql.*;
import sqlj.runtime.*;
import sqlj.runtime.ref.*;
import java.util.InputMismatchException;
import java.util.Scanner;

/*@lineinfo:generated-code*//*@lineinfo:7^2*/

//  ************************************************************
//  SQLJ context declaration:
//  ************************************************************

class Ctx 
extends sqlj.runtime.ref.ConnectionContextImpl
implements sqlj.runtime.ConnectionContext
{
  private static java.util.Map m_typeMap = null;
  private static final sqlj.runtime.ref.ProfileGroup profiles = new sqlj.runtime.ref.ProfileGroup();
  private static Ctx defaultContext = null;
  public Ctx(java.sql.Connection conn) 
    throws java.sql.SQLException 
  {
    super(profiles, conn);
  }
  public Ctx(java.lang.String url, java.lang.String user, java.lang.String password, boolean autoCommit) 
    throws java.sql.SQLException 
  {
    super(profiles, url, user, password, autoCommit);
  }
  public Ctx(java.lang.String url, java.util.Properties info, boolean autoCommit) 
    throws java.sql.SQLException 
  {
    super(profiles, url, info, autoCommit);
  }
  public Ctx(java.lang.String url, boolean autoCommit) 
    throws java.sql.SQLException 
  {
    super(profiles, url, autoCommit);
  }
  public Ctx(sqlj.runtime.ConnectionContext other) 
    throws java.sql.SQLException 
  {
    super(profiles, other);
  }
  public static Ctx getDefaultContext() 
  {
    if (defaultContext == null)
    {
      java.sql.Connection conn = sqlj.runtime.RuntimeContext.getRuntime().getDefaultConnection();
      if (conn != null)
      {
        try 
        {
          defaultContext = new Ctx(conn);
        }
        catch (java.sql.SQLException e) 
        {
        }
      }
    }
    return defaultContext;
  }
  public static void setDefaultContext(Ctx ctx) 
  {
    defaultContext = ctx;
  }
  public static java.lang.Object getProfileKey(sqlj.runtime.profile.Loader loader, java.lang.String profileName) 
    throws java.sql.SQLException 
  {
    return profiles.getProfileKey(loader, profileName);
  }
  public static sqlj.runtime.profile.Profile getProfile(java.lang.Object profileKey) 
  {
    return profiles.getProfile(profileKey);
  }
  public java.util.Map getTypeMap() 
  {
    return m_typeMap;
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:7^15*/
/*@lineinfo:generated-code*//*@lineinfo:8^2*/

//  ************************************************************
//  SQLJ iterator declaration:
//  ************************************************************

class NameIter 
extends sqlj.runtime.ref.ResultSetIterImpl
implements sqlj.runtime.NamedIterator
{
  private int LASTNAMENdx;
  private int EMPNONdx;
  public NameIter(sqlj.runtime.profile.RTResultSet resultSet) 
    throws java.sql.SQLException 
  {
    super(resultSet);
    EMPNONdx = findColumn("EMPNO");
    LASTNAMENdx = findColumn("LASTNAME");
  }
  public NameIter(sqlj.runtime.profile.RTResultSet resultSet, int fetchSize, int maxRows) 
    throws java.sql.SQLException 
  {
    super(resultSet, fetchSize, maxRows);
    EMPNONdx = findColumn("EMPNO");
    LASTNAMENdx = findColumn("LASTNAME");
  }
  public String EMPNO() 
    throws java.sql.SQLException 
  {
    return resultSet.getString(EMPNONdx);
  }
  public String LASTNAME() 
    throws java.sql.SQLException 
  {
    return resultSet.getString(LASTNAMENdx);
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:8^53*/
/*@lineinfo:generated-code*//*@lineinfo:9^2*/

//  ************************************************************
//  SQLJ iterator declaration:
//  ************************************************************

class InfoIter 
extends sqlj.runtime.ref.ResultSetIterImpl
implements sqlj.runtime.NamedIterator
{
  private int EDLEVELNdx;
  private int MIDINITNdx;
  private int FIRSTNAMENdx;
  private int LASTNAMENdx;
  private int EMPNONdx;
  public InfoIter(sqlj.runtime.profile.RTResultSet resultSet) 
    throws java.sql.SQLException 
  {
    super(resultSet);
    EMPNONdx = findColumn("EMPNO");
    LASTNAMENdx = findColumn("LASTNAME");
    FIRSTNAMENdx = findColumn("FIRSTNAME");
    MIDINITNdx = findColumn("MIDINIT");
    EDLEVELNdx = findColumn("EDLEVEL");
  }
  public InfoIter(sqlj.runtime.profile.RTResultSet resultSet, int fetchSize, int maxRows) 
    throws java.sql.SQLException 
  {
    super(resultSet, fetchSize, maxRows);
    EMPNONdx = findColumn("EMPNO");
    LASTNAMENdx = findColumn("LASTNAME");
    FIRSTNAMENdx = findColumn("FIRSTNAME");
    MIDINITNdx = findColumn("MIDINIT");
    EDLEVELNdx = findColumn("EDLEVEL");
  }
  public String EMPNO() 
    throws java.sql.SQLException 
  {
    return resultSet.getString(EMPNONdx);
  }
  public String LASTNAME() 
    throws java.sql.SQLException 
  {
    return resultSet.getString(LASTNAMENdx);
  }
  public String FIRSTNAME() 
    throws java.sql.SQLException 
  {
    return resultSet.getString(FIRSTNAMENdx);
  }
  public String MIDINIT() 
    throws java.sql.SQLException 
  {
    return resultSet.getString(MIDINITNdx);
  }
  public int EDLEVEL() 
    throws java.sql.SQLException 
  {
    return resultSet.getIntNoNull(EDLEVELNdx);
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:15^2*/
/*@lineinfo:generated-code*//*@lineinfo:16^2*/

//  ************************************************************
//  SQLJ iterator declaration:
//  ************************************************************

class CountIter 
extends sqlj.runtime.ref.ResultSetIterImpl
implements sqlj.runtime.NamedIterator
{
  private int COUNTNdx;
  public CountIter(sqlj.runtime.profile.RTResultSet resultSet) 
    throws java.sql.SQLException 
  {
    super(resultSet);
    COUNTNdx = findColumn("COUNT");
  }
  public CountIter(sqlj.runtime.profile.RTResultSet resultSet, int fetchSize, int maxRows) 
    throws java.sql.SQLException 
  {
    super(resultSet, fetchSize, maxRows);
    COUNTNdx = findColumn("COUNT");
  }
  public int COUNT() 
    throws java.sql.SQLException 
  {
    return resultSet.getIntNoNull(COUNTNdx);
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:16^33*/

class Iter {
    private static final String DB_URL = "jdbc:db2://127.0.0.1:50230/sample";
    private static final String USERNAME = "pc";
    private static final String PASSWORD = "030929";

    public static void main(String[] argv) {
        try {
            Class.forName("com.ibm.db2.jcc.DB2Driver");
            Ctx connCtx = new Ctx(DB_URL, USERNAME, PASSWORD, true);

            displayMainMenu(connCtx);

            connCtx.close();
        } catch (ClassNotFoundException e) {
            System.err.println("Could not load JDBC driver");
            e.printStackTrace();
        } catch (SQLException e) {
            handleSQLException(e);
        }
    }

    private static void displayMainMenu(Ctx connCtx) throws SQLException {
        Scanner scanner = new Scanner(System.in);
        int choice = -1;

        do {
            // 清屏
            try {
                if (System.getProperty("os.name").contains("Windows")) {
                    new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
                } else {
                    System.out.print("\033[H\033[2J");
                    System.out.flush();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            System.out.println("=============================");
            System.out.println("EMPLOYEE MANAGEMENT SYSTEM");
            System.out.println("=============================");
            System.out.println("Main Menu:");
            System.out.println("1. Insert into EMPLOYEE");
            System.out.println("2. Select from EMPLOYEE");
            System.out.println("3. Update EMPLOYEE");
            System.out.println("4. Delete from EMPLOYEE");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");

            if (scanner.hasNextInt()) {
                choice = scanner.nextInt();
                scanner.nextLine();
            } else {
                System.out.println("Invalid choice. Please enter a valid integer choice.");
                scanner.nextLine();
                continue;
            }

            switch (choice) {
                case 1:
                    insertEmployee(connCtx);
                    break;
                case 2:
                    selectFromEmployee(connCtx);
                    break;
                case 3:
                    updateEmployee(connCtx);
                    break;
                case 4:
                    deleteFromEmployee(connCtx);
                    break;
                case 0:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    Thread.sleep(2000);
            }
        } while (choice != 0);
    }

    private static void insertEmployee(Ctx connCtx) throws SQLException {
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n\nInsert into EMPLOYEE");
        System.out.print("Enter EMPNO: ");
        String empNo = scanner.nextLine();

        if (empNo.length() > 6) {
            System.out.println("EMPNO must be within 6 characters. Insertion failed.");
            return;
        }

        if (isEmployeeExists(connCtx, empNo)) {
            System.out.println("Employee with ID " + empNo + " already exists. Insertion failed.");
            return;
        }

        System.out.print("Enter FIRSTNME: ");
        String firstName = scanner.nextLine();
        if (firstName.length() > 12) {
            System.out.println("FIRSTNME must be within 12 characters. Insertion failed.");
            return;
        }

        System.out.print("Enter MIDINIT: ");
        String midInit = scanner.nextLine();
        if (midInit.length() != 1) {
            System.out.println("MIDINIT must be a single character. Insertion failed.");
            return;
        }

        System.out.print("Enter LASTNAME: ");
        String lastName = scanner.nextLine();
        if (lastName.length() > 15) {
            System.out.println("LASTNAME must be within 15 characters. Insertion failed.");
            return;
        }

        System.out.print("Enter EDLEVEL: ");
        int edLevel = scanner.nextInt();
        scanner.nextLine();


        try {
            /*@lineinfo:generated-code*//*@lineinfo:142^12*/

//  ************************************************************
//  #sql [connCtx] { INSERT INTO THEORY.EMPLOYEE (EMPNO, FIRSTNME, MIDINIT, LASTNAME, EDLEVEL)
//                  VALUES (:empNo, :firstName, :midInit, :lastName, :edLevel )
//               };
//  ************************************************************

{
  sqlj.runtime.ConnectionContext __sJT_connCtx = connCtx;
  if (__sJT_connCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_CONN_CTX();
  sqlj.runtime.ExecutionContext __sJT_execCtx = __sJT_connCtx.getExecutionContext();
  if (__sJT_execCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_EXEC_CTX();
  synchronized (__sJT_execCtx) {
    sqlj.runtime.profile.RTStatement __sJT_stmt = __sJT_execCtx.registerStatement(__sJT_connCtx, Iter_SJProfileKeys.getKey(0), 0);
    try 
    {
      __sJT_stmt.setString(1, empNo);
      __sJT_stmt.setString(2, firstName);
      __sJT_stmt.setString(3, midInit);
      __sJT_stmt.setString(4, lastName);
      __sJT_stmt.setInt(5, edLevel);
      __sJT_execCtx.executeUpdate();
    }
    finally 
    {
      __sJT_execCtx.releaseStatement();
    }
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:145^12*/
        }catch (SQLException e) {
                 handleSQLException(e);
                 return;
             }
        System.out.println("Employee inserted successfully.");
        Thread.sleep(2000);
    }

    private static void selectFromEmployee(Ctx connCtx) throws SQLException {
        Scanner scanner = new Scanner(System.in);
        int choice = -1;

        do {
            // 清屏
            try {
                if (System.getProperty("os.name").contains("Windows")) {
                    new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
                } else {
                    System.out.print("\033[H\033[2J");
                    System.out.flush();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            System.out.println("========================================");
            System.out.println("SELECT from EMPLOYEE");
            System.out.println("========================================");
            System.out.println("1. Select all employees");
            System.out.println("2. Select employee by ID");
            System.out.println("0. Return to main menu");
            System.out.print("Enter your choice: ");

            if (scanner.hasNextInt()) {
                choice = scanner.nextInt();
                scanner.nextLine();
            } else {
                System.out.println("Invalid choice. Please enter a valid integer choice.");
                scanner.nextLine();
                continue;
            }

            switch (choice) {
                case 1:
                    int numEmployees = selectAllEmployees(connCtx);
                    if (numEmployees == 0) {
                        System.out.println("No employees found.");
                        Thread.sleep(2000);
                    }
                    else {
                        System.out.println("Press Enter to continue...");
                        try {
                            System.in.read(); // 等待用户按下回车键
                        } catch (IOException e) {
                            e.printStackTrace();
                        }

                        // 在这里添加处理员工记录的代码
                        // 例如:
                        for (Employee employee : employees) {
                            System.out.println("Employee: " + employee.getName());
                        }
                    }
                    break;
                case 2:
                    System.out.print("Enter EMPNO: ");
                        String empNo = scanner.nextLine().trim();
                        if (empNo.isEmpty()) {
                            System.out.println("EMPNO cannot be empty. Selection failed.");
                            break;
                        }
                        if (empNo.length() > 6) {
                            System.out.println("EMPNO must be within 6 characters. Selection failed.");
                            break;
                        }
                        selectEmployeeById(connCtx, empNo);
                        break;
                case 0:
                    System.out.println("Going back to main menu...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 0);
    }

    private static int selectAllEmployees(Ctx connCtx) throws SQLException {
        NameIter nIter;
        int rowCount = 0;
        try {
            /*@lineinfo:generated-code*//*@lineinfo:235^12*/

//  ************************************************************
//  #sql [connCtx] nIter = { SELECT EMPNO, LASTNAME FROM THEORY.EMPLOYEE
//               };
//  ************************************************************

{
  sqlj.runtime.ConnectionContext __sJT_connCtx = connCtx;
  if (__sJT_connCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_CONN_CTX();
  sqlj.runtime.ExecutionContext __sJT_execCtx = __sJT_connCtx.getExecutionContext();
  if (__sJT_execCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_EXEC_CTX();
  synchronized (__sJT_execCtx) {
    sqlj.runtime.profile.RTStatement __sJT_stmt = __sJT_execCtx.registerStatement(__sJT_connCtx, Iter_SJProfileKeys.getKey(0), 1);
    try 
    {
      nIter = new NameIter(__sJT_execCtx.executeQuery(), __sJT_execCtx.getFetchSize(), __sJT_execCtx.getMaxRows());
    }
    finally 
    {
      __sJT_execCtx.releaseStatement();
    }
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:237^12*/

            while (nIter.next()) {
                System.out.println(nIter.LASTNAME() + ", ID #" + nIter.EMPNO());
                rowCount++;
            }
            nIter.close();
        } catch (SQLException e) {
            handleSQLException(e);
            return 0;
        }
        return rowCount;
    }

    private static void selectEmployeeById(Ctx connCtx, String empNo) throws SQLException {
        try {
             if (!isEmployeeExists(connCtx, empNo)) {
                        System.out.println("Employee with ID " + empNo + " does not exist.");
                        return;
                    }
            NameIter nIter;
            /*@lineinfo:generated-code*//*@lineinfo:258^12*/

//  ************************************************************
//  #sql [connCtx] nIter = { SELECT EMPNO, LASTNAME
//                  FROM THEORY.EMPLOYEE WHERE EMPNO = :empNo
//               };
//  ************************************************************

{
  sqlj.runtime.ConnectionContext __sJT_connCtx = connCtx;
  if (__sJT_connCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_CONN_CTX();
  sqlj.runtime.ExecutionContext __sJT_execCtx = __sJT_connCtx.getExecutionContext();
  if (__sJT_execCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_EXEC_CTX();
  synchronized (__sJT_execCtx) {
    sqlj.runtime.profile.RTStatement __sJT_stmt = __sJT_execCtx.registerStatement(__sJT_connCtx, Iter_SJProfileKeys.getKey(0), 2);
    try 
    {
      __sJT_stmt.setString(1, empNo);
      nIter = new NameIter(__sJT_execCtx.executeQuery(), __sJT_execCtx.getFetchSize(), __sJT_execCtx.getMaxRows());
    }
    finally 
    {
      __sJT_execCtx.releaseStatement();
    }
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:261^12*/

            while (nIter.next()) {
                    System.out.println(nIter.LASTNAME() + ", ID #" + nIter.EMPNO());
                              }
            nIter.close();
        }catch (SQLException e) {
                 handleSQLException(e);
                 return;
             }
    }

    private static void updateEmployee(Ctx connCtx) throws SQLException {
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n\nUpdate EMPLOYEE");
        System.out.print("Enter EMPNO: ");
        String empNo = scanner.nextLine();

        if (empNo.length() > 6) {
                    System.out.println("EMPNO must be within 6 characters. Update failed.");
                    return;
                }

        if (!isEmployeeExists(connCtx, empNo)) {
            System.out.println("Employee with ID " + empNo + " does not exist. Update failed.");
            return;
        }

        System.out.print("Enter new LASTNAME: ");
        String newLastName = scanner.nextLine();
        if (newLastName.length() > 15) {
            System.out.println("LASTNAME must be within 15 characters. Update failed.");
            return;
        }

        try {
            /*@lineinfo:generated-code*//*@lineinfo:298^12*/

//  ************************************************************
//  #sql [connCtx] { UPDATE THEORY.EMPLOYEE
//                  SET LASTNAME = :newLastName
//                  WHERE EMPNO = :empNo
//               };
//  ************************************************************

{
  sqlj.runtime.ConnectionContext __sJT_connCtx = connCtx;
  if (__sJT_connCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_CONN_CTX();
  sqlj.runtime.ExecutionContext __sJT_execCtx = __sJT_connCtx.getExecutionContext();
  if (__sJT_execCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_EXEC_CTX();
  synchronized (__sJT_execCtx) {
    sqlj.runtime.profile.RTStatement __sJT_stmt = __sJT_execCtx.registerStatement(__sJT_connCtx, Iter_SJProfileKeys.getKey(0), 3);
    try 
    {
      __sJT_stmt.setString(1, newLastName);
      __sJT_stmt.setString(2, empNo);
      __sJT_execCtx.executeUpdate();
    }
    finally 
    {
      __sJT_execCtx.releaseStatement();
    }
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:302^12*/
        }catch (SQLException e) {
                 handleSQLException(e);
                 return;
             }

        System.out.println("Employee updated successfully.");
    }

    private static void deleteFromEmployee(Ctx connCtx) throws SQLException {
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n\nDelete from EMPLOYEE");
        System.out.print("Enter EMPNO: ");
        String empNo = scanner.nextLine();

        if (empNo.length() > 6) {
                    System.out.println("EMPNO must be within 6 characters. Deletion failed.");
                    return;
                }

        if (!isEmployeeExists(connCtx, empNo)) {
            System.out.println("Employee with ID " + empNo + " does not exist. Deletion failed.");
            return;
        }

        try {
            /*@lineinfo:generated-code*//*@lineinfo:329^12*/

//  ************************************************************
//  #sql [connCtx] { DELETE FROM THEORY.EMPLOYEE WHERE EMPNO = :empNo
//               };
//  ************************************************************

{
  sqlj.runtime.ConnectionContext __sJT_connCtx = connCtx;
  if (__sJT_connCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_CONN_CTX();
  sqlj.runtime.ExecutionContext __sJT_execCtx = __sJT_connCtx.getExecutionContext();
  if (__sJT_execCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_EXEC_CTX();
  synchronized (__sJT_execCtx) {
    sqlj.runtime.profile.RTStatement __sJT_stmt = __sJT_execCtx.registerStatement(__sJT_connCtx, Iter_SJProfileKeys.getKey(0), 4);
    try 
    {
      __sJT_stmt.setString(1, empNo);
      __sJT_execCtx.executeUpdate();
    }
    finally 
    {
      __sJT_execCtx.releaseStatement();
    }
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:331^12*/
        }catch (SQLException e) {
                 handleSQLException(e);
                 return;
             }

        System.out.println("Employee deleted successfully.");
    }

    private static boolean isEmployeeExists(Ctx connCtx, String empNo) throws SQLException {
        CountIter cIter;
        try {
            int count = 0;
            /*@lineinfo:generated-code*//*@lineinfo:344^12*/

//  ************************************************************
//  #sql [connCtx] cIter = { SELECT COUNT(*) AS COUNT FROM THEORY.EMPLOYEE WHERE EMPNO = :empNo
//                       };
//  ************************************************************

{
  sqlj.runtime.ConnectionContext __sJT_connCtx = connCtx;
  if (__sJT_connCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_CONN_CTX();
  sqlj.runtime.ExecutionContext __sJT_execCtx = __sJT_connCtx.getExecutionContext();
  if (__sJT_execCtx == null) sqlj.runtime.error.RuntimeRefErrors.raise_NULL_EXEC_CTX();
  synchronized (__sJT_execCtx) {
    sqlj.runtime.profile.RTStatement __sJT_stmt = __sJT_execCtx.registerStatement(__sJT_connCtx, Iter_SJProfileKeys.getKey(0), 5);
    try 
    {
      __sJT_stmt.setString(1, empNo);
      cIter = new CountIter(__sJT_execCtx.executeQuery(), __sJT_execCtx.getFetchSize(), __sJT_execCtx.getMaxRows());
    }
    finally 
    {
      __sJT_execCtx.releaseStatement();
    }
  }
}


//  ************************************************************

/*@lineinfo:user-code*//*@lineinfo:346^20*/

            while (cIter.next()) {
                    count = cIter.COUNT();
                              }

            return count > 0;
        }catch (SQLException e) {
                 handleSQLException(e);
                 return false;
             }
    }

    private static void handleSQLException(SQLException e) {
        System.err.println("SQL Exception: " + e.getMessage());
        System.err.println("SQL State: " + e.getSQLState());
        System.err.println("Vendor Error Code: " + e.getErrorCode());
        e.printStackTrace();
    }

}/*@lineinfo:generated-code*/class Iter_SJProfileKeys 
{
  private java.lang.Object[] keys;
  private final sqlj.runtime.profile.Loader loader = sqlj.runtime.RuntimeContext.getRuntime().getLoaderForClass(getClass());
  private static Iter_SJProfileKeys inst = null;
  public static java.lang.Object getKey(int keyNum) 
    throws java.sql.SQLException 
  {
    synchronized(Iter_SJProfileKeys.class) {
      if (inst == null)
      {
        inst = new Iter_SJProfileKeys();
      }
    }
    return inst.keys[keyNum];
  }
  private Iter_SJProfileKeys() 
    throws java.sql.SQLException 
  {
    keys = new java.lang.Object[1];
    keys[0] = Ctx.getProfileKey(loader, "Iter_SJProfile0");
  }
}
