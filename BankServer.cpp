/**************************************************************************************/
/**** File name  : BankServer.cpp                                             *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#include<iostream>
#include <string>
#include <vector>
#include <ctime>
#include "User.h"
#include"BankServer.h"
using namespace std;

BankServer* BankServer::ptrBankServerObj = NULL;

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
	struct tm    Date;
	if(VecPtrUserData.empty())
	{
		VecPtrUserData.push_back(UserData);
		UserData_Iterator = VecPtrUserData.begin();
	}else
	{
		VecPtrUserData.push_back(UserData); 
	}
	std::cout<< "Enter user name: "<<std::endl;
	std::cin>> UserName;
	UserData-> User_SetUserName(UserName) ;
	std::cout<< "Enter user ID (id must be consisted of 15 number): " <<std::endl; 
	std::cin>> UserID;
	UserData-> User_SetUserID(UserID); 
	std::cout<<"Enter user deposit: "<<std::endl;
	std::cin>> Saved_Money;
	UserData->User_SetSaved_Money(Saved_Money) ;
	std::time(&Date_String);
	Date = std::gmtime(&Date_String);
	Transaction Transaction(ADD , Saved_Money , &Date );
}

enuBankServerStatus BankServer::BankServer_DeleteUserAccount(uint64_t User_ID)
{
	
}

enuBankServerStatus BankServer::BankServer_FindUser(uint64_t User_ID, User* ptrUserData)
{
	
}