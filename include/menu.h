/*
-- Nội dung tệp: Chứa các hàm hiển thị và xử lí lựa chọn từ menu
-- Số hàm: ...
*/

void showMenu() {
    cout << CYAN;
	cout << "+---------------------------------------------+ \n";
	cout << "|                    Menu                     | \n";
	cout << "+---------------------------------------------+ \n";
	cout << "| 1. Them/Cap nhat so tiet kiem               | \n";
	cout << "| 2. Xoa so tiet kiem                         | \n";
	cout << "| 3. Hien thi so tiet kiem                    | \n";
	cout << "| 4. Sap xep so tiet kiem                     | \n";
	cout << "| 5. Tim kiem/Loc so tiet kiem                | \n";
	cout << "| 6. Tinh tien lai tung so tiet kiem          | \n";
	cout << "| 7. Cap nhat thong tin ngan hang             | \n";
	cout << "| 8. Hien thi thong tin ngan hang             | \n";
	cout << "| 9. Bao cao thong ke ngan hang               | \n";
	cout << "| 0. Thoat chuong trinh                       | \n";
	cout << "+---------------------------------------------+ \n";
    cout << RESET;
}

void showMenu1() {
    cout << "\n";
    cout << CYAN;
	cout << "+---------------------------------------------+ \n";
	cout << "|       Menu: Them/Cap nhat so tiet kiem      | \n";
	cout << "+---------------------------------------------+ \n";
	cout << "| 1. Them so tiet kiem                        | \n";
	cout << "| 2. Cap nhat so tiet kiem                    | \n";
	cout << "| 0. Thoat                                    | \n";
	cout << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu1_1() {
    cout << "\n";
    cout << CYAN;
	cout << "+---------------------------------------------+ \n";
	cout << "|   Menu: Them/Cap nhat -> Them so tiet kiem  | \n";
	cout << "+---------------------------------------------+ \n";
	cout << "| 1. So tiet kiem co ky han                   | \n";
	cout << "| 2. So tiet kiem khong ky han                | \n";
	cout << "| 0. Thoat                                    | \n";
	cout << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu3() {
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

void showMenu4() {
    cout << "\n";
    cout << CYAN;
	cout << "+---------------------------------------------+ \n";
	cout << "|          Menu: Sap xep so tiet kiem         | \n";
	cout << "+---------------------------------------------+ \n";
	cout << "| 1. Sap xep theo ma khach hang               | \n";
	cout << "| 2. Sap xep theo ho va ten                   | \n";
	cout << "| 4. Sap xep theo ngay mo so                  | \n";
	cout << "| 5. Sap xep theo lai suat                    | \n";
	cout << "| 0. Thoat                                    | \n";
	cout << "+---------------------------------------------+ \n";
	cout << RESET;
}

void showMenu5() {
    cout << "\n";
    cout << CYAN;
    cout << "+---------------------------------------------+ \n";
    cout << "|       Menu: Tim kiem/Loc so tiet kiem       | \n";
    cout << "+---------------------------------------------+ \n";
    cout << "| 1. Tim kiem so tiet kiem                    | \n";
    cout << "| 2. Loc so tiet kiem                         | \n";
    cout << "| 0. Thoat                                    | \n";
    cout << "+---------------------------------------------+ \n";
    cout << RESET;
}

void showMenu5_1() {
    cout << "\n";
    cout << CYAN;
    cout << "+---------------------------------------------+ \n";
    cout << "|        Menu: Tim kiem/Loc -> Tim kiem       | \n";
    cout << "+---------------------------------------------+ \n";
    cout << "| 1. Tim theo ten                             | \n";
    cout << "| 2. Tìm theo mã khách hàng                   | \n";
    cout << "| 0. Thoat                                    | \n";
    cout << "+---------------------------------------------+ \n";
    cout << RESET;
}

void showMenu5_1_1() {
    cout << "\n";
    cout << CYAN;
    cout << "+---------------------------------------------+ \n";
    cout << "|  Menu: Tim kiem/Loc -> Tim kiem -> Thao tac | \n";
    cout << "+---------------------------------------------+ \n";
    cout << "| 1. Cap nhat so tiet kiem                    | \n";
    cout << "| 2. Xoa so tiet kiem                         | \n";
    cout << "| 0. Thoat                                    | \n";
    cout << "+---------------------------------------------+ \n";
    cout << RESET;
}

void showMenu5_2() {
    cout << "\n";
    cout << CYAN;
    cout << "+---------------------------------------------+ \n";
    cout << "|  Menu: Tim kiem/Loc -> Loc so tiet kiem     | \n";
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

void handleChoice1_1(Bank &B) {
    while(true) {
        showMenu1_1();
        int choice;
        choice = getChoice(0, 2);
        if(choice == 0) {
            break;
        }
        B.addAccount(choice);
    }
}

void handleChoice1_2(Bank &B) {}

void handleChoice1(Bank &B) {
    while(true) {
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

void handleChoice5_1_1(Bank &B) {}

void handleChoice5_1(Bank &B) {}

void handleChoice5_2(Bank &B) {}

void handleChoice5(Bank &B) {}

void handleChoice6(Bank &B) {}

void handleChoice7(Bank &B) {}

void handleChoice8(Bank &B) {}

void handleChoice9(Bank &B) {}

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
        default:
            cout << "\033[0;31m" << "+[Loi]-> Da co loi xay ra!" << RESET << endl;
    }
}