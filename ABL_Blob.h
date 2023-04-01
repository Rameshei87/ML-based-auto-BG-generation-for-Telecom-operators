// Definition of the ABL_Date class
#ifndef ABL_BLOB_H
#define ABL_BLOB_H

#include "GlobalData.h"
#include "ABL_BlobBase.h"
#include "ABL_SmartPointer.h"
#ifdef ABL_UNIT_TEST1
#include "ABL_UnitTest.h"
/*********************************************************************
#	File		:	ABL_Blob.cpp
#	Abstract	:	Implementation of a ABL_Blob datatype
#	Date		:	8th May, 2007
#	Author(s)	:	Nishant Shekhar
#	Code Size	:	104 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
======================================================================
#	Base Class	:	ABL_Base
======================================================================
#	member 
#	Variables	:	
#	char *m_lobPtr;
#	unsigned int m_isize;	
======================================================================
#	member 
#	Functions	:
#	ABL_Blob();
#	ABL_Blob(ABL_Blob &p_ABL_Blob);
#	~ABL_Blob();
#	ABL_Blob& operator =(const ABL_Blob &p_srcBlob) ;
#   bool operator ==(const ABL_Blob &p_srcBlob) const ;
#   bool operator !=(const ABL_Blob &p_srcBlob) const ;
#	unsigned int mb_getChunkSize() const ;
#   unsigned int mb_length() const ;
#	bool mb_isNull() const ;
#	bool mb_isInitialized() const;
#	unsigned int mb_readChunk(unsigned int  p_uiamount, unsigned char *p_buffer) const ;
#	unsigned int mb_writeChunk(	unsigned int p_iamount, unsigned char *p_buffer) ;
#   unsigned int mb_read(unsigned int  p_uiamount, unsigned char *p_buffer,	unsigned int p_offset = 1) const ;
#	unsigned int mb_write(unsigned int p_iamount, unsigned char *p_buffer, unsigned int p_offset = 1) ;
#	unsigned int mb_initialize(	unsigned int  p_uiamount, unsigned char *p_buffer);
======================================================================
#	Libraries:
*********************************************************************/
class ABL_Blob : public ABL_UnitTest
#else
class ABL_Blob
#endif
{
public:
	ABL_Blob() : m_ABL_BlobBasePtr(NULL){}	//Defualt Constructor
	ABL_Blob(const ABL_Blob &p_ABL_Blob): m_ABL_BlobBasePtr(p_ABL_Blob.m_ABL_BlobBasePtr)//Copy Constructor
	{

	}
	~ABL_Blob() {}
	//Overloaded Operators

	ABL_Blob& operator =(const ABL_Blob &p_srcBlob) 	//Assignment operator
	{
		m_ABL_BlobBasePtr = p_srcBlob.m_ABL_BlobBasePtr;
		return *this;
	}
    bool operator ==(const ABL_Blob &p_srcBlob) const 	//Equaity opertor
	{
		return (m_ABL_BlobBasePtr->mb_isEqual(*p_srcBlob.m_ABL_BlobBasePtr));
	}
	//Inequality operator
	inline bool operator !=(const ABL_Blob &p_srcBlob) const {return (!m_ABL_BlobBasePtr->mb_isEqual(*p_srcBlob.m_ABL_BlobBasePtr));}
	//other mem functions
	unsigned int mb_getChunkSize() const 				//checks the chunk size of blob
	{
		return m_ABL_BlobBasePtr->mb_getChunkSize();
	}
    unsigned int mb_length() const 					//Returns length of blobs
	{
		return m_ABL_BlobBasePtr->mb_length();
	}
	inline bool mb_isNull() const 					//Check if blob is null
	{
		return m_ABL_BlobBasePtr->mb_isNull();
	}
	//Set blob to null
	inline void mb_setNull(bool p_isNull = false)
	{
		return m_ABL_BlobBasePtr->mb_setNull(p_isNull);
	}
	bool mb_isInitialized() const						//Check if blob is uninitialized
	{
		return m_ABL_BlobBasePtr->mb_isInitialized();
	}
	//read from blob with internal offset pointer
	unsigned int mb_readChunk(unsigned int  p_uiamount, unsigned char *p_buffer)
	{
		return m_ABL_BlobBasePtr->mb_readChunk(p_uiamount, p_buffer);
	}
    //write from blob with internal offset pointer
	unsigned int mb_writeChunk(	unsigned int p_iamount, unsigned char *p_buffer)
	{
		return m_ABL_BlobBasePtr->mb_writeChunk(p_iamount, p_buffer);
	}
	//read from blob with specified offset
	unsigned int mb_read(	unsigned int  p_uiamount, unsigned char *p_buffer,
							unsigned int p_offset = 1) const 
	{
		return m_ABL_BlobBasePtr->mb_read(p_uiamount, p_buffer, p_offset);
	}
	//write from blob with specified offset
	unsigned int mb_write(	unsigned int p_iamount, unsigned char *p_buffer,
							unsigned int p_offset = 1)
	{
		return m_ABL_BlobBasePtr->mb_write(p_iamount, p_buffer, p_offset);
	}
	bool mb_flushBuffer()
	{
		return m_ABL_BlobBasePtr->mb_flushBuffer();
	}
	void mb_init(ABL_BlobBase* p_ABL_BlobBasePtr)
	{
		m_ABL_BlobBasePtr = p_ABL_BlobBasePtr;
	}
	ABL_BlobBase* mb_get()
	{
		if(m_ABL_BlobBasePtr!=NULL)
			return &(*m_ABL_BlobBasePtr);

		return NULL;
	}
#ifdef ABL_UNIT_TEST	
//	void mb_unitTest();											// Unit test function
#endif
private:
	ABL_SmartPointer<ABL_BlobBase> m_ABL_BlobBasePtr;
	friend class ABL_ResultSet;
	friend class ABL_Statement;
};

#endif  //ABL_BLOB_H

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
