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

int seek(struct Addressbooks * ads) {
	if (ads->size == 0) {
		cout << "通讯录为空！请添加联系人" << endl;
		system("pause");
		return -1;
	}
	string seekName;
	cout << "请输入联系人姓名" << endl;
	cin >> seekName;
	int i = 0;
	while (i < ads->size) {
		if (ads->personArray[i].m_name == seekName)
			{return i; }
			i++;
		
		
	}
	cout << "未找到联系人！" << endl;
	system("pause");
	return -1;
};

void changePerson(Addressbooks* ads, int i) {
	int number = 0;
	while (number != 6) {
		cout << "请选择要修改的信息:1.姓名，2.性别，3.地址，4.电话，5.年龄，6.退出修改" << endl;
		cin >> number;
		string n_name;
		string n_sex;
		string n_address;
		string n_phone;
		int n_age;

		switch (number) {
		case 1:
		{
			cout << "请输入姓名：" << endl;
			cin >> n_name;
			ads->personArray[i].m_name = n_name; }
			break;
		case 2:
		{
			cout << "请输入性别：" << endl;
			cin >> n_sex;
			ads->personArray[i].m_sex = n_sex; }
		break;
		case 3:
		{
			cout << "请输入地址：" << endl;
			cin >> n_address;
			ads->personArray[i].m_address = n_address; }
		break;
		case 4:
		{
			cout << "请输入电话：" << endl;
			cin >> n_phone;
			ads->personArray[i].m_phoneNumber = n_phone; }
		break;
		case 5:
		{
			cout << "请输入年龄：" << endl;
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
	cout << "删除完毕！" << endl;
	system("pause");
};

void cleanBook(Addressbooks* ads) {
	ads->size = 0;
	cout << "清除成功！"<< endl;
	system("pause");
	system("cls");
}
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
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;

		}
	}

	system("pause");
	return 0;
};