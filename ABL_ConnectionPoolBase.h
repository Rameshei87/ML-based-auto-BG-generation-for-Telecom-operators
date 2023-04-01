// ABL_Service.h: interface for the ABL_Service class.
//
//////////////////////////////////////////////////////////////////////
#ifndef ABL_CONNECTIONPOOL_BASE_H
#define ABL_CONNECTIONPOOL_BASE_H

#include "ABL_String.h"
class ABL_ConnectionBase;

//class to hold a specific database connection pool
class ABL_ConnectionPoolBase
{
public:
	ABL_ConnectionPoolBase(){}
	virtual ~ABL_ConnectionPoolBase(){}
	virtual bool mb_create(const ABL_String &p_userName, const ABL_String &p_passWord, const ABL_String p_connectString = "", unsigned int p_iminConnections =0, unsigned int p_imaxConnections =1, ABL_String p_dbString = "", ABL_String p_hostname = "",unsigned int p_port=0) = 0;
	//CHANGES FOR RECONNECT
	virtual ABL_ConnectionBase* mb_getConnection(bool p_timeout) = 0;	
	// Function will return a connection to the connection pool of the specified connectivity
	virtual bool mb_returnConnection(ABL_ConnectionBase *p_connectionPtr) = 0;
	//CHANGES FOR RECONNECT
	virtual void mb_reConnect(int l_connectionseq) = 0;
	int m_iconnectionSequence;
};

#endif // ABL_CONNECTIONPOOL_BASE_H
