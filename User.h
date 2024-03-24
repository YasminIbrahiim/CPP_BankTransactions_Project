/**************************************************************************************/
/**** File name  : User.h                                                     *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/

#ifndef  USER_H
#define  USER_H

class User
{
private: 
	std::string    UserName;
	uint64_t       UserID;
	uint64_t       Saved_Money;
	std::vector<Transaction*>    VecUserTransactionsPtr;
	std::vector<Transaction*>::iterator  VecUserTransactions_iterator;
	struct tm   CardExpirationDate;
	struct tm   CardAcctivationDate;
	
public:
	User() = default;
	~User();
	const std::string& User_GetUserName(void) const;
	uint64_t User_GetUserID(void) const;
	uint64_t User_GetSaved_Money(void) const;
	const struct tm& User_GetCardExpirationDate(void) const;
	const struct tm& User_GetCardAcctivationDate(void) const;
	
	void User_SetUserName(const std::string& UserNameCpy) ;
	void User_SetUserID(uint64_t UserIDCpy) ;
	void User_SetSaved_Money(uint64_t Saved_MoneyCpy) ;
	void User_SetCardExpirationDate(const struct tm& CardExpirationDateRef);
	void User_SetCardAcctivationDate(const struct tm& CardAcctivationDateRef);
	void User_AddTransaction(Transaction* UserTransactionPtr);
};

#endif
