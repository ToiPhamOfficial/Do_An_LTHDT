/* 
-- Thành viên code: Pham Van Toi
-- Nội dung tệp: Chứa các hàm xử lí tệp
-- Số hàm: ...
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile(const string &fn, string *d_arr, const int &n) {
    ifstream rf(fn);
    if(!rf) {
        cout << "!!!File not found!" << endl;
        return;
    }
    int i = 0;
    while(getline(rf, d_arr[i]) && i < n) {
        i++;
    }

    rf.close();
}

void writeFile(string fn, string *d_arr, const int &n) {
    ofstream wf(fn);
    for(int i = 0; i < n; i++) {
        wf << d_arr[i] << endl;
    }

    wf.close();
}
