// Definition of the ABL_DbDate class

#ifndef ABL_DBDATE_H
#define ABL_DBDATE_H

#include "GlobalData.h"

class ABL_Date;
class ABL_DateTime;
class ABL_String;

struct st_DateTime;
#ifdef ABL_UNIT_TEST
#include "ABL_UnitTest.h"
/*********************************************************************
#	File		:	ABL_DbDate.h
#	Abstract	:	Abstraction for a Date type in Database
#	Date		:	20th Dec, 2005
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	145 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Nishant Shekhar	28th June, 2006	changed valuation for 
#											hour, min,sec (0-59)
#	2		Amjath Khan.S	20th Dec, 2006	Standardization of the file
#											contents
#	3		Nishant Shekhar	15th Mar, 2007	added constructors accepting
#											date and datetime objects
#	4		Nishant Shekhar	08th Aug, 2007	added mb_toDateTimeStruct to
#											convert date into st_DateTime 
#											structure 
======================================================================
#	Base Class	:	ABL_Base
======================================================================
#	member 
#	Variables	:	
#
#	unsigned char m_arrDbDate[7];
======================================================================
#	member 
#	Functions	:
#
#	ABL_DbDate();
#	ABL_DbDate(char *p_cDbDatePtr,DATE_FMT = YYYYMMDDHH24MISS);
#	ABL_DbDate(const ABL_DbDate &p_ABL_DbDate);
#	ABL_DbDate(const ABL_Date &p_ABL_Date);			
#	ABL_DbDate(const ABL_DateTime &p_ABL_DateTime);
#	~ABL_DbDate();
#	ABL_DbDate& operator=(const ABL_DbDate &p_ABL_DbDate);
#	ABL_DbDate& operator=(char *p_cDatePtr);
#	ABL_DbDate& operator=(ABL_Date &p_ABL_Date);
#	ABL_DbDate& operator=(ABL_DateTime &p_ABL_DateTime);
#	char* mb_toDbDate();
#	char* mb_toText(DATE_FMT = YYYYMMDDHH24MISS);
#	ABL_String mb_toString(DATE_FMT = YYYYMMDDHH24MISS);
#	void mb_fromDbDate(const unsigned char *p_cDbDatePtr);
#	void mb_fromText(char *p_cDate_ptr,DATE_FMT= YYYYMMDDHH24MISS);
#	oracle::occi::Date mb_toOcciDate();
#	bool mb_validate(const unsigned char *p_dbdate);
#	bool mb_isLeapYear(st_datetime &p_stDateTimePtr);
#	int mb_daysInMonth(st_datetime &p_stDateTimePtr);
#	void mb_fromOcciDate(oracle::occi::Date p_occiDate);
#	void mb_unitTest();
======================================================================
#	Libraries:
**********************************************************************/
//##ModelId=4246A83601D4
class ABL_DbDate  : public ABL_UnitTest
#else
class ABL_DbDate 
#endif
{
public:
	//##ModelId=4246A83601E5
	ABL_DbDate();													// Default constructor
	//##ModelId=4246A83601E6
	ABL_DbDate(char *p_cDbDatePtr,DATE_FMT = YYYYMMDDHH24MISS);		// Constructor with char data and format specifier
	//##ModelId=4246A83601E9
	ABL_DbDate(const ABL_DbDate &p_ABL_DbDate);						// Copy Constructor
	//##ModelId=4246A83601EB
	ABL_DbDate(const ABL_Date &p_ABL_Date);							// Constructor accepting ABL_Date object
	//##ModelId=4246A83601F5
	ABL_DbDate(const ABL_DateTime &p_ABL_DateTime);					// Constructor accepting ABL_DateTime object
	//##ModelId=4246A83601F7
	~ABL_DbDate();													// Destructor

	//##ModelId=4246A83601F8
	ABL_DbDate& operator=(const ABL_DbDate &p_ABL_DbDate);			// Overloaded = operator to assign an ABL_DbDate object
	//##ModelId=4246A83601FA
	ABL_DbDate& operator=(char *p_cDatePtr);						// Overloaded = operator to assign a char atring (having Date)
	//##ModelId=4246A8360204
	ABL_DbDate& operator=(ABL_Date &p_ABL_Date);					// Overloaded = operator to assign an ABL_Date object
	//##ModelId=4246A8360206
	ABL_DbDate& operator=(ABL_DateTime &p_ABL_DateTime);			// Overloaded = operator to assign an ABL_DateTime object
	//##ModelId=4246A8360208
	char* mb_toDbDate() const;											// Returns the DbDate value as char string
	//##ModelId=4246A836020A
	char* mb_toText(DATE_FMT = YYYYMMDDHH24MISS) const;					// Returns the DbDate value as char string using specified format
	//##ModelId=4246A8360215
	ABL_String mb_toString(DATE_FMT = YYYYMMDDHH24MISS) const;			// Returns the DbDate value as ABL_String using specified format	
	//##ModelId=4246A8360218
	void mb_toDateTimeStruct(st_DateTime &p_st_DateTime);
	void mb_fromDateTimeStruct(st_DateTime &p_st_DateTime);
	void mb_fromDbDate(const unsigned char *p_cDbDatePtr);			// Initialise the object with data from the char string
	//##ModelId=4246A836021A
	void mb_fromText(char *p_cDate_ptr,DATE_FMT= YYYYMMDDHH24MISS);	// Initialise the object with data from the char string in format specified
	
	//##ModelId=4246A8360224
	//oracle::occi::Date mb_toOcciDate() const;								// Convert the DbDate into occi date
	//##ModelId=4246A8360226
	static bool mb_validate(const unsigned char *p_dbdate);				// validate if the given char string is a valid DbDate
	//##ModelId=4246A8360229
	static bool mb_isLeapYear(st_datetime &p_stDateTimePtr);				// Check if the year of the given datetime is a leapyear
	//##ModelId=4246A8360233
	static int mb_daysInMonth(st_datetime &p_stDateTimePtr);				// Returns number of days in the month of the given datetime
	//##ModelId=4246A8360236
	//void mb_fromOcciDate(oracle::occi::Date p_occiDate);			// Initialises the object with an OCCI date

#ifdef ABL_UNIT_TEST
	//##ModelId=4246A8360238
	void mb_unitTest();												// performs unit test
#endif 	
	
private:
	//##ModelId=4246A8360242
	unsigned char m_arrDbDate[7];
	
protected:
	friend class ABL_Date;
	friend class ABL_DateTime;
};
inline std::ostream& operator<<(std::ostream& p_ostream,const ABL_DbDate &p_ABL_DbDate ) 
{
	char l_tmpStr[18]; 
	strcpy(l_tmpStr, p_ABL_DbDate.mb_toText()); 
	p_ostream<<l_tmpStr; 
	return p_ostream; 
}
#endif	// ABL_DBDATE_H

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
