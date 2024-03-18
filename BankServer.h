/**************************************************************************************/
/**** File name  : BankServer.h                                               *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#ifndef  BANKSERVER_H
#define  BANKSERVER_H

typedef enum 
{
	E_OK,
	ERROR_ADD_USER_FAILED,
	ERROR_CARD_ACCTIVATION_FAILED,
	ERROR_ID_NOT_VALID
}enuBankServerStatus;

/* This class is simulating the bank server */
/* This is a singleton class you can create only one object from it */
class BankServer
{
private:
	vector<User*>  VecPtrUserData; /* vector that contains pointers to each user class */
	vector<User*>::iterator  UserData_Iterator;
	static BankServer* ptrBankServerObj;
	BankServer() = default;
	~BankServer() = default;
public: 	
	BankServer(const BankServer& BankServerObj) = delete;
	static BankServer*   GetBankServerInstance(void);
	enuBankServerStatus  BankServer_AddUserAccount(void);
	enuBankServerStatus  BankServer_DeleteUserAccount(uint64_t User_ID);
	enuBankServerStatus  BankServer_FindUser(uint64_t User_ID, User* ptrUserData);
};

#endif