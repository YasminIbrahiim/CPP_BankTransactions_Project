/**************************************************************************************/
/**** File name  : Card.h                                                     *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#ifndef  CARD_H
#define  CARD_H

class Card
{
private:
	std::string User_Name;
	uint64_t    Card_ID;
	struct tm   Card_ExpirationDate;
	struct tm   Card_AcctivationDate;
	
public: 
	Card()  = default;
	~Card() = default;
	
	void  Card_SetUserName(const std::string& User_NameCpy);
	void  Card_SetUserID(uint64_t   Card_IDCpy);
	void  Card_SetExpirationDate(const struct tm&  Card_ExpirationDateRef);
	void  Card_SetAcctivationDate(const struct tm&  Card_AcctivationDateRef);
	
	const std::string& Card_GetUserName(void) const;
	uint64_t  Card_GetUserID(void) const;
	const struct tm&  Card_GetExpirationDate(void) const;
	const struct tm&  Card_GetAcctivationDate(void) const;
};

#endif