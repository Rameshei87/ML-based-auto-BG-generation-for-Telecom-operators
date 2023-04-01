// ABL_ResultSet.h: interface for the ABL_ResultSet class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ABL_RESULTSET_H
#define ABL_RESULTSET_H


#include "GlobalData.h"
#include "ABL_stmtMetaData.h"
#include "ABL_ResultSetBase.h"
#include "ABL_SmartPointer.h"
#include "ABL_Blob.h"
#include "ABL_DbDate.h"
#include "ABL_String.h"


#ifdef ABL_UNIT_TEST1
#include "ABL_UnitTest.h"
/*********************************************************************
#	File		:	ABL_ResultSet.h
#	Abstract	:	class to hold the result of execution of a statement.
#	Date		:	2nd January, 2006
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	239 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Amjath Khan.S	26th Dec, 2006	Standardization of the file
#											contents
#	2		Nishant Shekhar	15th Mar, 2007	added overloaded operator for
											for binding _int64 with resultset
======================================================================
#	Base Class	:	none
======================================================================
#	member 
#	Variables	:	
#	OCIStmt *m_stmtPtr;	
#	OCIError *m_errorPtr;
#	OCISvcCtx *m_connectionPtr; 
#	int		m_ifetchCount;
#	int		m_ilistCount;
#	bool	m_bfetchdone;
#	bool	m_bfetchFlag;
#	std::vector<OCIDefine *> m_OCIDefinePtr;
#	std::vector<ABL_String_mapper*> m_vecstringMapper;
#	std::vector<ABL_int64_mapper*> m_vecint64Mapper;
#	std::vector<ABL_Blob_mapper*> m_vecBlobMapper;
#	std::vector<columnBuffer *> m_vecofColumnBinds;
======================================================================
#	member 
#	Functions	:
#
#	ABL_ResultSet();
#	ABL_ResultSet(const ABL_ResultSet& p_ablresultset);
#	virtual ~ABL_ResultSet();
#	ABL_ResultSet& operator =(const ABL_ResultSet &p_ABL_ResultSetPtr); 
#	ABL_ResultSet& operator <<(ABL_DbDate *p_ABL_DbDatePtr);
#	ABL_ResultSet& operator <<(int *p_integerPtr);
#	ABL_ResultSet& operator <<(float *p_floatPtr);
#	ABL_ResultSet& operator <<(ABL_String *p_stringPtr);
#	ABL_ResultSet& operator <<(long *p_longPtr);
#	ABL_ResultSet& operator <<(double *p_doublePtr);
#	ABL_ResultSet& operator <<(_int64 *p_int64Ptr);
#	ABL_ResultSet& operator <<(ABL_Blob *p_ABL_BlobPtr);
#	ABL_ResultSet& operator <<(unsigned int *p_uintegerPtr);
#	virtual int mb_fetch(); 
#	int		mb_getNumArrayRows();
#	void	mb_setBulkCount(int p_ibulkCount);
#	void	mb_setListCount(int p_ilistCount);
#	bool	mb_isNull(unsigned int p_icolumnIndex);
#	bool	mb_isTruncated(unsigned int p_iparamIndex);
#	void	mb_setErrorOnNull(unsigned int p_icolumnIndex,bool p_bcauseException);
#	std::vector<ABL_DATATYPE> mb_listColumnType();
#	ABL_stmtMetadata mb_getMetadata();
#	ABL_String mb_getString(unsigned int p_icolumnIndex);
#	int		   mb_getInt(unsigned int p_icolumnIndex);
#	float	   mb_getFloat(unsigned int p_icolumnIndex);
#	ABL_DbDate mb_getDate(unsigned int p_icolumnIndex);
#	double	   mb_getDouble(unsigned int p_icolumnIndex);
#	unsigned int mb_getUInt(unsigned int p_icolumnIndex);
#	_int64		mb_getInt64(unsigned int p_icolumnIndex);
#	ABL_Blob&   mb_getABL_Blob(unsigned int p_icolumnIndex);
#	ABL_ResultSet& operator >>(ABL_DbDate &p_ABL_DbDatePtr);
#	ABL_ResultSet& operator >>(int &p_integerPtr);
#	ABL_ResultSet& operator >>(float &p_floatPtr);
#	ABL_ResultSet& operator >>(ABL_String &p_stringPtr);
#	ABL_ResultSet& operator >>(double &p_doublePtr);
#	ABL_ResultSet& operator >>(_int64 &p_int64Ptr);
#	ABL_ResultSet& operator >>(ABL_Blob &p_ABL_BlobPtr);
#	ABL_ResultSet& operator >>(unsigned int &p_uintegerPtr);
#	void mb_unitTest();
#	bool	mb_initializeFetchBuffer();
#	bool	mb_reinitializeObject();	
======================================================================
#	Libraries:
*********************************************************************/

//##ModelId=4246A8350290
class ABL_ResultSet  : public ABL_UnitTest
#else
class ABL_ResultSet 
#endif
{
public:
	//##ModelId=4246A8350292
	ABL_ResultSet() : m_ABL_ResultSetBasePtr(NULL){}	// Default constructor
	//##ModelId=4246A8350293
	// Copy constructor
	ABL_ResultSet(const ABL_ResultSet& p_ablresultset): m_ABL_ResultSetBasePtr(p_ablresultset.m_ABL_ResultSetBasePtr) {}
	//##ModelId=4246A8350295
	virtual ~ABL_ResultSet()	// Default destructor
	{
		//delete m_ABL_ResultSetBasePtr;
	}
	// Overloaded = operator for assigning an ABL_ResultSet object
	//##ModelId=4246A835029F
	ABL_ResultSet& operator =(const ABL_ResultSet &p_ABL_ResultSetPtr)
	{
		m_ABL_ResultSetBasePtr = p_ABL_ResultSetPtr.m_ABL_ResultSetBasePtr;
		return *this;
	}
	// Overloaded << operator for binding an ABL_DbDate array to a fetched column
	//##ModelId=4246A83502A1
	ABL_ResultSet& operator <<(ABL_DbDate *p_ABL_DbDatePtr)
	{
		*m_ABL_ResultSetBasePtr << p_ABL_DbDatePtr;
		return *this;
	}
	// Overloaded << operator for binding an integer array to a fetched column
	//##ModelId=4246A83502A3
	ABL_ResultSet& operator <<(int *p_integerPtr)
	{
		*m_ABL_ResultSetBasePtr << p_integerPtr;
		return *this;	
	}
	// Overloaded << operator for binding a float array to a fetched column
	//##ModelId=4246A83502AF
	ABL_ResultSet& operator <<(float *p_floatPtr)
	{
		*m_ABL_ResultSetBasePtr << p_floatPtr;
		return *this;	
	}
	// Overloaded << operator for binding a string array to a fetched column
	//##ModelId=4246A83502B1
	ABL_ResultSet& operator <<(ABL_String *p_stringPtr)
	{
		*m_ABL_ResultSetBasePtr << p_stringPtr;
		return *this;	
	}
	// Overloaded << operator for binding a long array to a fetched column
	//##ModelId=4246A83502B3
	ABL_ResultSet& operator <<(long *p_longPtr)
	{
		*m_ABL_ResultSetBasePtr << p_longPtr;
		return *this;	
	}
	// Overloaded << operator for binding a double array to a fetched column
	//##ModelId=4246A83502B5
	ABL_ResultSet& operator <<(double *p_doublePtr)
	{
		*m_ABL_ResultSetBasePtr << p_doublePtr;
		return *this;	
	}
	// Overloaded << operator for binding a _int64 array to a fetched column
	//##ModelId=4246A83502C0
	ABL_ResultSet& operator <<(_int64 *p_int64Ptr)
	{
		*m_ABL_ResultSetBasePtr << p_int64Ptr;
		return *this;	
	}
	// Overloaded << operator for binding a ABL_Blob array to a fetched column
	ABL_ResultSet& operator <<(ABL_Blob *p_ABL_BlobPtr)
	{
		*m_ABL_ResultSetBasePtr << p_ABL_BlobPtr;
		return *this;	
	}
	// Overloaded << operator for binding a unsigned integer array to a fetched column
	ABL_ResultSet& operator <<(unsigned int *p_uintegerPtr)
	{
		*m_ABL_ResultSetBasePtr << p_uintegerPtr;
		return *this;	
	}
	//##ModelId=4246A83502C2
	virtual int mb_fetch() // Fetches the records and stores in the binded arrays
	{
		return m_ABL_ResultSetBasePtr->mb_fetch();
	}
	//##ModelId=4246A83502C4
	int		mb_getNumArrayRows() // Returns the number of rows fetched
	{
		return m_ABL_ResultSetBasePtr->mb_getNumArrayRows();
	}
	//##ModelId=4246A83502C5
	void	mb_setBulkCount(int p_ibulkCount) // Function to set the bulk count (rows)
	{
		m_ABL_ResultSetBasePtr->mb_setBulkCount(p_ibulkCount);
	}
	//##ModelId=4246A83502CE
	void	mb_setListCount(int p_ilistCount) // Function to set the column count	
	{
		m_ABL_ResultSetBasePtr->mb_setListCount(p_ilistCount);
	}
	// Function to check if a column value is NULL
	//##ModelId=4246A83502D0
	inline bool	mb_isNull(unsigned int p_iparamIndex) 
	{
		return m_ABL_ResultSetBasePtr->mb_isNull(p_iparamIndex);
	}
	// Function to check if a column value got truncated
	//##ModelId=4246A83502D2
	inline bool	mb_isTruncated(unsigned int p_iparamIndex)
	{
		return m_ABL_ResultSetBasePtr->mb_isTruncated(p_iparamIndex);
	}
	// Function to set whether an exception needs to be generated or not (for Null value fetched for a column)
	//##ModelId=4246A83502D4
	void	mb_setErrorOnNull(unsigned int p_icolumnIndex,bool p_bcauseException)
	{
		m_ABL_ResultSetBasePtr->mb_setErrorOnNull(p_icolumnIndex, p_bcauseException);
	}
	// Lists the column type of the columns in the resultset
	//##ModelId=4246A83502E0
	std::vector<ABL_DATATYPE> mb_listColumnType()
	{
		return m_ABL_ResultSetBasePtr->mb_listColumnType();
	}
	ABL_stmtMetadata mb_getMetadata()
	{
		ABL_stmtMetadata l_ABL_stmtMetadata;
		l_ABL_stmtMetadata.m_ABL_stmtMetadataBasePtr = m_ABL_ResultSetBasePtr->mb_getMetadata();
		return l_ABL_stmtMetadata;
	}
	//##ModelId=4246A83502E1
	ABL_String mb_getString(unsigned int p_icolumnIndex)	// Fetches a string from the column specified
	{
		return m_ABL_ResultSetBasePtr->mb_getString(p_icolumnIndex);
	}
	//##ModelId=4246A83502E3
	int		   mb_getInt(unsigned int p_icolumnIndex)		// Fetches an integer value from the column specified
	{
		return m_ABL_ResultSetBasePtr->mb_getInt(p_icolumnIndex);
	}
	//##ModelId=4246A83502EE
	float	   mb_getFloat(unsigned int p_icolumnIndex)	// Fetches a float value from the column specified
	{
		return m_ABL_ResultSetBasePtr->mb_getFloat(p_icolumnIndex);
	}	
	//##ModelId=4246A83502F0
	ABL_DbDate mb_getDate(unsigned int p_icolumnIndex)		// Fetches a date from the column specified
	{
		return m_ABL_ResultSetBasePtr->mb_getDate(p_icolumnIndex);
	}	
	//##ModelId=4246A83502F2
	double	   mb_getDouble(unsigned int p_icolumnIndex)	// Fetches a double value from the column specified
	{
		return m_ABL_ResultSetBasePtr->mb_getDouble(p_icolumnIndex);
	}	
	unsigned int mb_getUInt(unsigned int p_icolumnIndex)	// Fetches an unsigned integer value from the column specified
	{
		return m_ABL_ResultSetBasePtr->mb_getUInt(p_icolumnIndex);
	}
	_int64		mb_getInt64(unsigned int p_icolumnIndex)	// Fetches an integer64 value from the column specified
	{
		return m_ABL_ResultSetBasePtr->mb_getInt64(p_icolumnIndex);
	}
	ABL_Blob   mb_getABL_Blob(unsigned int p_icolumnIndex) // Fetches an ABL_Blob value from the column specified
	{
		return m_ABL_ResultSetBasePtr->mb_getABL_Blob(p_icolumnIndex);
	}
	// Overloaded >> operator for fetching row date value
	ABL_ResultSet& operator >>(ABL_DbDate &p_ABL_DbDatePtr)
	{
		*m_ABL_ResultSetBasePtr>> p_ABL_DbDatePtr;
		return *this;
	}
	// Overloaded >> operator for fetching row integer value
	ABL_ResultSet& operator >>(int &p_integerPtr)
	{
		*m_ABL_ResultSetBasePtr>> p_integerPtr;
		return *this;
	}
	// Overloaded >> operator for fetching row float value
	ABL_ResultSet& operator >>(float &p_floatPtr)
	{
		*m_ABL_ResultSetBasePtr>> p_floatPtr;
		return *this;
	}
	// Overloaded >> operator for fetching row ABL_String value
	ABL_ResultSet& operator >>(ABL_String &p_stringPtr)
	{
		*m_ABL_ResultSetBasePtr>> p_stringPtr;
		return *this;
	}
	// Overloaded >> operator for fetching row double value
	ABL_ResultSet& operator >>(double &p_doublePtr)
	{
		*m_ABL_ResultSetBasePtr>> p_doublePtr;
		return *this;
	}
	// Overloaded >> operator for fetching row int64 value
	ABL_ResultSet& operator >>(_int64 &p_int64Ptr)
	{
		*m_ABL_ResultSetBasePtr>> p_int64Ptr;
		return *this;
	}
	// Overloaded >> operator for fetching row ABL_Blob value
	ABL_ResultSet& operator >>(ABL_Blob &p_ABL_BlobPtr)
	{
		*m_ABL_ResultSetBasePtr>> p_ABL_BlobPtr;
		return *this;
	}
	// Overloaded >> operator for fetching row unsigned int value
	ABL_ResultSet& operator >>(unsigned int &p_uintegerPtr)
	{
		*m_ABL_ResultSetBasePtr>> p_uintegerPtr;
		return *this;
	}

#ifdef ABL_UNIT_TEST
	//##ModelId=4246A83502F4
	//void mb_unitTest();
#endif	
private:	
	ABL_SmartPointer<ABL_ResultSetBase> m_ABL_ResultSetBasePtr;
	friend class ABL_Statement;	
};
#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
