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
#define max 1000 //�涨ͨѶ¼��С
/*
�����ϵ��ʵ�ֲ���
1. �����ϵ�˽ṹ��
2. ���ͨѶ¼�ṹ��
3. main�����д���ͨѶ¼
4. ��װ�����ϵ�˺���
4. ���Թ���
*/
struct Person {
	string m_name;
	string m_sex;
	int m_age;
	string m_phoneNumber;
	string m_address;
};
struct Addressbooks {
	struct Person personArray[max];
	int size;
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
void addPerson(Addressbooks * p) 
{
	if (p->size == max) {
		cout << "ͨѶ¼�����޷����" << endl;
		return;
	}
	else {
		string name;
		cout << "����������" << endl;
		cin >> name;
		p->personArray[p->size].m_name = name;

		string sex;
		cout << "�������Ա�" << endl;
		cin >> sex;
		p->personArray[p->size].m_sex = sex;

		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		p->personArray[p->size].m_address = address;

		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		p->personArray[p->size].m_phoneNumber = phone;

		int age;
		cout << "����������" << endl;
		cin >> age;
		p->personArray[p->size].m_age = age;

		p->size++;
	}

}

void showPerson(struct Addressbooks * adb) {
	if (adb->size == 0) {
		cout << "��ǰͨѶ¼������ϵ��" << endl;
		
	}
	else {
		for (int i = 0; i < adb->size; i++) {
			cout << i + 1 << "." << adb->personArray[i].m_name
				<< "," << adb->personArray[i].m_age
				<< "," << adb->personArray[i].m_sex
				<< "," << adb->personArray[i].m_phoneNumber
				<< "," << adb->personArray[i].m_address << endl;
		}
	}
	system("pause");
	system("cls");//����

};

int seek(struct Addressbooks * ads) {
	if (ads->size == 0) {
		cout << "ͨѶ¼Ϊ�գ��������ϵ��" << endl;
		system("pause");
		return -1;
	}
	string seekName;
	cout << "��������ϵ������" << endl;
	cin >> seekName;
	int i = 0;
	while (i < ads->size) {
		if (ads->personArray[i].m_name == seekName)
			{return i; }
			i++;
		
		
	}
	cout << "δ�ҵ���ϵ�ˣ�" << endl;
	system("pause");
	return -1;
};

void changePerson(Addressbooks* ads, int i) {
	int number = 0;
	while (number != 6) {
		cout << "��ѡ��Ҫ�޸ĵ���Ϣ:1.������2.�Ա�3.��ַ��4.�绰��5.���䣬6.�˳��޸�" << endl;
		cin >> number;
		string n_name;
		string n_sex;
		string n_address;
		string n_phone;
		int n_age;

		switch (number) {
		case 1:
		{
			cout << "������������" << endl;
			cin >> n_name;
			ads->personArray[i].m_name = n_name; }
			break;
		case 2:
		{
			cout << "�������Ա�" << endl;
			cin >> n_sex;
			ads->personArray[i].m_sex = n_sex; }
		break;
		case 3:
		{
			cout << "�������ַ��" << endl;
			cin >> n_address;
			ads->personArray[i].m_address = n_address; }
		break;
		case 4:
		{
			cout << "������绰��" << endl;
			cin >> n_phone;
			ads->personArray[i].m_phoneNumber = n_phone; }
		break;
		case 5:
		{
			cout << "���������䣺" << endl;
			cin >> n_age;
			ads->personArray[i].m_age = n_age; }
		break;
		case 6:
			system("pause");
			break;
		}
	}
	
};
void deletPerson(Addressbooks * ads, int i) {
	for (; i < ads->size - 1; i++) {
		ads->personArray[i] = ads->personArray[i + 1];
	}
	ads->size--;
	cout << "ɾ����ϣ�" << endl;
	system("pause");
};

void cleanBook(Addressbooks* ads) {
	ads->size = 0;
	cout << "����ɹ���"<< endl;
	system("pause");
	system("cls");
}
int main() {
	int select = 0;
	//����ͨѶ¼
	Addressbooks newBook;
	//��ʼ��ͨѶ¼��Ա����
	newBook.size = 0;
	

	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1:
			addPerson(&newBook);
			break;
		case 2:
			showPerson(&newBook);
			break;
		case 3:
		{
			int i = seek(&newBook);
			if (i != -1) {
				deletPerson(&newBook, i);
			}
		}
			break;
		case 4:
		{int i = seek(&newBook);
		if (i != -1) {
			cout << i + 1 << "." << newBook.personArray[i].m_name
				<< "," << newBook.personArray[i].m_age
				<< "," << newBook.personArray[i].m_sex
				<< "," << newBook.personArray[i].m_phoneNumber
				<< "," << newBook.personArray[i].m_address << endl;
		}}
			break;
		case 5:
		{
			int i = seek(&newBook);
			if (i != -1) {
				changePerson(&newBook, i);
			}
		}
			break;
		case 6:
			cleanBook(&newBook);
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