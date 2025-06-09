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
    cout << "GREEN" << "+[Nhap ten khach hang]-> " << RESET;
    //cin >> ws;
    getline(cin, inputName); 
    inputName = correctName(inputName);
    if(inputName.length() > 22) {
        cout << YELLOW << "+[Canh bao]-> Khong duoc qua 22 ky tu, hay nhap lai." << RESET << endl;
    } else {
        customerName = inputName;
        break;
    }
  } while(inputName.length() > 22);

  // Nhập số CCCD
  do {
    //cin >> ws;
    cout << "GREEN" << "+[Nhap so CCCD]-> " << RESET;
    cin >> inputId; 
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
    if(inputAmount < 100000.0 && inputAmount > 999999999999.0) {
        cout << YELLOW << "+[Canh bao]-> So du toi da cho phep  > 100,000 VND và < 999,999,999,999 VND" << RESET << endl;
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
    if(inputRate <= 0 && inputRate > 10.0) {
        cout << YELLOW << "+[Canh bao]-> Lai suat toi da cho phép > 0 và <= 10%" << RESET << endl;
    } else {
        // thêm phần làm tròn đến 2 chữ số
        interestRate = inputRate;
    }
  } while(inputRate <= 0 && inputRate > 10.0);
  
  // Nhập ngày mở tài khoản
  cout << "GREEN" << "+[Nhap ngay mo tai khoan]-> " << RESET << endl;
  openDate.input();
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
    os << SavingsAccount::toString() << term;
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
		void addAccount(const int &accountType); // Hàm thêm tài khoản vào ngân hàng
		string getName(); // Hàm trả về tên của ngân hàng
        string getAddress(); // Hàm trả về  địa chỉ của ngân hàng
        string getPhone(); // Hàm trả về số điện thoại chăm sóc khách hàng của ngân hàng
        string getTaxCode(); // Hàm trả về mã số thuế của ngân hàng
        string getEmail(); // Hàm trả về email của ngân hàng
        int getNumAccounts(); // Hàm lấy số lượng tài khoản tiết kiệm
		/*void setName(const string &name); // Hàm đặt tên của ngân hàng
        void setAddress(const string &address); // Hàm đặt địa chỉ của ngân hàng
        void setTaxCode(const string &taxCode); // Hàm đặt mã số thuế của ngân hàng
        void setPhone(const string &phone); // Hàm đặt số điện thoại chăm sóc khách hàng của ngân hàng
        void setEmail(const string &email); // Hàm đặt email của ngân hàng*/
        string toString(); // Dịnh dạng thông tin ngân hàng thành chuỗi
        void loadFromFile(); // Tải thông tin ngân hàng từ tệp
		void saveToFile(); // Lưu thông tin ngân hàng đến tệp
        
        bool accountExists(const string &customerId); // Kiểm tra xem sổ tiết kiệm có tồn tại hay không
		bool removeAccount(const string &customerId); // Hàm xoá tài khoản khỏi ngân hàng
        void showAccounts(const int mod); // Hàm hiển thị các sổ tiết kiệm theo kiểu lựa chọn

        ~Bank(); // Hàm huỷ bỏ

        // Các hàm đang trong quá trình viết lại, có thể sẽ xoá
        static bool compareByName(SavingsAccount *a, SavingsAccount *b);
        static bool compareByBalance(SavingsAccount *a, SavingsAccount *b);
        void sortByName(bool ascending = true);
        void sortByBalance(bool ascending = true);
        
        void findAccountByCustomerId();
        void findAccountByCustomerName();
        void findAccountByIdNumber();
        void findAccountByOpenDate();
        void findAccountByInterestRate();
};

Bank::Bank() {
    name = address = taxCode = phone = email = "";
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

/*void Bank::setName(const string &name) {
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
}*/

bool Bank::accountExists(const string &customerId) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i]->getCustomerId() == customerId) {
            return true;
        }
    }
    return false;
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

void Bank::showAccounts(const int mod) {
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


// Các hàm tìm kiếm
void Bank::findAccountByCustomerId() {
    if (numAccounts == 0) {
        cout << "+[Canh bao]-> Khong co so tiet kiem nao!" << endl;
        system("pause");
        return;
    }

    string searchId;
    cout << "GREEN" << "+[Nhap ma khach hang]-> " << "\033[0m";
    getline(cin, searchId);

    ofstream wf("data/output.data");
    if (!wf) {
        cerr << "+[Loi]-> Khong mo duoc file de ghi ket qua!" << endl;
        return;
    }

    bool found = false;
    int index = 0;

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i]->getCustomerId() == searchId) {
            if (!found) {
                wf << "\n\n\n=============================== DANH SACH SO TIET KIEM TIM KIEM MA KHACH HANG =========================================\n\n";
                wf << getHorizontalBorder(1);
                wf << getTableHeader(1);
                wf << getHorizontalBorder(1);
                found = true;
            }
            wf << getTableRow(1, accounts[i], index++);
            wf << getHorizontalBorder(1);
        }
    }

    wf.close();

    if (!found) {
        cout << "+[Thong bao]-> Khong tim thay khach hang nao co ma: " << searchId << endl;
    } else {
        cout << "+[Thong bao]-> Da ghi ket qua vao file 'data/output.data'\n";
    }

    system("pause");
}

void Bank::findAccountByCustomerName() {
    if (numAccounts == 0) {
        cout << "+[Canh bao]-> Khong co so tiet kiem nao!" << endl;
        system("pause");
        return;
    }

    string name;
    cout << "GREEN" << "+[Nhap ten khach hang]-> " << "\033[0m";
    getline(cin, name);

    ofstream wf("data/output.data");
    if (!wf) {
        cerr << "+[Loi]-> Khong mo duoc file!" << endl;
        return;
    }

    bool found = false;
    int index = 0;

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i]->getCustomerName() == name) {
            if (!found) {
                wf << "=========== DANH SACH SO TIET KIEM TIM KIEM THEO TEN KHACH HANG ===========\n\n";
                wf << getHorizontalBorder(1);
                wf << getTableHeader(1);
                wf << getHorizontalBorder(1);
                found = true;
            }
            wf << getTableRow(1, accounts[i], index++);
            wf << getHorizontalBorder(1);
        }
    }

    wf.close();
    if (!found) cout << "+[Thong bao]-> Khong tim thay ten khach hang!" << endl;
    system("pause");
}

void Bank::findAccountByIdNumber() {
    if (numAccounts == 0) {
        cout << "+[Canh bao]-> Khong co so tiet kiem nao!" << endl;
        system("pause");
        return;
    }

    string id;
    cout << "GREEN" << "+[Nhap so CCCD]-> " << "\033[0m";
    getline(cin, id);

    ofstream wf("data/output.data");
    if (!wf) {
        cerr << "+[Loi]-> Khong mo duoc file!" << endl;
        return;
    }

    bool found = false;
    int index = 0;

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i]->getIdNumber() == id) {
            if (!found) {
                wf << "\n\n\n=========== DANH SACH SO TIET KIEM TIM KIEM THEO CCCD/CMT ===========\n\n";
                wf << getHorizontalBorder(1);
                wf << getTableHeader(1);
                wf << getHorizontalBorder(1);
                found = true;
            }
            wf << getTableRow(1, accounts[i], index++);
            wf << getHorizontalBorder(1);
        }
    }

    wf.close();
    if (!found) cout << "+[Thong bao]-> Khong tim thay CCCD/CMT!" << endl;
    system("pause");
}

void Bank::findAccountByOpenDate() {
    if (numAccounts == 0) {
        cout << "+[Canh bao]-> Khong co so tiet kiem nao!" << endl;
        system("pause");
        return;
    }

    int d, m, y;
    cout << "GREEN" << "+[Nhap ngay mo (d m y)]-> " << "\033[0m";
    cin >> d >> m >> y;
    cin.ignore();

    Date inputDate(d, m, y); // Giả sử bạn có lớp Date(d, m, y)

    ofstream wf("data/output.data");
    if (!wf) {
        cerr << "+[Loi]-> Khong mo duoc file!" << endl;
        return;
    }

    bool found = false;
    int index = 0;

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i]->getOpenDate() == inputDate) {
            if (!found) {
                wf << "\n\n\n=========== DANH SACH SO TIET KIEM TIM KIEM THEO NGAY MO ===========\n\n";
                wf << getHorizontalBorder(1);
                wf << getTableHeader(1);
                wf << getHorizontalBorder(1);
                found = true;
            }
            wf << getTableRow(1, accounts[i], index++);
            wf << getHorizontalBorder(1);
        }
    }

    wf.close();
    if (!found) cout << "+[Thong bao]-> Khong tim thay ngay mo tuong ung!" << endl;
    system("pause");
}

void Bank::findAccountByInterestRate() {
    if (numAccounts == 0) {
        cout << "+[Canh bao]-> Khong co so tiet kiem nao!" << endl;
        system("pause");
        return;
    }

    double rate;
    cout << "GREEN" << "+[Nhap lai suat can tim]-> " << "\033[0m";
    cin >> rate;
    cin.ignore();

    ofstream wf("data/output.data");
    if (!wf) {
        cerr << "+[Loi]-> Khong mo duoc file!" << endl;
        return;
    }

    bool found = false;
    int index = 0;

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i]->getInterestRate() == rate) {
            if (!found) {
                wf << "\n\n\n=========== DANH SACH SO TIET KIEM TIM KIEM THEO LAI SUAT ===========\n\n";
                wf << getHorizontalBorder(1);
                wf << getTableHeader(1);
                wf << getHorizontalBorder(1);
                found = true;
            }
            wf << getTableRow(1, accounts[i], index++);
            wf << getHorizontalBorder(1);
        }
    }

    wf.close();
    if (!found) cout << "+[Thong bao]-> Khong tim thay lai suat tuong ung!" << endl;
    system("pause");
}