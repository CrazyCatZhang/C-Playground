#include <iostream>
//#include "SpeakerManager.h"
#include "SpeakerManager.cpp"

int main() {

    srand((unsigned int)time(NULL));
    SpeakerManager speakerManager;
    int select = 0;
    while (true){
        speakerManager.ShowMenu();
        cout << "请选择：" << endl;
        cin >> select;
        switch (select) {
            case 0:
                speakerManager.exitSystem();
                break;
            case 1:
                speakerManager.startCompetition();
                break;
            case 2:
                speakerManager.showRecord();
                break;
            case 3:
                speakerManager.clearFile();
                break;
            default:
                break;
        }
    }
    return 0;
}
