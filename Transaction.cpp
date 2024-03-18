/**************************************************************************************/
/**** File name  : Transaction.cpp                                            *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/

#include "Transaction.h"

Transaction:: Transaction(uint8_t  TransactionTypeCpy, uint64_t Transaction_MoneyCpy , const struct tm&  Transaction_DateRef )
{
	TransactionType   = TransactionTypeCpy;
	Transaction_Money = Transaction_MoneyCpy;
	Transaction_Date.year  = Transaction_DateRef.year;
	Transaction_Date.month = Transaction_DateRef.month;
	Transaction_Date.day   = Transaction_DateRef.day;
}