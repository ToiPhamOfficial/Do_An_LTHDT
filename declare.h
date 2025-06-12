/*
-- Nội dung tệp: Nơi khai báo các lớp và hàm
-- Số lớp: 5
-- Số hàm: ...
*/

// Khai báo các lớp
class Date;
class SavingsAccount;
class TermAccount;
class NonTermAccount;
class Bank;

// Khai báo các hàm trong file "include/functions.h"
string trim(const string &s);  // Xoá khoảng trắng 2 đầu của chuỗi
double roundToTwoDecimals(double x); // Làm tròn số đến 2 chữ số thập phân
void splitData(const string &s, string d_arr[], const int &n, const char &delimiter); // Chia chuỗi bằng kí tự phân cách
string formatVND(const double &amount); // Định dạng tiền Việt Nam
string correctName(const string &str); // Chuẩn hoá họ và tên
bool isNumberString(const string &s); // Trả về true nếu chuỗi là số nguyên dương
string toLowerCase(const string &str); // Chuyển chuỗi về chữ thường
bool isValidEmail(const string &email); // Kiểm tra tính hợp lệ của email
string reverseName(string &hoTen); // Đảo ngược họ và tên
template<class T>
void customSort(T *arr[], const int &n, bool (*cmp)(T*, T*), bool ascending = true);

// Khai báo các hàm trong file "include/iofile.h"
string getHorizontalBorder(const int &type); // Trả về đường kẻ ngang của bảng
string getTableHeader(const int &type); // Trả về các cột tiêu đề của bảng
string getTableRow(const int &type, SavingsAccount *acc, const int &i); // Trả về hàng dữ liệu mỗi sổ tiết kiệm của bảng
void exportBankInfo(Bank &B); // Xuất thông tin ngân hàng ra tệp
void exportBankReport(Bank &B); // Xuất báo cáo ngân hàng
void exportTable(const string &title, SavingsAccount *accounts[], int n); // Xuất các sổ tiết kiệm ra tệp

// Khai báo các hàm trong file "include/menu.h"
void showBanner(); // Hiển thị banner
void showMenu(); // Hiển thị menu
void showMenu1(); // Hiển thị menu của lựa chọn 1
void showMenu1_1(); // Hiển thị menu của lựa chọn 1.1
void showMenu1_2(); // Hiển thị menu của lựa chọn 1.2
void showMenu3(); // Hiển thị mnenu của lựa chọn 3
void showMenu4(); // Hiển thị menu của lựa chọn 4
void showMenu5(); // Hiển thị menu của lựa chọn 5
void showmenu5_1(); // Hiển thị menu của lựa chọn 5.1
void showMenu5_2(); // Hiển thị menu của lựa chọn 5.2
int getChoice(const int &minChoice, const int &maxChoice, const string &optionInfo = ""); // Trả về lựa chọn từ menu
void handleChoice1_1(Bank &B); // Xử lí lựa chọn menu 1.1
void handleChoice1_2(Bank &B); // Xử lí lựa chọn menu 1.2
void handleChoice1(Bank &B); // Xử lí lựa chọn 1
void handleChoice2(Bank &B); // Xử lí lựa chọn 2
void handleChoice3(Bank &B); // Xử lí lựa chọn 3
void handleChoice4(Bank &B); // Xử lí lựa chọn 4
void handleChoice5_1_1(Bank &B); // Xử lí kết quả sau khi tìm kiếm
void handleChoice5_1(Bank &B); // Xử lí lựa chọn menu 5.1
void handleChoice5_2(Bank &B); // Xử lí lựa chọn menu 5.2
void handleChoice5(Bank &B); // Xử lí lựa chọn 5
void handleChoice6(Bank &B); // Xử lí lựa chọn 6
void handleChoice7(Bank &B); // Xử lí lựa chọn 7
void handleChoice8(Bank &B); // Xử lí lựa chọn 8
void handleChoice9(Bank &B); // Xử lí lựa chọn 9
void handleMainMenu(Bank &B); // Hàm xử lí các lựa chọn trong menu chính