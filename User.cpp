/**************************************************************************************/
/**** File name  : User.cpp                                                   *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#include <iostream>
#include <cstdint>
#include <vector>
#include <ctime>
#include "Transaction.h"
#include "User.h"

User::~User()
{
	for(VecUserTransactions_iterator = VecUserTransactionsPtr.begin(); VecUserTransactions_iterator != VecUserTransactionsPtr.end(); VecUserTransactions_iterator++ )
	{
		delete *VecUserTransactions_iterator;
	}
}

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

const struct tm& User::User_GetCardExpirationDate(void) const
{
	return CardExpirationDate;
}

const struct tm& User::User_GetCardAcctivationDate(void) const
{
	return CardAcctivationDate;
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

void User::User_SetCardExpirationDate(const struct tm& CardExpirationDateRef)
{
	CardExpirationDate.tm_sec	   = CardExpirationDateRef.tm_sec   ; 
	CardExpirationDate.tm_min	   = CardExpirationDateRef.tm_min	; 
	CardExpirationDate.tm_hour     = CardExpirationDateRef.tm_hour  ; 
	CardExpirationDate.tm_mday     = CardExpirationDateRef.tm_mday  ; 
	CardExpirationDate.tm_mon	   = CardExpirationDateRef.tm_mon   ; 
	CardExpirationDate.tm_year     = CardExpirationDateRef.tm_year  ; 
	CardExpirationDate.tm_wday     = CardExpirationDateRef.tm_wday  ; 
	CardExpirationDate.tm_yday     = CardExpirationDateRef.tm_yday  ; 
	CardExpirationDate.tm_isdst    = CardExpirationDateRef.tm_isdst ; 
}

void User::User_SetCardAcctivationDate(const struct tm& CardAcctivationDateRef)
{
	CardAcctivationDate.tm_sec	   = CardAcctivationDateRef.tm_sec   ; 
	CardAcctivationDate.tm_min	   = CardAcctivationDateRef.tm_min	 ; 
	CardAcctivationDate.tm_hour    = CardAcctivationDateRef.tm_hour  ; 
	CardAcctivationDate.tm_mday    = CardAcctivationDateRef.tm_mday  ; 
	CardAcctivationDate.tm_mon	   = CardAcctivationDateRef.tm_mon	 ; 
	CardAcctivationDate.tm_year    = CardAcctivationDateRef.tm_year  ; 
	CardAcctivationDate.tm_wday    = CardAcctivationDateRef.tm_wday  ; 
	CardAcctivationDate.tm_yday    = CardAcctivationDateRef.tm_yday  ; 
	CardAcctivationDate.tm_isdst   = CardAcctivationDateRef.tm_isdst ; 
}

void User::User_AddTransaction(Transaction* UserTransactionPtr)
{
	if(VecUserTransactionsPtr.empty())
	{
		VecUserTransactionsPtr.push_back(UserTransactionPtr);
		VecUserTransactions_iterator = VecUserTransactionsPtr.begin();
	}else
	{
		VecUserTransactionsPtr.push_back(UserTransactionPtr); 
	}
	if(UserTransactionPtr->Transaction_GetTransactionType() == ADD)
	{
		Saved_Money += UserTransactionPtr->Transaction_GetTransaction_Money();
	}else if(UserTransactionPtr->Transaction_GetTransactionType() == WITHDRAW)
	{
		Saved_Money -= UserTransactionPtr->Transaction_GetTransaction_Money();
	}else
	{
		
	}
}
