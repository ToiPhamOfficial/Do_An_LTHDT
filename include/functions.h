/* 
-- Nội dung tệp: Chứa các hàm tiện tích
-- Số hàm: ...
*/

string trim(const string &s) {
    int i = 0, j = s.length() - 1;
    while(s[i] == ' ') {
        i++;
    }
    while(s[j] == ' ') {
        j--;
    }
    return s.substr(i, j - i + 1);
}

void splitData(const string &s, string d_arr[], const int &n, const char &delimiter) {
    stringstream ss(s);
    string tmp;
    for(int i = 0; i < n; i++) {
        getline(ss, tmp, delimiter); tmp = trim(tmp);
        d_arr[i] = tmp;
    }
}

double roundToTwoDecimals(double x) {
    return round(x * 100.0) / 100.0;
}

string formatVND(const double &amount) {
    // Làm tròn đến 2 chữ số thập phân
    double roundedAmount = roundToTwoDecimals(amount);
    // Tách phần nguyên và phần thập phân
    long long integerPart = (long long)(roundedAmount);
    int decimalPart = (int)(round((roundedAmount - integerPart) * 100));
    // Format phần nguyên với dấu phẩy
    string numStr = to_string(integerPart);
    int n = numStr.length() - 3;
    while(n > 0) {
        numStr.insert(n, ",");
        n -= 3;
    }
    // Gắn phần thập phân
    ostringstream oss;
    oss << numStr << "." << setfill('0') << setw(2) << decimalPart;
    return oss.str();
}

string correctName(const string &str) {
    string result;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        word[0] = toupper(word[0]);
        for (size_t i = 1; i < word.length(); ++i) {
            word[i] = tolower(word[i]);
        }
        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }
    return result;
}

bool isNumberString(const string &str) {
    if (str == "") return false;
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

string toLowerCase(const string &str) {
    string result = str;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] + ('a' - 'A');
        }
    }
    return result;
}

bool isValidEmail(const string &email) {
    int at = email.find('@');
    int space = email.find(' ');
    int dot = email.find('.', at); // tim '.' sau '@'
    int com = email.rfind(".com"); // kiem tra .com o cuoi
    // Kiem tra dieu kien
    if (at == string::npos || at == 0 || at == email.length() - 1)
        return false;
    if (space != string::npos)
        return false;
    if (dot == string::npos || dot == email.length() - 1)
        return false;
    if (com == string::npos || com != email.length() - 4)
        return false;
    return true;
}

string reverseName(string &hoTen) {
    string tu[100]; // mang luu cac tu, toi da 100 tu
    int dem = 0;
    string temp = "";
    hoTen += ' '; // them khoang trang de tach tu cuoi
    for (char c : hoTen) {
        if (c != ' ') {
            temp += c;
        } else if (!temp.empty()) {
            tu[dem++] = temp;
            temp = "";
        }
    }
    string ketQua = "";
    for (int i = dem - 1; i >= 0; i--) {
        ketQua += tu[i];
        if (i > 0)
            ketQua += " ";
    }
    return ketQua;
}

template <class T>
void customSort(T *arr[], const int& n, bool (*cmp)(T*, T*), bool ascending) {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(ascending ? cmp(arr[j], arr[i]) : cmp(arr[i], arr[j])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}
