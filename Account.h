#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
protected:
	int balance;
	int password;
public:
	Account(int balance, int password);
	int withdraw(int money);
	int deposit(int money);
	int getbalance();
	int getpassword();
	~Account();
};

class smartbanking : public Account {
	int accountid;
public:
	smartbanking(int balance, int password, int accountid);
	int getaccountid();
	int account_transfer(int money, smartbanking* acc1);
	~smartbanking();
};
#endif