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

public:
	enuMachineStatus Machine_CheckDataValidation(void);
	enuMachineStatus Machine_CheckCardExpirationDate(void);
	enuMachineStatus Machine_SaveTransaction(Transaction* ptrTransaction);
	
};

#endi
