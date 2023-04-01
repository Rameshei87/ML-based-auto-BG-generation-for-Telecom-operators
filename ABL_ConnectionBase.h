// ABL_ConnectionBase.h: interface for the ABL_ConnectionBase class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ABL_CONNECTIONBASE_H
#define ABL_CONNECTIONBASE_H

#include "ABL_String.h"

class ABL_ConnectionPoolBase;
class ABL_StatementBase;
class ABL_Service;

class ABL_ConnectionBase
{
public:
	ABL_ConnectionBase() { };
	virtual ~ABL_ConnectionBase(){ };	
	virtual ABL_StatementBase* mb_createStatement(const ABL_String &p_statementString = "") = 0;
	virtual void mb_terminateStatement(ABL_StatementBase* p_ABL_Statement) = 0;
	virtual bool mb_ping() = 0;
	virtual void mb_commit() = 0;
	virtual void mb_rollback() = 0;
	virtual void mb_changePassword(const ABL_String &p_userName, const ABL_String &p_oldPassword, const ABL_String &p_newPassword) = 0;
	virtual void mb_flushCache() = 0;
	virtual void mb_setAutoCommit(bool p_bautoCommit) = 0;
	//CHANGES FOR RECONNECT
	int m_iconnectionSequence;
};

#endif 

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
