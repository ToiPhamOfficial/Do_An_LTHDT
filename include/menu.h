/* 
-- Thành viên code: Pham Van Toi
-- Nội dung tệp: Chứa các hàm hiển thị và xử lí lựa chọn từ menu
-- Số hàm: ...
*/

void mainMenu() {
    cout << endl;
    cout << "+-------------------- Menu --------------------+" << endl;
    cout << '|' << "1. " << lang_data[1] << endl;
    cout << '|' << "2. " << lang_data[2] << endl;
    cout << '|' << "3. " << lang_data[3] << endl;
    cout << '|' << "4. " << lang_data[4] << endl;
    cout << '|' << "5. " << lang_data[5] << endl;
    cout << '|' << "6. " << lang_data[6] << endl;
    cout << "+----------------------------------------------+" << endl;
}

void systemSettingsMenu() {
    cout << endl;
    cout << "+-------------------- Menu: Cai dat he thong --------------------+" << endl;
    cout << '|' << "1. Ngon ngu" << setw(54) << '|' << endl;
    cout << "+----------------------------------------------------------------+" << endl;
}

int chooseInMenu(const int &max_choice) {
    int choice;
    while(true) {
        cout << "|\n+[" << lang_data[8] << "]-> "; cin >> choice;
        if(choice >= 1 && choice <= max_choice) {
            return choice;
        } else {
            cout << "!!!" << lang_data[9] << endl;
        }
    }
}


void handleMainMenu(const int &choice) {
    switch(choice) {
        case 1:
            cout << "Choice 1" << endl;
            break;
        case 2:
            cout << "Choice 2" << endl;
            break;
        case 5: {
            systemSettingsMenu();
            int choice = chooseInMenu(1);
            cout << "1. Tiếng Việt" << endl;
            cout << "2. Tieng Viet khong dau" << endl;
            cout << "3. English" << endl;

            choice = chooseInMenu(3);
            if(choice == 1) {
                settings[1] = "vi";
            } else if(choice == 2) {
                settings[1] = "vi2";
            } else {
                settings[1] = "en";
            }
            writeFile("settings.st", settings, 5);
            reloadSystem();
            break;
        }
        case 6:
            running = false;
            break;
        default:
            cout << "Error" << endl;
    }
}

void testOutput() {
    ofstream fout("data/out/test_ouput.txt");
    fout << left;
    /*fout << tc_arr[22] <<  tc_arr[5] << tc_arr[27] << tc_arr[20] << tc_arr[27] 
         << tc_arr[10] << tc_arr[27] << tc_arr[15] << tc_arr[23] << endl;
    fout << tc_arr[21] << setw(5) << "STT" << tc_arr[21] << setw(24) << "HỌ VÀ TÊN" 
         << tc_arr[21] << setw(12) << "LỚP" << tc_arr[21] << setw(16) << "NGÀY SINH" << tc_arr[21] << endl;
    fout << tc_arr[29] <<  tc_arr[5] << tc_arr[26] << tc_arr[20] << tc_arr[26] 
         << tc_arr[10] << tc_arr[26] << tc_arr[15] << tc_arr[30] << endl;
    fout << tc_arr[21] << setw(5) << "1" << tc_arr[21] << setw(25) << "Phạm Văn Tới" 
         << tc_arr[21] << setw(10) << "65K1" << tc_arr[21] << setw(15) << "23/03/2006" << tc_arr[21] << endl;
    fout << tc_arr[29] <<  tc_arr[5] << tc_arr[26] << tc_arr[20] << tc_arr[26] << tc_arr[10] 
         << tc_arr[26] << tc_arr[15] << tc_arr[30] << endl;
    fout << tc_arr[21] << setw(5) << "2" << tc_arr[21] << setw(24) << "Phạm Tiến Sang" 
         << tc_arr[21] << setw(10) << "65K4" << tc_arr[21] << setw(15) << "22/06/2006" << tc_arr[21] << endl;
    fout << tc_arr[24] <<  tc_arr[5] << tc_arr[28] << tc_arr[20] << tc_arr[28] 
         << tc_arr[10] << tc_arr[28] << tc_arr[15] << tc_arr[25] << endl;*/
}

void gtestOutput() {
    cout << "───────────────────────────────────────────────────────" << endl;
}