/* 
-- Thành viên code: Pham Van Toi
-- Nội dung tệp: Chứa các hàm tiện tích
-- Số hàm: ...
*/

void trim(string &s) {
    int i = 0, j = s.length() - 1;
    while(s[i] == ' ') {
        i++;
    }
    while(s[j] == ' ') {
        j--;
    }
    s = s.substr(i, j - i + 1);
}

void splitData(const string &s, string *d_arr, const int &n) {
    stringstream ss(s);
    string tmp;
    for(int i = 0; i < n; i++) {
        getline(ss, tmp, '|'); trim(tmp);
        d_arr[i] = tmp;
    }
}

void loadLang(string lang, string *ld, int n) {
    string l_arr[5]{"vi", "vi2", "en"};
    /*if(lang != l_arr[0] && lang != l_arr[1]) {
        lang = "en";
        cout << "⚠ Language haven't support. System will use the default language (English)" << endl;
    }*/
    readFile("lang/" + lang + ".lang", ld, n);
}

void reloadSystem() {
    system("cls");
    loadLang(settings[1], lang_data, 12);
}

string formatVND(const int &amount) {
    string numStr = to_string(amount);
    int n = numStr.length() - 3;
    while(n > 0) {
        numStr.insert(n, ",");
        n -= 3;
    }
    
    return numStr + " VND";
}