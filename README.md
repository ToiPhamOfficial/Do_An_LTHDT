# 🏦 HỆ THỐNG QUẢN LÝ SỔ TIẾT KIỆM NGÂN HÀNG

## 📋 Mô tả đồ án
Đồ án **Lập trình hướng đối tượng** phát triển hệ thống quản lý sổ tiết kiệm cho ngân hàng, hỗ trợ quản lý hai loại sổ:
- **Sổ tiết kiệm có kỳ hạn** (Term Account)
- **Sổ tiết kiệm không kỳ hạn** (Non-term Account)

## 🎯 Mục tiêu đồ án
- Áp dụng các khái niệm lập trình hướng đối tượng (OOP)
- Thực hiện kế thừa (Inheritance) và đa hình (Polymorphism)
- Xây dựng hệ thống quản lý dữ liệu hoàn chỉnh
- Tính toán lãi suất theo quy định ngân hàng

## 🏗️ Cấu trúc dự án
```
Do_An_LTHDT/
├── main.cpp              # File chính chạy chương trình
├── declare.h             # Khai báo các lớp và hàm
├── include/              # Thư mục chứa các file header
│   ├── class.h           # Định nghĩa các lớp
│   ├── functions.h       # Các hàm tiện ích
│   ├── iofile.h          # Xử lý file input/output
│   └── menu.h            # Giao diện menu và xử lý
├── data/                 # Thư mục dữ liệu
│   ├── input.data        # File lưu dữ liệu đầu vào
│   └── output.data       # File xuất kết quả
├── main.exe              # File thực thi
├── LICENSE               # Giấy phép
└── README.md             # Tài liệu hướng dẫn
```

## 🔧 Yêu cầu hệ thống
- **Ngôn ngữ**: C++ (Chuẩn C++11 trở lên)
- **Compiler**: GCC/MinGW (Nếu dùng IDE chưa có sẵn compiler)
- **IDE**: VSCode hoặc Embarcadero Dev-C++
- **Hệ điều hành**: Windows/Linux/macOS
- **RAM**: Tối thiểu 4GB
- **Dung lượng**: ~50MB

## 📊 Thông tin quản lý

### Thông tin ngân hàng
- Tên ngân hàng
- Địa chỉ
- Mã số thuế (10 chữ số)
- Số điện thoại (10 chữ số)
- Email

### Thông tin sổ tiết kiệm
**Thông tin chung:**
- Họ tên khách hàng (5-21 ký tự)
- Mã khách hàng (T+5 số hoặc N+5 số)
- Số CCCD (12 chữ số)
- Số tiền gửi (100,000 - 999,999,999,999 VND)
- Ngày lập sổ
- Lãi suất tháng (0-1%)

**Sổ có kỳ hạn:**
- Kỳ hạn (số tháng)

## 💰 Công thức tính lãi

### Sổ không kỳ hạn
```
Tiền lãi = Tiền gửi × Lãi suất × Số tháng
```

### Sổ có kỳ hạn
```
Nếu số_tháng_gửi ≥ kỳ_hạn:
    Tiền lãi = Tiền gửi × Lãi suất × Số tháng
Ngược lại:
    Tiền lãi = 0 (rút trước hạn)
```

## 🚀 Hướng dẫn sử dụng

### 1. Biên dịch chương trình
```bash
# Sử dụng g++
g++ -o main main.cpp

# Hoặc với MinGW trên Windows
g++ -std=c++11 -o main.exe main.cpp
```

### 2. Chạy chương trình
```bash
# Linux/macOS
./main

# Windows
main.exe
```

### 3. Sử dụng menu
```
+---------------------------------------------+
|                    Menu                     |
+---------------------------------------------+
| 1. Them/Cap nhat so tiet kiem               |
| 2. Xoa so tiet kiem                         |
| 3. Hien thi so tiet kiem                    |
| 4. Sap xep so tiet kiem                     |
| 5. Tim kiem/Loc so tiet kiem                |
| 6. Tinh tien lai tung so tiet kiem          |
| 7. Cap nhat thong tin ngan hang             |
| 8. Hien thi thong tin ngan hang             |
| 9. Bao cao thong ke ngan hang               |
| 0. Thoat chuong trinh                       |
+---------------------------------------------+
```

## ✨ Chức năng chính

### 1. 📝 Quản lý sổ tiết kiệm
- **Thêm sổ mới**: Thêm sổ có kỳ hạn hoặc không kỳ hạn
- **Cập nhật thông tin**: Sửa đổi thông tin sổ hiện có
- **Xóa sổ**: Loại bỏ sổ tiết kiệm khỏi hệ thống

### 2. 📋 Hiển thị và tra cứu
- **Hiển thị tất cả sổ**: Xem danh sách toàn bộ sổ tiết kiệm
- **Hiển thị theo loại**: Sổ có kỳ hạn hoặc không kỳ hạn
- **Tìm kiếm**: Theo mã KH, tên, CCCD, kỳ hạn
- **Lọc dữ liệu**: Theo ngày, số dư, lãi suất, kỳ hạn

### 3. 📊 Sắp xếp và báo cáo
- **Sắp xếp**: Theo tên, ngày, số dư, lãi suất, kỳ hạn
- **Tính lãi**: Tính toán lãi suất từng sổ đến thời điểm hiện tại
- **Báo cáo**: Thống kê tổng quan ngân hàng

### 4. 🏦 Quản lý ngân hàng
- **Cập nhật thông tin**: Tên, địa chỉ, mã số thuế, liên lạc
- **Hiển thị thông tin**: Xuất thông tin ngân hàng ra file
- **Báo cáo thống kê**: Tổng số sổ, tổng tiền gửi, tổng lãi

## 💾 Quản lý dữ liệu

### File input.data
```
Tên_ngân_hàng | Địa_chỉ | Mã_số_thuế | Điện_thoại | Email

Số_lượng_sổ_tiết_kiệm
Mã_KH | Tên_KH | CCCD | Ngày_mở | Tiền_gửi | Lãi_suất | [Kỳ_hạn]
...
```

### File output.data
- Kết quả hiển thị bảng
- Báo cáo thống kê
- Danh sách tìm kiếm/lọc

## 🎨 Tính năng đặc biệt

### 🌈 Giao diện màu sắc
- **Xanh lá**: Nhập liệu và thông báo thành công
- **Vàng**: Cảnh báo và lỗi nhập liệu
- **Đỏ**: Lỗi nghiêm trọng
- **Xanh dương**: Thông báo hoàn thành
- **Cyan**: Tiêu đề và menu

### 🔒 Validation dữ liệu
- Kiểm tra định dạng mã khách hàng
- Validation số CCCD (12 chữ số, không trùng)
- Kiểm tra ngày hợp lệ
- Giới hạn số tiền và lãi suất hợp lý

### 📈 Tính toán thông minh
- Tự động tính số tháng từ ngày mở sổ đến hiện tại
- Áp dụng đúng công thức cho từng loại sổ
- Làm tròn số tiền đến 2 chữ số thập phân

## 🏛️ Kiến trúc hướng đối tượng

### Các lớp chính
```cpp
class Date              // Quản lý ngày tháng
class SavingsAccount    // Lớp cơ sở sổ tiết kiệm
class TermAccount       // Sổ có kỳ hạn (kế thừa)
class NonTermAccount    // Sổ không kỳ hạn (kế thừa)
class Bank             // Quản lý ngân hàng
```

### Nguyên tắc OOP được áp dụng
- **Encapsulation**: Che giấu dữ liệu với private/protected
- **Inheritance**: TermAccount và NonTermAccount kế thừa SavingsAccount
- **Polymorphism**: Virtual functions cho calculateInterest()
- **Abstraction**: Các interface rõ ràng cho từng lớp

## 🐛 Xử lý lỗi

### Validation đầu vào
- Kiểm tra định dạng số
- Validation email và phone
- Kiểm tra ngày hợp lệ
- Xử lý trùng lặp dữ liệu

### Xử lý file
- Kiểm tra file tồn tại
- Backup dữ liệu khi ghi
- Thông báo lỗi đọc/ghi file

## 👨‍💻 Tác giả
- **Tên nhóm**: [Nhóm 9]
- **Lớp**: [K65-LTHĐT02]
- **Môn học**: Lập trình hướng đối tượng

## 📄 Giấy phép
Dự án này được phát hành dưới giấy phép MIT. Xem file [LICENSE](LICENSE) để biết thêm chi tiết.

## 🙏 Lời cảm ơn
- Cảm ơn giảng viên hướng dẫn
- Cảm ơn các tài liệu tham khảo
- Cảm ơn cộng đồng lập trình C++
