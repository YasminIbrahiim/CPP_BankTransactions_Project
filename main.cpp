/**************************************************************************************/
/**** File name  : main.cpp                                                   *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/

#include <iostream>
#include <cstdint>
#include <ctime>
#include <vector>
#include "Card.h"
#include "Machine.h"
#include "Transaction.h"
#include "User.h"
#include "BankServer.h"

using namespace std;

int main()
{
	BankServer* BankServerObj = BankServer::GetBankServerInstance();
	Machine*    MachineObj    = Machine::GetMachineInstance();
	enuMachineStatus MachineStatusLOC = E_OK;
	
	time_t       Date_String;
	struct tm*   AcctivationDate;
	struct tm    Card_ExpirationDate;
	
	/* Add User Accounts */
	BankServerObj->BankServer_AddUserAccount("Yasmeen" , 182936291729373 , 100000);
	BankServerObj->BankServer_AddUserAccount("Ibrahim" , 182936291729323 , 200000);
	BankServerObj->BankServer_AddUserAccount("Ghareeb" , 182936291729334 , 50000 );
	
	/* Create User Cards */
	std::time(&Date_String);
	AcctivationDate = std::gmtime(&Date_String);
	
	Card_ExpirationDate.tm_sec  = AcctivationDate->tm_sec  ; 
	Card_ExpirationDate.tm_min  = AcctivationDate->tm_min  ;  
	Card_ExpirationDate.tm_hour = AcctivationDate->tm_hour ;  
	Card_ExpirationDate.tm_mday = AcctivationDate->tm_mday ;   
	Card_ExpirationDate.tm_mon  = AcctivationDate->tm_mon  ;  
	Card_ExpirationDate.tm_year = AcctivationDate->tm_year  + 5;
	Card_ExpirationDate.tm_wday = AcctivationDate->tm_wday ; 
	Card_ExpirationDate.tm_yday = AcctivationDate->tm_yday ;  
	Card_ExpirationDate.tm_isdst= AcctivationDate->tm_isdst;      
	Card* UserCard1 = new Card("Yasmeen" , 182936291729373 , Card_ExpirationDate ,*AcctivationDate );	
	Card* UserCard2 = new Card("Ibrahim" , 182936291729323 , Card_ExpirationDate ,*AcctivationDate );
	Card* UserCard3 = new Card("Ghareeb" , 182936291729334 , Card_ExpirationDate ,*AcctivationDate );
	
	/* User 1 interfacing with the machine to */
	MachineStatusLOC = MachineObj->Machine_Init(UserCard1);
	
	delete UserCard1;
	delete UserCard2;
	delete UserCard3;
	
	return 0;
}
