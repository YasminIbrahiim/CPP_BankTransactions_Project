/**************************************************************************************/
/**** File name  : Transaction.h                                              *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/

#ifndef  TRANSACTION_H
#define  TRANSACTION_H

#include <ctime>

#define WITHDRAW ((uint8_t)0)
#define ADD      ((uint8_t)1)

class Transaction
{
private:	
	uint8_t    TransactionType;    // add or withdraw
	uint64_t   Transaction_Money;  // amount of money added or withdrawn
	struct tm  Transaction_Date;   // date of transaction 
	
public:
	Transaction() = default;
	Transaction(uint8_t  TransactionTypeCpy, uint64_t Transaction_MoneyCpy , const struct tm&  Transaction_DateRef );
	~Transaction() = default;
	
	void Transaction_SetTransactionType(uint8_t TransactionTypeCpy);
	void Transaction_SetTransaction_Money(uint64_t Transaction_Money);
	void Transaction_SetTransaction_Date(const struct tm& Transaction_DateRef);
	
	uint8_t  Transaction_GetTransactionType(void) const;
	uint64_t Transaction_GetTransaction_Money(void) const;
	const struct tm&  Transaction_GetTransaction_Date(void) const;
};

#endif