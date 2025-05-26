/* 
-- Thành viên code: Pham Van Toi
-- Nội dung tệp: Chứa các lớp
-- Số lớp: ...
*/

const int MAX_CUSTOMER = 100;

class Date {
    private:
        int day, month, year;
    public:
        Date(int d = 1, int m = 1, int y = 2000);
        int getDay();
        int getMonth();
        int getYear();
        bool isValidDate(int d, int m, int y);
        void input();
};

// Định nghĩa constructor
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

// Định nghĩa các hàm get
int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

bool Date::isValidDate(int d, int m, int y) {
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return d <= 30;
    } else if (m == 2) {
        // Kiểm tra năm nhuận
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            return d <= 29;
        } else {
            return d <= 28;
        }
    }
    
    return true;
}

void Date::input() {
    cout << "Nhap ngay/thang/nam :" << endl;

    do {
        cout << "Nhap ngay (1-31): ";
        cin >> day;
        if (day < 1 || day > 31) 
            cout << "Ngay khong hop le, hay nhap lai!" << endl;
    } while (day < 1 || day > 31);

    do {
        cout << "Nhap thang (1-12): ";
        cin >> month;
        if (month < 1 || month > 12) 
            cout << "Thang khong hop le, hay nhap lai!" << endl;
    } while (month < 1 || month > 12);

    do {
        cout << "Nhap nam (1900-2100): ";
        cin >> year;
        if (year < 1900 || year > 2100) 
            cout << "Nam khong hop le, hay nhap lai!" << endl;
    } while (year < 1900 || year > 2100);

    if (!isValidDate(day, month, year)) {
        cout << "Ngay thang nam khong hop le, hay nhap lai!" << endl;
        input();  // Nhap lai neu khong hop le
    }
}

// Lớp SavingsAccount
class SavingsAccount {
	protected:
        string accountType;
        string customerName;
		string customerId;
		string idNumber;
		Date openDate;
        int depositAmount;
		double interestRate;
  	public:
        SavingsAccount();
        string getAccountType();
		string getCustomerName();
		string getCustomerId();
		string getIdNumber();
		double getDepositAmount();
		Date getOpenDate();
		double getInterestRate();
        void setAccountType(string type);
		void setCustomerName(string name);
		void setCustomerId(string id);
		void setIdNumber(string idNum);
		void setDepositAmount(double amount);
		void setOpenDate(Date date);
		void setInterestRate(double rate);
        virtual void setTerm(int t);
		void input();
		void display();
		virtual string toString();
        virtual ~SavingsAccount();
};

SavingsAccount::SavingsAccount() {
  customerName = "";
  customerId = "";
  idNumber = "";
  depositAmount = 0.0;
  interestRate = 0.0;
}

string SavingsAccount::getAccountType() {
    return accountType;
}

string SavingsAccount::getCustomerName() {
  return customerName;
}

string SavingsAccount::getCustomerId() {
  return customerId;
}

string SavingsAccount::getIdNumber() {
  return idNumber;
}

double SavingsAccount::getDepositAmount() {
  return depositAmount;
}

Date SavingsAccount::getOpenDate() {
    return openDate;
}

double SavingsAccount::getInterestRate() {
  return interestRate;
}

void SavingsAccount::setAccountType(string type) {
    accountType = type;
}

void SavingsAccount::setCustomerName(string name) {
  customerName = name;
}

void SavingsAccount::setCustomerId(string id) {
  customerId = id;
}

void SavingsAccount::setIdNumber(string idNum) {
  idNumber = idNum;
}

void SavingsAccount::setDepositAmount(double amount) {
  depositAmount = amount;
}

void SavingsAccount::setOpenDate(Date date) {
  openDate = date;
}

void SavingsAccount::setInterestRate(double rate) {
  interestRate = rate;
}

void SavingsAccount::setTerm(int t) {}

string SavingsAccount::toString() {
  stringstream ss;
  ss << customerName << "|" << customerId << "|" <<
    idNumber << "|" << depositAmount << "|" <<
    openDate.getDay() << "|" << openDate.getMonth() << "|" <<
    openDate.getYear() << "|" << interestRate;
  return ss.str();
}

SavingsAccount::~SavingsAccount() {}

// Lớp TermAccount (Có kỳ hạn)
class TermAccount : public SavingsAccount {
    private:
        int term;
    public:
        TermAccount();
        int getTerm();
        void setTerm(int t);
        double calculateInterest();
        string toString();
};

TermAccount::TermAccount() : SavingsAccount() {}

int TermAccount::getTerm() {
    return term;
}

void TermAccount::setTerm(int t) {
    term = t;
}

double TermAccount::calculateInterest() {
    int soThang = openDate.getMonth();
    if (soThang >= term) {
        return getDepositAmount() * getInterestRate() * soThang;
    }

    return 0.0;
}

string TermAccount::toString() {
    stringstream ss;
    ss << "Term" << " | "
       << SavingsAccount::toString() << " | "
       << term << " thang | "
       << calculateInterest() << " trieu dong";
    return ss.str();
}

// Lớp NonTermAccount (Không kỳ hạn)
class NonTermAccount : public SavingsAccount {
    public:
        NonTermAccount();
        double calculateInterest(int soThang);
        string toString();
};

NonTermAccount::NonTermAccount() : SavingsAccount() {}

double NonTermAccount::calculateInterest(int soThang) {
    return getDepositAmount() * getInterestRate() * soThang;
}

string NonTermAccount::toString() {
    int soThang;
    //cout << "Nhap so thang gui cho khach hang " << getCustomerName() << ": ";
    //cin >> soThang;
    //double tienLai = calculateInterest(soThang);
    stringstream ss;
    ss << "NonTerm" << "|"
       << getCustomerName() << "|"
       << getCustomerId() << "|"
       << getIdNumber() << "|"
       << getDepositAmount() << "|"
       << getOpenDate().getDay() << "/" << getOpenDate().getMonth() << "/" << getOpenDate().getYear() << "|"
       << getInterestRate() << "|"
       << "0";

    return ss.str();
}

// Định nghĩa lớp Bank
class Bank{
	private:
		string name, address, taxCode, phone, email;
        int cq;
		//SavingsAccount *accounts[MAX_CUSTOMER];
	public:
        SavingsAccount *accounts[MAX_CUSTOMER];
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
        string toString(); // Dịnh dạng thông tin ngân hàng thành chuỗi
        void loadFromFile(); // Tải thông tin ngân hàng từ tệp
		void saveToFile(); // Lưu thông tin ngân hàng đến tệp

        void search(const string &key);
};

// Định nghĩa các hàm của lớp Bank
Bank::Bank(string name, string address, string taxCode, string phone, string email) {
    this-> name = name; this->address = address;
    this->taxCode = taxCode; this->phone = phone;
    this->email = email;
}

void Bank::addAccount() {
    if(cq < MAX_CUSTOMER) {
        //accounts = new ;
        cout << "Enter customer name: ";
        //getline(cin, customer.customerName);
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

string Bank::toString() {
    ostringstream ss;
    ss << name << " | " << address << " | " << taxCode << " | " << phone << " | " << email;
    return ss.str();
}

void Bank::loadFromFile() {
    ifstream rf("data/input.data");
    if(!rf) {
        cout << "Tep du lieu khong ton tai!" << endl;
        return;
    }
    // Đọc thông tin ngân hàng
    string line;
    string *dataArr = new string[8];
    getline(rf, line);
    splitData(line, dataArr, 5);
    name = dataArr[0]; address = dataArr[1]; taxCode = dataArr[2]; phone = dataArr[3]; email = dataArr[4];
    getline(rf, line);
    // Đọc số lượng tài khoản khách hàng
    rf >> cq; rf.ignore();
    // Đọc thông tin các tài khoản
    int i = 0;
    while(getline(rf, line) && i < cq) {
        if(line.empty()) {
            continue;
        }
        stringstream ss(line);
        string accountType;
        getline(ss, accountType, '|'); trim(accountType);
        if(accountType == "Term") {
            splitData(line, dataArr, 8);
            accounts[i] = new TermAccount;
            accounts[i]->setTerm(stoi(dataArr[7]));
        } else if(accountType == "NonTerm") {
            splitData(line, dataArr, 7);
            accounts[i] = new NonTermAccount;
        } else {
            cout << "Tai du lieu khong thanh cong, vui long xem lai tep du lieu!" << endl;
            system("pause");
        }
        accounts[i]->setAccountType(dataArr[0]);
        accounts[i]->setCustomerName(dataArr[1]);
        accounts[i]->setCustomerId(dataArr[2]);
        accounts[i]->setIdNumber(dataArr[3]);
        Date date(23, 05, 2025);
        accounts[i]->setOpenDate(date);
        accounts[i]->setDepositAmount(stoi(dataArr[5]));
        accounts[i]->setInterestRate(stod(dataArr[6]));
        i++;
    }
    cout << "Tai du lieu tu tep thanh cong" << endl;
}

void Bank::saveToFile() {
    ofstream wf("data/input.data");
    // Ghi thông tin ngân hàng vào dòng đầu tiên
    wf << toString() << endl;
    wf << endl;
    // Ghi số lượng tài khoản
    wf << cq << endl;
    // Ghi thông tin các tài khoản
    for(int i = 0; i < cq; i++) {
        wf << accounts[i]->toString() << endl;
    }
}

void Bank::search(const string &keyWord) {
    SavingsAccount *searchResults[MAX_CUSTOMER];
    int j = 0;
    for(int i = 0; i < cq; i++) {
        string accountType = accounts[i]->getAccountType();
        if(accounts[i]->getAccountType() == keyWord) {
            searchResults[j++] = accounts[i];
        }
    }
    if(!j) {
        cout << "Khong co ket qua nao duoc tim thay" << endl;
        return;
    }
    outputData(searchResults, j);
}