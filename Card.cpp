/**************************************************************************************/
/**** File name  : Card.cpp                                                   *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/

#include <iostream>
#include <cstdint>
#include <ctime>
#include "Card.h"

void  Card::Card_SetUserName(const std::string& User_NameCpy)
{
	User_Name = User_NameCpy;
}

void  Card::Card_SetUserID(uint64_t   Card_IDCpy)
{
	Card_ID = Card_IDCpy;
}

void  Card::Card_SetExpirationDate(const struct tm&  Card_ExpirationDateRef)
{
	Card_ExpirationDate.tm_sec	 = Card_ExpirationDateRef.tm_sec  ;
	Card_ExpirationDate.tm_min	 = Card_ExpirationDateRef.tm_min  ;
	Card_ExpirationDate.tm_hour  = Card_ExpirationDateRef.tm_hour ;
	Card_ExpirationDate.tm_mday  = Card_ExpirationDateRef.tm_mday ;
	Card_ExpirationDate.tm_mon	 = Card_ExpirationDateRef.tm_mon  ;
	Card_ExpirationDate.tm_year  = Card_ExpirationDateRef.tm_year ;
	Card_ExpirationDate.tm_wday  = Card_ExpirationDateRef.tm_wday ;
	Card_ExpirationDate.tm_yday  = Card_ExpirationDateRef.tm_yday ;
	Card_ExpirationDate.tm_isdst = Card_ExpirationDateRef.tm_isdst;
}

void  Card::Card_SetAcctivationDate(const struct tm&  Card_AcctivationDateRef)
{
	Card_AcctivationDate.tm_sec	  = Card_AcctivationDateRef.tm_sec  ;
	Card_AcctivationDate.tm_min	  = Card_AcctivationDateRef.tm_min  ;
	Card_AcctivationDate.tm_hour  = Card_AcctivationDateRef.tm_hour ;
	Card_AcctivationDate.tm_mday  = Card_AcctivationDateRef.tm_mday ;
	Card_AcctivationDate.tm_mon	  = Card_AcctivationDateRef.tm_mon  ;
	Card_AcctivationDate.tm_year  = Card_AcctivationDateRef.tm_year ;
	Card_AcctivationDate.tm_wday  = Card_AcctivationDateRef.tm_wday ;
	Card_AcctivationDate.tm_yday  = Card_AcctivationDateRef.tm_yday ;
	Card_AcctivationDate.tm_isdst = Card_AcctivationDateRef.tm_isdst;
}

const std::string& Card::Card_GetUserName(void) const
{
	return User_Name;
}

uint64_t Card::Card_GetUserID(void) const
{
	return Card_ID;
}

const struct tm&  Card::Card_GetExpirationDate(void) const
{
	return Card_ExpirationDate;
}

const struct tm&  Card::Card_GetAcctivationDate(void) const
{
	return Card_AcctivationDate;
}








