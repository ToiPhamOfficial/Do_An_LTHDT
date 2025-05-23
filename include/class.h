/* 
-- Thành viên code: Pham Van Toi
-- Nội dung tệp: Chứa các lớp
-- Số lóp: ...
*/

const int MAX_CUSTOMER = 100;

class SavingsAccount; // lớp giả định

// Định nghĩa lớp Bank
class Bank{
	private:
		string name, address, taxCode, phone, email;
        int cq;
		SavingsAccount *accounts[MAX_CUSTOMER];
	public:
		Bank(string name = "null", string address = "null", string taxCode = "null", string phone = "null", string email = "null");
		void addAccount(); // Hàm thêm tài khoản vào ngân hàng
		string getName(); // Hàm trả về tên của ngân hàng
        string getAddress(); // Hàm trả về  địa chỉ của ngân hàng
        string getPhone(); // Hàm trả về số điện thoại chăm sóc khách hàng của ngân hàng
        string getTaxCode(); // Hàm trả về mã số thuế của ngân hàng
        string getEmail(); // Hàm trả về email của ngân hàng
		void setName(const string &name); // Hàm đặt tên của ngân hàng
        void setAddress(const string &address); // Hàm đặt địa chỉ của ngân hàng
        void setTaxCode(const string &taxCode); // Hàm đặt mã số thuế của ngân hàng
        void setPhone(const string &phone); // Hàm đặt số điện thoại chăm sóc khách hàng của ngân hàng
        void setEmail(const string &email); // Hàm đặt email của ngân hàng
		void removeAccount(const string &customerId); // Hàm xoá tài khoản khỏi ngân hàng
		double calculateInterest(); // Tính lãi của 1 khách hàng
		bool saveToFile(); // Lưu thông tin ngân hàng đến tệp
		bool loadFromFile(); // Tải thông tin ngân hàng từ tệp
};

// Định nghĩa các hàm của lớp Bank
Bank::Bank(string name, string address, string taxCode, string phone, string email) {
    this-> name = name; this->address = address;
    this->taxCode = taxCode; this->phone = phone;
    this->email = email;
}

void Bank::addAccount() {
    if(cq < MAX_CUSTOMER) {
        accounts = new ;
        cout << "Enter customer name: ";
        getline(cin, customer.customerName);
        //...
        
    } else {
        cout << "So luong khach hang da dat den toi da" << endl;
    }
}

string Bank::getName() {
    return name;
}

string Bank::getAddress() {
    return address;
}

string Bank::getTaxCode() {
    return taxCode;
}

string Bank::getPhone() {
    return phone;
}

string Bank::getEmail() {
    return email;
}

void Bank::setName(const string &name) {
    this->name = name;
}

void Bank::setAddress(const string &address) {
    this->address = address;
}

void Bank::setTaxCode(const string &taxCode) {
    this->taxCode = taxCode;
}

void Bank::setPhone(const string &phone) {
    this->phone = phone;
}

void Bank::setEmail(const string &email) {
    this->email = email;
}

void Bank::removeAccount(const string &ustomerId) { // cần xác định lưu danh sách tài khoản trong vector hay cấp phát động

}

double calculateInterest() { // cần lớp SavingsAccount để viết hàm

}