#include <iostream>
#include <regex>

// Hàm kiểm tra xem một từ tố có phải là tên hợp lệ trong Pascal hay không
bool isPascalIdentifier(const std::string& identifier) {
    std::regex pattern("^[a-zA-Z][a-zA-Z0-9_]*$");
    return std::regex_match(identifier, pattern);
}

int main() {
    int choice;
    do {
        std::cout << "=========================\n";
        std::cout << "Author: Vũ Đăng Khoa - 22010357\n";
        std::cout << "1. Kiểm tra từ tố Pascal\n";
        std::cout << "2. Thoát\n";
        std::cout << "=========================\n";
        std::cout << "Lựa chọn của bạn: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
        case 1: {
            std::string input;
            std::cout << "Nhập một từ tố để kiểm tra (Pascal identifier): ";
            std::getline(std::cin, input); 

            size_t start = input.find_first_not_of(" \t\n");
            size_t end = input.find_last_not_of(" \t\n");
            if (start != std::string::npos && end != std::string::npos) {
                input = input.substr(start, end - start + 1);
            } else {
                input = ""; 
            }

            if (isPascalIdentifier(input)) {
                std::cout << "\"" << input << "\" là một tên hợp lệ trong Pascal.\n";
            } else {
                std::cout << "\"" << input << "\" không phải là một tên hợp lệ trong Pascal.\n";
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