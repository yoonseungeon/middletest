#include "Account.h"
#include "Account_interface.h"

#include <iostream>
using namespace std;

void Account_interface::Pmenu() {
	cout << "------------------------------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �ܾ� ��ȸ" << endl;
	cout << "5. ���� ��ü" << endl;
	cout << "6. ����" << endl;
	cout << "------------------------------" << endl;
	cout << "��ȣ�� �Է��� �ּ��� >> ";
}
void Account_interface::PnewAcc(){
	int balance;
	int password;
	int accountid;

	cout << "������ ���� ��ȣ�� �Է��� �ּ���(���¹�ȣ ù ���ڴ� 0�� ������ �ּ���.) >> ";
	cin >> accountid;
	cout << "������ ���� 4�ڸ� ��й�ȣ�� �Է��� �ּ���(��й�ȣ ù ���ڴ� 0�� ������ �ּ���.) >> ";
	cin >> password;
	cout << "������ ������ ���� �ݾ��� �Է��� �ּ��� >> ";
	cin >> balance;
	Bank[person] = new smartbanking(balance, password, accountid);
	person++;
	cout << "���°� �����Ǿ����ϴ�." << endl;
}

void Account_interface::Pwithdraw() {
	int password;
	int money;
	cout << "���� ������ ��й�ȣ�� �Է����ּ��� >> ";
	cin >> password;
	cout << "����� �ݾ��� �Է����ּ��� >> ";
	cin >> money;
	int tempmoney, i, check = 0;
	for (i = 0; i < person; i++) {
		if (Bank[i]->getpassword() == password) {
			tempmoney = Bank[i]->withdraw(money);
			if (tempmoney == 0)
				cout << "�ܾ��� �����մϴ�." << endl;
			else
				cout << tempmoney << "���� ��ݵǾ����ϴ�. �ܾ��� " << Bank[i]->getbalance() << "�� �Դϴ�." << endl;
			check = 1;
		}
	}
	if (check == 0)
		cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
}




void Account_interface::Pdeposit(){
	int accountid;
	int money;
	int i, check = 0;
	cout << "�Ա��� ���� ��ȣ�� �Է��� �ּ��� >> ";
	cin >> accountid;
	cout << "�Ա��� �ݾ��� �Է��� �ּ��� >> ";
	cin >> money;
	for (i = 0; i < person; i++) {
		if (Bank[i]->getaccountid() == accountid) {
			cout << "�Ա� �Ǿ����ϴ�. �ܾ���" << Bank[i]->deposit(money)<< "�� �Դϴ�." <<endl;
			check = 1;
		}
	}
	if (check == 0)
		cout << "��ġ�ϴ� ���¹�ȣ�� �����ϴ�." << endl;
}


void Account_interface::Pbalance() {
	int password;
	cout << "���� ������ ��й�ȣ�� �Է����ּ��� >> ";
	cin >> password;
	int i, check = 0;
	for (i = 0; i < person; i++) {
		if (Bank[i]->getpassword() == password) {
			cout << "�ܾ��� " << Bank[i]->getbalance() << "�� �Դϴ�" << endl;
			check = 1;
		}
	}
	if (check == 0)
		cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
}

void Account_interface::Ptransfer() {
	int password;
	int accountid;
	int money;
	int temp1, temp2;
	int check1 = 0, check2 = 0;
	cout << "���� ������ ��й�ȣ�� �Է����ּ��� >> ";
	cin >> password;
	for (int i = 0; i < person; i++) {
		if (Bank[i]->getpassword() == password) {
			temp1 = i;
			check1 = 1;
		}
	}
	cout << "�Ա��� ���� ��ȣ�� �Է��� �ּ��� >> ";
	cin >> accountid;
	cout << "�Ա��� �ݾ��� �Է��� �ּ��� >> ";
	cin >> money;
	for (int i = 0; i < person; i++) {
		if (Bank[i]->getaccountid() == accountid) {
			temp2 = i;
			check2 = 1;
		}
	}
	if (check1 == 1 && check2 == 1) {
		cout << "������ü �� �ܾ��� " << Bank[temp1]->account_transfer(money,Bank[temp2]) << "�� �Դϴ�." << endl;
	}
	else if (check1 == 1 && check2 == 0) {
		cout << "�������� �ʴ� ���¹�ȣ �Դϴ�." << endl;
	}
	else if (check1 == 0 && check2 == 1) {
		cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
	}
	else if (check1 == 0 && check2 == 0) {
		cout << "��й�ȣ�� ���¹�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
	}
}

void Account_interface::end() {
	for(int i=0; i < person; i++)
		delete Bank[i];
}