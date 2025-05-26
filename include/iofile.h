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
    return c;
}

void writeFile(string fn, string *d_arr, const int &n) {
    ofstream wf(fn);
    for(int i = 0; i < n; i++) {
        wf << d_arr[i] << endl;
    }
}

void outputData(SavingsAccount *accounts[], int n) {
    ofstream wf("data/output.data");
    ostringstream ouputString;
    ouputString << "+-----+----------+--------------------+---------+--------------------"
                << "+---------------+---------------+----------+----------+" << endl
                << "|" << " STT " << "|" << "   Loai   " << "|" << "   Ten khach hang   "
                << "|" << "   MKH   " << "|" << "        CCCD        " 
                << "|" << "    Ngay mo    " << "|" << "     So du     "
                << "|" << " Lai suat " << "|" << "  Ky han  " << "|" << endl
                << "+-----+----------+--------------------+---------+--------------------"
                << "+---------------+---------------+----------+----------+" << endl;
    ouputString << left;
    for(int i = 0; i < n; i++) {
        ouputString << "|" << setw(5) << i + 1 << "|" << setw(10) << accounts[i]->getAccountType()
                    << "|" << setw(20) << accounts[i]->getCustomerName()
                    << "|" << setw(9) << accounts[i]->getCustomerId()
                    << "|" << setw(20) << accounts[i]->getIdNumber()
                    << "|" << setw(15) << "22/05/2025"
                    << "|" << setw(15) << formatVND(accounts[i]->getDepositAmount())
                    << "|" << setw(10) << accounts[i]->getInterestRate()
                    << "|" << setw(10) << 8 << "|" << endl;
        ouputString << "+-----+----------+--------------------+---------+--------------------"
                    << "+---------------+---------------+----------+----------+" << endl;
    }
    wf << ouputString.str();
    cout << ouputString.str();
}