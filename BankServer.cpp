/**************************************************************************************/
/**** File name  : BankServer.cpp                                             *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <ctime>
#include "Transaction.h"
#include "User.h"
#include "BankServer.h"
using namespace std;

BankServer* BankServer::ptrBankServerObj = NULL;

BankServer::~BankServer()
{
	for(UserData_Iterator = VecPtrUserData.begin(); UserData_Iterator != VecPtrUserData.end(); UserData_Iterator++ )
	{
		delete *UserData_Iterator;
	}
}

static BankServer*  BankServer::GetBankServerInstance(void)
{
	if(ptrBankServerObj == NULL)
	{
		ptrBankServerObj = new BankServer();
	}else
	{
	}
	return ptrBankServerObj;
}

enuBankServerStatus BankServer::BankServer_AddUserAccount(const std::string& UserName, uint64_t UserID, uint64_t Saved_Money)
{                         
	User* UserData = new User; 
	time_t       Date_String;
	struct tm*   AcctivationDate;
	struct tm    Card_ExpirationDate;
	
	UserData->User_SetUserName(UserName) ;
	UserData->User_SetUserID(UserID); 
	UserData->User_SetSaved_Money(Saved_Money) ;
	
	std::time(&Date_String);
	AcctivationDate = std::gmtime(&Date_String);
	Transaction*  Transaction1st = new Transaction(ADD , Saved_Money , *AcctivationDate );
	UserData->User_AddTransaction(Transaction1st);
	UserData->User_SetCardAcctivationDate(*AcctivationDate); 
	
	Card_ExpirationDate.tm_sec  = AcctivationDate->tm_sec  ; 
	Card_ExpirationDate.tm_min  = AcctivationDate->tm_min  ;  
	Card_ExpirationDate.tm_hour = AcctivationDate->tm_hour ;  
	Card_ExpirationDate.tm_mday = AcctivationDate->tm_mday ;   
	Card_ExpirationDate.tm_mon  = AcctivationDate->tm_mon  ;  
	Card_ExpirationDate.tm_year = AcctivationDate->tm_year  + 5;
	Card_ExpirationDate.tm_wday = AcctivationDate->tm_wday ; 
	Card_ExpirationDate.tm_yday = AcctivationDate->tm_yday ;  
	Card_ExpirationDate.tm_isdst= AcctivationDate->tm_isdst;      
	UserData->User_SetCardExpirationDate(Card_ExpirationDate); 
	if(VecPtrUserData.empty())
	{
		VecPtrUserData.push_back(UserData);
		UserData_Iterator = VecPtrUserData.begin();
	}else
	{
		VecPtrUserData.push_back(UserData); 
	}
	return BankServer_E_OK;
}

enuBankServerStatus BankServer::BankServer_DeleteUserAccount(uint64_t User_IDCpy)
{
	uint8_t IndexLOC ;
	enuBankServerStatus BankServerStatusLOC = BankServer_E_OK;
	for(IndexLOC = 0; IndexLOC < VecPtrUserData.size(); IndexLOC++ )
	{
		if(VecPtrUserData[IndexLOC]->User_GetUserID() == User_IDCpy)
		{
			delete VecPtrUserData[IndexLOC];
			VecPtrUserData.erase(VecPtrUserData.begin()+IndexLOC);
			BankServerStatusLOC = BankServer_E_OK;
		}
	}
	if(IndexLOC == VecPtrUserData.size())
	{
		BankServerStatusLOC =  BankServer_ERROR_ID_NOT_VALID;
	}
	return BankServerStatusLOC ;
}

enuBankServerStatus BankServer::BankServer_FindUser(uint64_t User_IDCpy, User*& UserPtr)
{
	uint8_t IndexLOC ;
	enuBankServerStatus BankServerStatusLOC = BankServer_E_OK;
	for(IndexLOC = 0; IndexLOC < VecPtrUserData.size(); IndexLOC++ )
	{
		if(VecPtrUserData[IndexLOC]->User_GetUserID() == User_IDCpy)
		{
			UserPtr = VecPtrUserData[IndexLOC];
			std::cout<<UserPtr<<std::endl;
			BankServerStatusLOC =  BankServer_E_OK;
			break;
		}
	}
	if(IndexLOC == VecPtrUserData.size())
	{
		UserPtr = NULL;
		BankServerStatusLOC =  BankServer_ERROR_ID_NOT_VALID;
	}
	return BankServerStatusLOC;
}