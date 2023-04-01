// Definition of the ABL_Mutex class

#ifndef ABL_MUTEX_H
#define ABL_MUTEX_H

#include "GlobalData.h"
#include "ABL_Guard.h"

#ifdef ABL_UNIT_TEST
#include "ABL_UnitTest.h"
/*********************************************************************
#	File		:	ABL_Mutex.h
#	Abstract	:	Implementation of mutex
#	Date		:	19th July, 2006
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	76 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Amjath Khan.S	23rd Dec, 2006	Standardization of the file
#											contents
#	2		Amjath Khan.S	28th Feb, 2007  Adding details for Guard Class
#	3		Nishant Shekhar 13th Apr, 2007	added support for spin lock
======================================================================
#	Base Class	:	none
======================================================================
#	member 
#	Variables	:	

#	pthread_mutex_t m_mutex;
======================================================================
#	member 
#	Functions	:

#	ABL_Mutex(bool p_benableSpinLock = false);
#	virtual ~ABL_Mutex();
#	bool mb_init(bool p_benableSpinLock = false);
#	bool mb_destroy();
#	bool mb_lock();
#	bool mb_trylock();
#	bool mb_unlock();
======================================================================
Libraries:
**********************************************************************/
//##ModelId=4246A836002E
class ABL_Mutex  : public ABL_UnitTest
#else
class ABL_Mutex
#endif
{
public:
	//##ModelId=4246A836003F
	ABL_Mutex(bool p_benableSpinLock = false);			// Default constructor
	//##ModelId=4246A8360040
	virtual ~ABL_Mutex();	// Default destructor
	
	//##ModelId=4246A8360042
	bool mb_init(bool p_benableSpinLock = false);			// Initialise a mutex variable
	//##ModelId=4246A8360043
	bool mb_destroy();		// Destroy a mutex variable
	//##ModelId=4246A836004E
	bool mb_lock();			// Try to lock a mutex and wait till mutex is acquired
	//##ModelId=4246A836004F
	bool mb_tryLock();		// Try to lock a mutex and return if not available
	//##ModelId=4246A8360050
	bool mb_unlock();		// Unlock the mutex

#ifdef ABL_UNIT_TEST
	//##ModelId=4246A8360051
	void mb_unitTest() ;	// Perform unit testing	
#endif
private:
	//##ModelId=4246A8360053
	pthread_mutex_t m_mutex;// mutex variable	
};
// Guard Class For ABL_Mutex
//##ModelId=4246A836005D
typedef ABL_Guard<ABL_Mutex,bool,&ABL_Mutex::mb_lock,&ABL_Mutex::mb_unlock> ABL_MutexGuard;

#endif // ABL_MUTEX_H

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
