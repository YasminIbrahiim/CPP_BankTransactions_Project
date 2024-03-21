/**************************************************************************************/
/**** File name  : Transaction.cpp                                            *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#include <iostream>
#include <ctime>
#include <vector>
#include <memory>
#include "Transaction.h"

Transaction::Transaction(uint8_t  TransactionTypeCpy, uint64_t Transaction_MoneyCpy ,const struct tm&  Transaction_DateRefCpy )
{
	TransactionType   = TransactionTypeCpy;
	Transaction_Money = Transaction_MoneyCpy;
	/**
	Member	    Type	Meaning	                    Range
    tm_sec	    int	    seconds after the minute	0-61*
    tm_min	    int	    minutes after the hour	    0-59
    tm_hour	    int	    hours since midnight	    0-23
    tm_mday	    int	    day of the month	        1-31
    tm_mon	    int	    months since January	    0-11
    tm_year	    int	    years since 1900	
    tm_wday	    int	    days since Sunday	        0-6
    tm_yday	    int	    days since January 1	    0-365
    tm_isdst	int	    Daylight Saving Time flag	        **/
	
	Transaction_Date.tm_sec	  = Transaction_DateRefCpy.tm_sec   ; 
    Transaction_Date.tm_min	  = Transaction_DateRefCpy.tm_min	;
    Transaction_Date.tm_hour  = Transaction_DateRefCpy.tm_hour  ;
    Transaction_Date.tm_mday  =	Transaction_DateRefCpy.tm_mday  ;
    Transaction_Date.tm_mon	  = Transaction_DateRefCpy.tm_mon	;
    Transaction_Date.tm_year  =	Transaction_DateRefCpy.tm_year  ;
    Transaction_Date.tm_wday  =	Transaction_DateRefCpy.tm_wday  ;
    Transaction_Date.tm_yday  =	Transaction_DateRefCpy.tm_yday  ;
    Transaction_Date.tm_isdst = Transaction_DateRefCpy.tm_isdst ;	 	
}

void Transaction::Transaction_SetTransactionType(uint8_t TransactionTypeCpy)
{
	TransactionType = TransactionTypeCpy;
}

void Transaction::Transaction_SetTransaction_Money(uint64_t Transaction_MoneyCpy)
{
	Transaction_Money = Transaction_MoneyCpy;
}

void Transaction::Transaction_SetTransaction_Date(const struct tm& Transaction_DateRefCpy)
{
	Transaction_Date.tm_sec	  = Transaction_DateRefCpy.tm_sec   ;
    Transaction_Date.tm_min	  = Transaction_DateRefCpy.tm_min	;
    Transaction_Date.tm_hour  = Transaction_DateRefCpy.tm_hour  ;
    Transaction_Date.tm_mday  =	Transaction_DateRefCpy.tm_mday  ;
    Transaction_Date.tm_mon	  = Transaction_DateRefCpy.tm_mon	;
    Transaction_Date.tm_year  =	Transaction_DateRefCpy.tm_year  ;
    Transaction_Date.tm_wday  =	Transaction_DateRefCpy.tm_wday  ;
    Transaction_Date.tm_yday  =	Transaction_DateRefCpy.tm_yday  ;
    Transaction_Date.tm_isdst = Transaction_DateRefCpy.tm_isdst ;	
}

uint8_t  Transaction::Transaction_GetTransactionType(void) const
{
	return TransactionType;
}

uint64_t Transaction::Transaction_GetTransaction_Money(void) const
{
	return Transaction_Money;
}

const struct tm&  Transaction::Transaction_GetTransaction_Date(void) const
{
	return Transaction_Date;
}