import java.sql.*;

/**
 * This example shows the use of the PreparedStatement
 *
 * @author Fabian Groffen <Fabian.Groffen@cwi.nl>
 */
public class PreparedExample {
	public static void main(String[] args) throws Exception {
		// make sure the driver is loaded
		Class.forName("nl.cwi.monetdb.jdbc.MonetDriver");
		Connection con = DriverManager.getConnection("jdbc:monetdb://localhost/notused", "monetdb", "monetdb");
		PreparedStatement st = con.prepareStatement("SELECT ? AS a1, ? AS a2");
		ResultSet rs;

		st.setString(1, "te\\s't");
		st.setInt(2, 10);

		rs = st.executeQuery();
		// get meta data and print columns with their type
		ResultSetMetaData md = rs.getMetaData();
		for (int i = 1; i <= md.getColumnCount(); i++) {
			System.out.print(md.getColumnName(i) + ":" +
				md.getColumnTypeName(i) + "\t");
		}
		System.out.println("");

		while (rs.next()) {
			for (int j = 1; j <= md.getColumnCount(); j++) {
				System.out.print(rs.getString(j) + "\t");
			}
			System.out.println("");
		}

		con.close();
	}
}
