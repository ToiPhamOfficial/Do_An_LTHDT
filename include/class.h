/* 
-- Nội dung tệp: Chứa các lớp
-- Số lớp: 5
*/

//============================ Định nghĩa lớp Date ============================\\.
class Date {
    private:
        int day, month, year;
    public:
        Date(int d = 1, int m = 1, int y = 2025); // Hàm thiết lập
        void input(); // Hàm nhập ngày, tháng, năm
        int getDay(); // Hàm trả về ngày
        int getMonth(); // Hàm trả về tháng
        int getYear(); // Hàm trả về năm
        static Date getCurrentDate(); // Hàm trả về ngày hiện tại
        static bool isValidDate(int d, int m, int y); // Kiểm tra tính hợp lệ của 1 ngày
        bool operator ==(const Date &other); // Hàm so sánh 2 ngày có bằng nhau hay không
        int monthsBetween(Date &other); // Hàm tính số tháng giữa 2 ngày
        string toString(); // Hàm định dạng ngày dạng chuỗi
        ~Date(); // Hàm huỷ bỏ
};

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
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
        cout << " +[Nhap nam (1900-2025)]-> ";
        cin >> year;
        if (year < 1900 || year > 2025) 
            cout << "Nam khong hop le, hay nhap lai!" << endl;
    } while (year < 1900 || year > 2025);

    if (!isValidDate(day, month, year)) {
        cout << "Ngay thang nam khong hop le, hay nhap lai!" << endl;
        input();  // Nhap lai neu khong hop le
    }
}

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

bool Date::operator ==(const Date &other) {
    return (this->day == other.day) && (this->month == other.month) && (this->year == other.year);
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

int Date::monthsBetween(Date &other){
	// Tinh tong so thang cua moi Date
	int thisMonth = year * 12 + month;
	int otherMonth = other.year * 12 + other.month;
	// Tinh khoang cach giua 2 thang
	int result = otherMonth - thisMonth;
	// Dieu chinh theo ngay
	if(other.day < day) {
        result--;
    }
	return result;
}

Date::~Date() {}


//=============================== Định nghĩa lớp SavingsAccount (Lớp sổ tiết kiệm) ===============================\\.
class SavingsAccount {
	protected:
        string customerName;
		string customerId;
		string idNumber;
		Date openDate;
        double depositAmount;
		double interestRate;
  	public:
        SavingsAccount(); // Hàm thiết lập
        virtual void input(); // Hàm nhập thông tin sổ tiết kiệm
        virtual void update(); // Hàm cập nhật sổ tiết kiệm
		string getCustomerName(); // Hàm trả về tên khách hàng
		string getCustomerId(); // Hàm trả về mã khách hàng
		string getIdNumber(); // Hàm trả về số CCCD của kháchh hàng
		double getDepositAmount(); // Hàm trả về số dư trong sổ tiết kiệm
		Date getOpenDate(); // Hàm trả về ngày mở sổ tiết kiệm
		double getInterestRate(); // Hàm trả về lãi suất của sổ tiết kiệm
        virtual int getTerm(); // Hàm trả về kỳ hạn của sổ tiết kiệm có kỳ hạn
		void setCustomerName(string name); // Hàm đặt tên khách hàng
		void setCustomerId(string id); // Hàm đặt mã khách hàng
		void setIdNumber(string idNum); // Hàm đặt số CCCD của khách hàng
		void setDepositAmount(double amount); // Hàm đặt số dư sổ tiết kiệm
        void setOpenDate(Date date); // Hàm đặt ngày mở sổ tiết kiệm
		void setInterestRate(double rate); // Hàm đặt lãi suất của sổ tiết kiệm
        virtual void setTerm(int t); // Hàm đặt kỳ hạn của sổ tiết kiệm có kỳ hạn
        virtual double calculateInterest(); // Hàm tính tiền lãi của sổ tiết kiệm
		virtual string toString(); // Hàm định dạng thông tin sổ tiết kiệm theo cấu trúc
        virtual ~SavingsAccount(); // Hàm huỷ bỏ
};

SavingsAccount::SavingsAccount() {
  customerName = "";
  customerId = "";
  idNumber = "";
  depositAmount = 0.0;
  interestRate = 0.0;
}

void SavingsAccount::input() {
  string inputName, inputId;
  double inputAmount, inputRate;
  // Nhập tên khách hàng
  do {
    cout << GREEN << "+[Nhap ten khach hang]-> " << RESET;
    getline(cin, inputName); 
    inputName = trim(inputName);
    inputName = correctName(inputName);
    if(inputName.length() > 21) {
        cout << YELLOW << "+[Canh bao]-> Khong duoc qua 21 ky tu, hay nhap lai." << RESET << endl;
    } else {
        customerName = inputName;
        break;
    }
  } while(inputName.length() > 21);
  // Nhập số CCCD
  do {
    cout << GREEN << "+[Nhap so CCCD]-> " << RESET;
    getline(cin, inputId);
    inputId = trim(inputId);
    if(inputId.length() != 12 /* thêm kiểm tra chuỗi số nguyên */) {
        cout << YELLOW << "+[Canh bao]-> CCCD phai gom 12 so" << RESET << endl;
    } else {
        idNumber = inputId;
        break;
    }
  } while(inputId.length() != 12);
  // Nhập số tiền gửi
  do {
    cout << GREEN << "+[Nhap so tien gui]-> " << RESET;
    cin >> inputAmount;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(999, '\n');
        cout << YELLOW << "+[Canh bao]-> Vui long nhap so du hop le!" << RESET << endl;
        continue;
    }
    if(inputAmount < 100000.0 || inputAmount > 999999999999.0) {
        cout << YELLOW << "+[Canh bao]-> So du cho phep  > 100,000 VND va < 999,999,999,999 VND" << RESET << endl;
    } else {
        // thêm làm tròn đến 2 chữ số
        depositAmount = inputAmount;
    }
  } while(inputAmount > 999999999999.0);
  // Nhập lãi suất
  do {
    cout << GREEN << "+[Nhap lai suat]-> " << RESET;
    cin >> inputRate;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(999, '\n');
        cout << YELLOW << "+[Canh bao]-> Vui long nhap lai suat hop le!" << RESET << endl;
        continue;
    }
    if(inputRate <= 0 || inputRate > 10.0) {
        cout << YELLOW << "+[Canh bao]-> Lai suat cho phep > 0 va <= 10%" << RESET << endl;
    } else {
        // thêm phần làm tròn đến 2 chữ số
        interestRate = inputRate;
    }
  } while(inputRate <= 0 && inputRate > 10.0);
  // Nhập ngày mở tài khoản
  cout << GREEN << "+[Nhap ngay mo tai khoan]: " << RESET << endl;
  openDate.input();
}

void SavingsAccount::update() {
  string inputName, inputId;
  double inputAmount, inputRate;
  // Nhập tên khách hàng
  do {
    cout << GREEN << "+[Nhap ten khach hang moi (0: bo qua)]-> " << RESET;
    getline(cin, inputName);
    inputName = trim(inputName);
    if(inputName == "0") {
        break;
    }
    inputName = correctName(inputName);
    if(inputName.length() > 21) {
        cout << YELLOW << "+[Canh bao]-> Khong duoc qua 21 ky tu, hay nhap lai." << RESET << endl;
    } else {
        customerName = inputName;
        break;
    }
  } while(inputName.length() > 21);
  // Nhập số CCCD
  do {
    cout << GREEN << "+[Nhap so CCCD moi (0: bo qua)]-> " << RESET;
    getline(cin, inputId);
    inputId = trim(inputId);
    if(inputId == "0") {
        break;
    }
    if(inputId.length() != 12 /* thêm kiểm tra chuỗi số nguyên */) {
        cout << YELLOW << "+[Canh bao]-> CCCD phai gom 12 so" << RESET << endl;
    } else {
        idNumber = inputId;
        break;
    }
  } while(inputId.length() != 12);
  // Nhập số tiền gửi
  do {
    cout << GREEN << "+[Nhap so tien gui moi (0: bo qua)]-> " << RESET;
    cin >> inputAmount;
    if(inputAmount == 0.0) {
        break;
    }
    if(cin.fail()) {
        cin.clear();
        cin.ignore(999, '\n');
        cout << YELLOW << "+[Canh bao]-> Vui long nhap so du hop le!" << RESET << endl;
        continue;
    }
    if(inputAmount < 100000.0 || inputAmount > 999999999999.0) {
        cout << YELLOW << "+[Canh bao]-> So du cho phep  > 100,000 VND va < 999,999,999,999 VND" << RESET << endl;
    } else {
        // thêm làm tròn đến 2 chữ số
        depositAmount = inputAmount;
    }
  } while(inputAmount < 100000.0 || inputAmount > 999999999999.0);
  // Nhập lãi suất
  do {
    cout << GREEN << "+[Nhap lai suat moi (0: bo qua)]-> " << RESET;
    cin >> inputRate;
    if(inputRate == 0.0) {
        break;
    }
    if(cin.fail()) {
        cin.clear();
        cin.ignore(999, '\n');
        cout << YELLOW << "+[Canh bao]-> Vui long nhap lai suat hop le!" << RESET << endl;
        continue;
    }
    if(inputRate < 0.0 || inputRate > 10.0) {
        cout << YELLOW << "+[Canh bao]-> Lai suat cho phep > 0 va <= 10%" << RESET << endl;
    } else {
        // thêm phần làm tròn đến 2 chữ số
        interestRate = inputRate;
    }
  } while(inputRate < 0 && inputRate > 10.0);
  // Nhập ngày mở tài khoản
  char c;
  cout << GREEN << "+[Nhap ngay mo tai khoan moi (0: bo qua)]: " << RESET;
  cin >> c;
  if(c != '0') {
    openDate.input(); 
  }
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

int SavingsAccount::getTerm() {
    return 0;
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

double SavingsAccount::calculateInterest() {
    return 0.0;
}

string SavingsAccount::toString() {
  ostringstream os;
  os << customerId << " | "
     << customerName << " | "  
     << idNumber << " | "
     << openDate.getDay() << "/" << openDate.getMonth() << "/"  << openDate.getYear()
     << " | " << depositAmount
     << " | " << interestRate;
  return os.str();
}

SavingsAccount::~SavingsAccount() {}


//================= Định nghĩa lớp TermAccount (Lớp sổ tiết kiệm có kỳ hạn) ================\\.
class TermAccount : public SavingsAccount {
    private:
        int term;
    public:
        TermAccount(); // Hàm thiết lập
        void input(); // Hàm nhập thông tin sổ tiết kiệm có kỳ hạn
        int getTerm(); // Hàm trả về kỳ hạn sổ tiết kiệm có kỳ hạn
        void setTerm(int t); // Hàm đặt kỳ hạn sổ tiết kiệm có kỳ hạn
        double calculateInterest(); // Hàm tính tiền lãi sổ tiết kiệm có kỳ hạn
        string toString(); // Hàm định dạng thông tin sổ tiết kiệm có kỳ hạn theo cấu trúc
        ~TermAccount(); // Hàm huỷ bỏ
};

TermAccount::TermAccount() : SavingsAccount() {}

void TermAccount::input() {
    cin.ignore();
    // Nhập mã khách hàng đúng định dạng: T + 5 số
    string inputId;
    bool validId = false;
    while (!validId) {
        cout << "GREEN" << "+[Nhap ma khach hang (T + 5 so)]-> " << RESET;
        getline(cin, inputId);
        // Kiểm tra định dạng: T + 5 số
        if (inputId.length() == 6 && inputId[0] == 'T') {
            bool allDigits = true;
            for (int i = 1; i < 6; i++) {
                if (!isdigit(inputId[i])) {
                    allDigits = false;
                    break;
                }
            }
            if (allDigits) {
                validId = true;
                customerId = inputId;
                cout << "\033[0;34m" << "+[Thong bao]-> Ma khach hang hop le!" << RESET << endl;
            } else {
                cout << YELLOW << "+[canh bao]-> Ma khach hang khong hop le! Can co dang T + 5 so" << RESET << endl;
            }
        } else {
            cout << YELLOW << "+[canh bao]-> Ma khach hang khong hop le! Can co dang T + 5 so" << RESET << endl;
        }
    }
    SavingsAccount::input();
    // Nhập kỳ hạn
    cout << "GREEN" << "+[Nhap ky han (thang)]-> " << RESET;
    cin >> term;
}

int TermAccount::getTerm() {
    return term;
}

void TermAccount::setTerm(int t) {
    term = t;
}

double TermAccount::calculateInterest() {
    Date currentDate = Date::getCurrentDate();
    int months = openDate.monthsBetween(currentDate);
    if (months < 0) {
        return 0.0; // Khong tinh lai nhung ngay trong tuong lai
    }
    if (months >= term) {
        return depositAmount * interestRate * months;
    } else {
        return 0.0; // Không tính lãi nếu rút trước hạn
    }
}

string TermAccount::toString() {
    ostringstream os;
    os << SavingsAccount::toString() << " | " << term;
    return os.str();
}

TermAccount::~TermAccount() {}


//=============== Định nghĩa lớp TermAccount (Lớp sổ tiết kiệm không kỳ hạn) ================\\.
class NonTermAccount : public SavingsAccount {
    public:
        NonTermAccount(); // Hàm thiết lập
        void input(); // Hàm nhập thông tin sổ tiết kiệm không kỳ hạn
        double calculateInterest(); // Hàm tính tiền lãi sổ  tiết kiệm không kỳ hạn
        ~NonTermAccount(); // Hàm huỷ bỏ
};

NonTermAccount::NonTermAccount() : SavingsAccount() {}

void NonTermAccount::input() {
    // Nhập mã khách hàng đúng định dạng: NT + 5 số
    string inputId;
    bool validId = false;
    while (!validId) {
        cout << "GREEN" << "+[Nhap ma khach hang (NT + 5 so)]-> " << RESET;
        getline(cin, inputId);
        // Kiểm tra định dạng: NT + 5 số
        if (inputId.length() == 6 && inputId[0] == 'N') {
            bool allDigits = true;
            for (int i = 2; i < 6; i++) {
                if (!isdigit(inputId[i])) {
                    allDigits = false;
                    break;
                }
            }
            if (allDigits) {
                validId = true;
                customerId = inputId;
                cout << "\033[0;34m" << "+[Thong bao]-> Ma khach hang hop le!" << RESET << endl;
            } else {
                cout << YELLOW << "+[canh bao]-> Ma khach hang khong hop le! Can co dang NT + 5 so" << RESET << endl;
            }
        } else {
            cout << YELLOW << "+[canh bao]-> Ma khach hang khong hop le! Can co dang NT + 5 so" << RESET << endl;
        }
    }
    SavingsAccount::input();
}

double NonTermAccount::calculateInterest() {
    Date currentDate = Date::getCurrentDate();
	int months = openDate.monthsBetween(currentDate);
    if (months < 0) {
        return 0.0; // Khong tinh lai nhung ngay trong tuong lai
    }
    return depositAmount * interestRate * months;
}

NonTermAccount::~NonTermAccount() {}


//============================= Định nghĩa lớp Bank =============================\\.
class Bank {
	private:
		string name, address, taxCode, phone, email;
        int numAccounts;
		SavingsAccount *accounts[MAX_CUSTOMER];
	public:
		Bank(); // Hàm thiết lập
        void update(); // Hàm cập nhật thông tin ngân hàng
		void addAccount(const int &accountType); // Hàm thêm tài khoản vào ngân hàng
		string getName(); // Hàm trả về tên của ngân hàng
        string getAddress(); // Hàm trả về  địa chỉ của ngân hàng
        string getPhone(); // Hàm trả về số điện thoại chăm sóc khách hàng của ngân hàng
        string getTaxCode(); // Hàm trả về mã số thuế của ngân hàng
        string getEmail(); // Hàm trả về email của ngân hàng
        int getNumAccounts(); // Hàm lấy số lượng tài khoản tiết kiệm
        string toString(); // Dịnh dạng thông tin ngân hàng thành chuỗi
        void loadFromFile(); // Tải thông tin ngân hàng từ tệp
		void saveToFile(); // Lưu thông tin ngân hàng đến tệp
        
        bool accountExists(const string &customerId); // Kiểm tra xem sổ tiết kiệm có tồn tại hay không
        void updateAccountInfo(const string &customerId);
		bool removeAccount(const string &customerId); // Hàm xoá tài khoản khỏi ngân hàng
        void showAccounts(const int &mod); // Hàm hiển thị các sổ tiết kiệm theo kiểu lựa chọn
        void calculateInterestPerAccount(); // Hàm tính tiền lãi mỗi sổ tiết kiệm

        ~Bank(); // Hàm huỷ bỏ

        // Các hàm đang trong quá trình viết lại, có thể sẽ xoá
        static bool compareByName(SavingsAccount *a, SavingsAccount *b);
        static bool compareByBalance(SavingsAccount *a, SavingsAccount *b);
        void sortByName(bool ascending = true);
        void sortByBalance(bool ascending = true);
        
        // hàm test trước
        int countAccountsByType(const int &type);
        double calculateTotalBalance();
        double calculateTotalInterest();

};

Bank::Bank() {
    name = address = taxCode = phone = email = "";
}

void Bank::update() {
    string newName, newAddress, newTaxCode, newPhone, newEmail;
    // Nhập tên ngân hàng
    do {
        cout << GREEN << "+[Nhap ten ngan hang]-> " << RESET;
        cin.ignore();
        getline(cin, newName);
        newName = trim(newName);
        if(newName.length() > 50) {
            cout << YELLOW << "+[Canh bao]-> Ten ngan hang khong duoc qua 50 ky tu" << RESET << endl;
        } else {
            name = newName; // Cập nhật tên ngân hàng
            break; // Thoát vòng lặp nếu tên hợp lệ
        }
    } while(newName.length() > 50);
    // Nhập địa chỉ ngân hàng
    cout << GREEN << "+[Nhap dia chi ngan hang]-> " << RESET;
    getline(cin, newAddress);
    newAddress = trim(newAddress);
    address = newAddress; // Cập nhật địa chỉ ngân hàng
    // Nhập mã số thuế ngân hàng
    cout << GREEN << "+[Nhap ma so thue ngan hang]-> " << RESET;
    getline(cin, newTaxCode);
    newTaxCode = trim(newTaxCode);
    taxCode = newTaxCode; // Cập nhật mã số thuế ngân hàng
    // Nhập số điện thoại ngân hàng
    cout << GREEN << "+[Nhap so dien thoai ngan hang]-> " << RESET;
    getline(cin, newPhone);
    newPhone = trim(newPhone);
    phone = newPhone; // Cập nhật số điện thoại ngân hàng
    // Nhập email ngân hàng
    cout << GREEN << "+[Nhap email ngan hang]-> " << RESET;
    getline(cin, newEmail);
    newEmail = trim(newEmail);
    email = newEmail; // Cập nhật email ngân hàng
    // Lưu thông tin ngân hàng vào tệp
    saveToFile();
}

void Bank::addAccount(const int &accountType) {
    if(numAccounts < MAX_CUSTOMER) {
        if(accountType == 1) {
            accounts[numAccounts] = new TermAccount();
        } else if(accountType == 2) {
            accounts[numAccounts] = new NonTermAccount();
        } else {
            return;
        }
        accounts[numAccounts]->input();
        numAccounts++;
        cout << BLUE << "+[Thong bao]-> Them tai khoan thanh cong!" << RESET << endl;
        saveToFile();
    } else {
        cout << YELLOW << "+[canh bao]-> So luong khach hang da dat den toi da" << RESET << endl;
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

bool Bank::accountExists(const string &customerId) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i]->getCustomerId() == customerId) {
            return true;
        }
    }
    return false;
}

void Bank::updateAccountInfo(const string &customerId) {
    int foundIndex = -1;
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i]->getCustomerId() == customerId) {
            foundIndex = i;
            break;
        }
    }
    if(foundIndex == -1) {
        return;
    }
    accounts[foundIndex]->update();
}

bool Bank::removeAccount(const string &customerId) {
    int foundIndex = -1;
    // Tìm tài khoản cần xóa
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i]->getCustomerId() == customerId) {
            foundIndex = i;
            break;
        }
    }
    if(foundIndex == -1) {
        return false;
    }
    // Xóa tài khoản đã tìm thấy
    delete accounts[foundIndex];
    // Di chuyển các tài khoản sau lên
    for(int i = foundIndex; i < numAccounts - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    numAccounts--;
    saveToFile();
    return true;
}

string Bank::toString() {
    ostringstream ss;
    ss << name << " | " << address << " | " << taxCode << " | " << phone << " | " << email;
    return ss.str();
}

void Bank::loadFromFile() {
    ifstream rf("data/input.data");
    if(!rf) {
        cout << RED << "+[Loi]-> Tep du lieu khong ton tai!" << RESET << endl;
        return;
    }
    // Đọc thông tin ngân hàng
    string line;
    string dataArr[7];
    getline(rf, line);
    splitData(line, dataArr, 5, '|');
    name = dataArr[0]; address = dataArr[1]; taxCode = dataArr[2];
    phone = dataArr[3]; email = dataArr[4];
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
        string customerId;
        getline(ss, customerId, '|');
        customerId = trim(customerId);
        if(customerId[0] == 'T') {
            splitData(line, dataArr, 7, '|');
            accounts[i] = new TermAccount;
            accounts[i]->setTerm(stoi(dataArr[6]));
        } else if(customerId[0] == 'N') {
            splitData(line, dataArr, 6, '|');
            accounts[i] = new NonTermAccount;
        } else {
            cout << YELLOW << "+[canh bao]-> Tai du lieu khong thanh cong, vui long xem lai tep du lieu!" << RESET << endl;
            system("pause");
            return;
        }
        accounts[i]->setCustomerId(dataArr[0]);
        accounts[i]->setCustomerName(dataArr[1]);
        accounts[i]->setIdNumber(dataArr[2]);
        
        // Xử lý ngày tháng
        string dateStr = dataArr[3];
        string dateArr[3];
        splitData(dateStr, dateArr, 3, '/');
        Date date(stoi(dateArr[0]), stoi(dateArr[1]), stoi(dateArr[2]));
        accounts[i]->setOpenDate(date);
        accounts[i]->setDepositAmount(stod(dataArr[4]));
        accounts[i]->setInterestRate(stod(dataArr[5]));
        i++;
    }
    cout << "\033[0;34m" << "+[Thong bao]-> Tai du lieu tu tep thanh cong" << RESET << endl;
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

void Bank::showAccounts(const int &mod) {
    ofstream wf("data/output.data");
    if(!wf) {
        cout << YELLOW << "+[Canh bao]-> Doc tep that bai. Vui long kiem tra lai tep" << RESET << endl;
        return;
    }
    switch (mod) {
        case 1:
            wf << setw(73) << "-Tat ca so tiet kiem-\n\n";
            break;
        case 2:
            wf << "-Cac so tiet kiem co ky han-\n\n";
            break;
        case 3:
            wf << "-Cac so tiet kiem khong ky han-\n\n";
            break;
        default:
            return;
    }
    wf << getHorizontalBorder(1);
    wf << getTableHeader(1);
    wf << getHorizontalBorder(1);
    int j = 0;
    for(int i = 0; i < numAccounts; i++) {
        if(mod == 2 && accounts[i]->getCustomerId()[0] != 'T') {
            continue;
        }
        if(mod == 3 && accounts[i]->getCustomerId()[0] != 'N') {
            continue;
        }
        wf << getTableRow(1, accounts[i], j);
        wf << getHorizontalBorder(1);
        j++;
    }

    wf.close();
}

void Bank::calculateInterestPerAccount() {
    ofstream wf("data/output.data");
    if(!wf) {
        cout << YELLOW << "+[Canh bao]-> Doc tep that bai. Vui long kiem tra lai tep" << RESET << endl;
        return;
    }
    wf << setw(80) << "-Tien lai moi so-\n\n";
    wf << getHorizontalBorder(2);
    wf << getTableHeader(2);
    wf << getHorizontalBorder(2);
    for(int i = 0; i < numAccounts; i++) {
        wf << getTableRow(2, accounts[i], i);
        wf << getHorizontalBorder(2);
    }

    wf.close();
}

Bank::~Bank() {}



bool Bank::compareByName(SavingsAccount *a, SavingsAccount *b) {
    return a->getCustomerName() < b->getCustomerName();
}

bool Bank::compareByBalance(SavingsAccount *a, SavingsAccount *b) {
    return a->getDepositAmount() < b->getDepositAmount();
}

void Bank::sortByName(bool ascending) {
    customSort(accounts, numAccounts, compareByName, ascending);
    //exportTable(accounts, numAccounts);
}

void Bank::sortByBalance(bool ascending) {
    customSort(accounts, numAccounts, compareByBalance, ascending);
    //exportTable(accounts, numAccounts);
}

int Bank::countAccountsByType(const int &type) {
    // 1: Có kỳ hạn
    // 2: Không kỳ hạn
    int c = 0;
    for(int i = 0; i < numAccounts; i++) {
        char at = accounts[i]->getCustomerId()[0];
        if(type == 1 && at == 'T') {
            c++;
        } else if(type == 2 && at == 'N') {
            c++;
        }
    }
    return c;
}

double Bank::calculateTotalBalance() {
    double totalBalance = 0;
    for(int i = 0; i < numAccounts; i++) {
        totalBalance += accounts[i]->getDepositAmount();
    }
    return totalBalance;
}

double Bank::calculateTotalInterest() {
    double totalInterest = 0;
    for(int i = 0; i < numAccounts; i++) {
        totalInterest += accounts[i]->calculateInterest();
    }
    return totalInterest;
}