// Definition of the ABL_Date class

#ifndef ABL_DATE_H
#define ABL_DATE_H

#include "GlobalData.h"
#include "ABL_UnitTest.h"
#include <cstring>
class ABL_DateTime;
class ABL_DbDate;
class ABL_String;

#ifdef ABL_UNIT_TEST
//#include "ABL_UnitTest.h"
/*********************************************************************
#	File		:	ABL_Date.h
#	Abstract	:	Implementation of a Date datatype
#	Date		:	8th August, 2006
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	214 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Amjath Khan.S	22nd Dec, 2006	Standardization of the file
#											contents
#	2		Nishant Shekhar 23rd Feb, 2006	made some functions inline
#	3		Nishant Shekhar 15th Mar, 2006	added constructors accepting 
											Dbdate and DateTime objects and
											added interface for get juliandate
======================================================================
#	Base Class	:	ABL_Base
======================================================================
#	member 
#	Variables	:	
#
#	long m_ljulianDay;		
======================================================================
#	member 
#	Functions	:
#
#	ABL_Date(const ABL_Date& p_ABL_Date);
#	ABL_Date(const ABL_DbDate &p_ABL_DbDate);
#	ABL_Date(const ABL_DateTime &p_ABL_DateTime);
#	ABL_Date(char *p_cDatePtr);
#	ABL_Date(long p_ljulianDay) {m_ljulianDay = p_ljulianDay;}
#	ABL_Date(int p_iyear = 1,int p_imonth = 1,int p_day_n = 1);
#	~ABL_Date();
#	inline ABL_Date& operator=(const ABL_Date p_ABL_Date);
#	inline ABL_Date& operator=(char* p_cDatePtr);
#	inline ABL_Date& operator=(long p_ljulianDay);
#	ABL_Date& operator=(const ABL_DateTime p_ABL_DateTime);
#	ABL_Date& operator=(const ABL_DbDate p_ABL_DbDate);
#	inline bool operator == (const ABL_Date &p_ABL_Date) const ;
#	inline bool operator >  (const ABL_Date &p_ABL_Date) const ;
#	inline bool operator <  (const ABL_Date &p_ABL_Date) const ;
#	inline bool operator != (const ABL_Date &p_ABL_Date) const ;
#	inline bool operator >= (const ABL_Date &p_ABL_Date) const ;
#	inline bool operator <= (const ABL_Date &p_ABL_Date) const ;
#	inline void operator += (const int p_idays_n);
#	ABL_Date operator+(const int p_idays_n); 
#	long mb_YMDtoJday(st_date &p_stdatePtr);
#	long mb_YMDtoJday(int p_iyear,int p_imonth,int p_day_n);
#	void mb_JdaytoYMD(int &p_iyear,int &p_imonth,int &p_day_n);
#	void mb_JdaytoYMD(st_date &p_stdatePtr);
#	void mb_fromText(char *p_cDatePtr);
#	void mb_fromSysDate();
#	const char* mb_toCharText(ABL_DATE_FMT p_fmt=YYYYMMDD) const;
#	ABL_String mb_toString(ABL_DATE_FMT p_fmt=YYYYMMDD) const;
#	oracle::occi::Date mb_toOcciDate()const ;
#	static bool mb_validate(st_date &p_stdatePtr);
#	static bool mb_validate(char *p_cDatePtr);
#	static long mb_dateDiff(char *p_cDatePtrOne, char *p_cDatePtrTwo);
#	long mb_addDays(int p_idays); 
#	long mb_addMonths(int p_imonths);
#	static int mb_isLeapYear(st_date &p_stdatePtr);
#	static int mb_daysInMonth(st_date &p_stdatePtr);
#	long mb_getJulianDate();
======================================================================
#	Libraries:
*********************************************************************/

//##ModelId=4246A837005D
class ABL_Date : public ABL_UnitTest
#else
class ABL_Date
#endif
{
public:
#ifdef ABL_UNIT_TEST
	//##ModelId=4246A8370060
	ABL_Date();													// Default constructor
#endif
	//##ModelId=4246A8370061
	ABL_Date(const ABL_Date& p_ABL_Date);						// Copy constructor
	//##ModelId=4246A837006D
	ABL_Date(const ABL_DbDate &p_ABL_DbDate);					// Constructor accepting ABL_DbDate object	
	//##ModelId=4246A837006F
	ABL_Date(const ABL_DateTime &p_ABL_DateTime);				// Constructor accepting ABL_DateTime object

	//##ModelId=4246A8370071
	ABL_Date(char *p_cDatePtr);									// Constructor with a char string as parameter
	//##ModelId=4246A8370073
	ABL_Date(long p_ljulianDay) {m_ljulianDay = p_ljulianDay;}	// Constructor with a Julian Day value as parameter
#ifdef ABL_UNIT_TEST
	// To resolve constructor call in case of unit testing
	//##ModelId=4246A837007D
	ABL_Date(int p_iyear,int p_imonth ,int p_day_n );			// Constructor with day, month and date given as individual params
#else
	ABL_Date(int p_iyear = 1,int p_imonth = 1,int p_day_n = 1);	// Constructor with day, month and date given as individual params
#endif
	//##ModelId=4246A8370081
	~ABL_Date();												// Default destructor
	// Overloaded = operator for assigning ABL_Date Object
	//##ModelId=4246A8370082
	inline ABL_Date& operator=(const ABL_Date p_ABL_Date) { this->m_ljulianDay = p_ABL_Date.m_ljulianDay; return *this; }
	// Overloaded = operator for assigning a char string	
	//##ModelId=4246A8370084
	inline ABL_Date& operator=(char* p_cDatePtr) {	this->mb_fromText(p_cDatePtr); return *this; }
	// Overloaded = operator for assigning Julian Day value
	//##ModelId=4246A837008D
	inline ABL_Date& operator=(long p_ljulianDay){	this->m_ljulianDay = p_ljulianDay; return *this; }
	// Overloaded = operator for assigning ABL_DateTime Object
	//##ModelId=4246A837008F
	ABL_Date& operator=(const ABL_DateTime p_ABL_DateTime);
	
	//##ModelId=4246A8370091
	ABL_Date& operator=(const ABL_DbDate p_ABL_DbDate);			// Overloaded = operator for assigning ABL_DbDate Object
	// Overloaded == operator for comparing with an ABL_Date Object
	//##ModelId=4246A837009C
	inline bool operator == (const ABL_Date &p_ABL_Date) const {	return(this->m_ljulianDay == p_ABL_Date.m_ljulianDay) ; }
	// Overloaded > operator for comparing with an ABL_Date Object
	//##ModelId=4246A837009F
	inline bool operator >  (const ABL_Date &p_ABL_Date) const { return(this->m_ljulianDay > p_ABL_Date.m_ljulianDay) ;}
	// Overloaded < operator for comparing with an ABL_Date Object
	//##ModelId=4246A83700A2
	inline bool operator <  (const ABL_Date &p_ABL_Date) const { return(this->m_ljulianDay < p_ABL_Date.m_ljulianDay); }				
	// Overloaded != operator for comparing with an ABL_Date Object	
	//##ModelId=4246A83700AC
	inline bool operator != (const ABL_Date &p_ABL_Date) const { return(this->m_ljulianDay != p_ABL_Date.m_ljulianDay); }				
	// Overloaded >= operator for comparing with an ABL_Date Object
	//##ModelId=4246A83700AF
	inline bool operator >= (const ABL_Date &p_ABL_Date) const { return(this->m_ljulianDay >= p_ABL_Date.m_ljulianDay); }				
	// Overloaded <= operator for comparing with an ABL_Date Object
	//##ModelId=4246A83700B2
	inline bool operator <= (const ABL_Date &p_ABL_Date) const { return(this->m_ljulianDay <= p_ABL_Date.m_ljulianDay); } 				
	// Overloaded += operator for adding n days to an ABL_Date Object
	//##ModelId=4246A83700BD
	inline void operator += (const int p_idays_n) { m_ljulianDay += (long)p_idays_n; }						
	// Overloaded + operator for adding n days to an ABL_Date Object and create a new ABL_Date object
	//##ModelId=4246A83700BF
	ABL_Date operator+(const int p_idays_n) { return (ABL_Date(m_ljulianDay+(long)p_idays_n)); }						
			
	//##ModelId=4246A83700C1
	long mb_YMDtoJday(st_date &p_stdatePtr);					// Converts the date given in structure into julian day value and returns
	// Converts the date components given as individual params into julian day value and returns
	//##ModelId=4246A83700CC
	long mb_YMDtoJday(int p_iyear,int p_imonth,int p_day_n);
	//##ModelId=4246A83700D0
	void mb_JdaytoYMD(int &p_iyear,int &p_imonth,int &p_day_n) const;	// Converts the julian day value into date components and returns
	//##ModelId=4246A83700DC
	void mb_JdaytoYMD(st_date &p_stdatePtr) const;					// Converts the julian day value into date structure and returns
	//##ModelId=4246A83700DF
	void mb_fromText(char *p_cDatePtr);							// Initializes the object with char string
	//##ModelId=4246A83700EB
	void mb_fromSysDate();										// Initializes the object with sysdate
	//##ModelId=4246A83700EC
	const char* mb_toCharText(ABL_DATE_FMT p_fmt=YYYYMMDD) const;		// Converts ABL_Date into char string in requested format
	//##ModelId=4246A83700EF
	ABL_String mb_toString(ABL_DATE_FMT p_fmt=YYYYMMDD) const;		// Converts ABL_Date into ABL_String in requested format
	//##ModelId=4246A83700FA
	//oracle::occi::Date mb_toOcciDate()const ;						// Converts ABL_Date into OCCI Date
	//##ModelId=4246A83700FC
	static bool mb_validate(st_date &p_stdatePtr);				// Validates the date given in the date structure
	//##ModelId=4246A83700FF
	static bool mb_validate(char *p_cDatePtr);					// Validates the date given in the char string
	//##ModelId=4246A8370109
	static long mb_dateDiff(char *p_cDatePtrOne, char *p_cDatePtrTwo);	// Find the days between 2 dates given as char strings
	// Adds n days to an ABL_Date object
	//##ModelId=4246A837010D
	long mb_addDays(int p_idays) { m_ljulianDay += p_idays; return m_ljulianDay;}
	//##ModelId=4246A837010F
	long mb_addMonths(int p_imonths);							// Adds n months to an ABL_Date object
	//##ModelId=4246A8370119
	static int mb_isLeapYear(st_date &p_stdatePtr);				// Checks if the year of the date given as date structure is leap year
	//##ModelId=4246A837011C
	static int mb_daysInMonth(st_date &p_stdatePtr);			// Find the number of days in the month of the dat structure

	//##ModelId=4246A837011F
	inline long mb_getJulianDate() const { return m_ljulianDay; }//returns julian date	
	inline unsigned short mb_getDayOfWeek() const {return (unsigned short)((m_ljulianDay%7)+1);};
#ifdef ABL_UNIT_TEST
	//##ModelId=4246A8370121
	void mb_unitTest();											// Unit test function
#endif

private:
	//##ModelId=4246A8370128
	long m_ljulianDay;		

protected:
	friend class ABL_DbDate;
	friend class ABL_DateTime;
};

inline std::ostream& operator<<(std::ostream& p_ostream,const ABL_Date &p_ABL_Date ) 
{
	char l_Str[20]; 
	strcpy(l_Str, p_ABL_Date.mb_toCharText()); 
	p_ostream<<l_Str;
	return p_ostream; 
}
#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
