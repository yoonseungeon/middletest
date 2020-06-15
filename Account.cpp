#include "Account.h"

Account::Account(int balance, int password) {
	this->balance = balance;
	this->password = password;
}
int Account::withdraw(int money) {
	if (balance >= money) {
		balance -= money;
		return money;
	}
	else
		return 0;
}
int Account::deposit(int money) {
	balance += money;
	return balance;
}
int Account::getbalance() {
	return balance;
}
int Account::getpassword() {
	return password;
}
Account::~Account(){
}

smartbanking::smartbanking(int balance, int password, int accountid) : Account(balance, password) {
	this->accountid = accountid;
}

int smartbanking::getaccountid() {
	return accountid;
}
int smartbanking::account_transfer(int money, smartbanking* acc1) {
	if (balance >= money) {
		balance -= money;
		acc1->balance += money;
		return balance;
	}
	else
		return 0;
}
smartbanking::~smartbanking() {
}
