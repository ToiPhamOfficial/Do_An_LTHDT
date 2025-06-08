// Include thư viện
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;

// Định nghĩa màu sắc
#define BLACK "\033[0;30m"
#define WHITE "\033[0;37m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

// Khai báo và định nghĩa hằng
const int MAX_CUSTOMER = 100;
// Khai báo và định nghĩa các biến toàn cục
bool running = true; // Biến trạng thái chạy của hệ thống

// Include các tệp header riêng
#include "declare.h"
#include "include/class.h"
#include "include/functions.h"
#include "include/iofile.h"
#include "include/menu.h"

int main() {
    Bank B;
    B.loadFromFile();
    //B.saveToFile()
    
    // beta - Set global bank pointer for search result operations
    bank = &B;

    // Hiển thị menu chính
    while(running) {
        system("cls");
        cout << CYAN;
        cout << setw(75) << "/-------------------------------------\\" << endl
             << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
        cout << WHITE;
        cout << " HE THONG QUAN LI TAI KHOAN TIET KIEM ";
        cout << CYAN;
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
             << setw(75) << "\\-------------------------------------/" << endl;
        cout << RESET;
        handleMainMenu(B);
    }

    system("pause");
}


/// Xem dữ liệu có hợp lệ hay ko trước khi saveToFile