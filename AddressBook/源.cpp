/*
* 通讯录管理系统
* 系统功能：
* 1.添加联系人：向系统中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）
* 2.显示联系人：显示通讯录中所有联系人信息
* 3.删除联系人：按照姓名进行删除指定联系人
* 4.查找联系人：按照姓名查看指定联系人信息
* 5.修改联系人：按照姓名重新修改指定联系人
* 6.清空联系人：清空通讯录中所有信息
* 7.退出通讯录：退出当前使用的通讯录
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
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
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
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;

		}
	}

	system("pause");
	return 0;
};