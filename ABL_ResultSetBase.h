// ABL_ResultSetBase.h: interface for the ABL_ResultSetBase class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ABL_RESULTSETBASE_H
#define ABL_RESULTSETBASE_H

#include <GlobalData.h>

class ABL_Blob;
class ABL_DbDate;
class ABL_String;
class ABL_StatementBase;
class ABL_stmtMetadataBase;

class ABL_ResultSetBase 
{
public:
	ABL_ResultSetBase() {}
	virtual ~ABL_ResultSetBase() {}
	virtual ABL_ResultSetBase&	operator << (ABL_DbDate *p_ABL_DbDatePtr) = 0 ;
	virtual ABL_ResultSetBase&	operator << (int *p_integerPtr) = 0 ;
	virtual ABL_ResultSetBase&	operator << (float *p_floatPtr) = 0 ;
	virtual ABL_ResultSetBase&	operator << (ABL_String *p_stringPtr) = 0 ;
	virtual ABL_ResultSetBase&	operator << (long *p_longPtr) = 0 ;
	virtual ABL_ResultSetBase&	operator << (double *p_doublePtr) = 0 ;
	virtual ABL_ResultSetBase&	operator << (_int64 *p_int64Ptr) = 0 ;
	virtual ABL_ResultSetBase&	operator << (ABL_Blob *p_ABL_BlobPtr) = 0 ;
	virtual ABL_ResultSetBase&	operator << (unsigned int *p_uintegerPtr) = 0 ;
	
	virtual int	 mb_fetch() = 0 ;
	virtual int		mb_getNumArrayRows() = 0 ;
	virtual void	mb_setBulkCount(int p_ibulkCount) = 0 ;
	virtual void	mb_setListCount(int p_ilistCount) = 0 ;
	virtual bool	mb_isNull(unsigned int p_iparamIndex) = 0 ;
	virtual bool	mb_isTruncated(unsigned int p_iparamIndex) = 0 ;
	virtual void	mb_setErrorOnNull(unsigned int p_icolumnIndex,bool p_bcauseException) = 0 ;
	virtual std::vector<ABL_DATATYPE> mb_listColumnType() = 0 ;
	virtual ABL_stmtMetadataBase* mb_getMetadata() = 0 ;
	virtual ABL_String mb_getString(unsigned int p_icolumnIndex) = 0 ;
	virtual int		   mb_getInt(unsigned int p_icolumnIndex) = 0 ;
	virtual float	   mb_getFloat(unsigned int p_icolumnIndex) = 0 ;
	virtual ABL_DbDate mb_getDate(unsigned int p_icolumnIndex) = 0 ;
	virtual double	   mb_getDouble(unsigned int p_icolumnIndex) = 0 ;
	virtual unsigned int mb_getUInt(unsigned int p_icolumnIndex) = 0 ;
	virtual _int64		mb_getInt64(unsigned int p_icolumnIndex) = 0 ;
	virtual ABL_Blob   mb_getABL_Blob(unsigned int p_icolumnIndex) = 0 ;

	virtual ABL_ResultSetBase& operator >>	(ABL_DbDate &p_ABL_DbDatePtr) = 0 ;
	virtual ABL_ResultSetBase& operator >>	(int &p_integerPtr) = 0 ;
	virtual ABL_ResultSetBase& operator >>	(float &p_floatPtr) = 0 ;
	virtual ABL_ResultSetBase& operator >>	(ABL_String &p_stringPtr) = 0 ;
	virtual ABL_ResultSetBase& operator >>	(double &p_doublePtr) = 0 ;
	virtual ABL_ResultSetBase& operator >>	(_int64 &p_int64Ptr) = 0 ;
	virtual ABL_ResultSetBase& operator >>	(ABL_Blob &p_ABL_BlobPtr) = 0 ;
	virtual ABL_ResultSetBase& operator >>	(unsigned int &p_uintegerPtr) = 0 ;

};
#endif

/*********************************************************************
#
#                 Copyright 2006 - 2007  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/
