// Include thư viện
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <map>
using namespace std;

// Khai báo các biến toàn cục
string *settings = new string[5]; // Biến chứa các cài đặt của hệ thống
string *lang_data = new string[15]; // Biến chứa ngôn ngữ hệ thống
bool running = true; // Biến trạng thái chạy của hệ thống

// Include các tệp header riêng
#include "declare.h"
#include "include/class.h"
#include "include/iofile.h"
#include "include/menu.h"
#include "include/functions.h"

int main() {
    // Tải cài đặt hệ thống
    readFile("settings.st", settings, 5);

    // Tải ngôn ngữ
    loadLang(settings[1], lang_data, 15);

    // Hiển thị menu chính
    while(!running) {
        system("cls");
        mainMenu();
        handleMainMenu(chooseInMenu(6));
    }

    Bank b;
    b.loadFromFile();
    cout << b.accounts[0]->getDepositAmount() << endl;

    delete[] settings;
    delete[] lang_data;
    system("pause");
}
