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
    wf << "+-----+----------------------+---------+--------------"
       << "+-------------+-------------------+--------------+----------------+" << endl
       << "|" << " STT " << "|" << "      Khach hang      "
       << "|" << "   MKH   " << "|" << "   CMT/CCCD   " 
       << "|" << "   Ngay mo   " << "|" << "    So du (VND)    "
       << "|" << " Lai suat (%) " << "|" << " Ky han (thang) " << "|" << endl
       << "+-----+----------------------+---------+--------------"
       << "+-------------+-------------------+--------------+----------------+" << endl;
    wf << left;
    for(int i = 0; i < n; i++) {
        wf << "|" << setw(5) << i + 1 
           << "|" << setw(22) << accounts[i]->getCustomerName()
           << "|" << setw(9) << accounts[i]->getCustomerId()
           << "|" << setw(14) << accounts[i]->getIdNumber()
           << "|" << setw(13) << accounts[i]->getOpenDate().toString()
           << "|" << setw(19) << formatVND(accounts[i]->getDepositAmount())
           << "|" << setw(14) << accounts[i]->getInterestRate()
           << "|" << setw(16) << ((accounts[i]->getTerm() == 0) ? "N/A" : to_string(accounts[i]->getTerm())) 
           << "|" << endl;
        wf << "+-----+----------------------+---------+--------------"
           << "+-------------+-------------------+--------------+----------------+" << endl;
    }
}

// beta
void exportToTextFile(SavingsAccount *accounts[], int n, const string &filename) {
    string filepath = "data/" + filename + ".txt";
    ofstream file(filepath);
    
    if (file.is_open()) {
        file << "+-----+----------+----------------------+---------+--------------"
             << "+-------------+-------------------+--------------+----------------+" << endl
             << "|" << " STT " << "|" << "   Loai   " << "|" << "      Khach hang      "
             << "|" << "   MKH   " << "|" << "   CMT/CCCD   " 
             << "|" << "   Ngay mo   " << "|" << "    So du (VND)    "
             << "|" << " Lai suat (%) " << "|" << " Ky han (thang) " << "|" << endl
             << "+-----+----------+----------------------+---------+--------------"
             << "+-------------+-------------------+--------------+----------------+" << endl;
        
        for(int i = 0; i < n; i++) {
            file << "|" << setw(5) << i + 1 
                 << "|" << setw(10) << accounts[i]->getAccountType()
                 << "|" << setw(22) << accounts[i]->getCustomerName()
                 << "|" << setw(9) << accounts[i]->getCustomerId()
                 << "|" << setw(14) << accounts[i]->getIdNumber()
                 << "|" << setw(13) << accounts[i]->getOpenDate().toString()
                 << "|" << setw(19) << formatVND(accounts[i]->getDepositAmount())
                 << "|" << setw(14) << accounts[i]->getInterestRate()
                 << "|" << setw(16) << ((accounts[i]->getTerm() == 0) ? "N/A" : to_string(accounts[i]->getTerm())) 
                 << "|" << endl;
            file << "+-----+----------+----------------------+---------+--------------"
                 << "+-------------+-------------------+--------------+----------------+" << endl;
        }
        
        file.close();
        cout << BLUE << "+[Thong bao]-> Da xuat ket qua ra file: " << filepath << RESET << endl;
    } else {
        cout << RED << "+[Loi]-> Khong the mo file de ghi!" << RESET << endl;
    }
}