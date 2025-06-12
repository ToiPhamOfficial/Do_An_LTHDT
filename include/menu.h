/*
-- Nội dung tệp: Chứa các hàm hiển thị và xử lí lựa chọn từ menu
-- Số hàm: ...
*/

void showBanner() {
    cout << CYAN;
    cout << setw(69) << "/-------------------------------\\" << endl
            << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
            << " HE THONG QUAN LI SO TIET KIEM "
            << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << setw(69) << "\\-------------------------------/" << endl;
    cout << RESET;
}

void showMenu() {
    string spaces(29, ' '); 
    cout << CYAN;
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "|                    Menu                     | \n";
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "| 1. Them/Cap nhat so tiet kiem               | \n";
	cout << spaces << "| 2. Xoa so tiet kiem                         | \n";
	cout << spaces << "| 3. Hien thi so tiet kiem                    | \n";
	cout << spaces << "| 4. Sap xep so tiet kiem                     | \n";
	cout << spaces << "| 5. Tim kiem/Loc so tiet kiem                | \n";
	cout << spaces << "| 6. Tinh tien lai tung so tiet kiem          | \n";
	cout << spaces << "| 7. Cap nhat thong tin ngan hang             | \n";
	cout << spaces << "| 8. Hien thi thong tin ngan hang             | \n";
	cout << spaces << "| 9. Bao cao thong ke ngan hang               | \n";
	cout << spaces << "| 0. Thoat chuong trinh                       | \n";
	cout << spaces << "+---------------------------------------------+ \n";
    cout << RESET;
}

void showMenu1() {
    string spaces(29, ' ');
    cout << "\n";
    cout << CYAN;
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "|       Menu: Them/Cap nhat so tiet kiem      | \n";
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "| 1. Them so tiet kiem                        | \n";
	cout << spaces << "| 2. Cap nhat so tiet kiem                    | \n";
	cout << spaces << "| 0. Thoat                                    | \n";
	cout << spaces << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu1_1() {
    string spaces(29, ' ');
    cout << "\n";
    cout << CYAN;
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "|   Menu: Them/Cap nhat -> Them so tiet kiem  | \n";
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "| 1. So tiet kiem co ky han                   | \n";
	cout << spaces << "| 2. So tiet kiem khong ky han                | \n";
	cout << spaces << "| 0. Thoat                                    | \n";
	cout << spaces << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu3() {
    string spaces(29, ' ');
    cout << "\n";
    cout << CYAN;
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "|         Menu: Hien thi so tiet kiem         | \n";
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "| 1. Hien thi tat ca so tiet kiem             | \n";
	cout << spaces << "| 2. Hien thi cac so co ky han                | \n";
	cout << spaces << "| 3. Hien thi cac so khong ky han             | \n";
	cout << spaces << "| 0. Thoat                                    | \n";
	cout << spaces << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu4() {
    string spaces(29, ' ');
    cout << "\n";
    cout << CYAN;
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "|          Menu: Sap xep so tiet kiem         | \n";
	cout << spaces << "+---------------------------------------------+ \n";
	cout << spaces << "| 1. Sap xep theo ten khach hang              | \n";
	cout << spaces << "| 2. Sap xep theo ngay mo so                  | \n";
	cout << spaces << "| 3. Sap xep theo so du                       | \n";
	cout << spaces << "| 4. Sap xep theo lai suat                    | \n";
    cout << spaces << "| 5. Sap xep theo ky han                      | \n";
	cout << spaces << "| 0. Thoat                                    | \n";
	cout << spaces << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu5() {
    string spaces(29, ' ');
    cout << "\n";
    cout << CYAN;
    cout << spaces << "+---------------------------------------------+ \n";
    cout << spaces << "|       Menu: Tim kiem/Loc so tiet kiem       | \n";
    cout << spaces << "+---------------------------------------------+ \n";
    cout << spaces << "| 1. Tim kiem so tiet kiem                    | \n";
    cout << spaces << "| 2. Loc so tiet kiem                         | \n";
    cout << spaces << "| 0. Thoat                                    | \n";
    cout << spaces << "+---------------------------------------------+ \n";
    cout << RESET;
}

void showMenu5_1() {
    string spaces(29, ' ');
    cout << "\n";
    cout << CYAN;
    cout << spaces << "+---------------------------------------------+ \n";
    cout << spaces << "|        Menu: Tim kiem/Loc -> Tim kiem       | \n";
    cout << spaces << "+---------------------------------------------+ \n";
    cout << spaces << "| 1. Tim theo ma khach hang                   | \n";
    cout << spaces << "| 2. Tim theo ten                             | \n";
    cout << spaces << "| 3. Tim theo so CCCD                         | \n";
    cout << spaces << "| 4. Tim theo ky han                          | \n";
    cout << spaces << "| 0. Thoat                                    | \n";
    cout << spaces << "+---------------------------------------------+ \n";
    cout << RESET;
}

void showMenu5_2() {
    string spaces(29, ' ');
    cout << "\n";
    cout << CYAN;
    cout << spaces << "+---------------------------------------------+ \n";
    cout << spaces << "|  Menu: Tim kiem/Loc -> Loc so tiet kiem     | \n";
    cout << spaces << "+---------------------------------------------+ \n";
    cout << spaces << "| 1. Loc theo ngay mo so tu ngay X den ngay Y | \n";
    cout << spaces << "| 2. Loc theo so du > X va < Y                | \n";
    cout << spaces << "| 3. Loc theo lai suat > X% va < Y%           | \n";
    cout << spaces << "| 4. Loc theo ky han > X thang va < Y thang   | \n";
    cout << spaces << "| 0. Thoat                                    | \n";
    cout << spaces << "+---------------------------------------------+ \n";
    cout << RESET;
}

int getChoice(const int &minChoice, const int &maxChoice, const string &optionInfo) {
    int choice;
    while(true) {
        cout << GREEN << "+[Nhap lua chon";
        if(!optionInfo.empty()) {
            cout << " (" << optionInfo << ")";
        }
        cout << "]-> " << RESET;
        cin >> choice;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << YELLOW << "+[Canh bao]-> Vui long nhap so nguyen hop le!" << RESET << endl;
            continue;
        }
        if(choice >= minChoice && choice <= maxChoice) {
            return choice;
        } else {
            cout << YELLOW << "+[Canh bao]-> Lua chon khong hop le, vui long chon lai!" << RESET << endl;
        }
    }
}

void handleChoice1_1(Bank &B) {
    while(true) {
        system("cls");
        showBanner();
        showMenu1_1();
        int choice;
        choice = getChoice(0, 2);
        if(choice == 0) {
            break;
        }
        B.addAccount(choice);
    }
}

void handleChoice1_2(Bank &B) {
    if(B.getNumAccounts() == 0) {
        cout << YELLOW << "+[Canh bao]-> Chua co so tiet kiem nao, vui long them so tiet kiem!" << RESET << endl;
        return;
    }
    cin.ignore();
    while(true) {
        string customerId;
        cout << GREEN << "+[Nhap ma khach hang can cap nhat so tiet kiem (0: thoat)]-> " << RESET;
        getline(cin, customerId);
        customerId = trim(customerId);
        if(customerId == "0") {
            break;
        }
        if(!B.accountExists(customerId)) {
            cout << GREEN << "+[Canh bao]-> Ma khach hang khong ton tai. Vui long thu lai!" << RESET << endl;
            continue;
        }
        B.updateAccountInfo(customerId);
    }
}

void handleChoice1(Bank &B) {
    while(true) {
        system("cls");
        showBanner();
        showMenu1();    
        int choice = getChoice(0, 2);
        switch(choice) {
            case 0:
                system("pause");
                return;
            case 1: {
                handleChoice1_1(B);
                system("pause");
                break;
            }
            case 2: {
                handleChoice1_2(B);
                system("pause");
                break;
            }
        }
    }
}

void handleChoice2(Bank &B) {
    if(B.getNumAccounts() == 0) {
        cout << YELLOW << "+[Canh bao]-> Chua co so tiet kiem nao, vui long them so tiet kiem!" << RESET << endl;
        system("pause");
        return;
    }
    string customerId;
    int ans;
    while (true) {
        cout << GREEN << "+[Nhap ma khach hang can xoa (0: thoat)]-> " << RESET;
        cin >> customerId;
        if(customerId == "0") {
            break;
        }
        if(!B.accountExists(customerId)) {
            cout << YELLOW << "+[Canh bao]-> Ma khach hang khong ton tai. Vui long thu lai!" << RESET << endl;
            continue;
        }
        int ans;
        cout << GREEN << "+[Xac nhan xoa so tiet kiem " << RED << customerId << GREEN << " (1: co | 0: khong)]-> " << RESET;
        cin >> ans;
        if(ans) {
            if(B.removeAccount(customerId)) {
                cout << BLUE << "+[Thong bao]-> Da xoa so tiet kiem " << customerId << " thanh cong!" << RESET << endl;
            } else {
                cout << YELLOW << "+[Canh bao]-> Khong the xoa so tiet kiem " << customerId << ", vui long thu lai!" << RESET << endl;
            }
        }
        cout << GREEN << "+[Ban muon xoa so tiet kiem nao nua khong? (1: co | 0: khong)]-> " << RESET;
        cin >> ans;
        if(!ans) {
            break;
        }
    }
}

// Các hàm xử lí chức năng cho từng lựa chọn
void handleChoice3(Bank &B) {
    if(B.getNumAccounts() == 0) {
        cout << YELLOW << "+[Canh bao]-> Chua co so tiet kiem nao, vui long them so tiet kiem!" << RESET << endl;
        system("pause");
        return;
    }
    while(true) {
        system("cls");
        showBanner();
        showMenu3();
        int choice;
        choice = getChoice(0, 3);
        if(choice == 0) {
            system("pause");
            break;
        }
        B.showAccounts(choice);
    }
}

void handleChoice4(Bank &B) {
    if(B.getNumAccounts() == 0) {
        cout << YELLOW << "+[Canh bao]-> Chua co so tiet kiem nao, vui long them so tiet kiem!" << RESET << endl;
        system("pause");
        return;
    }
    while(true) {
        system("cls");
        showBanner();
        showMenu4();
        int choice, accending;
        choice = getChoice(0, 5);
        if(choice == 0) {
            system("pause");
            break;
        }
        accending = getChoice(0, 1, "0: giam dan | 1: tang dan");
        switch(choice) {
            case 1:
                B.sort(1, accending);
                break;
            case 2:
                B.sort(2, accending);
                break;
            case 3:
                B.sort(3, accending);
                break;
            case 4:
                B.sort(4, accending);
                break;
            case 5:
                B.sort(5, accending);
                break;
        }
        cout << BLUE << "+[Thong bao]-> Da sap xep cac so tiet kiem (Xem trong tep 'data/output.data')!" << RESET << endl;
        system("pause");
    }
}

void handleChoice5_1(Bank &B) {
    while(true) {
        system("cls");
        showBanner();
        showMenu5_1();
        int choice = getChoice(0, 4);
        if(choice == 0) {
            system("pause");
            return;
        }
        string keyWord;
        switch(choice) {
            case 1: // Tìm theo mã khách hàng
                cout << GREEN << "+[Nhap ma khach hang can tim]-> " << RESET;
                cin >> keyWord;
                B.search(1, keyWord);
                break;
            case 2: // Tìm theo tên
                cout << GREEN << "+[Nhap ten khach hang can tim]-> " << RESET;
                cin.ignore();
                getline(cin, keyWord);
                B.search(2, keyWord);
                break;
            case 3: // Tìm theo số CCCD
                cout << GREEN << "+[Nhap so CCCD can tim]-> " << RESET;
                cin >> keyWord;
                B.search(3, keyWord);
                break;
            case 4: // Tìm theo kỳ hạn
                cout << GREEN << "+[Nhap ky han can tim]-> " << RESET;
                cin >> keyWord;
                B.search(4, keyWord);
                break;
        }
        system("pause");
    }
}

void handleChoice5_2(Bank &B) {
    while(true) {
        system("cls");
        showBanner();
        showMenu5_2();
        int choice = getChoice(0, 4);
        if(choice == 0) {
            system("pause");
            break;
        }
        Date startDate, endDate;
        double minAmount, maxAmount, minRate, maxRate;
        switch(choice) {
            case 1: {// Lọc theo ngày mở sổ
                cout << GREEN << "+[Nhap ngay bat dau]:" << RESET << endl;
                startDate.input();
                cout << GREEN << "+[Nhap ngay ket thuc]:" << RESET << endl;
                endDate.input();
                B.filterByOpenDate(startDate, endDate);
                break;
            }
            case 2: { // Lọc theo số dư
                cout << GREEN << "+[Nhap so du toi thieu]-> " << RESET;
                cin >> minAmount;
                cout << GREEN << "+[Nhap so du toi da]-> " << RESET;
                cin >> maxAmount;
                B.filterByAmount(minAmount, maxAmount);
                break;
            }
            case 3: { // Lọc theo lãi suất
                cout << GREEN << "+[Nhap lai suat toi thieu]-> " << RESET;
                cin >> minRate;
                cout << GREEN << "+[Nhap lai suat toi da]-> " << RESET;
                cin >> maxRate;
                B.filterByInterestRate(minRate, maxRate);
                break;
            }
            case 4: { // Lọc theo kỳ hạn
                int termMin, termMax;
                cout << GREEN << "+[Nhap ky han toi thieu (thang)]-> " << RESET;
                cin >> termMin;
                cout << GREEN << "+[Nhap ky han toi da (thang)]-> " << RESET;
                cin >> termMax;
                B.filterByTerm(termMin, termMax);
                break;
            }
        }
    }
}

void handleChoice5(Bank &B) {
    if(B.getNumAccounts() == 0) {
        cout << YELLOW << "+[Canh bao]-> Chua co so tiet kiem nao, vui long them so tiet kiem!" << RESET << endl;
        system("pause");
        return;
    }
    while(true) {
        system("cls");
        showBanner();
        showMenu5();
        int choice = getChoice(0, 2);
        switch(choice) {
            case 0:
                system("pause");
                return;
            case 1:
                handleChoice5_1(B);
                break;
            case 2:
                handleChoice5_2(B);
                break;
        }
    }
}

void handleChoice6(Bank &B) {
    if(B.getNumAccounts() == 0) {
        cout << YELLOW << "+[Canh bao]-> Chua co so tiet kiem nao, vui long them so tiet kiem!" << RESET << endl;
        system("pause");
        return;
    }
    B.calculateInterestPerAccount();
    cout << BLUE << "+[Thong bao]-> Da tinh tien lai tung so tiet kiem (Xem trong tep 'data/output.data')!" << RESET << endl;
    system("pause");
}

void handleChoice7(Bank &B) {
    B.update();
    cout << BLUE << "+[Thong bao]-> Cap nhat thong tin ngan hang thanh cong!" << RESET << endl;
    system("pause");
}

void handleChoice8(Bank &B) {
    if(B.getName().empty()) {
        cout << YELLOW << "+[Canh bao]-> Chua co thong tin ngan hang, vui long cap nhat thong tin!" << RESET << endl;
        system("pause");
        return;
    }
    exportBankInfo(B);
    system("pause");
}

void handleChoice9(Bank &B) {
    if(B.getName().empty()) {
        cout << YELLOW << "+[Canh bao]-> Chua co thong tin ngan hang, vui long cap nhat thong tin!" << RESET << endl;
        system("pause");
        return;
    }
    exportBankReport(B); 
    system("pause");
}

void handleMainMenu(Bank &B) {
    showMenu();
    int choice = getChoice(0, 11);
    switch(choice) {
        case 0:
            running = false;
            break;
        case 1: {
            handleChoice1(B);
            break;
        }
        case 2: {
            handleChoice2(B);
            break;
        }
        case 3: {
            handleChoice3(B);
            break;
        }
        case 4: {
            handleChoice4(B);
            break;
        }   
        case 5: {
            handleChoice5(B);
            break;
        }
        case 6: {
            handleChoice6(B);
            break;
        }
        case 7: {
            handleChoice7(B);
            break;
        }
        case 8: {
            handleChoice8(B);
            break;
        }
        case 9: {
            handleChoice9(B);
            break;
        }
    }
}