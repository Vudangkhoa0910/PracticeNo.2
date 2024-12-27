#include <iostream>
#include <regex>

bool isPascalRelation(const std::string& token) {
    std::regex pattern("^(=|<>|<|<=|>|>=)$");
    return std::regex_match(token, pattern);
}

int main() {
    std::string input;
    int choice;

    do {
        std::cout << "=========================\n";
        std::cout << "Author: Vũ Đăng Khoa - 22010357\n";
        std::cout << "1. Kiểm tra toán tử quan hệ Pascal\n";
        std::cout << "2. Thoát\n";
        std::cout << "=========================\n";
        std::cout << "Lựa chọn của bạn: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::cout << "Nhập một từ tố để kiểm tra (toán tử quan hệ): ";
            std::getline(std::cin, input);

            if (isPascalRelation(input)) {
                std::cout << "\"" << input << "\" là một toán tử quan hệ hợp lệ trong Pascal.\n";
            } else {
                std::cout << "\"" << input << "\" không phải là một toán tử quan hệ hợp lệ trong Pascal.\n";
            }
            break;
        }
        case 2:
            std::cout << "Thoát chương trình. Hẹn gặp lại!\n";
            break;
        default:
            std::cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại.\n";
        }
    } while (choice != 2);

    return 0;
}