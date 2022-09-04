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
#define max 1000 //规定通讯录大小
/*
添加联系人实现步骤
1. 设计联系人结构体
2. 设计通讯录结构体
3. main函数中创建通讯录
4. 封装添加联系人函数
4. 测试功能
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
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
};
void addPerson(Addressbooks * p) 
{
	if (p->size == max) {
		cout << "通讯录已满无法添加" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		p->personArray[p->size].m_name = name;

		string sex;
		cout << "请输入性别" << endl;
		cin >> sex;
		p->personArray[p->size].m_sex = sex;

		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		p->personArray[p->size].m_address = address;

		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		p->personArray[p->size].m_phoneNumber = phone;

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		p->personArray[p->size].m_age = age;

		p->size++;
	}

}

void showPerson(struct Addressbooks * adb) {
	if (adb->size == 0) {
		cout << "当前通讯录暂无联系人" << endl;
		
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
	system("cls");//清屏

};
int main() {
	int select = 0;
	//创建通讯录
	Addressbooks newBook;
	//初始化通讯录人员个数
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