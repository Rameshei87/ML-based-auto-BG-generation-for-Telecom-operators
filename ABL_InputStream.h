// Definition of the ABL_InputStream class

#ifndef ABL_INPUTSTREAM_H
#define ABL_INPUTSTREAM_H

#include "GlobalData.h"
#include "ABL_String.h"
class  CBaseStream;
class	ABL_DbDate;
class	ABL_Date;
class	ABL_DateTime;

#ifdef ABL_UNIT_TEST
#include "ABL_UnitTest.h"
/*********************************************************************
#	File		:	ABL_InputStream.h
#	Abstract	:	input stream for sending data to a socket
#	Date		:	22nd November, 2006
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	152 lines	
#	Design		:	
#	References	
#	Module		:	Stream Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Nishant Shekhar	29th Dec, 2006	Standardization of the file
#											contents
#	2		Nishant Shekhar	25th Jan, 2007	Added interface for streaming
#											ABL_String objects
#	3		Nishant Shekhar 15th Mar, 2007	added interface for streaming ABL_
											DbDate, ABL_DateTime and ABL_Date
======================================================================
#	Base Class	:	none
======================================================================
#	member 
#	Variables	:	
#	
#	int  m_idataChunkSize;
#	int  m_ifreeMemoryInChunk;
#	long m_ltotalDataBuffered;
#	char *m_writePtr;
#	std::vector<char *> m_vecOfBuffers;
======================================================================
#	member 
#	Functions	:
#	
#	ABL_InputStream(int p_idataChunkSize = 1024);				 
#   virtual ~ABL_InputStream();									 
#   virtual ABL_InputStream& operator<<(const char *);			 
#	virtual ABL_InputStream& operator<<(const unsigned char *);	 
#	virtual ABL_InputStream& operator<<(const signed char *);	 
#	virtual ABL_InputStream& operator<<(const short &);			 
#	virtual ABL_InputStream& operator<<(const unsigned short &); 
#	virtual ABL_InputStream& operator<<(const int &);			 
#	virtual ABL_InputStream& operator<<(const unsigned int &);	 
#	virtual ABL_InputStream& operator<<(const long &);			 
#	virtual ABL_InputStream& operator<<(const unsigned long &);	 
#	virtual ABL_InputStream& operator<<(const float &);			 
#	virtual ABL_InputStream& operator<<(const double &);		 
#	virtual ABL_InputStream& operator<<(const long double &);
#	virtual ABL_InputStream& operator<<(const _int64 &);	-- added on 15/03/2007
#	virtual ABL_InputStream& operator<<(const std::string &);
#	virtual ABL_InputStream& operator<<(const ABL_Date &);		-- added on 15/03/2007
#	virtual ABL_InputStream& operator<<(const ABL_DateTime &);	-- added on 15/03/2007
#	virtual ABL_InputStream& operator<<(const ABL_DbDate &);	-- added on 15/03/2007
#	virtual ABL_InputStream& operator<<(CBaseStream &);			 
#	char * mb_getStream();										 
#	void mb_flush();											 
======================================================================
Libraries:
**********************************************************************/

//##ModelId=4246A83600BB
class ABL_InputStream : public ABL_UnitTest
#else
class ABL_InputStream
#endif
{
public:
	//##ModelId=4246A83600BD
    ABL_InputStream(int p_idataChunkSize = 1024);				 // Default constructor
	//##ModelId=4246A83600BF
    virtual ~ABL_InputStream();									 // Default destructor
																 
	//##ModelId=4246A83600CB
	virtual ABL_InputStream& operator<<(const char *);			 // Overloaded operator <<, for streaming character array
	//##ModelId=4246A83600CE
	virtual ABL_InputStream& operator<<(const unsigned char *);	 // Overloaded operator <<, for streaming unsigned character array
	//##ModelId=4246A83600D1
	virtual ABL_InputStream& operator<<(const signed char *);	 // Overloaded operator <<, for streaming signed character array
	//##ModelId=4246A83600DA
	virtual ABL_InputStream& operator<<(const short &);			 // Overloaded operator <<, for streaming short variable
	//##ModelId=4246A83600DD
	virtual ABL_InputStream& operator<<(const unsigned short &); // Overloaded operator <<, for streaming unsigned short variable
	//##ModelId=4246A83600E0
	virtual ABL_InputStream& operator<<(const int &);			 // Overloaded operator <<, for streaming int variable
	//##ModelId=4246A83600EA
	virtual ABL_InputStream& operator<<(const unsigned int &);	 // Overloaded operator <<, for streaming unsigned int variable
	//##ModelId=4246A83600ED
	virtual ABL_InputStream& operator<<(const long &);			 // Overloaded operator <<, for streaming long variable
	//##ModelId=4246A83600F0
	virtual ABL_InputStream& operator<<(const unsigned long &);	 // Overloaded operator <<, for streaming unsigned long variable
	//##ModelId=4246A83600FA
	virtual ABL_InputStream& operator<<(const float &);			 // Overloaded operator <<, for streaming float variable
	//##ModelId=4246A83600FD
	virtual ABL_InputStream& operator<<(const double &);		 // Overloaded operator <<, for streaming double variable
	//##ModelId=4246A8360100
	virtual ABL_InputStream& operator<<(const long double &);	 // Overloaded operator <<, for streaming long double variable
	virtual ABL_InputStream& operator<<(const std::string &);	 // Overloaded operator <<, for streaming std::string variable
	//##ModelId=4246A8360109
	virtual ABL_InputStream& operator<<(const ABL_String &);	 // Overloaded operator <<, for streaming ABL_String variable
	//##ModelId=4246A836010C
	virtual ABL_InputStream& operator<<(CBaseStream &);			 // Overloaded operator <<, for streaming objects derived from CBaseStream class
	//##ModelId=4246A836010F
	virtual ABL_InputStream& operator<<(const _int64 &);
	//##ModelId=4246A8360119
	virtual ABL_InputStream& operator<<(const ABL_Date &);	
	//##ModelId=4246A836011C
	virtual ABL_InputStream& operator<<(const ABL_DateTime &);
	//##ModelId=4246A836011F
	virtual ABL_InputStream& operator<<(const ABL_DbDate &);

	//##ModelId=4246A8360122
	char * mb_getStream();										 // returns streamed data in form of character array 
	//##ModelId=4246A8360128
	void mb_flush();											 // flushes the stream

#ifdef ABL_UNIT_TEST
	//##ModelId=4246A8360129
	void mb_setChunkSize(int p_idataChunkSize);					 // Used for setting various buffer sizes for testing derived classes
	//##ModelId=4246A836012B
	void mb_unitTest();											 // Unit test function
#endif	//ABL_UNIT_TEST
protected:  														 
	//##ModelId=4246A836012C
	int  m_idataChunkSize;										 // varaible storing the buffer chunk size
	//##ModelId=4246A8360138
	int  m_ifreeMemoryInChunk;									 // variable storing total available buffer in current buffer chunk
	//##ModelId=4246A8360139
	long m_ltotalDataBuffered;									 //	variable storing total buffer size of the stream
	//##ModelId=4246A8360148
	char *m_writePtr;											 // pointer pointing to end of current buffer in use.
	//##ModelId=4246A836015A
	std::vector<char *> m_vecOfBuffers;							 // vector holds the buffer chunks pointer
};

#endif  //ABL_INPUTSTREAM_H

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
