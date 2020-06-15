#include "Account.h"
#include "Account_interface.h"

#include <iostream>
using namespace std;

void Account_interface::Pmenu() {
	cout << "------------------------------" << endl;
	cout << "1. 계좌 생성" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 잔액 조회" << endl;
	cout << "5. 계좌 이체" << endl;
	cout << "6. 종료" << endl;
	cout << "------------------------------" << endl;
	cout << "번호를 입력해 주세요 >> ";
}
void Account_interface::PnewAcc(){
	int balance;
	int password;
	int accountid;

	cout << "생성할 계좌 번호를 입력해 주세요(계좌번호 첫 숫자는 0을 제외해 주세요.) >> ";
	cin >> accountid;
	cout << "생성할 정수 4자리 비밀번호를 입력해 주세요(비밀번호 첫 숫자는 0을 제외해 주세요.) >> ";
	cin >> password;
	cout << "생성시 계좌의 넣을 금액을 입력해 주세요 >> ";
	cin >> balance;
	Bank[person] = new smartbanking(balance, password, accountid);
	person++;
	cout << "계좌가 생성되었습니다." << endl;
}

void Account_interface::Pwithdraw() {
	int password;
	int money;
	cout << "본인 계좌의 비밀번호를 입력해주세요 >> ";
	cin >> password;
	cout << "출금할 금액을 입력해주세요 >> ";
	cin >> money;
	int tempmoney, i, check = 0;
	for (i = 0; i < person; i++) {
		if (Bank[i]->getpassword() == password) {
			tempmoney = Bank[i]->withdraw(money);
			if (tempmoney == 0)
				cout << "잔액이 부족합니다." << endl;
			else
				cout << tempmoney << "원이 출금되었습니다. 잔액은 " << Bank[i]->getbalance() << "원 입니다." << endl;
			check = 1;
		}
	}
	if (check == 0)
		cout << "비밀번호가 틀렸습니다." << endl;
}




void Account_interface::Pdeposit(){
	int accountid;
	int money;
	int i, check = 0;
	cout << "입금할 계좌 번호를 입력해 주세요 >> ";
	cin >> accountid;
	cout << "입금할 금액을 입력해 주세요 >> ";
	cin >> money;
	for (i = 0; i < person; i++) {
		if (Bank[i]->getaccountid() == accountid) {
			cout << "입금 되었습니다. 잔액은" << Bank[i]->deposit(money)<< "원 입니다." <<endl;
			check = 1;
		}
	}
	if (check == 0)
		cout << "일치하는 계좌번호가 없습니다." << endl;
}


void Account_interface::Pbalance() {
	int password;
	cout << "본인 계좌의 비밀번호를 입력해주세요 >> ";
	cin >> password;
	int i, check = 0;
	for (i = 0; i < person; i++) {
		if (Bank[i]->getpassword() == password) {
			cout << "잔액은 " << Bank[i]->getbalance() << "원 입니다" << endl;
			check = 1;
		}
	}
	if (check == 0)
		cout << "비밀번호가 틀렸습니다." << endl;
}

void Account_interface::Ptransfer() {
	int password;
	int accountid;
	int money;
	int temp1, temp2;
	int check1 = 0, check2 = 0;
	cout << "본인 계좌의 비밀번호를 입력해주세요 >> ";
	cin >> password;
	for (int i = 0; i < person; i++) {
		if (Bank[i]->getpassword() == password) {
			temp1 = i;
			check1 = 1;
		}
	}
	cout << "입금할 계좌 번호를 입력해 주세요 >> ";
	cin >> accountid;
	cout << "입금할 금액을 입력해 주세요 >> ";
	cin >> money;
	for (int i = 0; i < person; i++) {
		if (Bank[i]->getaccountid() == accountid) {
			temp2 = i;
			check2 = 1;
		}
	}
	if (check1 == 1 && check2 == 1) {
		cout << "계좌이체 후 잔액은 " << Bank[temp1]->account_transfer(money,Bank[temp2]) << "원 입니다." << endl;
	}
	else if (check1 == 1 && check2 == 0) {
		cout << "존재하지 않는 계좌번호 입니다." << endl;
	}
	else if (check1 == 0 && check2 == 1) {
		cout << "비밀번호가 틀렸습니다." << endl;
	}
	else if (check1 == 0 && check2 == 0) {
		cout << "비밀번호와 계좌번호가 틀렸습니다." << endl;
	}
}

void Account_interface::end() {
	for(int i=0; i < person; i++)
		delete Bank[i];
}