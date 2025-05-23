/* 
-- Thành viên code: Pham Van Toi
-- Nội dung tệp: Chứa các hàm tiện tích
-- Số hàm: ...
*/

#include <iostream>
#include <string>
#include <sstream>
#include <map>
//using namespace std;

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

void splitData(const string &s, map<string, string> &m) {
    stringstream ss(s);
    string key, value;
    getline(ss, key, '=');
    getline(ss, value);
    trim(key); trim(value);
    m[key] = value;
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