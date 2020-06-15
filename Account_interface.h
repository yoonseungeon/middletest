#ifndef ACCOUNT_INTERFACE_H
#define ACCOUNT_INTERFACE_H

#include "Account.h"

class Account_interface {
	int person= 0;
	smartbanking* Bank[10];
public:
	void Pmenu();
	void PnewAcc();
	void Pdeposit();
	void Pwithdraw();
	void Pbalance();
	void Ptransfer();
	void end();
};

#endif