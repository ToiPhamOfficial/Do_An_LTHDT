/* 
-- Nội dung tệp: Chứa các hàm xử lí tệp
-- Số hàm: ...
*/

string getHorizontalBorder(const int &type) {
    string p1 = "+-----+---------+----------------------+--------------+------------+";
    string p2 = "--------------------+--------------+----------------+";
    switch(type) {
        case 1:
            return p1 + p2 + "\n";
        case 2:
            return p1 + p2 + "--------------------+\n";
        default:
            return "";
    }
}

string getTableHeader(const int &type) {
    ostringstream os;
    os << "|" << " STT " << "|" << "   MKH   "
       << "|" << "      Khach hang      " << "|" << "   CMT/CCCD   " 
       << "|" << "   Ngay mo  " << "|" << "     So du (VND)    "
       << "|" << " Lai suat (%) " << "|" << " Ky han (thang) " << "|";
    switch(type) {
        case 1: {
            os << endl;
            return os.str();
        }
        case 2: {
            os << "   Tien lai (VND)   " << "|" << endl;
            return os.str();
        }
        default:
            return "";
    }
}

string getTableRow(const int &type, SavingsAccount *acc, const int &i) {
    ostringstream os;
    os << left;
    os << "| " << setw(4) << i + 1 
       << "| " << setw(8) << acc->getCustomerId()
       << "| " << setw(21) << acc->getCustomerName()
       << "| " << setw(13) << acc->getIdNumber()
       << "| " << setw(11) << acc->getOpenDate().toString()
       << "| " << setw(19) << formatVND(acc->getDepositAmount())
       << "| " << setw(13) << acc->getInterestRate()
       << "| " << setw(15) << ((acc->getTerm() == 0) ? "N/A" : to_string(acc->getTerm()));
    switch(type) {
        case 1: {
            os << "|" << endl;
            return os.str();
        }
        case 2: {
            os << "| " << setw(19) << formatVND(acc->calculateInterest()) << "|" << endl;
            return os.str();
        }
        default:
            return "";
    }
}

void exportBankInfo(Bank &B) {
    ofstream wf("data/output.data");
    wf << setw(48) << "-Thong tin ngan hang-\n\n";
    wf << "+-----------------+---------------------------------------------------+" << endl;
    wf << "|    Thong tin    |                      Noi dung                     |" << endl;
    wf << "+-----------------+---------------------------------------------------+" << endl;
    wf << "| Ten ngan hang   | " << left << setw(50) << B.getName() << "|" << endl;
    wf << "+-----------------+---------------------------------------------------+" << endl;
    wf << "| Dia chi         | " << left << setw(50) << B.getAddress() << "|" << endl;
    wf << "+-----------------+---------------------------------------------------+" << endl;
    wf << "| Ma so thue      | " << left << setw(50) << B.getTaxCode() << "|" << endl;
    wf << "+-----------------+---------------------------------------------------+" << endl;
    wf << "| Dien thoai      | " << left << setw(50) << B.getPhone() << "|" << endl;
    wf << "+-----------------+---------------------------------------------------+" << endl;
    wf << "| Email           | " << left << setw(50) << B.getEmail() << "|" << endl;
    wf << "+-----------------+---------------------------------------------------+" << endl;
}

void exportBankReport(Bank &B) {
    ofstream wf("data/output.data");
    wf << setw(51) << "-Bao cao thong ke ngan hang-\n\n";
    wf << "+-----------------------------------+-----------------------------------+" << endl;
    wf << "|             Thong tin             |              Noi dung             |" << endl;
    wf << "+-----------------------------------+-----------------------------------+" << endl;
    wf << "| Tong so so tiet kiem              | " << left << setw(34) << B.getNumAccounts() << "|" << endl;
    wf << "+-----------------------------------+-----------------------------------+" << endl;
    wf << "| Tong so so tiet kiem co ky han    | " << left << setw(34) << B.countAccountsByType(1) << "|" << endl;
    wf << "+-----------------------------------+-----------------------------------+" << endl;
    wf << "| Tong so so tiet kiem khong ky han | " << left << setw(34) << B.countAccountsByType(2) << "|" << endl;
    wf << "+-----------------------------------+-----------------------------------+" << endl;
    wf << "| Tong so du (VND)                  | " << left << setw(34) << formatVND(B.calculateTotalBalance()) << "|" << endl;
    wf << "+-----------------------------------+-----------------------------------+" << endl;
    wf << "| Tong tien lai phai tra (VND)      | " << left << setw(34) << formatVND(B.calculateTotalInterest()) << "|" << endl;
    wf << "+-----------------------------------+-----------------------------------+" << endl;
}
  
void exportTable(const string &title, SavingsAccount *accounts[], int n) {
    ofstream wf("data/output.data");
    if(!wf) {
        cout << YELLOW << "+[Canh bao]-> Doc tep that bai. Vui long kiem tra lai tep" << RESET << endl;
        return;
    }
    wf << title;
    wf << getHorizontalBorder(1);
    wf << getTableHeader(1);
    wf << getHorizontalBorder(1);
    for(int i = 0; i < n; i++) {
        wf << getTableRow(1, accounts[i], i);
        wf << getHorizontalBorder(1);
    }

    wf.close();
}