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

// Khai báo và định nghĩa hằng, biến toàn cục
const int MAX_CUSTOMER = 100;
bool running = true; // Biến điều khiển vòng lặp chính

// Include các tệp header riêng
#include "declare.h"
#include "include/class.h"
#include "include/functions.h"
#include "include/iofile.h"
#include "include/menu.h"   

int main() {
    // Tạo đối tượng ngân hàng để quản lí sổ tiết kiệm 
    Bank B;
    B.loadFromFile();
    // Hiển thị menu chính
    while(running) {
        system("cls");
        showBanner();
        handleMainMenu(B);
    }

    system("pause");
    return 0;
}