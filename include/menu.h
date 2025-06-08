/*
-- Nội dung tệp: Chứa các hàm hiển thị và xử lí lựa chọn từ menu
-- Số hàm: ...
*/

void showMenu() {
    cout << CYAN;
	cout << "+---------------------------------------------+ \n";
	cout << "|                    Menu                     | \n";
	cout << "+---------------------------------------------+ \n";
	cout << "|  1. Them so tiet kiem moi                   | \n";
	cout << "|  2. Cap nhat thong tin so tiet kiem         | \n";
	cout << "|  3. Xoa so tiet kiem                        | \n";
	cout << "|  4. Hien thi so tiet kiem                   | \n";
	cout << "|  5. Sap xep so tiet kiem                    | \n";
	cout << "|  6. Tim kiem so tiet kiem                   | \n";
	cout << "|  7. Loc so tiet kiem                        | \n";
	cout << "|  8. Tinh tien lai moi so tiet kiem          | \n";
	cout << "|  9. Tinh tong tien lai phai tra             | \n";
	cout << "| 10. Cap nhat thong tin ngan hang            | \n";
	cout << "| 11. Hien thi thong tin ngan hang            | \n";
	cout << "|  0. Thoat chuong trinh                      | \n";
	cout << "+---------------------------------------------+ \n";
    cout << RESET;
}

void showMenu1() {
    cout << "\n";
    cout << CYAN;
	cout << "+---------------------------------------------+ \n";
	cout << "|         Menu: Them so tiet kiem moi         | \n";
	cout << "+---------------------------------------------+ \n";
	cout << "| 1. So tiet kiem co ky han                   | \n";
	cout << "| 2. So tiet kiem khong ky han                | \n";
	cout << "| 0. Thoat                                    | \n";
	cout << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu4() {
    cout << "\n";
    cout << CYAN;
	cout << "+---------------------------------------------+ \n";
	cout << "|         Menu: Hien thi so tiet kiem         | \n";
	cout << "+---------------------------------------------+ \n";
	cout << "| 1. Hien thi tat ca so tiet kiem             | \n";
	cout << "| 2. Hien thi cac so co ky han                | \n";
	cout << "| 3. Hien thi cac so khong ky han             | \n";
	cout << "| 0. Thoat                                    | \n";
	cout << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu5() {
    cout << "\n";
    cout << CYAN;
	cout << "+---------------------------------------------+ \n";
	cout << "|          Menu: Sap xep so tiet kiem         | \n";
	cout << "+---------------------------------------------+ \n";
	cout << "| 1. Sap xep Ma Khach Hang                    | \n";
	cout << "| 2. Sap xep Ho Va Ten                        | \n";
	cout << "| 3. Sap xep CCCD                             | \n";
	cout << "| 4. Sap xep Ngay Lap So                      | \n";
	cout << "| 5. Sap xep Lai So                           | \n";
	cout << "| 0. Thoat                                    | \n";
	cout << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu6_1() {
    cout << "\n";
    cout << CYAN;
    cout << "+---------------------------------------------+ \n";
    cout << "|         Menu: Tim kiem so tiet kiem         | \n";
    cout << "+---------------------------------------------+ \n";
    cout << "| 1. Cap nhat so tiet kiem                    | \n";
    cout << "| 2. Xoa so tiet kiem                         | \n";
    cout << "| 0. Thoat                                    | \n";
    cout << "+---------------------------------------------+ \n";
    cout << RESET;
}

void showMenu6_2() {
    cout << "\n";
    cout << CYAN;
    cout << "+---------------------------------------------+ \n";
    cout << "|   Menu: Tim kiem so tiet kiem -> Thao tac   | \n";
    cout << "+---------------------------------------------+ \n";
    cout << "| 1. Cap nhat so tiet kiem                    | \n";
    cout << "| 2. Xoa so tiet kiem                         | \n";
    cout << "| 0. Thoat                                    | \n";
    cout << "+---------------------------------------------+ \n";
    cout << RESET;
}

// SỬA LẠI PHẦN NÀY CHO LỰA CHỌN 6 (tham khảo theo code của chatgpt bên dưới)
void showMenu7() {
    cout << "\n";
    cout << CYAN;
    cout << "+---------------------------------------------+ \n";
    cout << "|            Menu: Loc so tiet kiem           | \n";
    cout << "+---------------------------------------------+ \n";
    cout << "| 1. Loc cac so co so du > X                  | \n";
    cout << "| 2. Loc cac so co so du < X                  | \n";
    cout << "| 0. Thoat                                    | \n";
    cout << "+---------------------------------------------+ \n";
    cout << RESET;
}

int getChoice(const int &minChoice, const int &maxChoice, const string &optionInfo) {
    int choice;
    while(true) {
        cout << GREEN << "+[Nhap lua chon]";
        if(!optionInfo.empty()) {
            cout << " (" << optionInfo << ")";
        }
        cout << "-> " << RESET;
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

void handleChoice1(Bank &B) {
    while(true) {
        showMenu1();
        int choice = getChoice(0, 2);
        switch(choice) {
            case 0:
                system("pause");
                return;
            case 1: {
                B.addAccount(choice);
                break;
            }
            case 2: {
                B.addAccount(choice);
                break;
            }
        }
    }
}

bool handleRemoveAccountChoice(Bank &B, const string &customerId) {
    if (!B.accountExists(customerId)) {
        cout << YELLOW << "+[Canh bao]-> Ma khach hang khong ton tai. Vui long thu lai!" << RESET << endl;
        return false;
    } else {
        int ans;
        cout << GREEN << "+[Xac nhan xoa (1: co | 0: khong)]-> " << RESET;
        cin >> ans;
        if(ans == 1) {
            B.removeAccount(customerId);
            cout << BLUE << "+[Thong bao]-> Xoa tai khoan thanh cong" << RESET << endl;
        }
    }
    return true;
}

void handleChoice2(Bank &B) {
    string customerId;
    int ans;
    while (true) {
        cout << GREEN << "+[Nhap ma khach hang can xoa (0: thoat)]-> " << RESET;
        cin >> customerId;
        if(customerId == "0") {
            break;
        }
        if(!handleRemoveAccountChoice(B, customerId)) {
            continue;
        }
        cout << GREEN << "+[Ban muon xoa tai khoan nao nua khong? (1: co | 0: khong)]-> " << RESET;
        cin >> ans;
        if(!ans) {
            break;
        }
    }
}

// Các hàm xử lí chức năng cho từng lựa chọn
void handleChoice3(Bank &B) {}

void handleChoice4(Bank &B) {}

void handleChoice5_2(Bank &B, SavingsAccount *searchResults[], int &numResults) {}

void handleChoice5_1(Bank &B) {}

void handleChoice6(Bank &B) {}

void handleChoice7(Bank &B) {}

void handleChoice8(Bank &B) {}

void handleChoice9(Bank &B) {}

void handleChoice10(Bank &B) {}

void handleChoice11(Bank &B) {}

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
            // Chưa làm
        }
        case 4: {
            // Chưa làm
        }   
        case 5: {
            // Chưa làm
        }
        case 6: {
            // Chưa làm
        }
        case 7: {
            // Chưa làm
        }
        case 8: {
            // Chưa làm
        }
        case 9: {
            // Chưa làm
        }
        case 10: {
            // Chưa làm
        }
        case 11: {
            // Chưa làm
        }
        default:
            cout << "\033[0;31m" << "+[Loi]-> Da co loi xay ra!" << RESET << endl;
    }
}