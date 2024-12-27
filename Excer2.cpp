#include <iostream>
#include <regex>

bool isInteger(const std::string& number) {
    std::regex pattern("^[+-]?[0-9]+$");
    return std::regex_match(number, pattern);
}

bool isReal(const std::string& number) {
    std::regex pattern("^[+-]?[0-9]*\\.[0-9]+$");
    return std::regex_match(number, pattern);
}

bool isPascalNumber(const std::string& number) {
    std::regex pattern("^[+-]?[0-9]+(\\.[0-9]+)?$");
    return std::regex_match(number, pattern);
}

int main() {
    std::string input;
    int choice;

    do {
        std::cout << "=========================\n";
        std::cout << "Author: Vũ Đăng Khoa - 22010357\n";
        std::cout << "1. Kiểm tra số nguyên\n";
        std::cout << "2. Kiểm tra số thập phân\n";
        std::cout << "3. Kiểm tra số Pascal (cả hai)\n";
        std::cout << "4. Thoát\n";
        std::cout << "=========================\n";
        std::cout << "Lựa chọn của bạn: ";
        std::cin >> choice;
        std::cin.ignore(); // Xóa ký tự xuống dòng còn sót trong bộ đệm

        switch (choice) {
        case 1: {
            std::cout << "Nhập một từ tố để kiểm tra số nguyên: ";
            std::getline(std::cin, input);
            if (isInteger(input)) {
                std::cout << "\"" << input << "\" là một số nguyên hợp lệ trong Pascal.\n";
            } else {
                std::cout << "\"" << input << "\" không phải là một số nguyên hợp lệ trong Pascal.\n";
            }
            break;
        }
        case 2: {
            std::cout << "Nhập một từ tố để kiểm tra số thập phân: ";
            std::getline(std::cin, input);
            if (isReal(input)) {
                std::cout << "\"" << input << "\" là một số thập phân hợp lệ trong Pascal.\n";
            } else {
                std::cout << "\"" << input << "\" không phải là một số thập phân hợp lệ trong Pascal.\n";
            }
            break;
        }
        case 3: {
            std::cout << "Nhập một từ tố để kiểm tra số Pascal (cả số nguyên và thập phân): ";
            std::getline(std::cin, input);
            if (isPascalNumber(input)) {
                std::cout << "\"" << input << "\" là một số hợp lệ trong Pascal.\n";
            } else {
                std::cout << "\"" << input << "\" không phải là một số hợp lệ trong Pascal.\n";
            }
            break;
        }
        case 4:
            std::cout << "Thoát chương trình. Hẹn gặp lại!\n";
            break;
        default:
            std::cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại.\n";
        }
    } while (choice != 4);

    return 0;
}