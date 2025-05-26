/* 
-- Thành viên code: Pham Van Toi
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

// Khai báo các hàm
int readFile(const string &file_name, string *d_arr, const int &n); // Hàm đọc dữ liệu từ tệp
void writeFile(string file_name, string data_arr, const int &n); // Hàm ghi dữ liệu vào tệp
void loadLang(string lang, string *lang_data); // Hàm tải ngôn ngữ vào chương trình
void mainMenu(); // Hàm hiển thị menu
void systemSettingsMenu(); // Hàm hiển thị menu cài đặt hệ thống
int chooseInMenu(const int &max_sl); // Hàm trả về lựa chọn từ menu
void handleMainMenu(const int &sl); // Hàm xử lí các lựa chọn trong menu chính
void reloadSystem(); // Hàm tải lại hệ thống

void trim(string &s);  // Hàm xoá khoảng trắng 2 đầu của chuỗi
void splitData(const string &s, string *d_arr, const int &n);
string formatVND(const int &amount);
void outputData(SavingsAccount *accounts[], int n);