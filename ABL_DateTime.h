// Definition of the ABL_DateTime class

#ifndef ABL_DATETIME_H
#define ABL_DATETIME_H

#include "GlobalData.h"
#include "ABL_Date.h"
class ABL_DbDate;
class ABL_String;

#ifdef ABL_UNIT_TEST
#include "ABL_UnitTest.h"
/*********************************************************************
#	File		:	ABL_DateTime.h
#	Abstract	:	Abstraction for a DateTime type in Database
#	Date		:	20th Dec, 2005
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	177 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Amjath Khan.S	21st Dec, 2006	Standardization of the file
#											contents
#	2		Nishant Shekhar 23rd Feb, 2006	made some functions inline
======================================================================
#	Base Class	:	ABL_Base
======================================================================
#	member 
#	Variables	:	
#
#	_int64 m_lljulianDayTime;
======================================================================
#	member 
#	Functions	:
#
#	ABL_DateTime(const ABL_DateTime &p_ABL_DateTime);				
#	ABL_DateTime(char *p_cDatePtr,DATE_FMT p_fmt=YYYYMMDDHH24MISS);	
#	ABL_DateTime(_int64 p_lljulianDayTime);							
#	ABL_DateTime(int p_iyear = 1,int p_imonth = 1,int p_iday = 1, int p_ihour = 0,int p_iminute = 0,int p_isecond = 0);
#	ABL_DateTime(const ABL_Date& p_ABL_Date);		
#	ABL_DateTime(const ABL_DbDate &p_ABL_DbDate);
#	~ABL_DateTime();												
#	ABL_DateTime& operator=(const ABL_DateTime p_ABL_DateTime);		
#	ABL_DateTime& operator=(char* p_cDatePtr);						
#	ABL_DateTime& operator=(_int64 p_lljulianDayTime);				
#	ABL_DateTime& operator=(const ABL_Date p_ABL_Date);				
#	ABL_DateTime& operator=(const ABL_DbDate p_ABL_DbDate);			
#	ABL_DateTime& operator=(const ABL_String p_ABL_String);			
#	bool operator==(const ABL_DateTime &p_ABL_DateTime);			
#	bool operator>(const ABL_DateTime &p_ABL_DateTime);				
#	bool operator<(const ABL_DateTime &p_ABL_DateTime);				
#	bool operator!=(const ABL_DateTime &p_ABL_DateTime);			
#	bool operator>=(const ABL_DateTime &p_ABL_DateTime);			
#	bool operator<=(const ABL_DateTime &p_ABL_DateTime);			
#	void operator+=(const int p_idays);								
#	ABL_DateTime operator+(const int p_idays);						
#	_int64 mb_toJulianDateTime(st_datetime &p_stDateTimePtr);
#	_int64 mb_toJulianDateTime(int p_iyear,int p_imonth,int p_iday,int p_ihour,int p_iminute,int p_isecond);
#	void mb_toDateTime(int &p_iyear,int &p_imonth,int &p_iday, int &p_ihour,int &p_iminute,int &p_isecond);
#	void mb_toDateTime(st_datetime &p_stDateTimePtr);				
#	void mb_fromText(char *p_cDatePtr="",DATE_FMT p_fmt= YYYYMMDDHH24MISS);
#	void mb_fromSysDate();											
#	const char* mb_toCharText(DATE_FMT p_fmt= YYYYMMDDHH24MISS);	
#	ABL_String mb_toString(DATE_FMT p_fmt= YYYYMMDDHH24MISS);		
#	oracle::occi::Date mb_toOcciDate();								
#	bool mb_validate(st_datetime &p_stDateTimePtr);					
#	bool mb_validate(char *p_cDatePtr,DATE_FMT p_fmt= YYYYMMDDHH24MISS);
#	_int64 mb_dateTimeDiff(char *p_cDate1Ptr, char *p_cDate2Ptr);	
#	_int64 mb_addDays(int p_idays);									
#	_int64 mb_addMonths(int p_imonths);								
#	_int64 mb_addHours(int p_ihours);								
#	_int64 mb_addMinutes(int p_iminutes);							
#	_int64 mb_addSeconds(int p_iseconds);							
#	int mb_isLeapYear(st_datetime &p_stDateTimePtr);				
#	int mb_daysInMonth(st_datetime &p_stDateTimePtr);				
#	ABL_DateTime();													
#	void mb_unitTest();												
======================================================================
#	Libraries:
*********************************************************************/

//##ModelId=4246A83602DE
class ABL_DateTime : public ABL_UnitTest
#else
class ABL_DateTime
#endif
{
public:

	//##ModelId=4246A83602F0
	ABL_DateTime(const ABL_DateTime &p_ABL_DateTime);				// Copy Constructor
	
	//##ModelId=4246A83602F2
	ABL_DateTime(const ABL_Date& p_ABL_Date);							//Constructor accepting ABL_Date object
	//##ModelId=4246A83602F4
	ABL_DateTime(const ABL_DbDate &p_ABL_DbDate);						// Constructor accepting ABL_DbDate object	
	
	//##ModelId=4246A83602FD
	ABL_DateTime(const char *p_cDatePtr,DATE_FMT p_fmt=YYYYMMDDHH24MISS);	// Constructor with char string and format specifier
	//##ModelId=4246A8360300
	ABL_DateTime(_int64 p_lljulianDayTime);							// Constructor with JulianDayTime value
#ifndef ABL_UNIT_TEST
	// Constructor with year, month, day, hour, minute and second passed as parameters
	//##ModelId=4246A8360302
	ABL_DateTime(int p_iyear = 1,int p_imonth = 1,int p_iday = 1, int p_ihour = 0,int p_iminute = 0,int p_isecond = 0);
#else
	// Constructor with year, month, day, hour, minute and second passed as parameters
	ABL_DateTime(int p_iyear,int p_imonth,int p_iday, int p_ihour,int p_iminute,int p_isecond );
#endif
	//##ModelId=4246A8360311
	~ABL_DateTime();												// Destructor

	// Overloaded = operator for assigning an ABL_DateTime object
	//##ModelId=4246A8360312
	inline ABL_DateTime& operator=(const ABL_DateTime p_ABL_DateTime) { m_lljulianDayTime = p_ABL_DateTime.m_lljulianDayTime; return *this; } 		
	// Overloaded = operator for assigning a char string
	//##ModelId=4246A8360314
	inline ABL_DateTime& operator=(const char* p_cDatePtr) { this->mb_fromText(p_cDatePtr,YYYYMMDDHH24MISS); return *this; }
	// Overloaded = operator for assigning a JulianDaytime value
	//##ModelId=4246A836031D
	inline ABL_DateTime& operator=(_int64 p_lljulianDayTime) {	m_lljulianDayTime = p_lljulianDayTime; return *this; }
	// Overloaded = operator for assigning an ABL_Date object	
	//##ModelId=4246A836031F
	inline ABL_DateTime& operator=(const ABL_Date p_ABL_Date) { m_lljulianDayTime = (_int64)p_ABL_Date.m_ljulianDay*TIME_MULTIPLIER; return *this;	}
	//##ModelId=4246A8360321
	ABL_DateTime& operator=(const ABL_DbDate p_ABL_DbDate);			// Overloaded = operator for assigning an ABL_DbDate object
	//##ModelId=4246A836032C
	ABL_DateTime& operator=(const ABL_String p_ABL_String);			// Overloaded = operator for assigning an ABL_String data

	// Overloaded == operator for comparing with an ABL_DateTime object
	//##ModelId=4246A836032E
	inline bool operator==(const ABL_DateTime &p_ABL_DateTime) const { return(this->m_lljulianDayTime == p_ABL_DateTime.m_lljulianDayTime); }
	// Overloaded > operator for comparing with an ABL_DateTime object
	//##ModelId=4246A8360331
	inline bool operator>(const ABL_DateTime &p_ABL_DateTime) const { return(this->m_lljulianDayTime > p_ABL_DateTime.m_lljulianDayTime); }				
	// Overloaded < operator for comparing with an ABL_DateTime object
	//##ModelId=4246A836033C
	inline bool operator<(const ABL_DateTime &p_ABL_DateTime) const { return(this->m_lljulianDayTime < p_ABL_DateTime.m_lljulianDayTime); }				
	// Overloaded != operator for comparing with an ABL_DateTime object
	//##ModelId=4246A836033F
	inline bool operator!=(const ABL_DateTime &p_ABL_DateTime) const { return(this->m_lljulianDayTime != p_ABL_DateTime.m_lljulianDayTime); }			
	// Overloaded >= operator for comparing with an ABL_DateTime object
	//##ModelId=4246A8360342
	inline bool operator>=(const ABL_DateTime &p_ABL_DateTime) const { return(this->m_lljulianDayTime >= p_ABL_DateTime.m_lljulianDayTime); }			
	// Overloaded <= operator for comparing with an ABL_DateTime object
	//##ModelId=4246A8360345
	inline bool operator<=(const ABL_DateTime &p_ABL_DateTime) const { return(this->m_lljulianDayTime <= p_ABL_DateTime.m_lljulianDayTime); }			
	// Overloaded += operator for adding n Days
	//##ModelId=4246A836034D
	inline void operator+=(const int p_idays) { m_lljulianDayTime += ((_int64)p_idays*(_int64)TIME_MULTIPLIER); }		
	// Overloaded + operator for adding n Days
	//##ModelId=4246A836034F
	inline ABL_DateTime operator+(const int p_idays) { return (ABL_DateTime(m_lljulianDayTime + ((_int64)p_idays * (_int64)TIME_MULTIPLIER))); }
	
	//##ModelId=4246A8360351
	_int64 mb_toJulianDateTime(st_datetime &p_stDateTimePtr);		// Returns the juliandatetime value for the datetime passed as structure
	// Returns the juliandatetime value for the date and time value passed as paramters
	//##ModelId=4246A836035C
	_int64 mb_toJulianDateTime(int p_iyear,int p_imonth,int p_iday,int p_ihour,int p_iminute,int p_isecond);
	// Initializes the ABL_DateTime object with the date and time value passed as paramters
	//##ModelId=4246A8360363
	void mb_toDateTime(int &p_iyear,int &p_imonth,int &p_iday, int &p_ihour,int &p_iminute,int &p_isecond) const;
	//##ModelId=4246A8360372
	void mb_toDateTime(st_datetime &p_stDateTimePtr) const;				// Initializes the ABL_DateTime object with the datetime passed as structure
	// Initializes the ABL_DateTime object with the datetime passed as char string in the format specified
	//##ModelId=4246A836037B
	void mb_fromText(const char *p_cDatePtr="",DATE_FMT p_fmt= YYYYMMDDHH24MISS);
	//##ModelId=4246A836037E
	void mb_fromSysDate();											// Initializes the ABL_DateTime object with current date time
	//##ModelId=4246A836037F
	const char* mb_toCharText(DATE_FMT p_fmt= YYYYMMDDHH24MISS) const;	// Formats the date time as per the format specified and returns as char string
	//##ModelId=4246A836038B
	ABL_String mb_toString(DATE_FMT p_fmt= YYYYMMDDHH24MISS) const;		// Formats the date time as per the format specified and returns as ABL_String
	//##ModelId=4246A836038E
//	oracle::occi::Date mb_toOcciDate() const;								// Converts the date time into OCCI Date object and returns
	//##ModelId=4246A8360390
	static bool mb_validate(st_datetime &p_stDateTimePtr);					// Validates the date and time given as structure data
	// Validates the date and time given as char string in the format specified
	//##ModelId=4246A8360399
	static bool mb_validate(char *p_cDatePtr,DATE_FMT p_fmt= YYYYMMDDHH24MISS);
	//##ModelId=4246A836039D
	static _int64 mb_dateTimeDiff(char *p_cDate1Ptr, char *p_cDate2Ptr);	// Returns the julian date time value difference two date times given as char strings
	//##ModelId=4246A83603A1
	_int64 mb_addDays(int p_idays);									// Returns the julian date time value after adding specified days
	//##ModelId=4246A83603AA
	_int64 mb_addMonths(int p_imonths);								// Returns the julian date time value after adding specified months
	//##ModelId=4246A83603AC
	_int64 mb_addHours(int p_ihours);								// Returns the julian date time value after adding specified hours
	//##ModelId=4246A83603AE
	_int64 mb_addMinutes(int p_iminutes);							// Returns the julian date time value after adding specified minutes
	//##ModelId=4246A83603BA
	_int64 mb_addSeconds(_int64 p_iseconds);						// Returns the julian date time value after adding specified seconds	
	//##ModelId=4246A83603BC
	static int mb_isLeapYear(st_datetime &p_stDateTimePtr);				// Checks if the year of the date time structure is leap year or not
	//##ModelId=4246A83603BF
	static int mb_daysInMonth(st_datetime &p_stDateTimePtr);				// Returns the number of days in the month of the date time structure 
	//##ModelId=4246A83603C9
	inline _int64 mb_getJulianDateTime() const { return m_lljulianDayTime; }	//returns julian date
	inline unsigned short mb_getDayOfWeek() const {return (unsigned short)((m_lljulianDayTime/TIME_MULTIPLIER)%7)+1;};
#ifdef ABL_UNIT_TEST
	//##ModelId=4246A83603CB
	ABL_DateTime();													// Default constructor for unit testing
	//##ModelId=4246A83603CC
	void mb_unitTest();												// Function for unit testing
#endif

private:
	//##ModelId=4246A83603CE
	_int64 m_lljulianDayTime;		// To store the Julian Day Time value 	
protected:
	friend class ABL_DbDate;
	friend class ABL_Date;
};
inline std::ostream& operator<<(std::ostream& p_ostream,const ABL_DateTime &p_ABL_DateTime ) {char l_Str[20]; strcpy(l_Str, p_ABL_DateTime.mb_toCharText()); p_ostream<<l_Str; return p_ostream; }
#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
