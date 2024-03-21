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
	std::vector<Transaction>     UserTransactions;
	std::vector<Transaction>::iterator  Vect_UserTransactions_iterator;
public:
	User() = default;
	~User() = default;
	const std::string& User_GetUserName(void) const;
	uint64_t User_GetUserID(void) const;
	uint64_t User_GetSaved_Money(void) const;
	void User_SetUserName(const std::string& UserNameCpy) ;
	void User_SetUserID(uint64_t UserIDCpy) ;
	void User_SetSaved_Money(uint64_t Saved_MoneyCpy) ;
};

#endif
