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
		if (num == 1) { //���� ����
			Aif.PnewAcc();
		}
		else if (num == 2) { //�Ա�
			Aif.Pdeposit();
		}
		else if (num == 3) {//���
			Aif.Pwithdraw();
		}
		else if (num == 4) {//�ܾ� ��ȸ
			Aif.Pbalance();
		}
		else if (num == 5) {//������ü
			Aif.Ptransfer();
		}
		else if (num == 6) {//����
			Aif.end();
			break;
		}
		cout << endl;
	}
	return 0;
}
