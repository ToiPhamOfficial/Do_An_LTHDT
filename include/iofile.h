/* 
-- Thành viên code: Pham Van Toi
-- Nội dung tệp: Chứa các hàm xử lí tệp
-- Số hàm: ...
*/

int readFile(const string &fn, string *d_arr, const int &n) {
    ifstream rf(fn);
    if(!rf) {
        return -1;
    }
    int c = 0;
    string tmp;
    while(c < n && getline(rf, tmp)) {
        if(!tmp.empty()) {
            d_arr[c] = tmp;
            c++;
        }
    }
    rf.close();
    return c;
}

void writeFile(string fn, string *d_arr, const int &n) {
    ofstream wf(fn);
    for(int i = 0; i < n; i++) {
        wf << d_arr[i] << endl;
    }

    wf.close();
}