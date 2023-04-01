#ifndef ABL_LOGGER_H
#define ABL_LOGGER_H

#include "ABL_Mutex.h"
#include "ABL_String.h"
#include "ABL_Date.h"
#include <map>

#define MAX_SEQUENCE 999	
#define MAX_SIZE 1024*1024 // 1MB

std::string gb_baseName(std::string p_fileName); // strips out directory info from string

//##ModelId=4246A83402BF
enum LOG_LEVELS		// define log levels for logger
{
	//##ModelId=4246A83402C1
	LEVEL1 = 0,
	//##ModelId=4246A83402CE
	LEVEL2,
	//##ModelId=4246A83402CF
	LEVEL3,
	//##ModelId=4246A83402DE
	LEVEL4,
	//##ModelId=4246A83402DF
	LEVEL5
};

#define DEBUG    LEVEL1<<"|"<<(int)pthread_self()<<"|"<<gb_baseName(__FILE__)<<"|"<<__LINE__<<"|"<<ABL_Logger::mb_getSystemDate()<<"|"<<"DEBUG    |" 
#define INFO     LEVEL2<<"|"<<(int)pthread_self()<<"|"<<gb_baseName(__FILE__)<<"|"<<__LINE__<<"|"<<ABL_Logger::mb_getSystemDate()<<"|"<<"INFO     |" 
#define WARNING  LEVEL3<<"|"<<(int)pthread_self()<<"|"<<gb_baseName(__FILE__)<<"|"<<__LINE__<<"|"<<ABL_Logger::mb_getSystemDate()<<"|"<<"WARNING  |" 
#define _ERROR   LEVEL4<<"|"<<(int)pthread_self()<<"|"<<gb_baseName(__FILE__)<<"|"<<__LINE__<<"|"<<ABL_Logger::mb_getSystemDate()<<"|"<<"ERROR    |" 
#define CRITICAL LEVEL5<<"|"<<(int)pthread_self()<<"|"<<gb_baseName(__FILE__)<<"|"<<__LINE__<<"|"<<ABL_Logger::mb_getSystemDate()<<"|"<<"CRITICAL |" 

//##ModelId=4246A83402EE
enum MODIFIER // Macros for modifiers
{
	//##ModelId=4246A83402F0
	Endl = 0,
	//##ModelId=4246A83402FD
	Tab
};

//##ModelId=4246A83402FE
struct ltpthread
{
	//##ModelId=4246A834030E
	bool operator()(pthread_t s1, pthread_t s2) const
	{
		return (pthread_equal(s1 , s2) ?true:false );
	}
};

/*********************************************************************
#	File		:	ABL_Logger.h
#	Abstract	:	Service layer Logger class, holding logging 
#					funcitonalities provided by the service layer
#	Date		:	6th August, 2007
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	364 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#
======================================================================
#	Base Class	:	none
======================================================================
#	member 
#	Variables	:	
#
#	
======================================================================
#	member 
#	Functions	:
#
======================================================================
#	Libraries:
*********************************************************************/
class ABL_LogTarget
{
public:
	ABL_LogTarget() : m_iloglevel(0), m_bisFile(false)//Log Target constructor
	{
		m_loggerMutex.mb_init();
	}
	virtual ~ABL_LogTarget() {m_loggerMutex.mb_destroy();}//Log Target destructor
	virtual void mb_writeLog(const std::string &p_message) = 0;	  //log function.
	inline bool	 mb_TargetisFile() 
	{
		return m_bisFile;
	}
	//void mb_setLogLevel(unsigned int p_loglevel);
	//Interface for setting specific log level
	//void mb_setSpecificLogLevel(unsigned int p_loglevel, bool p_bspecific);
	inline unsigned int mb_getLogLevel()
	{
		return m_iloglevel;
	}
protected:
	unsigned int m_iloglevel;						//Log level, specific to each log target
	//bool		 m_bspecificLevel;					//flag for logging only for specific level
	ABL_Mutex	 m_loggerMutex;						// Mutex for the trace file functionality
	bool		 m_bisFile;
};

#ifdef ABL_UNIT_TEST
#include "ABL_UnitTest.h"
class ABL_FileTarget : public ABL_LogTarget , public ABL_UnitTest
#else
class ABL_FileTarget : public ABL_LogTarget
#endif
{
public:
	ABL_FileTarget();
	virtual ~ABL_FileTarget();
	void mb_writeLog(const std::string &p_message);
	bool mb_initFileLogger(ABL_String p_fileName = "",int p_ilogLevel = 0, unsigned int m_imaxfileSize = MAX_SIZE, unsigned int m_imaxSequence = MAX_SEQUENCE, bool m_buseDateInFileName = true);
	void mb_setMaxFileSize(unsigned int p_imaxFileSize = MAX_SIZE);
	void mb_setMaxRotation(unsigned int p_imaxFileSize = MAX_SEQUENCE);
	inline void mb_useDateInFileNames(bool p_buseDate = true){	m_buseDateInFileName = p_buseDate; }

#ifdef ABL_UNIT_TEST
	void mb_unitTest();												  // Unit test function
#endif 

private:
	int m_isequence;			// File sequence number
	std::string m_fileName;		// File name of the log file
	std::string m_baseName;		// File path name
	bool m_bfileStatus;			// File status
	bool m_buseDateInFileName;
	std::ofstream m_outputFile;	// Output stream for the log file
	ABL_Date	 m_fileCreationDate;
	unsigned int m_imaxfileSize;
	unsigned int m_imaxSequence;
};


#ifdef ABL_UNIT_TEST
class ABL_Logger : public ABL_UnitTest
#else
class ABL_Logger
#endif
{
public:
	ABL_Logger() { }
	~ABL_Logger() { }
	// Open the log file for writing Trace Entries
	bool mb_initLogger(ABL_String p_fileName = "",int p_ilogLevel = 0, ABL_String p_targetId ="DEFAULT", unsigned int p_imaxfileSize = MAX_SIZE, unsigned int p_imaxSequence = MAX_SEQUENCE, bool p_buseDateInFileName = true);
	
	void mb_addTarget(ABL_String p_targetName, ABL_LogTarget *p_ABL_LogTargetPtr);
	
	void mb_removeTarget(ABL_String p_targetName = "");

	ABL_LogTarget * mb_getTarget(ABL_String p_targetName = "");
	// overloaded << operator to write an ABL_String into the stream
	ABL_Logger& operator <<(ABL_String &p_ABL_String);
	// overloaded << operator to write a string into the the stream
	ABL_Logger& operator <<(const std::string &p_string);
	// overloaded << operator to write a char array into the stream
	ABL_Logger& operator <<(const char *p_charPtr);
	// overloaded << operator to specify log level for a trace entry
	ABL_Logger& operator <<(enum LOG_LEVELS p_elogLevel);
	// overloaded << operator to pass modifiers
	ABL_Logger& operator <<(enum MODIFIER p_emodifier);
	// overloaded << operator to write an integer value into the stream
	ABL_Logger& operator <<(const int p_intergerValue);
	// overloaded << operator to write an double value into the stream
	ABL_Logger& operator <<(const double p_doubleValue);//RAMS
	// Function to get the system date and time
	static std::string mb_getSystemDate();
	void mb_writeLog(); 	// Function to write stream into the log file
	//void mb_setLogLevel(ABL_String p_targetName = "", unsigned int p_ilogLevel = 0);
	void mb_setLogLevel(unsigned int p_ilogLevel = 0);
#ifdef ABL_UNIT_TEST
	void mb_unitTest();												  // Unit test function
#endif 
private:	
	std::string m_logMessage;	// Log message to be written into the log file
	unsigned int m_ilogLevel;	
	std::map<pthread_t,std::string *> m_threadMap; // Map to map thread and its log message
	std::map<std::string, ABL_LogTarget*> m_logTargets;
};

#endif //ABL_LOGGER_H

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
