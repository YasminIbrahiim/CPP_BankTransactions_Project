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
	vector<Transaction*> UserTransactions;

public:
	User();
	~User();
	std::string User_GetUserName(void);
	uint64_t    User_GetUserID(void);
	uint64_t    User_GetSaved_Money(void);
	void User_SetUserName(const std::string& UserNameCpy);
	void User_SetUserID(uint64_t UserIDCpy);
	void User_SetSaved_Money(uint64_t Saved_MoneyCpy);
};

#endif
