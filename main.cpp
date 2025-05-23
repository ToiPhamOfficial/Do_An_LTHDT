// Include thư viện
#include <iostream>
#include <string>
using namespace std;

// Khai báo các biến toàn cục
string *settings = new string[5]; // Biến chứa các cài đặt của hệ thống
string *lang_data = new string[15]; // Biến chứa ngôn ngữ hệ thống
bool running = true; // Biến trạng thái chạy của hệ thống

// Include các tệp header riêng
#include "include.h"
#include "include/class.h"
#include "include/iofile.h"
#include "include/menu.h"
#include "include/functions.h"

int main() {
    // Dọn màn hình terminal
    system("cls");

    // Tải cài đặt hệ thống
    readFile("settings.st", settings, 5);

    // Tải ngôn ngữ
    loadLang(settings[1], lang_data, 15);

    // Hiển thị menu chính
    while(running) {
        mainMenu();
        handleMainMenu(selectionInMenu(6));
    }

    //testOutput();

    delete[] settings;
    delete[] lang_data;
    system("pause");
}
