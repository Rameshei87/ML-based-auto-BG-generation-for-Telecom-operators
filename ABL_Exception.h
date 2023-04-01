// Definition of the ABL_Exception class

#ifndef ABL_EXCEPTION_H 
#define ABL_EXCEPTION_H

#include <exception>

#include "GlobalData.h"

/*********************************************************************
#	File		:	ABL_Exception.h
#	Abstract	:	Implementation to capture various exceptions that
#					can be generated in the system
#	Date		:	21st Feb, 2006
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	77 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Amjath Khan.S	20th Dec, 2006	Standardization of the file
#											contents
======================================================================
#	Base Class	:	none
======================================================================
#	member 
#	Variables	:	
#	int			m_ierrorCode;
#	int			m_idbErrorCode;
#	std::string m_errorString;
#	std::string m_dbErrorString;
======================================================================
#	member 
#	Functions	:
#
#	ABL_Exception( int p_ierrorCode = 0, std::string p_errorString = "" );
#	ABL_Exception( const OCIError &p_OCIError );
#	ABL_Exception( const ABL_Exception &p_ABL_Exception );
#	virtual ~ABL_Exception();
#	int		mb_getErrorCode();
#	int		mb_getDBErrorCode();
#	const char* mb_what();
#	std::string	mb_getMessage();
======================================================================
#	Libraries:
*********************************************************************/
//##ModelId=4246A8360167
class ABL_Exception : public std::exception
{
public:
	//##ModelId=4246A8360178
	ABL_Exception( int p_ierrorCode = 0, std::string p_errorString = "" );
	ABL_Exception( int p_ierrorCode, std::string filename, int lineno, std::string p_errorString);
	//##ModelId=4246A836017D
	ABL_Exception( const ABL_Exception &p_ABL_Exception );
	//##ModelId=4246A8360187
	virtual ~ABL_Exception() throw();
	
	//##ModelId=4246A8360189
	int			mb_getErrorCode();
	//##ModelId=4246A836018A
	int			mb_getDBErrorCode();
	//##ModelId=4246A836018B
    const char* what();
	//##ModelId=4246A836018C
	std::string	mb_getMessage();	

protected:
	//##ModelId=4246A836018D
	int			m_ierrorCode;
	//##ModelId=4246A8360196
	int			m_idbErrorCode;
	//##ModelId=4246A8360198
	std::string m_errorString;
	//##ModelId=4246A83601A6
	std::string m_dbErrorString;
};

#endif // ABL_EXCEPTION_H

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
