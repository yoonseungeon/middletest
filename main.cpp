#include "Account_interface.h"
#include "Account.h"

#include <iostream>
using namespace std;

int main(void) {
	Account_interface Aif;
	int num;
	while (true) {
		Aif.Pmenu();
		cin >> num;
		if (num == 1) { //계좌 생성
			Aif.PnewAcc();
		}
		else if (num == 2) { //입금
			Aif.Pdeposit();
		}
		else if (num == 3) {//출금
			Aif.Pwithdraw();
		}
		else if (num == 4) {//잔액 조회
			Aif.Pbalance();
		}
		else if (num == 5) {//계좌이체
			Aif.Ptransfer();
		}
		else if (num == 6) {//종료
			Aif.end();
			break;
		}
		cout << endl;
	}
	return 0;
}
