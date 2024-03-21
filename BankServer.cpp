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

enuBankServerStatus BankServer::BankServer_AddUserAccount(void)
{
	User* UserData = new User; 
	std::string  UserName;
	uint64_t     UserID;
	uint64_t     Saved_Money;
	time_t       Date_String;
	struct tm*   Date;
	std::cout<< "Enter user name: "<<std::endl;
	std::cin>> UserName;
	UserData->User_SetUserName(UserName) ;
	std::cout<< "Enter user ID (id must be consisted of 15 number): " <<std::endl; 
	std::cin>> UserID;
	UserData->User_SetUserID(UserID); 
	std::cout<<"Enter user deposit: "<<std::endl;
	std::cin>> Saved_Money;
	UserData->User_SetSaved_Money(Saved_Money) ;
	std::time(&Date_String);
	Date = std::gmtime(&Date_String);
	Transaction Transaction(ADD , Saved_Money , *Date );
	if(VecPtrUserData.empty())
	{
		VecPtrUserData.push_back(UserData);
		UserData_Iterator = VecPtrUserData.begin();
	}else
	{
		VecPtrUserData.push_back(UserData); 
	}
	return E_OK;
}

enuBankServerStatus BankServer::BankServer_DeleteUserAccount(uint64_t User_IDCpy)
{
	uint8_t* IndexPtr = NULL;
	enuBankServerStatus BankServerStatusLOC = E_OK;
	*IndexPtr = VecPtrUserData.size();
	BankServer_FindUser(User_IDCpy , IndexPtr);
	if(*IndexPtr != VecPtrUserData.size())
	{
		delete VecPtrUserData[*IndexPtr];
		delete_element(VecPtrUserData , *IndexPtr);
		BankServerStatusLOC = E_OK;
	}else
	{
		BankServerStatusLOC = ERROR_ID_NOT_VALID;
	}
	return BankServerStatusLOC ;
}

enuBankServerStatus BankServer::BankServer_FindUser(uint64_t User_IDCpy, uint8_t* IndexPtrCpy)
{
	uint8_t IndexLOC ;
	enuBankServerStatus BankServerStatusLOC = E_OK;
	for(IndexLOC = 0; IndexLOC < VecPtrUserData.size(); IndexLOC++ )
	{
		if(VecPtrUserData[IndexLOC]->User_GetUserID() == User_IDCpy)
		{
			*IndexCpy = IndexLOC;
			BankServerStatusLOC =  E_OK;
		}
	}
	if(IndexLOC == VecPtrUserData.size())
	{
		BankServerStatusLOC =  ERROR_ID_NOT_VALID;
	}
	return BankServerStatusLOC;
}