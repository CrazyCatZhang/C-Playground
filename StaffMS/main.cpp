#include <iostream>
#include "Header/WorkerManagement.h"
#include "Source/WorkerManagement.cpp"
using namespace std;

int main() {

    WorkerManagement workerManagement;
    int select = 0;
    while (1){
        workerManagement.ShowMenu();
        cout << "请选择：" << endl;
        cin >> select;
        switch (select) {
            case 0:
                workerManagement.Exit();
                break;
            case 1:
                workerManagement.addEmployee();
                break;
            case 2:
                workerManagement.ShowEmployee();
                break;
            case 3:
                workerManagement.deleteEmployee();
                break;
            case 4:
                workerManagement.updateEmployee();
                break;
            case 5:
                workerManagement.selectEmployee();
                break;
            case 6:
                workerManagement.sortEmployee();
                break;
            case 7:
                workerManagement.emptyFile();
                break;
            default:
                cout << "输入有误 请重新输入...";
                cout << "按Enter键继续";
                getchar();
                cin.get();
                system("clear");
                break;
        }
    }

    return 0;
}
