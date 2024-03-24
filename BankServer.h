/**************************************************************************************/
/**** File name  : BankServer.h                                               *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#ifndef  BANKSERVER_H
#define  BANKSERVER_H

typedef enum 
{
	BankServer_E_OK,
	BankServer_ERROR_ADD_USER_FAILED,
	BankServer_ERROR_CARD_ACCTIVATION_FAILED,
	BankServer_ERROR_ID_NOT_VALID
}enuBankServerStatus;

/* This class is simulating the bank server */
/* This is a singleton class you can create only one object from it */
class BankServer
{
private:
	std::vector<User*>  VecPtrUserData; /* vector that contains pointers to each user class */
	std::vector<User*>::iterator  UserData_Iterator;
	static BankServer* ptrBankServerObj;
	BankServer() = default;
	~BankServer();
public: 	
	BankServer(const BankServer& BankServerObj) = delete;
	static BankServer*   GetBankServerInstance(void);
	enuBankServerStatus  BankServer_AddUserAccount(const std::string& UserName, uint64_t UserID, uint64_t Saved_Money);
	enuBankServerStatus  BankServer_DeleteUserAccount(uint64_t User_IDCpy);
	enuBankServerStatus  BankServer_FindUser(uint64_t User_IDCpy, User*& UserPtr);
};

#endif