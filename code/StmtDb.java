import java.sql.*;
import java.util.InputMismatchException;
import java.util.Scanner;

class StmtDb {
  private static final String DB_URL = "jdbc:db2://127.0.0.1:50230/sample";
  private static final String USERNAME = "pc";
  private static final String PASSWORD = "030929";

  public static void main(String[] argv) {
    try {
      Class.forName("com.ibm.db2.jcc.DB2Driver");
      Connection con = DriverManager.getConnection(DB_URL, USERNAME, PASSWORD);
      con.setAutoCommit(true);

      displayMainMenu(con);

      con.close();
    } catch (ClassNotFoundException e) {
      System.err.println("Could not load JDBC driver");
      e.printStackTrace();
    } catch (SQLException e) {
      handleSQLException(e);
    }
  }

  private static final String MAIN_MENU_TITLE = "EMPLOYEE MANAGEMENT SYSTEM";
  private static final String[] MAIN_MENU_OPTIONS = {
          "1. Insert into EMPLOYEE",
          "2. Select from EMPLOYEE",
          "3. Update EMPLOYEE",
          "4. Delete from EMPLOYEE",
          "0. Exit"
  };

  public static void displayMainMenu(Connection con) throws SQLException {
    Scanner scanner = new Scanner(System.in);
    int choice;

    do {
      printMainMenu();
      choice = getIntInput(scanner, "Enter your choice: ");

      switch (choice) {
        case 1:
          insertEmployee(con);
          break;
        case 2:
          selectFromEmployee(con);
          break;
        case 3:
          updateEmployee(con);
          break;
        case 4:
          deleteFromEmployee(con);
          break;
        case 0:
          System.out.println("Exiting...");
          break;
        default:
          System.out.println("Invalid choice. Please try again.");
      }
    } while (choice != 0);
  }

  private static void printMainMenu() {
    System.out.println("\n\n\n\n\n=============================");
    System.out.println(MAIN_MENU_TITLE);
    System.out.println("=============================");
    System.out.println("Main Menu:");
    for (String option : MAIN_MENU_OPTIONS) {
      System.out.println(option);
    }
  }

  private static int getIntInput(Scanner scanner, String prompt) {
    while (true) {
      System.out.print(prompt);
      String input = scanner.nextLine();
      try {
        return Integer.parseInt(input);
      } catch (NumberFormatException e) {
        System.out.println("Invalid choice. Please enter a valid integer choice.");
      }
    }
  }

  private static boolean containsDigit(String str) {
    for (int i = 0; i < str.length(); i++) {
      if (Character.isDigit(str.charAt(i))) {
        return true;
      }
    }
    return false;
  }

  private static void insertEmployee(Connection con) throws SQLException {
    Scanner scanner = new Scanner(System.in);

    System.out.println("\n\nInsert into EMPLOYEE");
    System.out.print("Enter the number of employees to insert: ");
    int numEmployees;
    try {
      numEmployees = scanner.nextInt();
      scanner.nextLine(); // 清除输入缓冲区中的换行符
    } catch (InputMismatchException e) {
      System.out.println("Invalid input. Insertion aborted.");
      scanner.nextLine();
      return;
    }

    String insertSql = "INSERT INTO THEORY.EMPLOYEE (EMPNO, FIRSTNME, MIDINIT, LASTNAME, EDLEVEL) " +
            "VALUES (?, ?, ?, ?, ?)";

    for (int i = 0; i < numEmployees; i++) {
      System.out.printf("\nEnter information for employee %d:\n", i + 1);

      System.out.print("EMPNO: ");
      String empNo = scanner.nextLine();
      if (empNo.isEmpty()) {
        System.out.println("EMPNO cannot be empty. Insertion failed for this employee.");
        continue;
      }
      try {
        int empNoInt = Integer.parseInt(empNo);
        if (empNoInt < 0) {
          System.out.println("EMPNO must be a positive integer. Insertion failed for this employee.");
          continue;
        }
        if (String.valueOf(empNoInt).length() > 6) {
          System.out.println("EMPNO must be within 6 characters. Insertion failed for this employee.");
          continue;
        }
      } catch (NumberFormatException e) {
        System.out.println("EMPNO must be a valid integer. Insertion failed for this employee.");
        continue;
      }

      if (isEmployeeExists(con, empNo)) {
        System.out.println("Employee with ID " + empNo + " already exists. Insertion failed for this employee.");
        continue;
      }

      System.out.print("FIRSTNME: ");
      String firstName = scanner.nextLine();
      if (firstName.isEmpty()) {
        System.out.println("FIRSTNME cannot be empty. Insertion failed for this employee.");
        continue;
      }
      if (containsDigit(firstName)) {
        System.out.println("FIRSTNME cannot contain digits. Insertion failed for this employee.");
        continue;
      }
      if (firstName.length() > 12) {
        System.out.println("FIRSTNME must be within 12 characters. Insertion failed for this employee.");
        continue;
      }

      System.out.print("MIDINIT: ");
      String midInit = scanner.nextLine();
      if (midInit.isEmpty()) {
        System.out.println("MIDINIT cannot be empty. Insertion failed for this employee.");
        continue;
      }
      if (midInit.length() != 1) {
        System.out.println("MIDINIT must be a single character. Insertion failed for this employee.");
        continue;
      }
      if (containsDigit(midInit)) {
        System.out.println("MIDINIT cannot be a digit. Insertion failed for this employee.");
        continue;
      }

      System.out.print("LASTNAME: ");
      String lastName = scanner.nextLine();
      if (lastName.isEmpty()) {
        System.out.println("LASTNAME cannot be empty. Insertion failed for this employee.");
        continue;
      }
      if (containsDigit(lastName)) {
        System.out.println("LASTNAME cannot contain digits. Insertion failed for this employee.");
        continue;
      }
      if (lastName.length() > 15) {
        System.out.println("LASTNAME must be within 15 characters. Insertion failed for this employee.");
        continue;
      }

      System.out.print("EDLEVEL: ");
      int edLevel;
      try {
        edLevel = scanner.nextInt();
        scanner.nextLine(); // 清除输入缓冲区中的换行符
      } catch (InputMismatchException e) {
        System.out.println("EDLEVEL must be an integer. Insertion failed for this employee.");
        scanner.nextLine();
        continue;
      }

      try (PreparedStatement pstmt = con.prepareStatement(insertSql)) {
        pstmt.setString(1, empNo);
        pstmt.setString(2, firstName);
        pstmt.setString(3, midInit);
        pstmt.setString(4, lastName);
        pstmt.setInt(5, edLevel);
        pstmt.executeUpdate();
        System.out.println("Record inserted successfully.");
      }
    }

    selectAllEmployees(con);
  }

  private static void selectFromEmployee(Connection con) throws SQLException {
    Scanner scanner = new Scanner(System.in);

    System.out.println("\n\nSelect from EMPLOYEE");
    System.out.println("1. Select all employees");
    System.out.println("2. Select employee by ID");
    System.out.print("Enter your choice: ");
    int choice;
    if (scanner.hasNextInt()) {
      choice = scanner.nextInt();
      scanner.nextLine(); // 清除输入缓冲区中的换行符
    } else {
      System.out.println("Invalid choice. Please enter a valid integer choice.");
      scanner.nextLine();
      return;
    }

    switch (choice) {
      case 1:
        selectAllEmployees(con);
        break;
      case 2:
        System.out.print("Enter EMPNO: ");
        String empNo = scanner.next();
        if (empNo.length() > 6) {
          System.out.println("EMPNO must be within 6 characters. Selection failed.");
          return;
        }
        selectEmployeeById(con, empNo);
        break;
      default:
        System.out.println("Invalid choice.");
    }
  }

  private static void selectAllEmployees(Connection con) throws SQLException {
    String selectAllSql = "SELECT EMPNO, FIRSTNME, MIDINIT, LASTNAME, EDLEVEL FROM THEORY.EMPLOYEE";

    try (Statement stmt = con.createStatement();
         ResultSet rs = stmt.executeQuery(selectAllSql)) {
      System.out.println("+-----------+---------------+---------------+---------------+---------------+");
      System.out.println("| Employee #| First Name    | Middle Initial| Last Name     | Edu. Level    |");
      System.out.println("+-----------+---------------+---------------+---------------+---------------+");
      while (rs.next()) {
        System.out.printf("| %-10s| %-14s| %-14s| %-14s| %-14d|\n",
                rs.getString(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getInt(5));
      }
      System.out.println("+-----------+---------------+---------------+---------------+---------------+");
    }
  }

  private static void selectEmployeeById(Connection con, String empNo) throws SQLException {
    String selectByIdSql = "SELECT EMPNO, FIRSTNME, MIDINIT, LASTNAME, EDLEVEL " +
            "FROM THEORY.EMPLOYEE WHERE EMPNO = ?";

    try (PreparedStatement pstmt = con.prepareStatement(selectByIdSql)) {
      pstmt.setString(1, empNo);
      try (ResultSet rs = pstmt.executeQuery()) {
        if (rs.next()) {
          System.out.println("+-----------+---------------+---------------+---------------+---------------+");
          System.out.println("| Employee #| First Name    | Middle Initial| Last Name     | Edu. Level    |");
          System.out.println("+-----------+---------------+---------------+---------------+---------------+");
          System.out.printf("| %-10s| %-14s| %-14s| %-14s| %-14d|\n",
                  rs.getString(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getInt(5));
          System.out.println("+-----------+---------------+---------------+---------------+---------------+");
        } else {
          System.out.println("Employee with ID " + empNo + " does not exist.");
        }
      }
    }
  }

  private static void updateEmployee(Connection con) throws SQLException {
    Scanner scanner = new Scanner(System.in);

    System.out.println("\n\nUpdate EMPLOYEE");
    System.out.print("Enter EMPNO of the employee to update: ");
    String empNo = scanner.nextLine();

    if (empNo.length() > 6) {
      System.out.println("EMPNO must be within 6 characters. Update failed.");
      return;
    }

    if (!isEmployeeExists(con, empNo)) {
      System.out.println("Employee with ID " + empNo + " does not exist. Update failed.");
      return;
    }

    System.out.print("Enter New FIRSTNME: ");
    String firstName = scanner.nextLine();
    if (firstName.length() > 12) {
      System.out.println("FIRSTNME must be within 12 characters. Update failed.");
      return;
    }

    System.out.print("Enter New MIDINIT: ");
    String midInit = scanner.nextLine();
    if (midInit.length() != 1) {
      System.out.println("MIDINIT must be a single character. Update failed.");
      return;
    }

    System.out.print("Enter New LASTNAME: ");
    String lastName = scanner.nextLine();
    if (lastName.length() > 15) {
      System.out.println("LASTNAME must be within 15 characters. Update failed.");
      return;
    }

    System.out.print("Enter New EDLEVEL: ");
    int edLevel;
    try {
      edLevel = scanner.nextInt();
      scanner.nextLine(); // 清除输入缓冲区中的换行符
    } catch (InputMismatchException e) {
      System.out.println("EDLEVEL must be an integer. Update failed.");
      scanner.nextLine();
      return;
    }

    String updateSql = "UPDATE THEORY.EMPLOYEE SET FIRSTNME = ?, MIDINIT = ?, LASTNAME = ?, EDLEVEL = ? WHERE EMPNO = ?";

    try (PreparedStatement pstmt = con.prepareStatement(updateSql)) {
      pstmt.setString(1, firstName);
      pstmt.setString(2, midInit);
      pstmt.setString(3, lastName);
      pstmt.setInt(4, edLevel);
      pstmt.setString(5, empNo);
      int rowsAffected = pstmt.executeUpdate();
      System.out.println(rowsAffected + " record(s) updated successfully.");
      selectAllEmployees(con);
    }
  }


  private static void deleteFromEmployee(Connection con) throws SQLException {
    Scanner scanner = new Scanner(System.in);

    System.out.println("\n\nDelete from EMPLOYEE");
    System.out.print("Enter EMPNO of the employee to delete: ");
    String empNo = scanner.nextLine();

    if (empNo.length() > 6) {
      System.out.println("EMPNO must be within 6 characters. Deletion failed.");
      return;
    }

    if (!isEmployeeExists(con, empNo)) {
      System.out.println("Employee with ID " + empNo + " does not exist. Deletion failed.");
      return;
    }

    // 先打印出要删除的员工信息
    selectEmployeeById(con, empNo);

    // 询问用户是否确认删除
    System.out.print("\nAre you sure you want to delete this employee? (y/n): ");
    String confirmation = scanner.nextLine();
    if (!confirmation.equalsIgnoreCase("y")) {
      System.out.println("Deletion cancelled.");
      return;
    }

    String deleteSql = "DELETE FROM THEORY.EMPLOYEE WHERE EMPNO = ?";

    try (PreparedStatement pstmt = con.prepareStatement(deleteSql)) {
      pstmt.setString(1, empNo);
      int rowsAffected = pstmt.executeUpdate();
      System.out.println(rowsAffected + " record(s) deleted successfully.");
      selectAllEmployees(con);
    }
  }

  private static boolean isEmployeeExists(Connection con, String empNo) throws SQLException {
    String selectByIdSql = "SELECT EMPNO FROM THEORY.EMPLOYEE WHERE EMPNO = ?";

    try (PreparedStatement pstmt = con.prepareStatement(selectByIdSql)) {
      pstmt.setString(1, empNo);
      try (ResultSet rs = pstmt.executeQuery()) {
        return rs.next();
      }
    }
  }

  private static void handleSQLException(SQLException sqlEx) {
    while (sqlEx != null) {
      System.err.println("SQLException information");
      System.err.println("Error msg: " + sqlEx.getMessage());
      System.err.println("SQLSTATE: " + sqlEx.getSQLState());
      System.err.println("Error code: " + sqlEx.getErrorCode());
      sqlEx.printStackTrace();
      sqlEx = sqlEx.getNextException();
    }
  }
}
