/*
* ͨѶ¼����ϵͳ
* ϵͳ���ܣ�
* 1.�����ϵ�ˣ���ϵͳ��������ˣ���Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ��
* 2.��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
* 3.ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
* 4.������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
* 5.�޸���ϵ�ˣ��������������޸�ָ����ϵ��
* 6.�����ϵ�ˣ����ͨѶ¼��������Ϣ
* 7.�˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼
*/

#include<iostream>
#include<string>
using namespace std;

struct people {
	string name;
	string sex;
	int age;
	string phoneNumber;
	string address;
};
void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
};
int main() {
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;

		}
	}

	system("pause");
	return 0;
};