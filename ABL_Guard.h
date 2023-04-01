// Definition of the ABL_Guard class

#ifndef ABL_GUARD_H
#define ABL_GUARD_H

#include "GlobalData.h"

/*********************************************************************
#	File		:	ABL_Guard.h
#	Abstract	:	Implementation of mutex
#	Date		:	28th Feb, 2007
#	Author(s)	:	Dinabandhu Mitra
#	Code Size	:	61 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	Base Class	:	none
======================================================================
#	member 
#	Variables	:	

#	T& m_lockObject
======================================================================
#	member 
#	Functions	:

#	ABL_Guard();
#	virtual ~ABL_Guard();
======================================================================
Libraries:
**********************************************************************/

//##ModelId=4246AD71031C
template <class T, class R, R (T::*p_lockerFuncPtr)(),R (T::*p_unlockerFuncPtr)()>
class ABL_Guard
{
public:
	//##ModelId=4246AD71032E
        ABL_Guard(T &p_lockObject):m_lockObject(p_lockObject)
        {
                (m_lockObject.*p_lockerFuncPtr)();
        }
	//##ModelId=4246AD710330
        ~ABL_Guard()
        {
                (m_lockObject.*p_unlockerFuncPtr)();
        }
private:
	//##ModelId=4246AD710331
        T& m_lockObject;
};

#endif // ABL_GUARD_H

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
