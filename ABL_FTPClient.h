// Interface of the ABL_FTPClient class
//
//////////////////////////////////////////////////////////////////////

#ifndef ABL_FTPCLIENT_H
#define ABL_FTPCLIENT_H

#include "GlobalData.h"
#include "ABL_Socket.h"
#include "ABL_String.h"
#include <openssl/ssl.h>

//##ModelId=48AAB95502BF
enum FTP_EXCEPTIONS
{
	//##ModelId=48AAB95502C1
	UNEXPECTED_SERVER_RESPONSE = 467,
	//##ModelId=48AAB95502CE
	AUTH_FAILURE,
	//##ModelId=48AAB95502CF
	GENERAL_ERROR
};

#ifdef ABL_UNIT_TEST
#include "ABL_UnitTest.h"
//##ModelId=48AAB95502FD
class ABL_FTPClient : public ABL_UnitTest
#else
/*********************************************************************
#	File		:	ABL_FTPClient.h
#	Abstract	:	Abstraction of a generic FTP client to send/recieve
					files adhering to rfc959 specification.
#	Date		:	23rd June, 2008
#	Author(s)	:	Sunil Kumar Reddy
#	Code Size	:	200 lines	
#	Design		:	
#	References	
#	Module		:	Base Module of @Billity Service Layer
======================================================================
#	Revision History
======================================================================
#	SI		Edited by		Date			Area Edited
======================================================================
#	1		Shrikant S H	07th Jan, 2009	The change directory(CWD)
#											facility is introduced.
#	2		Chitranshu		03rd Dec 2009	Introduced interfaces for
#											Removing file and Directory
#											from Remote Server.
#	3		Chitranshu		23rd Dec 2009	Added functionality of FTPS over TLS
#	4		Shrikant S H	24th Dec 2009	Added some utility functions
======================================================================
#	Base Class	:	None
======================================================================
#	member 
#	Variables	:	
#
#	ABL_Socket m_controlSocket;
#	std::string m_server;
#	unsigned short m_iport;
#	std::string m_username;
#	std::string m_password;
#	std::string returnstring;
#	bool LoggedIn;
======================================================================
#	member 
#	Functions	:
#
#	ABL_FTPClient(void);
#	ABL_FTPClient(std::string p_FTPServer = "127.0.0.1", const int p_iFTPPort = FTP_PORT, 
					std::string p_username = "", std::string p_password = "");
#	void mb_setFTPServer(std::string p_username = "", std::string p_password = "", std::string p_FTPServer = "127.0.0.1", const int p_FTPPort = 21 );
#	void mb_downloadFile(const std::string &p_localPath, const std::string &p_serverPath, const int p_irecvChunkSize = 8);
#	void mb_uploadFile(const std::string &p_localPath, const std::string &p_serverPath);
#	std::string mb_getLastServerResponse(void);
#	void mb_quit();
#	void mb_changeDir(const ABL_String &p_serverPath);
#	void mb_login();
#	void createDataSocket(ABL_Socket &p_dataSocket);
#	void mb_deleteFile(const ABL_String &p_serverPath);
#	void mb_removeDirectory(const ABL_String &p_serverPath);
======================================================================
#	Libraries:
*********************************************************************/
//!ABL_FTPClient Class
/*! The Class is used to send email via FTP server. It internally uses RFC959 (FTP) protocol to communicate with the FTP server
*/
class ABL_FTPClient
#endif
{
public:
	/**Default constructor which initializes all the ftp server variables to deafault values.
	*/
	//##ModelId=48AAB95502FF
	ABL_FTPClient(void);
	
	/**Constructor to facilitate inline initialisation of ftp server variables
	* @param p_username -> ABL_String variable having the username
	* @param p_password -> ABL_String variable having the password
	* @param p_FTPServer -> ABL_String variable having the ftp server name/ip address
	* @param p_iFTPPort -> integer variable having the port number.Default is 21.
	* @param p_useSecure -> Boolean value to indicate the whether secure TLS mode to be used or not.Default false
	*/
	//##ModelId=48AAB9550301

	ABL_FTPClient(const ABL_String p_username, const ABL_String p_password,
		const ABL_String p_FTPServer = "127.0.0.1", const int p_iFTPPort = 21, const bool p_useSecure = false);
	
	/**Interface to set server variables meant to use in conjuction with default constructor
	* @param p_username -> ABL_String variable having the username
	* @param p_password -> ABL_String variable having the password
	* @param p_FTPServer -> ABL_String variable having the ftp server name/ip address
	* @param p_iFTPPort -> integer variable having the port number.Default is 21.
	* @param p_useSecure ->  Boolean value to indicate the whether secure TLS mode to be used or not.Default false
	*/
	//##ModelId=48AAB9550311
	void mb_setFTPServer(ABL_String p_username = "", ABL_String p_password = "", ABL_String p_FTPServer = "127.0.0.1", const int p_FTPPort = 21, const bool p_useSecure = false);
	
	/**Interface to download a file from the server to a specified local file location.
	*@param p_localPath -> ABL_String variable having the local file path is passed by reference.
	*@param p_serverPath -> ABL_String variable having the server file path is passed by reference.
	*@param p_irecvChunkSize -> Integer variable to specify the number bytes for each chunk of data.
	*/
	//##ModelId=48AAB9550316
	void mb_downloadFile(const ABL_String &p_localPath, const ABL_String &p_serverPath, const int p_irecvChunkSize = 8);

	/**Interface to upload a file to the server from any specified local file location.
	*@param p_localPath -> ABL_String variable having the local file path is passed by reference.
	*@param p_serverPath -> ABL_String variable having the server file path is passed by reference.
	*/
	//##ModelId=48AAB955031F
	void mb_uploadFile(const ABL_String &p_localPath, const ABL_String &p_serverPath);

	/**Utility function to get the ftp server response incase of any server errors/exceptions.
	*/
	//##ModelId=48AAB9550322
	std::string mb_getLastServerResponse(void);

	/**Interface to terminate FTP session with the server.
	*/
	//##ModelId=48AAB9550324
	void mb_quit();

	/**Interface to change the remote directory
	*@param p_serverPath -> ABL_String variable having the directory path passed as reference.
	*/
	//##ModelId=4A3A12090005
	void mb_changeDir(const ABL_String &p_serverPath);
	std::string mb_getFileList(std::string pattern);

    /**Interface to remove the remote file
	*@param p_serverPath -> ABL_String variable having the file path passed as reference.
	*/
    void mb_deleteFile(const ABL_String &p_serverPath);

    /**Interface to remove the remote directory
	*@param p_serverPath -> ABL_String variable having the diectory path passed as reference.
	*/
    void mb_removeDirectory(const ABL_String &p_serverPath);

	/**Interface to rename the file 
	*@param p_currentFileName -> ABL_String variable having the current file name
	*@param p_newFileName -> ABL_String variable having the new file name
	*/
	void mb_renameFile(const ABL_String &p_currentFileName,const ABL_String &p_newFileName);

	/**Interface to get the size of the file
	*@param p_fileName -> ABL_String variable having the file name for which size is needed
	*/
	int mb_getFileSize(const ABL_String &p_fileName);

	/**Interface to create the directory on remote server
	*@param p_dirName -> ABL_String variable having the directory name
	*/
	void mb_createDirectory(const ABL_String &p_dirName);

	/**Interface to check for the existance of the file
	*@param p_fileName -> ABL_String variable having the file name
	*/
	bool mb_checkForFile(const ABL_String &p_fileName);


#ifdef ABL_UNIT_TEST
	//##ModelId=48AAB9550325
	void mb_unitTest();											// Unit test function
#endif
	//##ModelId=48AAB955032C
	~ABL_FTPClient(void);

	/** \example Sample_ABL_FtpClient.cpp
	* This is an example of how to use the ABL_FtpClient Class.
	*/

private:
	//##ModelId=48AAB955032F
	ABL_Socket m_controlSocket;		//Control socket to issue FTP commands to server

	//##ModelId=48AAB9550333
	void mb_login();				//Utility function which encapsulates login sequence with FTP server

		/** Method to intialize secure control connection
	*/
	void mb_initSSL();

	/** Method to close secure control connection
	*/
	void mb_closeSSL();

	/** Method to send control commands on secure/insecure control connection
	* @param p_string -> std::string containing the command to be sent
	*/
	void mb_send(std::string p_string);

	/** Method to send control commands on secure/insecure control connection
	* @param p_buffer -> buffer containing the command to be sent
	* @param p_size -> size of buffer
	*/
	void mb_send(char* p_buffer, size_t p_size);

	/** Method to receive response on secure/insecure control connection
	* @param p_buffer -> buffer to hold the response
	* @param p_size -> size of buffer
	*/
	void mb_receive(char* p_buff, size_t p_size);

	/** Utility to use TLS to authenticate with server.
	*/
	void mb_loginSecure();

	//##ModelId=48AAB9550334
	void mb_createDataSocket(ABL_Socket &p_dataSocket);	//Utility to create data connection with FTP server incase of download/upload/etc.,

	// Server IP.
	//##ModelId=48AAB955033E
	std::string m_server;
	// The port to mail to on the FTP server.
	//##ModelId=48AAB9550342
	unsigned short m_iport;
	// username for authenticated FTP
	//##ModelId=48AAB955034C
	std::string m_username;
	// password m_for authenticated FTP
	//##ModelId=48AAB9550351
	std::string m_password;
	// filled in with server return strings in case of error
	//##ModelId=48AAB9550356
	std::string m_returnString;
	//Used to find login status
	//##ModelId=48AAB955035E
	bool m_bLoggedIn;

	bool m_useSecure;

	SSL_CTX* m_sslContext;
	SSL* m_sslConnection;
};
#endif
/*********************************************************************
#
#                 Copyright 2008 - 2009  
#                 Lifetree Convergence Ltd.
#
*********************************************************************/

