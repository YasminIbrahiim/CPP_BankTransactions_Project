/**************************************************************************************/
/**** File name  : Machine.cpp                                                *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#include <iostream>
#include <cstdint>
#include <vector>
#include <ctime>
#include "Transaction.h"
#include "User.h"
#include "BankServer.h"
#include "Card.h"
#include "Machine.h"

Machine* Machine::ptrMachineObj = NULL;

static Machine*  Machine::GetMachineInstance(void)
{
	if(ptrMachineObj == NULL)
	{
		ptrMachineObj = new Machine();
	}else
	{
	}
	return ptrMachineObj;	
}

enuMachineStatus Machine::Machine_Init(Card* CardDataPtr)
{
	enuMachineStatus MachineStatusLOC = E_OK;
	uint32_t   Option;
	uint64_t  TransactionMoney;
	time_t       Date_String;
	struct tm*   TransactionDate;
	User*        UserDataPtr;
	BankServer* BankServerObj = BankServer::GetBankServerInstance();
	BankServerObj->BankServer_FindUser(CardDataPtr->Card_GetUserID() , UserDataPtr);
	
	if (Machine_CheckDataValidation(CardDataPtr->Card_GetUserID()) == E_OK)
	{
		if (Machine_CheckCardExpirationDate(CardDataPtr->Card_GetExpirationDate()) == E_OK)
		{
			std::cout<<"Select one of the following options: " <<std::endl
			<< "0. Withdraw money"<<std::endl 
			<< "1. Add money "<<std::endl
			<< "2. quit machine interface"<<std::endl;
			std::cin>> Option;
			if(Option == 0)
			{
				Transaction* TransactionData = new Transaction;
				TransactionData->Transaction_SetTransactionType(WITHDRAW);
				std::cout<<"Enter the amount of money"<<std::endl;
				std::cin>>TransactionMoney;
				TransactionData->Transaction_SetTransaction_Money(TransactionMoney);
				std::time(&Date_String);
				TransactionDate = std::gmtime(&Date_String);
				TransactionData->Transaction_SetTransaction_Date(*TransactionDate);
				UserDataPtr->User_AddTransaction(TransactionData);
				std::cout<<"Your Transaction is done successfully"<<std::endl;
			}else if(Option == 1)
			{
				Transaction* TransactionData = new Transaction;
				TransactionData->Transaction_SetTransactionType(ADD);
				std::cout<<"Enter the amount of money"<<std::endl;
				std::cin>>TransactionMoney;
				TransactionData->Transaction_SetTransaction_Money(TransactionMoney);
				std::time(&Date_String);
				TransactionDate = std::gmtime(&Date_String);
				TransactionData->Transaction_SetTransaction_Date(*TransactionDate);
				UserDataPtr->User_AddTransaction(TransactionData);
				std::cout<<"Your Transaction is done successfully"<<std::endl;
			}else if(Option == 2)
			{
				// Do nothing
			}
		}else
		{
			MachineStatusLOC = ERROR_CARD_EXPIRED;
		}
		
	}else
	{
		MachineStatusLOC = ERROR_DATA_NOT_VALID;
	}
	return MachineStatusLOC;	
}

enuMachineStatus Machine::Machine_CheckDataValidation(uint64_t Card_IDCpy)
{
	User*     UserDataPtr;
	BankServer* BankServerObj = BankServer::GetBankServerInstance();
	BankServerObj->BankServer_FindUser(Card_IDCpy , UserDataPtr);
	std::cout<<UserDataPtr<<std::endl;
	if(UserDataPtr != NULL )
	{
		return E_OK;
	}else
	{
		return ERROR_DATA_NOT_VALID;
	}
	
}

enuMachineStatus Machine::Machine_CheckCardExpirationDate(const struct tm& CardExpirationDateRef)
{
	enuMachineStatus MachineStatusLOC = E_OK;
	time_t       Date_String;
	struct tm*   TransactionDate;
	std::time(&Date_String);
	TransactionDate = std::gmtime(&Date_String);		
	if(CardExpirationDateRef.tm_year < TransactionDate->tm_year )
	{
		MachineStatusLOC = ERROR_CARD_EXPIRED;
	}else if (CardExpirationDateRef.tm_year == TransactionDate->tm_year )
	{
		if(CardExpirationDateRef.tm_mon < TransactionDate->tm_mon)
		{
			MachineStatusLOC = ERROR_CARD_EXPIRED;
		}else if(CardExpirationDateRef.tm_mon == TransactionDate->tm_mon)
		{
			if(CardExpirationDateRef.tm_mday <= TransactionDate->tm_mday)
			{
				MachineStatusLOC = ERROR_CARD_EXPIRED;
			}else
			{
				MachineStatusLOC = E_OK;
			}
		}else
		{
			MachineStatusLOC = E_OK;
		}
	}else
	{
		MachineStatusLOC = E_OK;
	}
	return MachineStatusLOC;
}
