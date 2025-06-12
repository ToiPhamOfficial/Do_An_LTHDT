/* 
-- Nội dung tệp: Chứa các lớp
-- Số lớp: 5
*/

class Bank; // Khai báo lớp Bank để sử dụng trong lớp SavingsAccount

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
        bool operator >(const Date &other); // Hàm so sánh 2 ngày có lớn hơn hay không
        bool operator <(const Date &other); // Hàm so sánh 2 ngày có nhỏ hơn hay không
        bool operator >=(const Date &other); // Hàm so sánh 2 ngày có lớn hơn hoặc bằng hay không
        bool operator <=(const Date &other); // Hàm so sánh 2 ngày có nhỏ hơn hoặc bằng hay không
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
        cout << GREEN << " +[Nhap ngay (1-31)]-> " << RESET;
        cin >> day;
        if (day < 1 || day > 31) 
            cout << YELLOW << " +[Canh bao]-> Ngay khong hop le, hay nhap lai!" << RESET << endl;
    } while (day < 1 || day > 31);
    do {
        cout << GREEN << " +[Nhap thang (1-12)]-> " << RESET;
        cin >> month;
        if (month < 1 || month > 12) 
            cout << YELLOW << " +[Canh bao]-> Thang khong hop le, hay nhap lai!" << RESET << endl;
    } while (month < 1 || month > 12);
    do {
        cout << GREEN << " +[Nhap nam (1900-2025)]-> " << RESET;
        cin >> year;
        if (year < 1900 || year > 2025) 
            cout << YELLOW << " +[Canh bao]-> Nam khong hop le, hay nhap lai!" << RESET << endl;
    } while (year < 1900 || year > 2025);
    Date current = Date::getCurrentDate();
    // So sánh: nếu ngày nhập vào lớn hơn ngày hiện tại thì nhập lại
    if(*this > current || !isValidDate(day, month, year)) {
        cout << YELLOW << " +[Canh bao]-> Ngay thang nam khong hop le, hay nhap lai!" << RESET << endl;
        input();
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
    if(m == 4 || m == 6 || m == 9 || m == 11) {
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

bool Date::operator>(const Date &other) {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day > other.day;
}

bool Date::operator<(const Date &other) {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator>=(const Date &other) {
    if (year != other.year) return year > other.year;
    if (month != other.month) return month > other.month;
    return day >= other.day;
}

bool Date::operator<=(const Date &other) {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day <= other.day;
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
        virtual void inputOrUpdate(const bool &isUpdateMode = false, string existingCustomerIds[] = nullptr, string existingIdNumbers[] = nullptr, const int &numExisting = 0); // Hàm nhập thông tin hoạc cập nhật sổ tiết kiệm
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

void SavingsAccount::inputOrUpdate(const bool &isUpdateMode, string existingCustomerIds[], string existingIdNumbers[], const int &numExisting) {
    string inputName, inputId;
    double inputAmount, inputRate;
    
    // Nhập tên khách hàng
    do {
        cout << GREEN << "+[Nhap ten khach hang" << (isUpdateMode ? " moi (0: bo qua)" : "") << "]-> " << RESET;
        getline(cin, inputName); 
        inputName = trim(inputName);
        if(isUpdateMode && inputName == "0") break;
        inputName = correctName(inputName);
        if(inputName.length() > 21) {
            cout << YELLOW << "+[Canh bao]-> Khong duoc qua 21 ky tu, hay nhap lai." << RESET << endl;
            continue;
        }
        customerName = inputName;
        break;
    } while(inputName.length() > 21);

    // Nhập số CCCD với kiểm tra trùng lặp
    do {
        cout << GREEN << "+[Nhap so CCCD" << (isUpdateMode ? " moi (0: bo qua)" : "") << "]-> " << RESET;
        getline(cin, inputId);
        inputId = trim(inputId);
        if(isUpdateMode && inputId == "0") break;
        if(inputId.length() != 12 || !isNumberString(inputId)) {
            cout << YELLOW << "+[Canh bao]-> CCCD phai gom 12 chu so" << RESET << endl;
            continue;
        }
        // Kiểm tra trùng lặp CCCD
        bool isDuplicate = false;
        if(existingIdNumbers != nullptr && !isUpdateMode) {
            for(int i = 0; i < numExisting; i++) {
                if(existingIdNumbers[i] == inputId) {
                    isDuplicate = true;
                    break;
                }
            }
        }
        if(isDuplicate) {
            cout << YELLOW << "+[Canh bao]-> So CCCD da ton tai, vui long nhap so khac!" << RESET << endl;
            continue;
        }
        idNumber = inputId;
        break;
    } while(inputId.length() != 12 || !isNumberString(inputId));
    
    // Nhập số tiền gửi
    do {
        cout << GREEN << "+[Nhap so tien gui" << (isUpdateMode ? " moi (0: bo qua)" : "") << "]-> " << RESET;
        cin >> inputAmount;
        if(isUpdateMode && inputAmount == 0.0) break;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << YELLOW << "+[Canh bao]-> Vui long nhap so du hop le!" << RESET << endl;
            continue;
        }
        if(inputAmount < 100000.0 || inputAmount > 999999999999.0) {
            cout << YELLOW << "+[Canh bao]-> So du cho phep  > 100,000 VND va < 999,999,999,999 VND" << RESET << endl;
            continue;
        }
        depositAmount = roundToTwoDecimals(inputAmount);
    } while(inputAmount < 100000.0 || inputAmount > 999999999999.0);

    // Nhập lãi suất
    do {
        cout << GREEN << "+[Nhap lai suat" << (isUpdateMode ? " moi (0: bo qua)" : "") << "]-> " << RESET;
        cin >> inputRate;
        if(isUpdateMode && inputRate == 0.0) break;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << YELLOW << "+[Canh bao]-> Vui long nhap lai suat hop le!" << RESET << endl;
            continue;
        }
        if(inputRate <= 0 || inputRate > 10.0) {
            cout << YELLOW << "+[Canh bao]-> Lai suat cho phep > 0 va <= 10%" << RESET << endl;
            continue;
        }
        interestRate = roundToTwoDecimals(inputRate);
    } while(inputRate <= 0 || inputRate > 10.0);
    
    // Nhập ngày mở sổ tiết kiệm
    if(isUpdateMode) {
        char c;
        cout << GREEN << "+[Nhap ngay mo so tiet kiem moi (0: bo qua)]: " << RESET;
        cin >> c;
        if(c != '0') {
            openDate.input(); 
        }
    } else {
        cout << GREEN << "+[Nhap ngay mo so tiet kiem]: " << RESET << endl;
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
     << " | " << fixed << setprecision(2) << depositAmount
     << " | " << fixed << setprecision(2) << interestRate;
  return os.str();
}

SavingsAccount::~SavingsAccount() {}


//================= Định nghĩa lớp TermAccount (Lớp sổ tiết kiệm có kỳ hạn) ================\\.
class TermAccount : public SavingsAccount {
    private:
        int term;
    public:
        TermAccount(); // Hàm thiết lập
        void inputOrUpdate(const bool &isUpdateMode = false, string existingCustomerIds[] = nullptr, string existingIdNumbers[] = nullptr, const int &numExisting = 0); // Hàm nhập thông tin sổ tiết kiệm có kỳ hạn
        int getTerm(); // Hàm trả về kỳ hạn sổ tiết kiệm có kỳ hạn
        void setTerm(int t); // Hàm đặt kỳ hạn sổ tiết kiệm có kỳ hạn
        double calculateInterest(); // Hàm tính tiền lãi sổ tiết kiệm có kỳ hạm
        string toString(); // Hàm định dạng thông tin sổ tiết kiệm có kỳ hạn theo cấu trúc
        ~TermAccount(); // Hàm huỷ bỏ
};

TermAccount::TermAccount() : SavingsAccount() {}

void TermAccount::inputOrUpdate(const bool &isUpdateMode, string existingCustomerIds[], string existingIdNumbers[], const int &numExisting) {
    cin.ignore();
    
    // Nhập mã khách hàng đúng định dạng: T + 5 chữ số với kiểm tra trùng lặp
    string inputId;
    bool validId = false;
    while (!validId) {
        cout << GREEN << "+[Nhap ma khach hang" << (isUpdateMode ? " moi (0: bo qua)" : "") << "]-> " << RESET;
        getline(cin, inputId);
        inputId = trim(inputId);
        if(isUpdateMode && inputId == "0") break;
        // Kiểm tra định dạng: T + 5 chữ số
        if (inputId.length() == 6 && inputId[0] == 'T') {
            bool allDigits = true;
            for (int i = 1; i < 6; i++) {
                if (!isdigit(inputId[i])) {
                    allDigits = false;
                    break;
                }
            }
            if(allDigits) {
                // Kiểm tra trùng lặp mã khách hàng
                bool isDuplicate = false;
                if(existingCustomerIds != nullptr && !isUpdateMode) {
                    for(int i = 0; i < numExisting; i++) {
                        if(existingCustomerIds[i] == inputId) {
                            isDuplicate = true;
                            break;
                        }
                    }
                }
                if(isDuplicate) {
                    cout << YELLOW << "+[Canh bao]-> Ma khach hang da ton tai, vui long nhap ma khac!" << RESET << endl;
                } else {
                    validId = true;
                    customerId = inputId;
                }
            } else {
                cout << YELLOW << "+[Canh bao]-> Ma khach hang khong hop le! Can co dang T + 5 chu so" << RESET << endl;
            }
        } else {
            cout << YELLOW << "+[Canh bao]-> Ma khach hang khong hop le! Can co dang T + 5 chu so" << RESET << endl;
        }
    }
    
    SavingsAccount::inputOrUpdate(isUpdateMode, existingCustomerIds, existingIdNumbers, numExisting);
    
    // Nhập kỳ hạn
    do {
        cout << GREEN << "+[Nhap ky han" << (isUpdateMode ? " moi (0: bo qua)" : "") << "]-> " << RESET;
        cin >> term;
        if(isUpdateMode && term == 0) break;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << YELLOW << "+[Canh bao]-> Vui long nhap ky han hop le!" << RESET << endl;
            continue;
        }
        if(term < 1 || term > 60) {
            cout << YELLOW << "+[Canh bao]-> Ky han cho phep tu 1 den 60 thang" << RESET << endl;
        } else {
            break;
        }
    } while(term < 1 || term > 60);
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
        return depositAmount * (interestRate / 100) * months;
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
        void inputOrUpdate(const bool &isUpdateMode = false, string existingCustomerIds[] = nullptr, string existingIdNumbers[] = nullptr, const int &numExisting = 0);
        double calculateInterest(); // Hàm tính tiền lãi sổ  tiết kiệm không kỳ hạn
        ~NonTermAccount(); // Hàm huỷ bỏ
};

void NonTermAccount::inputOrUpdate(const bool &isUpdateMode, string existingCustomerIds[], string existingIdNumbers[], const int &numExisting) {
    // Nhập mã khách hàng đúng định dạng: N + 5 chữ số với kiểm tra trùng lặp
    string inputId;
    bool validId = false;
    while (!validId) {
        cout << GREEN << "+[Nhap ma khach hang" << (isUpdateMode ? " moi (0: bo qua)" : "") << "]-> " << RESET;
        getline(cin, inputId);
        inputId = trim(inputId);
        if(isUpdateMode && inputId == "0") break;
        
        // Kiểm tra định dạng: N + 5 chữ số
        if (inputId.length() == 6 && inputId[0] == 'N') {
            bool allDigits = true;
            for(int i = 1; i < 6; i++) {
                if(!isdigit(inputId[i])) {
                    allDigits = false;
                    break;
                }
            }
            if (allDigits) {
                // Kiểm tra trùng lặp mã khách hàng
                bool isDuplicate = false;
                if(existingCustomerIds != nullptr && !isUpdateMode) {
                    for(int i = 0; i < numExisting; i++) {
                        if(existingCustomerIds[i] == inputId) {
                            isDuplicate = true;
                            break;
                        }
                    }
                }
                
                if(isDuplicate) {
                    cout << YELLOW << "+[Canh bao]-> Ma khach hang da ton tai, vui long nhap ma khac!" << RESET << endl;
                } else {
                    validId = true;
                    customerId = inputId;
                }
            } else {
                cout << YELLOW << "+[Canh bao]-> Ma khach hang khong hop le! Can co dang N + 5 chu so" << RESET << endl;
            }
        } else {
            cout << YELLOW << "+[Canh bao]-> Ma khach hang khong hop le! Can co dang N + 5 chu so" << RESET << endl;
        }
    }
    SavingsAccount::inputOrUpdate(isUpdateMode, existingCustomerIds, existingIdNumbers, numExisting);
}

double NonTermAccount::calculateInterest() {
    Date currentDate = Date::getCurrentDate();
	int months = openDate.monthsBetween(currentDate);
    if (months < 0) {
        return 0.0; // Khong tinh lai nhung ngay trong tuong lai
    }
    return depositAmount * (interestRate / 100) * months;
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
		string getName(); // Hàm trả về tên của ngân hàng
        string getAddress(); // Hàm trả về  địa chỉ của ngân hàng
        string getPhone(); // Hàm trả về số điện thoại chăm sóc khách hàng của ngân hàng
        string getTaxCode(); // Hàm trả về mã số thuế của ngân hàng
        string getEmail(); // Hàm trả về email của ngân hàng
        int getNumAccounts(); // Hàm lấy số lượng sổ tiết kiệm
        string toString(); // Định dạng thông tin ngân hàng thành chuỗi
        void loadFromFile(); // Tải thông tin ngân hàng từ tệp
		void saveToFile(); // Lưu thông tin ngân hàng đến tệp
        void addAccount(const int &accountType); // Hàm thêm sổ tiết kiệm vào ngân hàng
        void updateAccountInfo(const string &customerId);
		bool removeAccount(const string &customerId); // Hàm xoá sổ tiết kiệm khỏi ngân hàng
        bool accountExists(const string &customerId); // Kiểm tra xem sổ tiết kiệm có tồn tại hay không
        void showAccounts(const int &mod); // Hàm hiển thị các sổ tiết kiệm theo kiểu lựa chọn
        void calculateInterestPerAccount(); // Hàm tính tiền lãi mỗi sổ tiết kiệm
        int countAccountsByType(const int &type); // Hàm đếm số lượng sổ tiết kiệm theo loại
        double calculateTotalAmount(); // Hàm tính tổng số dư của tất cả các sổ tiết kiệm
        double calculateTotalInterest(); // Hàm tính tổng tiền lãi của tất cả các sổ tiết kiệm
        static bool compareByName(SavingsAccount *a, SavingsAccount *b); // Hàm so sánh theo tên khách hàng
        static bool compareByOpenDate(SavingsAccount *a, SavingsAccount *b); // Hàm so sánh theo ngày mở sổ tiết kiệm
        static bool compareByAmount(SavingsAccount *a, SavingsAccount *b); // Hàm so sánh theo số dư sổ tiết kiệm
        static bool compareByInterest(SavingsAccount *a, SavingsAccount *b); // Hàm so sánh theo lãi suất sổ tiết kiệm
        static bool compareByTerm(SavingsAccount *a, SavingsAccount *b); // Hàm so sánh theo kỳ hạn sổ tiết kiệm có kỳ hạn
        void sort(const int &mod, bool ascending = true); // Hàm sắp xếp các sổ tiết kiệm theo kiểu lựa chọn
        void search(const int &mod, const string &keyword); // Hàm tìm kiếm các sổ tiết kiệm theo kiểu lựa chọn
        void filterByOpenDate(const Date &startDate, const Date &endDate); // Hàm lọc các sổ tiết kiệm theo ngày mở
        void filterByAmount(const double &minAmount, const double &maxAmount); // Hàm lọc các sổ tiết kiệm theo số dư
        void filterByInterestRate(const double &minRate, const double &maxRate); // Hàm lọc các sổ tiết kiệm theo lãi suất
        void filterByTerm(const int &termMin, const int &termMax); // Hàm lọc các sổ tiết kiệm theo kỳ hạn
        ~Bank(); // Hàm huỷ bỏ
};

Bank::Bank() {
    name = address = taxCode = phone = email = "";
    numAccounts = 0;
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
            name = newName; 
            break;
        }
    } while(newName.length() > 50);
    // Nhập địa chỉ ngân hàng
    do {
        cout << GREEN << "+[Nhap dia chi ngan hang]-> " << RESET;
        getline(cin, newAddress);
        newAddress = trim(newAddress);
        if(newAddress.length() > 50) {
            cout << YELLOW << "+[Canh bao]-> Dia chi ngan hang khong duoc qua 50 ky tu" << RESET << endl;
        } else {
            address = newAddress; 
            break;
        }
    } while(newAddress.length() > 50);
    // Nhập mã số thuế ngân hàng
    do {
        // Kiểm tra mã số thuế có đúng định dạng không
        if(newTaxCode.length() != 10 || !isNumberString(newTaxCode)) {
            cout << YELLOW << "+[Canh bao]-> Ma so thue ngan hang phai gom 10 chu so, vui long nhap lai!" << RESET << endl;
            cout << GREEN << "+[Nhap ma so thue ngan hang]-> " << RESET;
            getline(cin, newTaxCode);
            newTaxCode = trim(newTaxCode);
        } else {
            break; // Thoát vòng lặp nếu mã số thuế hợp lệ
        }
    } while(true);
    do {
        // Kiểm tra số điện thoại có đúng định dạng không
        cout << GREEN << "+[Nhap so dien thoai ngan hang]-> " << RESET;
        getline(cin, newPhone);
        newPhone = trim(newPhone);
        if(newPhone.length() != 10 || !isNumberString(newPhone)) {
            cout << YELLOW << "+[Canh bao]-> So dien thoai ngan hang phai gom 10 chu so, vui long nhap lai!" << RESET << endl;
        } else {
            break; // Thoát vòng lặp nếu số điện thoại hợp lệ
        }
    } while(true);
    // Nhập email ngân hàng
    do {
        cout << GREEN << "+[Nhap email ngan hang]-> " << RESET;
        getline(cin, newEmail);
        newEmail = trim(newEmail);
        if(!isValidEmail(newEmail)) {
            cout << YELLOW << "+[Canh bao]-> Email khong hop le, vui long nhap lai!" << RESET << endl;
        } else {
            break; // Thoát vòng lặp nếu email hợp lệ
        }
    } while(!isValidEmail(newEmail));
    // Lưu thông tin ngân hàng vào tệp
    saveToFile();
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
    if(line.empty()) {
        return;
    }
    splitData(line, dataArr, 5, '|');
    name = dataArr[0]; address = dataArr[1]; taxCode = dataArr[2];
    phone = dataArr[3]; email = dataArr[4];
    getline(rf, line);
    // Đọc số lượng sổ tiết kiệm khách hàng
    rf >> numAccounts; rf.ignore();
    // Đọc thông tin các sổ tiết kiệm
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
            cout << YELLOW << "+[Canh bao]-> Tai du lieu khong thanh cong, vui long xem lai tep du lieu!" << RESET << endl;
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
    rf.close();
}    

void Bank::saveToFile() {
    ofstream wf("data/input.data");
    // Ghi thông tin ngân hàng vào dòng đầu tiên
    wf << toString() << endl;
    wf << endl;
    // Ghi số lượng sổ tiết kiệm
    if(numAccounts == 0) {
        wf << "0" << endl; // Nếu không có sổ tiết kiệm nào thì ghi 0
        return;
    } else {
        wf << numAccounts << endl;
    }
    // Ghi thông tin các sổ tiết kiệm
    for(int i = 0; i < numAccounts; i++) {
        wf << accounts[i]->toString() << endl;
    }
}

void Bank::addAccount(const int &accountType) {
    if(numAccounts < MAX_CUSTOMER) {
        // Tạo mảng mã khách hàng và CCCD hiện có
        string existingCustomerIds[MAX_CUSTOMER];
        string existingIdNumbers[MAX_CUSTOMER];
        
        for(int i = 0; i < numAccounts; i++) {
            existingCustomerIds[i] = accounts[i]->getCustomerId();
            existingIdNumbers[i] = accounts[i]->getIdNumber();
        }
        
        if(accountType == 1) {
            accounts[numAccounts] = new TermAccount();
        } else if(accountType == 2) {
            accounts[numAccounts] = new NonTermAccount();
        } else {
            return;
        }
        
        accounts[numAccounts]->inputOrUpdate(false, existingCustomerIds, existingIdNumbers, numAccounts);
        numAccounts++;
        cout << BLUE << "+[Thong bao]-> Them so tiet kiem thanh cong!" << RESET << endl;
        saveToFile();
    } else {
        cout << YELLOW << "+[Canh bao]-> So luong khach hang da dat den toi da" << RESET << endl;
    }
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
    
    // Tạo mảng mã khách hàng và CCCD hiện có (loại trừ tài khoản đang cập nhật)
    string existingCustomerIds[MAX_CUSTOMER];
    string existingIdNumbers[MAX_CUSTOMER];
    int count = 0;
    
    for(int i = 0; i < numAccounts; i++) {
        if(i != foundIndex) {
            existingCustomerIds[count] = accounts[i]->getCustomerId();
            existingIdNumbers[count] = accounts[i]->getIdNumber();
            count++;
        }
    }
    
    accounts[foundIndex]->inputOrUpdate(true, existingCustomerIds, existingIdNumbers, count);
}

bool Bank::removeAccount(const string &customerId) {
    int foundIndex = -1;
    // Tìm sổ tiết kiệm cần xóa
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i]->getCustomerId() == customerId) {
            foundIndex = i;
            break;
        }
    }
    if(foundIndex == -1) {
        return false;
    }
    // Xóa sổ tiết kiệm đã tìm thấy
    delete accounts[foundIndex];
    // Di chuyển các sổ tiết kiệm sau lên
    for(int i = foundIndex; i < numAccounts - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    numAccounts--;
    saveToFile();
    return true;
}

bool Bank::accountExists(const string &customerId) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i]->getCustomerId() == customerId) {
            return true;
        }
    }
    return false;
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

double Bank::calculateTotalAmount() {
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

bool Bank::compareByName(SavingsAccount *a, SavingsAccount *b) {
    return a->getCustomerName() < b->getCustomerName();
}

bool Bank::compareByOpenDate(SavingsAccount *a, SavingsAccount *b) {
    return a->getOpenDate() < b->getOpenDate();
}

bool Bank::compareByAmount(SavingsAccount *a, SavingsAccount *b) {
    return a->getDepositAmount() < b->getDepositAmount();
}

bool Bank::compareByInterest(SavingsAccount *a, SavingsAccount *b) {
    return a->getInterestRate() < b->getInterestRate();
}

bool Bank::compareByTerm(SavingsAccount *a, SavingsAccount *b) {
    return a->getTerm() < b->getTerm();
}

void Bank::sort(const int &mod, bool ascending) {
    // 1: Sắp xếp theo tên
    // 2: Sắp xếp theo ngày mở sổ
    // 3: Sắp xếp theo số dư
    // 4: Sắp xếp theo lãi suất
    // 5: Sắp xếp theo kỳ hạn
    switch(mod) {
        case 1: {
            customSort(accounts, numAccounts, compareByName, ascending);
            string spaces(42, ' ');
            string title = spaces + "-Danh sach so tiet kiem sap xep theo ten-\n\n";
            exportTable(title, accounts, numAccounts);
            break;
        }
        case 2: {
            customSort(accounts, numAccounts, compareByOpenDate, ascending);
            string spaces(38, ' ');
            string title = spaces + "-Danh sach so tiet kiem sap xep theo ngay mo so-\n\n";
            exportTable(title, accounts, numAccounts);
            break;
        }
        case 3: {
            customSort(accounts, numAccounts, compareByAmount, ascending);
            string spaces(41, ' ');
            string title = spaces + "-Danh sach so tiet kiem sap xep theo so du-\n\n";
            exportTable(title, accounts, numAccounts);
            break;
        }
        case 4: {
            customSort(accounts, numAccounts, compareByInterest, ascending);
            string spaces(39, ' ');
            string title = spaces + "-Danh sach so tiet kiem sap xep theo lai suat-\n\n";
            exportTable(title, accounts, numAccounts);
            break;
        }
        case 5: {
            customSort(accounts, numAccounts, compareByTerm, ascending);
            string spaces(40, ' ');
            string title = spaces + "-Danh sach so tiet kiem sap xep theo ky han-\n\n";
            exportTable(title, accounts, numAccounts);
            break;
        }
    }
}

void Bank::search(const int &mod, const string &keyWord) {
    // 1: Tìm kiếm theo mã khách hàng
    // 2: Tìm kiếm theo tên
    // 3: Tìm kiếm theo số CCCD
    // 4: Tìm kiếm theo kỳ hạn
    int fc = 0; // Số lượng sổ tiết kiệm tìm thấy
    SavingsAccount *foundAccounts[MAX_CUSTOMER];
    for(int i = 0; i < numAccounts; i++) {
        SavingsAccount *acc = accounts[i];
        bool found = false;
        switch(mod) {
            case 1: // Tìm theo mã khách hàng
                if(acc->getCustomerId() == keyWord) {
                    found = true;
                }
                break;
            case 2: // Tìm theo tên
                if(acc->getCustomerName().find(keyWord) != string::npos) {
                    found = true;
                }
                break;
            case 3: // Tìm theo số CCCD
                if(acc->getIdNumber() == keyWord) {
                    found = true;
                }
                break;
            case 4: // Tìm theo kỳ hạn
                if(to_string(acc->getTerm()).find(keyWord) != string::npos) {
                    found = true;
                }
                break;
        }
        if(found) {
            foundAccounts[fc++] = acc; // Lưu sổ tiết kiệm tìm thấy
        }
    }
    if(fc != 0) {
        // Hiển thị kết quả tìm kiếm
        string spaces(42, ' ');
        string title = spaces + "-Danh sach so tiet kiem tim thay-\n\n";
        exportTable(title, foundAccounts, fc);
    }
}

void Bank::filterByOpenDate(const Date &startDate, const Date &endDate) {
    SavingsAccount *filteredAccounts[MAX_CUSTOMER];
    int fc = 0; // Số lượng sổ tiết kiệm lọc được
    for(int i = 0; i < numAccounts; i++) {
        Date openDate = accounts[i]->getOpenDate();
        if(openDate >= startDate && openDate <= endDate) {
            filteredAccounts[fc++] = accounts[i];
        }
    }
    if(fc != 0) {
        // Hiển thị kết quả lọc
        string spaces(42, ' ');
        string title = spaces + "-Danh sach so tiet kiem theo ngay mo so-\n\n";
        exportTable(title, filteredAccounts, fc);
    } else {
        cout << YELLOW << "+[Canh bao]-> Khong co so tiet kiem nao trong khoang thoi gian nay" << RESET << endl;
    }
}

void Bank::filterByAmount(const double &minAmount, const double &maxAmount) {
    SavingsAccount *filteredAccounts[MAX_CUSTOMER];
    int fc = 0; // Số lượng sổ tiết kiệm lọc được
    for(int i = 0; i < numAccounts; i++) {
        double amount = accounts[i]->getDepositAmount();
        if(amount >= minAmount && amount <= maxAmount) {
            filteredAccounts[fc++] = accounts[i];
        }
    }
    if(fc != 0) {
        // Hiển thị kết quả lọc
        string spaces(42, ' ');
        string title = spaces + "-Danh sach so tiet kiem theo so du-\n\n";
        exportTable(title, filteredAccounts, fc);
    } else {
        cout << YELLOW << "+[Canh bao]-> Khong co so tiet kiem nao trong khoang so du nay" << RESET << endl;
    }
}

void Bank::filterByInterestRate(const double &minRate, const double &maxRate) {
    SavingsAccount *filteredAccounts[MAX_CUSTOMER];
    int fc = 0; // Số lượng sổ tiết kiệm lọc được
    for(int i = 0; i < numAccounts; i++) {
        double rate = accounts[i]->getInterestRate();
        if(rate >= minRate && rate <= maxRate) {
            filteredAccounts[fc++] = accounts[i];
        }
    }
    if(fc != 0) {
        // Hiển thị kết quả lọc
        string spaces(42, ' ');
        string title = spaces + "-Danh sach so tiet kiem theo lai suat-\n\n";
        exportTable(title, filteredAccounts, fc);
    } else {
        cout << YELLOW << "+[Canh bao]-> Khong co so tiet kiem nao trong khoang lai suat nay" << RESET << endl;
    }
}

void Bank::filterByTerm(const int &termMin, const int &termMax) {
    // Hàm lọc các sổ tiết kiệm theo kỳ hạn
    SavingsAccount *filteredAccounts[MAX_CUSTOMER];
    int fc = 0; // Số lượng sổ tiết kiệm lọc được
    for(int i = 0; i < numAccounts; i++) {
        if(accounts[i]->getCustomerId()[0] == 'T' && accounts[i]->getTerm() >= termMin && accounts[i]->getTerm() <= termMax) {
            filteredAccounts[fc++] = accounts[i];
        }
    }
    if(fc != 0) {
        // Hiển thị kết quả lọc
        string spaces(42, ' ');
        string title = spaces + "-Danh sach so tiet kiem theo ky han-\n\n";
        exportTable(title, filteredAccounts, fc);
    } else {
        cout << YELLOW << "+[Canh bao]-> Khong co so tiet kiem nao co ky han nay" << RESET << endl;
    }
}


Bank::~Bank() {
    for(int i = 0; i < numAccounts; i++) {
        delete accounts[i];
    }
}