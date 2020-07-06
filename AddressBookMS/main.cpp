#include <iostream>
#define MAX 1000
using namespace std;

struct Person {
    string name;
    int sex;
    int age;
    string phone;
    string address;
};
struct AddressBooks {
    Person person[MAX];
    int maxsize;
};


void showMenu() {
    cout << "************************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查询联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空通讯录 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "************************" << endl;
}

void addPerson(AddressBooks *addressBooks) {

    if (addressBooks->maxsize == MAX) {
        cout << "通讯录已满 请删除用户..." << endl;
        return;
    } else {
        cout << "请输入姓名:" << endl;
        string name;
        cin >> name;
        addressBooks->person[addressBooks->maxsize].name = name;
        cout << "请输入年龄:" << endl;
        int age;
        cin >> age;
        addressBooks->person[addressBooks->maxsize].age = age;
        cout << "请输入性别:" << endl;
        cout << "1——Man" << endl;
        cout << "2——Woman" << endl;
        int sex;
        while (1) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                addressBooks->person[addressBooks->maxsize].sex = sex;
                break;
            } else {
                cout << "输入有误 请重新输入..." << endl;
            }
        }
        cout << "请输入电话号码：" << endl;
        string phone;
        cin >> phone;
        addressBooks->person[addressBooks->maxsize].phone = phone;
        cout << "请输入地址：" << endl;
        string address;
        cin >> address;
        addressBooks->person[addressBooks->maxsize].address = address;
        addressBooks->maxsize++;
        cout << "添加成功..." << endl;
    }
    cout << "按任意键继续..." << endl;
    system("read");
    system("clear");
}

void showPerson(AddressBooks *addressBooks) {
    if (addressBooks->maxsize == 0) {
        cout << "通讯录没有用户信息 请添加..." << endl;
    } else {
        for (int i = 0; i < addressBooks->maxsize; ++i) {
            cout << "姓名：" << addressBooks->person[i].name << "\t";
            cout << "性别：" << (addressBooks->person[i].sex == 1 ? "Man" : "Woman") << "\t";
            cout << "年龄：" << addressBooks->person[i].age << "\t";
            cout << "电话：" << addressBooks->person[i].phone << "\t";
            cout << "地址：" << addressBooks->person[i].address << endl;
        }
    }
    cout << "按任意键继续..." << endl;
    system("read");
    system("clear");
}

int isExist(AddressBooks * addressBooks,string name){
    for (int i = 0; i < addressBooks->maxsize; ++i) {
        if (addressBooks->person[i].name == name)
            return i;
    }
    return -1;
}

void deletePerson(AddressBooks * addressBooks){
    cout << "请输入你要删除的用户的名字：" << endl;
    string name;
    cin >> name;
    if (isExist(addressBooks,name) != -1){
        for (int i = isExist(addressBooks,name); i < addressBooks->maxsize; ++i) {
            addressBooks->person[i] = addressBooks->person[i + 1];
        }
        addressBooks->maxsize--;
        cout << "删除成功..." << endl;
    } else{
        cout << "未找到该用户 请添加..." << endl;
    }
    cout << "按任意键继续..." << endl;
    system("read");
    system("clear");
}

void selectPerson(AddressBooks * addressBooks){
    cout << "请输入你要查询的用户的名字：" << endl;
    string name;
    cin >> name;
    if (isExist(addressBooks,name) != -1){
        cout << "姓名：" << addressBooks->person[isExist(addressBooks,name)].name << "\t";
        cout << "性别：" << (addressBooks->person[isExist(addressBooks,name)].sex == 1 ? "Man" : "Woman") << "\t";
        cout << "年龄：" << addressBooks->person[isExist(addressBooks,name)].age << "\t";
        cout << "电话：" << addressBooks->person[isExist(addressBooks,name)].phone << "\t";
        cout << "地址：" << addressBooks->person[isExist(addressBooks,name)].address << endl;
    } else{
        cout << "未查询到该用户 请添加..." << endl;
    }
    cout << "按任意键继续..." << endl;
    system("read");
    system("clear");
}

void updatePerson(AddressBooks * addressBooks){
    cout << "请输入你要修改的用户的名字：" << endl;
    string name;
    cin >> name;
    int result = isExist(addressBooks,name);
    if (result != -1){
        cout << "请输入新的姓名:" << endl;
        string name;
        cin >> name;
        addressBooks->person[result].name = name;
        cout << "请输入新的年龄:" << endl;
        int age;
        cin >> age;
        addressBooks->person[result].age = age;
        cout << "请输入新的性别:" << endl;
        cout << "1——Man" << endl;
        cout << "2——Woman" << endl;
        int sex;
        while (1) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                addressBooks->person[result].sex = sex;
                break;
            } else {
                cout << "输入有误 请重新输入..." << endl;
            }
        }
        cout << "请输入新的电话号码：" << endl;
        string phone;
        cin >> phone;
        addressBooks->person[result].phone = phone;
        cout << "请输入新的地址：" << endl;
        string address;
        cin >> address;
        addressBooks->person[result].address = address;
        cout << "修改成功..." << endl;
    } else{
        cout << "用户不存在 请添加..." << endl;
    }
    cout << "按任意键继续..." << endl;
    system("read");
    system("clear");
}

void emptyPerson(AddressBooks * addressBooks){
    if (addressBooks->maxsize == 0){
        cout << "该通讯录已经为空..." << endl;
    } else{
        addressBooks->maxsize = 0;
        cout << "清空成功..." << endl;
    }
    cout << "按任意键继续..." << endl;
    system("read");
    system("clear");
}

int main() {

    AddressBooks addressBooks;
    addressBooks.maxsize = 0;
    int select;
    while (1) {
        showMenu();
        cout << "请选择：" << endl;
        cin >> select;
        switch (select) {
            case 1:
                addPerson(&addressBooks);
                break;
            case 2:
                showPerson(&addressBooks);
                break;
            case 3:
                deletePerson(&addressBooks);
                break;
            case 4:
                selectPerson(&addressBooks);
                break;
            case 5:
                updatePerson(&addressBooks);
                break;
            case 6:
                emptyPerson(&addressBooks);
                break;
            case 0:
                cout << "欢迎下次使用..." << endl;
                cout << "按任意键继续..." << endl;
                system("read");
                system("clear");
                return 0;
            default:
                cout << "输入有误 请重新输入..." << endl;
                cout << "按任意键继续..." << endl;
                system("read");
                system("clear");
                break;
        }
    }
}
