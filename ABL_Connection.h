// ABL_Connection.h: interface for the ABL_Connection class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ABL_CONNECTION_H
#define ABL_CONNECTION_H

#include "ABL_String.h"
#include "ABL_ConnectionBase.h"
#include "ABL_Mutex.h"

class ABL_Service;
class ABL_Statement;
/*********************************************************************
#	File		:	ABL_Connection.h
#	Abstract	:	ABL_Connection class grants a connection to the 
#					database at the time of construction and returns 
#					the connection to the Connection pool upon destruction. 
#					ABL_Connection also creates and destroys statement objects.
#	Date		:	9th January, 2006
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	97 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Amjath Khan.S	24th Dec, 2006	Standardization of the file
#											contents
======================================================================
#	Base Class	:	none
======================================================================
#	member 
#	Variables	:	
#	ABL_ConnectionBase *m_ABL_ConnectionBasePtr;
#
======================================================================
#	member 
#	Functions	:
#
#	ABL_Connection();				
#	virtual ~ABL_Connection();		
#	bool mb_createConnection(ABL_Service &p_ABL_Service, bool p_bautoCommit = false,bool p_timeout = false, ABL_String p_dbString = "DB1");
#	ABL_Statement mb_createStatement(const ABL_String &p_statementString = " ");
#	void mb_terminateStatement(ABL_Statement& p_ABL_Statement);
#	void mb_commit();				
#	void mb_rollback();				
#	void mb_changePassword(const ABL_String &p_userName, const ABL_String &p_oldPassword, const ABL_String &p_newPassword);
#	void mb_flushCache();			
#	void mb_unitTest();		
#	void mb_recreateConnection(ABL_Service &p_ABL_Service,ABL_String p_dbString = "");
======================================================================
#	Libraries:
*********************************************************************/
#ifdef ABL_UNIT_TEST
class ABL_Connection  : public ABL_UnitTest
#else
class ABL_Connection  
#endif
{
public:
	//##ModelId=4246A837014A
	ABL_Connection();				// Default constructor		
	//##ModelId=4246A837014B
	virtual ~ABL_Connection();		// Default destructor		
	// Create a connection using the connection details in  ABL_Service object, by default AutoCommit is off

	bool mb_createConnection(ABL_Service &p_ABL_Service, bool p_bautoCommit = false, bool p_timeout = false, ABL_String p_dbString = "");
	// Attaches a Statement (Query) to a connection for execution

	ABL_Statement mb_createStatement(const ABL_String &p_statementString = "");
	// detaches the Statement (Query) attached to a connection

	bool mb_ping();		//Makes a round trip call to the server to confirm that the connection and the server are active.

	void mb_terminateStatement(ABL_Statement& p_ABL_Statement);

	void mb_commit();				// Commits the Database transactions for the connection

	void mb_rollback();				// Rollsback the Database transactions for the connection
	// Change the password for a connection
	void mb_changePassword(const ABL_String &p_userName, const ABL_String &p_oldPassword, const ABL_String &p_newPassword);

	void mb_flushCache();			// Flushes the Object cache, so that the dirtied Objects are refreshed in Database
	//CHANGES FOR RECONNECT
	void mb_recreateConnection(ABL_Service &p_ABL_Service,ABL_String p_dbString = "");

#ifdef ABL_UNIT_TEST
	void mb_unitTest();		// perform unit testing
#endif

private:
	ABL_ConnectionBase *m_ABL_ConnectionBasePtr;
};

#endif 

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
