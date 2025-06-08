/*
-- Nội dung tệp: Nơi khai báo các lớp và hàm
-- Số lớp: ...
-- Số hàm: ...
*/

// Khai báo các lớp
class Date;
class SavingsAccount;
class TermAccount;
class NonTermAccount;
class Bank;

// Khai báo các hàm trong file "include/functions.h"
string trim(const string &s);  // Hàm xoá khoảng trắng 2 đầu của chuỗi
void splitData(const string &s, string d_arr[], const int &n, const char &delimiter); // Chia chuỗi bằng kí tự phân cách
string formatVND(const double &amount); // Hàm định dạng tiền Việt Nam
bool compareByName(SavingsAccount *a, SavingsAccount *b);
bool compareByBalance(SavingsAccount *a, SavingsAccount *b);
template<class T>
void customSort(T *arr[], const int &n, bool (*cmp)(T*, T*), bool ascending = true);
string correctName(const string &str); // Hàm chuẩn hoá họ và tên

// Khai báo các hàm trong file "include/iofile.h"
string getHorizontalBorder(const int &type); // Hàm trả về đường kẻ ngang của bảng
string getTableHeader(const int &type); //Hàm trả về các cột tiêu đề của bảng
string getTableRow(const int &type, SavingsAccount *acc, const int &i); // Hàm trả về hàng dữ liệu mỗi sổ tiết kiệm của bảng
void exportBankInfo(Bank &b); // Xuất thông tin ngân hàng ra tệp
void exportTable(SavingsAccount *accounts[], int n); // Xuất các sổ tiết kiệm ra tệp

// Khai báo các hàm trong file "include/menu.h"
void showMenu(); // Hàm hiển thị menu
int getChoice(const int &minChoice, const int &maxChoice, const string &optionInfo = ""); // Hàm trả về lựa chọn từ menu
void handleMainMenu(Bank &B, const int &sl); // Hàm xử lí các lựa chọn trong menu chính










// beta
// Sử dụng trong hàm handleSearchResults để lấy con trỏ đến đối tượng Bank hiện tại
Bank *bank = nullptr;
void exportToTextFile(SavingsAccount *accounts[], int n, const string &filename);
void handleSearchResults(SavingsAccount *searchResults[], int &numResults);