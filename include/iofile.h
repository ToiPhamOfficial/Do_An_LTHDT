/* 
-- Nội dung tệp: Chứa các hàm xử lí tệp
-- Số hàm: ...
*/

void exportBankInfo(Bank &B) {
    ofstream wf("data/output.data");
    wf << "+-----------------------------------------------+" << endl
       << "| Ten ngan hang: " << setw(31) << B.getName() << "|" << endl
       << "| Dia chi: " << setw(37) << B.getAddress() << "|" << endl
       << "| Ma so thue: " << setw(34) << B.getTaxCode() << "|" << endl
       << "| Dien thoai: " << setw(34) << B.getPhone() << "|" << endl
       << "| Email: " << setw(39) << B.getEmail() << "|" << endl;
    wf << "+-----------------------------------------------+" << endl;
}

string getHorizontalBorder(const int &type) {
    string p1 = "+-----+---------+----------------------+--------------+-------------+";
    string p2 = "-------------------+--------------+----------------+";
    string type1 = p1 + p2 + "\n";
    string type2 = p1 + p2 + "-----------+\n";
    if(type == 1) {
        return type1;
    } else if(type == 2) {
        return type2;
    } else {
        return "";
    }
}

string getTableHeader(const int &type) {
    ostringstream os;
    os << "|" << " STT " << "|" << "   MKH   "
       << "|" << "      Khach hang      " << "|" << "   CMT/CCCD   " 
       << "|" << "   Ngay mo   " << "|" << "    So du (VND)    "
       << "|" << " Lai suat (%) " << "|" << " Ky han (thang) " << "|";
    if(type == 1) {
        os << endl;
        return os.str();
    } else if(type == 2) {
        os << "   Tien lai    " << endl;
        return os.str();
    } else {
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
       << "| " << setw(12) << acc->getOpenDate().toString()
       << "| " << setw(18) << formatVND(acc->getDepositAmount())
       << "| " << setw(13) << acc->getInterestRate()
       << "| " << setw(15) << ((acc->getTerm() == 0) ? "N/A" : to_string(acc->getTerm())) 
       << "| ";
    if(type == 1) {
        os << endl;
        return os.str();
    } else if(type == 2) {
        os << acc->calculateInterest() << "| ";
        return os.str();
    } else {
        return "";
    }
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