/**************************************************************************************/
/**** File name  : User.cpp                                                   *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#include <iostream>
#include <cstdint>
#include <vector>
#include "Transaction.h"
#include "User.h"

const std::string& User::User_GetUserName(void) const
{
	return UserName;
}

uint64_t  User::User_GetUserID(void) const
{
	return UserID;
}

uint64_t  User::User_GetSaved_Money(void) const
{
	return Saved_Money;
}

void User::User_SetUserName(const std::string& UserNameCpy) 
{
	UserName = UserNameCpy;
}

void User::User_SetUserID(uint64_t UserIDCpy) 
{
	UserID = UserIDCpy;
}

void User::User_SetSaved_Money(uint64_t Saved_MoneyCpy) 
{
	Saved_Money = Saved_MoneyCpy;
}