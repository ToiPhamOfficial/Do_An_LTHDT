/* 
-- Thành viên code: Pham Van Toi
-- Nội dung tệp: Chứa các hàm hiển thị và xử lí lựa chọn từ menu
-- Số hàm: ...
*/

void mainMenu() {
    cout << CYAN;
    cout << "+-------------------- Menu --------------------+" << endl;
    cout << "| 1. Cap nhat thong tin ngan hang              |" << endl;
    cout << "| 2. Cap nhat thong tin tai khoan              |" << endl;
    cout << "| 3. Them tai khoan moi                        |" << endl;
    cout << "| 4. Loc theo loai tai khoan                   |" << endl;
    cout << "| 5. Tim kiem tai khoan                        |" << endl;
    cout << "| 6. Sap xep tai khoan                         |" << endl;
    cout << "| 0. Thoat                                     |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << RESET;
}

void updateBankInfoMenu() {
    cout << endl;
    cout << CYAN;
    cout << "+----- Menu: Cap nhat thong tin ngan hang -----+" << endl;
    cout << "| 1. Cap nhat                                  |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << RESET;
}

int chooseInMenu(const int &max_choice) {
    int choice;
    while(true) {
        cout << GREEN << "+[Nhap lua chon]-> " << RESET; cin >> choice;
        if(choice >= 0 && choice <= max_choice) {
            return choice;
        } else {
            cout << YELLOW << "+[Canh bao]-> Lua chon khong hop le, vui long chon lai" << endl;
        }
    }
}

// beta
void handleSearch() {
    cout << endl;
    cout << CYAN;
    cout << "+---- Menu: Tim kiem tai khoan -> Thao tac ----+" << endl;
    cout << "| 1. Sap xep ket qua                           |" << endl;
    cout << "| 2. Xuat ra file                              |" << endl;
    cout << "| 3. Loc them                                  |" << endl;
    cout << "| 4. Cap nhat thong tin tai khoan              |" << endl;
    cout << "| 5. Xoa tai khoan                             |" << endl;
    cout << "| 0. Quay lai                                  |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << RESET;
}

// beta
void handleSortResultsMenu() {
    cout << endl;
    cout << CYAN;
    cout << "+-------- Menu: Sap xep ket qua tim kiem -------+" << endl;
    cout << "| 1. Sap xep theo ten khach hang                |" << endl;
    cout << "| 2. Sap xep theo so du                         |" << endl;
    cout << "| 3. Sap xep theo ngay mo tai khoan             |" << endl;
    cout << "| 4. Sap xep theo loai tai khoan                |" << endl;
    cout << "| 0. Quay lai                                   |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << RESET;
}

// beta
bool compareByOpenDate(SavingsAccount *a, SavingsAccount *b) {
    Date dateA = a->getOpenDate();
    Date dateB = b->getOpenDate();
    
    if (dateA.getYear() != dateB.getYear())
        return dateA.getYear() < dateB.getYear();
    if (dateA.getMonth() != dateB.getMonth())
        return dateA.getMonth() < dateB.getMonth();
    return dateA.getDay() < dateB.getDay();
}

// beta
bool compareByAccountType(SavingsAccount *a, SavingsAccount *b) {
    return a->getAccountType() < b->getAccountType();
}

// beta
void handleFilterMenu() {
    cout << endl;
    cout << CYAN;
    cout << "+------------ Menu: Loc them ket qua ------------+" << endl;
    cout << "| 1. Loc theo loai tai khoan                     |" << endl;
    cout << "| 2. Loc theo so du > X                          |" << endl;
    cout << "| 3. Loc theo so du < X                          |" << endl;
    cout << "| 4. Loc theo ngay mo tai khoan                  |" << endl;
    cout << "| 0. Quay lai                                    |" << endl;
    cout << "+-----------------------------------------------+" << endl;
    cout << RESET;
}

void handleMainMenu(Bank &B, const int &choice) {
    switch(choice) {
        case 0:
            running = false;
            break;
        case 1: {
            updateBankInfoMenu();
            string customerId;
            cout << "Nhap id khach hang can xoa: "; getline(cin, customerId);
            B.removeAccount(customerId);
            system("pause");
            break;
        }
        case 2: {
            cout << BLUE << "+[Thong bao]-> Bang gom " << B.getNumAccounts() << " tai khoan tiet kiem" << RESET << endl;
            B.display();
            system("pause");
            break;}
        case 3: {
            B.addAccount();
            system("pause");
            break;}
        case 4: {
            cout << GREEN << "+[Nhap loai tai khoan can loc (Term/NonTerm)]-> " << RESET;
            string accountType;
            cin >> accountType;
            
            SavingsAccount *filteredAccounts[MAX_CUSTOMER];
            int numFiltered = 0;
            B.search(accountType, filteredAccounts, numFiltered);
            
            if(numFiltered > 0) {
                cout << BLUE << "+[Thong bao]-> Co " << numFiltered << " tai khoan loai " << accountType << ":" << RESET << endl;
                outputData(filteredAccounts, numFiltered);
            } else {
                cout << BLUE << "+[Thong bao]-> Khong co tai khoan loai " << accountType << RESET << endl;
            }
            system("pause");
            break;}        case 5: {
            while(true) {
                string kw;
                int numResults = 0;
                SavingsAccount *searchResults[MAX_CUSTOMER];
                cin.ignore();
                cout << GREEN << "+[Nhap tu khoa tim kiem]-> " << RESET; getline(cin, kw);
                if(kw.empty()) {
                    cout << YELLOW << "+[Canh bao]-> Tu khoa khong duoc de trong" << RESET << endl;
                    break;
                }
                B.search(kw, searchResults, numResults);
                if(numResults) {
                    cout << BLUE << "+[Thong bao]-> Co " << numResults << " ket qua da duoc tim thay:" << RESET << endl;
                    outputData(searchResults, numResults);
                    
                    // beta - Thêm xử lý kết quả tìm kiếm
                    handleSearchResults(searchResults, numResults);
                } else {
                    cout << BLUE << "+[Thong bao]-> Khong co ket qua nao duoc tim thay" << RESET << endl;
                }                
                int ans;
                cout << GREEN << "+[Ban muon tim tiep khong? (1: co | 0: khong)]-> " << RESET; cin >> ans;
                if(!ans) {
                    break;
                }
            }
            system("pause");
            break;
        }
        case 6: {
            int choice;
            cout << endl;
            cout << CYAN;
            cout << "+----------------------------------------------+" << endl;
            cout << "| 1. Sap xep theo ten                          |" << endl;
            cout << "| 2. Sap xep theo so du                        |" << endl;
            cout << "+----------------------------------------------+" << endl;
            cout << RESET;
            cout << GREEN <<"+[Nhap lua chon]-> " << RESET;
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << BLUE << "+[Thong bao]-> Danh sach da duoc sap xep theo ten: " << RESET << endl;
                    B.sortByName();
                    break;
                case 2:
                    cout << BLUE << "+[Thong bao]-> Danh sach da duoc sap xep theo so du: " << RESET << endl;
                    B.sortByBalance();
                    break;
                default:
                    cout << YELLOW << "+[Canh bao]-> Lua chon khong hop le" << RESET << endl;
                    break;
            }
            B.saveToFile();
            system("pause");
            break;
        }

        default:
            cout << "\033[0;31m" << "+[Loi]-> Da co loi xay ra!" << RESET << endl;
    }
}

// beta
void handleSearchResults(SavingsAccount *searchResults[], int &numResults) {
    if (numResults <= 0) {
        cout << BLUE << "+[Thong bao]-> Khong co ket qua de xu ly" << RESET << endl;
        system("pause");
        return;
    }
    
    while (true) {
        handleSearch();
        int choice = chooseInMenu(5);
        
        if (choice == 0) break;
        
        switch (choice) {
            case 1: { // Sắp xếp kết quả
                handleSortResultsMenu();
                int sortChoice = chooseInMenu(4);
                
                if (sortChoice == 0) break;
                
                bool ascending = true;
                cout << GREEN << "+[Sap xep tang dan? (1: Tang, 0: Giam)]-> " << RESET;
                int sortOrder;
                cin >> sortOrder;
                ascending = (sortOrder == 1);
                
                switch (sortChoice) {
                    case 1: // Theo tên
                        customSort(searchResults, numResults, Bank::compareByName, ascending);
                        cout << BLUE << "+[Thong bao]-> Danh sach da duoc sap xep theo ten khach hang" << RESET << endl;
                        break;
                    case 2: // Theo số dư
                        customSort(searchResults, numResults, Bank::compareByBalance, ascending);
                        cout << BLUE << "+[Thong bao]-> Danh sach da duoc sap xep theo so du" << RESET << endl;
                        break;
                    case 3: // Theo ngày mở
                        customSort(searchResults, numResults, compareByOpenDate, ascending);
                        cout << BLUE << "+[Thong bao]-> Danh sach da duoc sap xep theo ngay mo tai khoan" << RESET << endl;
                        break;
                    case 4: // Theo loại tài khoản
                        customSort(searchResults, numResults, compareByAccountType, ascending);
                        cout << BLUE << "+[Thong bao]-> Danh sach da duoc sap xep theo loai tai khoan" << RESET << endl;
                        break;
                }
                outputData(searchResults, numResults);
                system("pause");
                break;
            }            case 2: { // Xuất ra file
                string filename;
                cout << GREEN << "+[Nhap ten file xuat (khong can duoi)]-> " << RESET;
                cin.ignore();
                getline(cin, filename);
                
                if (filename.empty()) {
                    filename = "search_results";
                }
                
                cout << CYAN;
                cout << "+----------- Menu: Dinh dang xuat file -----------+" << endl;
                cout << "| 1. Xuat file CSV                                |" << endl;
                cout << "| 2. Xuat file TXT                                |" << endl;
                cout << "+-----------------------------------------------+" << endl;
                cout << RESET;
                
                int formatChoice = chooseInMenu(2);
                
                if (formatChoice == 1) {
                    // Xuất file CSV
                    string filepath = "data/" + filename + ".csv";
                    ofstream file(filepath);
                    
                    if (file.is_open()) {
                        // Ghi tiêu đề
                        file << "STT,Loai,Khach hang,MKH,CMT/CCCD,Ngay mo,So du,Lai suat,Ky han\n";
                        
                        // Ghi dữ liệu
                        for (int i = 0; i < numResults; i++) {
                            file << i+1 << ","
                                 << searchResults[i]->getAccountType() << ","
                                 << searchResults[i]->getCustomerName() << ","
                                 << searchResults[i]->getCustomerId() << ","
                                 << searchResults[i]->getIdNumber() << ","
                                 << searchResults[i]->getOpenDate().toString() << ","
                                 << searchResults[i]->getDepositAmount() << ","
                                 << searchResults[i]->getInterestRate() << ","
                                 << ((searchResults[i]->getTerm() == 0) ? "N/A" : to_string(searchResults[i]->getTerm())) << "\n";
                        }
                        
                        file.close();
                        cout << BLUE << "+[Thong bao]-> Da xuat ket qua ra file: " << filepath << RESET << endl;
                    } else {
                        cout << RED << "+[Loi]-> Khong the mo file de ghi!" << RESET << endl;
                    }
                } else if (formatChoice == 2) {
                    // Xuất file TXT
                    exportToTextFile(searchResults, numResults, filename);
                }
                
                system("pause");
                break;
            }
            case 3: { // Lọc thêm                handleFilterMenu();
                int filterChoice = chooseInMenu(4);
                
                if (filterChoice == 0) break;
                
                SavingsAccount *filteredResults[MAX_CUSTOMER];
                int numFiltered = 0;
                
                switch (filterChoice) {
                    case 1: { // Lọc theo loại tài khoản
                        string accountType;
                        cout << GREEN << "+[Nhap loai tai khoan can loc (Term/NonTerm)]-> " << RESET;
                        cin >> accountType;
                        
                        for (int i = 0; i < numResults; i++) {
                            if (searchResults[i]->getAccountType() == accountType) {
                                filteredResults[numFiltered++] = searchResults[i];
                            }
                        }
                        break;
                    }
                    case 2: { // Lọc theo số dư > X
                        double minBalance;
                        cout << GREEN << "+[Nhap so du toi thieu]-> " << RESET;
                        cin >> minBalance;
                        
                        for (int i = 0; i < numResults; i++) {
                            if (searchResults[i]->getDepositAmount() > minBalance) {
                                filteredResults[numFiltered++] = searchResults[i];
                            }
                        }
                        break;
                    }
                    case 3: { // Lọc theo số dư < X
                        double maxBalance;
                        cout << GREEN << "+[Nhap so du toi da]-> " << RESET;
                        cin >> maxBalance;
                        
                        for (int i = 0; i < numResults; i++) {
                            if (searchResults[i]->getDepositAmount() < maxBalance) {
                                filteredResults[numFiltered++] = searchResults[i];
                            }
                        }
                        break;
                    }
                    case 4: { // Lọc theo ngày mở tài khoản
                        cout << CYAN << "Chon kieu loc theo ngay:" << RESET << endl;
                        cout << "1. Sau ngay" << endl;
                        cout << "2. Truoc ngay" << endl;
                        int dateFilterType = chooseInMenu(2);
                        
                        cout << GREEN << "+[Nhap ngay mo tai khoan can so sanh]-> " << RESET << endl;
                        Date compareDate;
                        compareDate.input();
                        
                        for (int i = 0; i < numResults; i++) {
                            Date accountDate = searchResults[i]->getOpenDate();
                            bool shouldInclude = false;
                            
                            if (dateFilterType == 1) { // Sau ngày
                                // Tài khoản mở sau ngày so sánh
                                if (accountDate.getYear() > compareDate.getYear() ||
                                   (accountDate.getYear() == compareDate.getYear() && 
                                    accountDate.getMonth() > compareDate.getMonth()) ||
                                   (accountDate.getYear() == compareDate.getYear() && 
                                    accountDate.getMonth() == compareDate.getMonth() && 
                                    accountDate.getDay() > compareDate.getDay())) {
                                    shouldInclude = true;
                                }
                            } else { // Trước ngày
                                // Tài khoản mở trước ngày so sánh
                                if (accountDate.getYear() < compareDate.getYear() ||
                                   (accountDate.getYear() == compareDate.getYear() && 
                                    accountDate.getMonth() < compareDate.getMonth()) ||
                                   (accountDate.getYear() == compareDate.getYear() && 
                                    accountDate.getMonth() == compareDate.getMonth() && 
                                    accountDate.getDay() < compareDate.getDay())) {
                                    shouldInclude = true;
                                }
                            }
                            
                            if (shouldInclude) {
                                filteredResults[numFiltered++] = searchResults[i];
                            }
                        }
                        break;
                    }
                }
                
                if (numFiltered > 0) {
                    cout << BLUE << "+[Thong bao]-> Co " << numFiltered << " ket qua sau khi loc:" << RESET << endl;
                    outputData(filteredResults, numFiltered);
                    
                    // Cập nhật kết quả tìm kiếm
                    cout << GREEN << "+[Ban co muon cap nhat ket qua tim kiem? (1: Co, 0: Khong)]-> " << RESET;
                    int updateChoice;
                    cin >> updateChoice;
                    
                    if (updateChoice == 1) {
                        for (int i = 0; i < numFiltered; i++) {
                            searchResults[i] = filteredResults[i];
                        }
                        numResults = numFiltered;
                        cout << BLUE << "+[Thong bao]-> Da cap nhat ket qua tim kiem!" << RESET << endl;
                    }
                } else {
                    cout << BLUE << "+[Thong bao]-> Khong co ket qua nao sau khi loc" << RESET << endl;
                }
                
                system("pause");
                break;
            }
            case 4: { // Cập nhật thông tin tài khoản
                int index;
                cout << GREEN << "+[Nhap STT tai khoan can cap nhat]-> " << RESET;
                cin >> index;
                index--; // Chuyển từ STT hiển thị sang index
                
                if (index >= 0 && index < numResults) {
                    SavingsAccount *account = searchResults[index];
                    
                    cout << BLUE << "+[Thong bao]-> Cap nhat thong tin tai khoan: " << account->getCustomerName() << RESET << endl;
                    
                    cout << endl;
                    cout << CYAN;                    cout << "+------ Menu: Cap nhat thong tin tai khoan ------+" << endl;
                    cout << "| 1. Cap nhat ten khach hang                     |" << endl;
                    cout << "| 2. Cap nhat so CMT/CCCD                        |" << endl;
                    cout << "| 3. Cap nhat so du                              |" << endl;
                    cout << "| 4. Cap nhat lai suat                           |" << endl;
                    if (account->getAccountType() == "Term") {
                        cout << "| 5. Cap nhat ky han                             |" << endl;
                    }
                    cout << "| 0. Quay lai                                    |" << endl;
                    cout << "+-----------------------------------------------+" << endl;
                    cout << RESET;
                    
                    int maxChoice = (account->getAccountType() == "Term") ? 5 : 4;
                    int updateChoice = chooseInMenu(maxChoice);
                    cin.ignore();
                    
                    switch (updateChoice) {
                        case 1: {
                            string name;
                            cout << GREEN << "+[Nhap ten moi]-> " << RESET;
                            getline(cin, name);
                            name = correctName(name);
                            account->setCustomerName(name);
                            cout << BLUE << "+[Thong bao]-> Da cap nhat ten thanh cong!" << RESET << endl;
                            break;
                        }
                        case 2: {
                            string idNumber;
                            cout << GREEN << "+[Nhap so CMT/CCCD moi]-> " << RESET;
                            getline(cin, idNumber);
                            account->setIdNumber(idNumber);
                            cout << BLUE << "+[Thong bao]-> Da cap nhat so CMT/CCCD thanh cong!" << RESET << endl;
                            break;
                        }
                        case 3: {
                            double amount;
                            cout << GREEN << "+[Nhap so du moi]-> " << RESET;
                            cin >> amount;
                            account->setDepositAmount(amount);
                            cout << BLUE << "+[Thong bao]-> Da cap nhat so du thanh cong!" << RESET << endl;
                            break;
                        }                        case 4: {
                            double rate;
                            cout << GREEN << "+[Nhap lai suat moi (%)]-> " << RESET;
                            cin >> rate;
                            account->setInterestRate(rate);
                            cout << BLUE << "+[Thong bao]-> Da cap nhat lai suat thanh cong!" << RESET << endl;
                            break;
                        }
                        case 5: {
                            if (account->getAccountType() == "Term") {
                                int term;
                                cout << GREEN << "+[Nhap ky han moi (thang)]-> " << RESET;
                                cin >> term;
                                account->setTerm(term);
                                cout << BLUE << "+[Thong bao]-> Da cap nhat ky han thanh cong!" << RESET << endl;
                            }
                            break;
                        }
                    }
                      // Hiển thị lại tài khoản sau khi cập nhật
                    if (updateChoice > 0) {
                        cout << BLUE << "+[Thong bao]-> Thong tin tai khoan sau khi cap nhat:" << RESET << endl;
                        SavingsAccount *temp[1] = {account};
                        outputData(temp, 1);
                        
                        // Lưu thay đổi vào file
                        if (bank != nullptr) {
                            bank->saveToFile();
                            cout << BLUE << "+[Thong bao]-> Da luu thay doi vao file!" << RESET << endl;
                        }
                    }
                } else {
                    cout << YELLOW << "+[Canh bao]-> STT khong hop le!" << RESET << endl;
                }
                system("pause");
                break;
            }
            case 5: { // Xóa tài khoản
                int index;
                cout << GREEN << "+[Nhap STT tai khoan can xoa]-> " << RESET;
                cin >> index;
                index--; // Chuyển từ STT hiển thị sang index
                
                if (index >= 0 && index < numResults) {
                    SavingsAccount *account = searchResults[index];
                    
                    cout << YELLOW << "+[Canh bao]-> Ban co chac chan muon xoa tai khoan: " 
                         << account->getCustomerName() << " (" << account->getCustomerId() << ")? (1: Co, 0: Khong)]-> " << RESET;
                    int confirm;
                    cin >> confirm;
                    
                    if (confirm == 1) {
                        string customerId = account->getCustomerId();
                        
                        // Lấy con trỏ đến đối tượng Bank từ main
                        extern Bank *bank; // Giả sử có biến global hoặc bạn cần thay đổi cách lấy bank
                        
                        if (bank != nullptr) {
                            bank->removeAccount(customerId);
                            
                            // Cập nhật lại mảng kết quả tìm kiếm
                            for (int i = index; i < numResults - 1; i++) {
                                searchResults[i] = searchResults[i + 1];
                            }
                            numResults--;
                            
                            cout << BLUE << "+[Thong bao]-> Xoa tai khoan thanh cong!" << RESET << endl;
                            cout << BLUE << "+[Thong bao]-> Danh sach sau khi xoa:" << RESET << endl;
                            outputData(searchResults, numResults);
                        } else {
                            cout << RED << "+[Loi]-> Khong the xoa tai khoan!" << RESET << endl;
                        }
                    }
                } else {
                    cout << YELLOW << "+[Canh bao]-> STT khong hop le!" << RESET << endl;
                }
                system("pause");
                break;
            }
        }
    }
}