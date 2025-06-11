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
