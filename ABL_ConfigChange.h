// Definition of the ABL_CONFIGCHANGE_H class
#ifndef ABL_CONFIGCHANGE_H
#define ABL_CONFIGCHANGE_H


/*********************************************************************
#	File		:	ABL_ConfigChange.h
#	Abstract	:	Notification class
#	Date		:	10th Oct, 2007
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	48 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
======================================================================
#	Base Class	:	
======================================================================
#	member 
#	Variables	:	
======================================================================
#	member 
#	Functions	:

======================================================================
#	Libraries:
*********************************************************************/
class ABL_ConfigChange
{
public:
	ABL_ConfigChange() {}
	virtual ~ABL_ConfigChange() {}
	virtual void mb_notify() = 0;
};

#endif  //ABL_CONFIGCHANGE_H

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
