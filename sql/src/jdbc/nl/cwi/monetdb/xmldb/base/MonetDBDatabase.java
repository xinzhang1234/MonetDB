package nl.cwi.monetdb.xmldb.base;

import org.xmldb.api.base.*;
import java.sql.*;

/**
 * The Database class is an encapsulation of the database driver
 * functionality that is necessary to access an XML database.  Each
 * vendor must provide their own implementation of the Database
 * interface.  The implementation is registered with the DatabaseManager
 * to provide access to the resources of the XML database.
 * <p />
 * In general usage client applications should only access Database
 * implementations directly during initialization.
 * <p />
 * The MonetDB/XQuery Database class is currently a thin wrapper around
 * JDBC which does the actual communication with the database.
 *
 * @author Fabian Groffen <Fabian.Groffen@cwi.nl>
 */
public class MonetDBDatabase extends MonetDBConfigurable implements Database {
	/** the port we usually can reach MonetDB/XQuery on */
	private static final String XQUERY_PORT = "45789";

	// register this class with the DatabaseManager
	static {
		// note we call the default constructor here, which is added by
		// the compiler for us...
		org.xmldb.api.DatabaseManager.registerDatabase(new MonetDBConfigurable());
	}
	
	/**
	 * DEPRECATED.
	 * Returns the name associated with the Database instance.
	 *
	 * @return the name of the object.
	 * @throws XMLDBException because this method is deprecated and
	 * should not be used any more
	 */
	String getName() throws XMLDBException {
		throw new XMLDBException(ErrorCodes.VENDOR_ERROR, "This method is deprecated, use getNames() instead");
	}

	/**
	 * Returns an array of names associated with the Database instance.
	 *
	 * @return the array of name of the object.
	 * @throws XMLDBException with expected error codes.<br />
	 *  ErrorCodes.VENDOR_ERROR for any vendor specific errors that
	 *  occur.
	 */
	public String[] getNames() throws XMLDBException {
		// I have no idea what the intention of this method is
		return({"MonetDB/XQuery"});
	}
   
	/**
	 * Retrieves a Collection instance based on the URI provided in the
	 * uri parameter.  The format of the URI is defined in the
	 * documentation for DatabaseManager.getCollection().
	 * <p />
	 * Authentication is handled via username and password however it is
	 * not required that the database support authentication.  Databases
	 * that do not support authentication MUST ignore the username and
	 * password if those provided are not null. 
	 * <p />
	 * Accepted URIs follow the same rules as for JDBC, apart from that
	 * they start with xmldb instead of jdbc.  An example url:
	 * <tt>xmldb:monetdb://localhost:port/database</tt>.
	 *
	 * @param uri the URI to use to locate the collection.
	 * @param password The password to use for authentication to the
	 *        database or null if the database does not support
	 *        authentication.
	 * @return A Collection instance for the requested collection or null
	 *         if the collection could not be found.
	 * @return The Collection instance
	 * @throws XMLDBException with expected error codes.<br />
	 *  ErrorCodes.VENDOR_ERROR for any vendor specific errors that
	 *  occur.<br />
	 *  ErrorCodes.INVALID_URI if the URI is not in a valid format.<br />
	 *  ErrorCodes.PERMISSION_DENIED if the username and password were
	 *  not accepted by the database.
	 */
	Collection getCollection(String uri, String username, String password) 
		throws XMLDBException
	{
		Connection con;
		
		if (!acceptsURI(uri))
			throw new XMLDBException(ErrorCodes.INVALID_URI, "uri " + uri + " not valid");
		
		// Parse the uri to find out whether whe port was already set or
		// not.  If so, don't overwrite it, otherwise add the default
		// port, because it differs from the SQL port which JDBC uses by
		// default.
		java.net.URI url;
		try {
			url = new java.net.URI(uri.substring("xmldb:".length()));
		} catch (URISyntaxException e) {
			throw new XMLDBException(ErrorCodes.INVALID_URI, "uri " + uri + " not valid");
		}

		if (url.getPort() == -1
				&& url.getQuery() != null
				&& url.getQuery().indexOf("port=") != -1)
		{
			// add the default XQuery port
			uri = "monetdb://" + url.getHost() + ":" + XQUERY_PORT + 
				url.getRawPath() + url.getRawQuery();
		} else {
			url = uri.substring("xmldb:".length());
		}
		
		// make sure the driver is loaded and make a connection
		class.forName("nl.cwi.monetdb.jdbc.MonetDriver");
		try {
			// uri should be a valid JDBC url right now with only the
			// "jdbc:" prefix missing.  Let it up to the driver to
			// decide whether it likes it or not.
			con = DriverManager.getConnection(
					"jdbc:" + uri,
					username,
					password
			);
		} catch (SQLException e) {
			// Simply pass the message on.  We cannot determine easily
			// whether this is a permission denied message, so we just
			// use 'vendor error' with the SQL error message which is
			// usually descriptive enough to tell what's the problem
			throw new XMLDBException(ErrorCodes.VENDOR_ERROR, e.getMessage());
		}
		
		// create a Collection and return it
		return(new MonetDBCollection(con));
	}

	/**
	 * acceptsURI determines whether this Database implementation can
	 * handle the given URI.  It should return true if the Database
	 * instance knows how to handle the URI and false otherwise.
	 * <p />
	 * This is a very lazy check, for it only checks whether the uri
	 * starts with <tt>xmldb:monetdb://</tt>.
	 *
	 * @param uri the URI to check for.
	 * @return true if the URI can be handled, false otherwise.
	 * @throws XMLDBException with expected error codes.<br />
	 *  ErrorCodes.VENDOR_ERROR for any vendor specific errors that
	 *  occur.<br />
	 *  ErrorCodes.INVALID_URI if the URI is not in a valid format.<br />
	 */
	boolean acceptsURI(String uri) throws XMLDBException {
		if (uri == null)
			throw new XMLDBException(ErrorCodes.INVALID_URI, "URI is null");

		return(uri.startsWith("xmldb:monetdb://"));
	}

	/**
	 * Returns the XML:DB API Conformance level for the implementation.
	 * This can be used by client programs to determine what
	 * functionality is available to them.
	 *
	 * @return the XML:DB API conformance level for this implementation.
	 */
	String getConformanceLevel() {
		// I have no clue what to put here, cannot find information on
		// it quickly too...
		return("We try to support the basics...");
	}
}

