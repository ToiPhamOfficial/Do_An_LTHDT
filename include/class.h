/* 
-- Thành viên code: Pham Van Toi
-- Nội dung tệp: Chứa các lớp
-- Số lớp: ...
*/

class Date {
    private:
        int day = 7, month = 5, year = 2025;
    public:
        Date(int d = 1, int m = 1, int y = 2000);
        int getDay();
        int getMonth();
        int getYear();
        static Date getCurrentDate();
        bool isValidDate(int d, int m, int y);
        void input();
        string toString();
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

Date Date::getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
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
    do {
        cout << " +[Nhap ngay (1-31)]-> ";
        cin >> day;
        if (day < 1 || day > 31) 
            cout << " +[Canh bao]-> Ngay khong hop le, hay nhap lai!" << endl;
    } while (day < 1 || day > 31);

    do {
        cout << " +[Nhap thang (1-12)]-> ";
        cin >> month;
        if (month < 1 || month > 12) 
            cout << "Thang khong hop le, hay nhap lai!" << endl;
    } while (month < 1 || month > 12);

    do {
        cout << " +[Nhap nam (1900-2100)]-> ";
        cin >> year;
        if (year < 1900 || year > 2100) 
            cout << "Nam khong hop le, hay nhap lai!" << endl;
    } while (year < 1900 || year > 2100);

    if (!isValidDate(day, month, year)) {
        cout << "Ngay thang nam khong hop le, hay nhap lai!" << endl;
        input();  // Nhap lai neu khong hop le
    }
}

string Date::toString() {
    ostringstream os;
    if(day < 10) {
        os << "0" << day;
    } else {
        os << day;
    }
    os << "/";
    if(month < 10) {
        os << "0" << month;
    } else {
        os << month;
    }
    os << "/" << year;

    return os.str();
}

// Lớp SavingsAccount
class SavingsAccount {
	protected:
        string accountType;
        string customerName;
		string customerId;
		string idNumber;
		Date openDate;
        double depositAmount;
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
        virtual int getTerm();
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

int SavingsAccount::getTerm() { return 0; }

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
  ss << accountType << "|" << customerName << "|" << customerId << "|" 
     << idNumber << "|" << openDate.getDay() << "/" << openDate.getMonth() << "/" 
     << openDate.getYear() << "|" << depositAmount << "|" << interestRate;
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
    ss << "Term" << "|"
       << getCustomerName() << "|"
       << getCustomerId() << "|"
       << getIdNumber() << "|"
       << getOpenDate().getDay() << "/" << getOpenDate().getMonth() << "/" << getOpenDate().getYear() << "|"
       << getDepositAmount() << "|"
       << getInterestRate() << "|"
       << term;
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
    stringstream ss;
    ss << "NonTerm" << "|"
       << getCustomerName() << "|"
       << getCustomerId() << "|"
       << getIdNumber() << "|"
       << getOpenDate().getDay() << "/" << getOpenDate().getMonth() << "/" << getOpenDate().getYear() << "|"
       << getDepositAmount() << "|"
       << getInterestRate();

    return ss.str();
}

// Định nghĩa lớp Bank
class Bank{
	private:
		string name, address, taxCode, phone, email;
        int numAccounts;
		SavingsAccount *accounts[MAX_CUSTOMER];
	public:
		Bank(string name = "null", string address = "null", string taxCode = "null", string phone = "null", string email = "null");
		void addAccount(); // Hàm thêm tài khoản vào ngân hàng
		string getName(); // Hàm trả về tên của ngân hàng
        string getAddress(); // Hàm trả về  địa chỉ của ngân hàng
        string getPhone(); // Hàm trả về số điện thoại chăm sóc khách hàng của ngân hàng
        string getTaxCode(); // Hàm trả về mã số thuế của ngân hàng
        string getEmail(); // Hàm trả về email của ngân hàng
        int getNumAccounts(); // Hàm lấy số lượng tài khoản tiết kiệm
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

        void display(); // Hàm hiển thị toàn bộ tài khoản
        void search(const string &key, SavingsAccount *searchResults[], int &c);
        static bool compareByName(SavingsAccount *a, SavingsAccount *b);
        static bool compareByBalance(SavingsAccount *a, SavingsAccount *b);
        void sortByName(bool ascending = true);
        void sortByBalance(bool ascending = true);
};

// Định nghĩa các hàm của lớp Bank
Bank::Bank(string name, string address, string taxCode, string phone, string email) {
    this-> name = name; this->address = address;
    this->taxCode = taxCode; this->phone = phone;
    this->email = email;
}

void Bank::addAccount() {
    //
    if(numAccounts < MAX_CUSTOMER) {
        int accountType;
        cout << endl;
        cout << "\033[0;36m";
        cout << "+---------- Menu: Them tai khoan moi ----------+" << endl;
        cout << "| 1. Tai khoan co ky han                       |" << endl;
        cout << "| 2. Tai khoan khong ky han                    |" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "\033[0m";
        
        do {
            cout << "\033[0;32m" << "+[Nhap lua chon]-> " << "\033[0m"; 
            cin >> accountType;
            if(accountType != 1 && accountType != 2) {
                cout << "\033[0;33m" << "+[Canh bao]-> Lua chon khong hop le, vui long chon lai" << endl;
            }
        } while(accountType != 1 && accountType != 2);
        
        cin.ignore();
        string customerName, customerId, idNumber;
        double depositAmount, interestRate;
        cout << "\033[0;32m" << "+[Nhap ten khach hang]-> " << "\033[0m";
        getline(cin, customerName); customerName = correctName(customerName);
        cout << "\033[0;32m" << "+[Nhap ma khach hang]-> " << "\033[0m";
        getline(cin, customerId);
        cout << "\033[0;32m" << "+[Nhap so CCCD/CMT]-> " << "\033[0m";
        getline(cin, idNumber);
        cout << "\033[0;32m" << "+[Nhap so tien gui]-> " << "\033[0m";
        cin >> depositAmount;
        
        cout << "\033[0;32m" << "+[Nhap lai suat (%)]-> " << "\033[0m";
        cin >> interestRate;
        
        Date openDate;
        cout << "\033[0;32m" << "+[Nhap ngay mo tai khoan]-> " << "\033[0m" << endl;
        openDate.input();
        
        if(accountType == 1) {
            int term;
            cout << "\033[0;32m" <<"+[Nhap ky han (thang)]-> " << "\033[0m";
            cin >> term;
            
            accounts[numAccounts] = new TermAccount();
            accounts[numAccounts]->setAccountType("Term");
            accounts[numAccounts]->setTerm(term);
        } else {
            accounts[numAccounts] = new NonTermAccount();
            accounts[numAccounts]->setAccountType("NonTerm");
        }
        accounts[numAccounts]->setCustomerName(customerName);
        accounts[numAccounts]->setCustomerId(customerId);
        accounts[numAccounts]->setIdNumber(idNumber);
        accounts[numAccounts]->setDepositAmount(depositAmount);
        accounts[numAccounts]->setInterestRate(interestRate);
        accounts[numAccounts]->setOpenDate(openDate);
        
        numAccounts++;
        cout << "\033[0;34m" << "+[Thong bao]-> Them tai khoan thanh cong!" << "\033[0m" << endl;
        saveToFile();
    } else {
        cout << "\033[0;33m" << "+[Canh bao]-> So luong khach hang da dat den toi da" << "\033[0m" << endl;
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

int Bank::getNumAccounts() {
    return numAccounts;
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

void Bank::removeAccount(const string &customerId) {
    int foundIndex = -1;
    // Tìm tài khoản cần xóa
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i]->getCustomerId() == customerId) {
            foundIndex = i;
            break;
        }
    }
    if(foundIndex == -1) {
        cout << "\033[0;33m" << "+[Canh bao]-> Khong tim thay tai khoan co ma " << RED << customerId << "\033[0m" << endl;
        return;
    }
    // Xóa tài khoản đã tìm thấy
    delete accounts[foundIndex];
    // Di chuyển các tài khoản sau lên
    for(int i = foundIndex; i < numAccounts - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    numAccounts--;
    cout << "\033[0;34m" << "+[Thong bao]-> Xoa tai khoan thanh cong!" << "\033[0m" << endl;
    saveToFile();
}

double Bank::calculateInterest() {
    double totalInterest = 0.0;
    for(int i = 0; i < numAccounts; i++) {
        if(dynamic_cast<TermAccount*>(accounts[i])) {
            TermAccount* termAccount = dynamic_cast<TermAccount*>(accounts[i]);
            totalInterest += termAccount->calculateInterest();
        } else if(dynamic_cast<NonTermAccount*>(accounts[i])) {
            NonTermAccount* nonTermAccount = dynamic_cast<NonTermAccount*>(accounts[i]);
            int months = 1; // Mặc định 1 tháng
            totalInterest += nonTermAccount->calculateInterest(months);
        }
    }
    return totalInterest;
}

string Bank::toString() {
    ostringstream ss;
    ss << name << " | " << address << " | " << taxCode << " | " << phone << " | " << email;
    return ss.str();
}

void Bank::loadFromFile() {
    ifstream rf("data/input.data");
    if(!rf) {
        cout << "\033[0;33m" << "+[Canh bao]-> Tep du lieu khong ton tai!" << "\033[0m" << endl;
        return;
    }
    // Đọc thông tin ngân hàng
    string line;
    string *dataArr = new string[8];
    getline(rf, line);
    splitData(line, dataArr, 5, '|');
    name = dataArr[0]; address = dataArr[1]; taxCode = dataArr[2]; phone = dataArr[3]; email = dataArr[4];
    getline(rf, line);
    // Đọc số lượng tài khoản khách hàng
    rf >> numAccounts; rf.ignore();
    // Đọc thông tin các tài khoản
    int i = 0;
    while(getline(rf, line) && i < numAccounts) {
        if(line.empty()) {
            continue;
        }
        stringstream ss(line);
        string accountType;
        getline(ss, accountType, '|'); accountType = trim(accountType);
        if(accountType == "Term") {
            splitData(line, dataArr, 8, '|');
            accounts[i] = new TermAccount;
            accounts[i]->setTerm(stoi(dataArr[7]));
        } else if(accountType == "NonTerm") {
            splitData(line, dataArr, 7, '|');
            accounts[i] = new NonTermAccount;
        } else {
            cout << "\033[0;33m" << "+[Canh bao]-> Tai du lieu khong thanh cong, vui long xem lai tep du lieu!" << "\033[0m" << endl;
            system("pause");
            return;
        }
        accounts[i]->setAccountType(dataArr[0]);
        accounts[i]->setCustomerName(dataArr[1]);
        accounts[i]->setCustomerId(dataArr[2]);
        accounts[i]->setIdNumber(dataArr[3]);
        
        // Xử lý ngày tháng
        string dateStr = dataArr[4];
        string *dateArr = new string[3];
        splitData(dateStr, dateArr, 3, '/');
        Date date(stoi(dateArr[0]), stoi(dateArr[1]), stoi(dateArr[2]));
        accounts[i]->setOpenDate(date);
        accounts[i]->setDepositAmount(stod(dataArr[5]));
        accounts[i]->setInterestRate(stod(dataArr[6]));
        i++;
    }
    cout << "\033[0;34m" << "+[Thong bao]-> Tai du lieu tu tep thanh cong" << "\033[0m" << endl;
    delete[] dataArr;
}

void Bank::saveToFile() {
    ofstream wf("data/input.data");
    // Ghi thông tin ngân hàng vào dòng đầu tiên
    wf << toString() << endl;
    wf << endl;
    // Ghi số lượng tài khoản
    wf << numAccounts << endl;
    // Ghi thông tin các tài khoản
    for(int i = 0; i < numAccounts; i++) {
        wf << accounts[i]->toString() << endl;
    }
}



//// Beta
void Bank::display() {
    outputData(accounts, numAccounts);
}

void Bank::search(const string &keyWord, SavingsAccount *searchResults[], int &c) {
    c = 0;
    for(int i = 0; i < numAccounts; i++) {
        bool flag1 = accounts[i]->getAccountType() == keyWord;
        bool flag2 = accounts[i]->getCustomerName().find(keyWord) != string::npos;
        bool flag3 = accounts[i]->getCustomerId() == keyWord;
        bool flag4 = accounts[i]->getIdNumber() == keyWord;
        
        if(flag1 || flag2 || flag3 || flag4) {
            searchResults[c++] = accounts[i];
        }
    }
}

bool Bank::compareByName(SavingsAccount *a, SavingsAccount *b) {
    return a->getCustomerName() < b->getCustomerName();
}

bool Bank::compareByBalance(SavingsAccount *a, SavingsAccount *b) {
    return a->getDepositAmount() < b->getDepositAmount();
}

void Bank::sortByName(bool ascending) {
    customSort(accounts, numAccounts, compareByName, ascending);
    outputData(accounts, numAccounts);
}

void Bank::sortByBalance(bool ascending) {
    customSort(accounts, numAccounts, compareByBalance, ascending);
    outputData(accounts, numAccounts);
}