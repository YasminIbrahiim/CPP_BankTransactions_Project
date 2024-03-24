/**************************************************************************************/
/**** File name  : Machine.h                                                  *********/  
/**** Author     : Yasmeen Ibrahim                                            *********/
/**** Description:                                                            *********/
/**************************************************************************************/
#ifndef  MACHINE_H
#define  MACHINE_H

typedef enum
{
	E_OK,
	ERROR_DATA_NOT_VALID,
	ERROR_CARD_EXPIRED,
	ERROR_SAVE_TRANSACTION_FAILED
}enuMachineStatus;


class Machine
{
private:
	static Machine* ptrMachineObj;
public:
	Machine() = default;
	~Machine() = default;
	Machine(const Machine& MachineObj) = delete;
	static Machine*   GetMachineInstance(void);
	enuMachineStatus Machine_Init(Card* CardDataPtr);
	enuMachineStatus Machine_CheckDataValidation(uint64_t Card_IDCpy);
	enuMachineStatus Machine_CheckCardExpirationDate(const struct tm& CardExpirationDateRef);
	
};

#endif
