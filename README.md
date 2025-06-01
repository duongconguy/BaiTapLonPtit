# Hệ Thống Quản Lý Đăng Nhập & Ví Điểm

Đây là một hệ thống quản lý đăng nhập và ví điểm được viết bằng C++. Hệ thống cho phép người dùng đăng ký tài khoản, đăng nhập, quản lý ví điểm và thực hiện các giao dịch.

## Yêu cầu hệ thống

- Windows 10 trở lên
- MinGW-w64 (phiên bản 8.1.0 trở lên)
- Các thư viện C++ chuẩn

## Cài đặt

1. Tải và cài đặt MinGW-w64 từ trang chủ: https://www.mingw-w64.org/downloads/
   - Chọn phiên bản mới nhất (8.1.0)
   - Architecture: x86_64
   - Threads: posix
   - Exception: seh
   - Build revision: Latest

2. Thêm đường dẫn đến thư mục bin của MinGW-w64 vào biến môi trường PATH:
   - Mở System Properties (Win + Pause/Break)
   - Click vào "Advanced system settings"
   - Click vào "Environment Variables"
   - Trong phần "System variables", tìm và chọn "Path"
   - Click "Edit"
   - Click "New"
   - Thêm đường dẫn đến thư mục bin của MinGW-w64 (thường là C:\mingw64\bin)
   - Click "OK" để lưu

3. Khởi động lại PowerShell hoặc Command Prompt

## Biên dịch và chạy chương trình

1. Mở PowerShell hoặc Command Prompt
2. Di chuyển đến thư mục chứa mã nguồn
3. Chạy file build.bat:
   ```
   .\build.bat
   ```

## Tính năng chính

1. Đăng ký tài khoản
   - Tạo tài khoản mới với tên đăng nhập, họ tên, email, số điện thoại
   - Tự động tạo ví điểm cho tài khoản mới
   - Hỗ trợ tạo mật khẩu tự động

2. Đăng nhập
   - Xác thực người dùng bằng tên đăng nhập và mật khẩu
   - Mật khẩu được mã hóa bằng SHA-256

3. Quản lý ví điểm
   - Xem số dư ví
   - Chuyển điểm cho người dùng khác
   - Xác thực giao dịch bằng OTP

4. Quản lý giao dịch
   - Xem lịch sử giao dịch
   - Theo dõi các giao dịch đã thực hiện

5. Bảo mật
   - Mật khẩu được mã hóa
   - Xác thực OTP cho các giao dịch
   - Backup và phục hồi dữ liệu

## Cấu trúc thư mục

- `main.cpp`: File chính chứa hàm main và menu chương trình
- `UserAccount.h/cpp`: Quản lý thông tin tài khoản người dùng
- `UserManager.h/cpp`: Quản lý các tài khoản người dùng
- `Wallet.h/cpp`: Quản lý thông tin ví điểm
- `WalletManager.h/cpp`: Quản lý các ví điểm
- `Transaction.h/cpp`: Quản lý thông tin giao dịch
- `TransactionManager.h/cpp`: Quản lý các giao dịch
- `OTPManager.h/cpp`: Quản lý mã OTP
- `Hash.h/cpp`: Hàm mã hóa mật khẩu
- `utils.h/cpp`: Các hàm tiện ích
- `data/`: Thư mục chứa dữ liệu
  - `users.dat`: Dữ liệu người dùng
  - `wallets.dat`: Dữ liệu ví điểm
  - `transactions.dat`: Dữ liệu giao dịch
  - `backup/`: Thư mục chứa bản sao lưu

## Lưu ý

- Dữ liệu được lưu trong thư mục `data/`
- Nên thực hiện backup dữ liệu thường xuyên
- Mật khẩu được mã hóa nên không thể khôi phục nếu quên
- OTP được tạo ngẫu nhiên và chỉ có hiệu lực trong một khoảng thời gian ngắn
