// Definition of the ABL_RWLock class

#ifndef ABL_RWLOCK_H
#define ABL_RWLOCK_H

#include "GlobalData.h"
#include "ABL_Guard.h"

#ifdef ABL_UNIT_TEST
#include "ABL_UnitTest.h"
/*********************************************************************
#	File		:	ABL_RWLock.h
#	Abstract	:	Implementation of Read Write Lock
#	Date		:	26th Feb, 2007
#	Author(s)	:	Amjath Khan
#	Code Size	:	77 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Amjath Khan.S	28th Feb, 2007  Adding details for Guard Class
======================================================================
#	Base Class	:	none
======================================================================
#	member 
#	Variables	:	

#	pthread_rwlock_t m_rwmutex;
======================================================================
#	member 
#	Functions	:

#	ABL_RWLock();
#	virtual ~ABL_RWLock();
#	bool mb_init();
#	bool mb_destroy();
#	bool mb_lockToRead();	
#	bool mb_tryLockToRead();
#	bool mb_lockToWrite();	
#	bool mb_tryLockToWrite();
#	bool mb_unlock();
======================================================================
Libraries:
**********************************************************************/

//##ModelId=4246AD7003B9
class ABL_RWLock  : public ABL_UnitTest
#else
class ABL_RWLock
#endif
{
public:
	//##ModelId=4246AD7003C9
	ABL_RWLock();			// Default constructor
	//##ModelId=4246AD7003CA
	virtual ~ABL_RWLock();	// Default destructor
	
	//##ModelId=4246AD7003CC
	bool mb_init();			// Initialise a read write lock variable
	//##ModelId=4246AD7003CD
	bool mb_destroy();		// Destroy a read write lock variable
	//##ModelId=4246AD7003D8
	bool mb_lockToRead();	// Try to lock a read write lock for reading and wait till read write lock is acquired
	//##ModelId=4246AD7003D9
	bool mb_tryLockToRead();// Try to lock a read write lock for reading and return if not available
	//##ModelId=4246AD7003DA
	bool mb_lockToWrite();	// Try to lock a read write lock for writing and wait till read write lock is acquired
	//##ModelId=4246AD7003DB
	bool mb_tryLockToWrite();// Try to lock a read write lock for writing and return if not available
	//##ModelId=4246AD7003DC
	bool mb_unlock();		// Unlock the read write lock
#ifdef ABL_UNIT_TEST
	//##ModelId=4246AD7003DD
	void mb_unitTest() ;	// Perform unit testing	
#endif
private:
	//##ModelId=4246AD710001
	pthread_rwlock_t m_rwmutex;// read write lock variable	
};

//##ModelId=4246AD710005
typedef ABL_Guard<ABL_RWLock,bool,&ABL_RWLock::mb_lockToRead,&ABL_RWLock::mb_unlock> ABL_ReadGuard; // Guard Class for Read Lock
//##ModelId=4246AD710010
typedef ABL_Guard<ABL_RWLock,bool,&ABL_RWLock::mb_lockToWrite,&ABL_RWLock::mb_unlock> ABL_WriteGuard; // Guard Class for Write Guard

#endif // ABL_RWLock_H

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
