#include <iostream>
#include "Management/Management.h"


int main() {
    Management management;
    int select = 0;
    while (1){
        management.ShowMenu();
        cout << "请选择：" << endl;
        cin >> select;
        switch (select) {
            case 1:
                management.login(STUDENTFILE,1);
                break;
            case 2:
                management.login(TEACHERFILE,2);
                break;
            case 3:
                management.login(ADMINFLE,3);
                break;
            case 0:
                management.exitSystem();
                break;
            default:
                break;
        }
    }

    return 0;
}
