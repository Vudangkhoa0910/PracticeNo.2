#include <iostream>
#include <regex>

bool isPascalIdentifier(const std::string& token) {
    std::regex pattern("^[a-zA-Z][a-zA-Z0-9_]*$");
    return std::regex_match(token, pattern);
}

bool isPascalNumber(const std::string& token) {
    std::regex pattern("^[+-]?[0-9]+(\\.[0-9]+)?$");
    return std::regex_match(token, pattern);
}

bool isPascalRelation(const std::string& token) {
    std::regex pattern("^(=|<>|<|<=|>|>=)$");
    return std::regex_match(token, pattern);
}

int main() {
    std::string input;
    int choice;

    do {
        std::cout << "=============================\n";
        std::cout << "1. Kiểm tra tên Pascal\n";
        std::cout << "2. Kiểm tra chữ số Pascal\n";
        std::cout << "3. Kiểm tra toán tử quan hệ Pascal\n";
        std::cout << "4. Thoát\n";
        std::cout << "=============================\n";
        std::cout << "Lựa chọn của bạn: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
        case 1: {
            std::cout << "Nhập một từ tố để kiểm tra tên Pascal: ";
            std::getline(std::cin, input);

            if (isPascalIdentifier(input)) {
                std::cout << "\"" << input << "\" là một tên hợp lệ trong Pascal.\n";
            } else {
                std::cout << "\"" << input << "\" không phải là một tên hợp lệ trong Pascal.\n";
            }
            break;
        }
        case 2: {
            std::cout << "Nhập một từ tố để kiểm tra chữ số Pascal: ";
            std::getline(std::cin, input);

            if (isPascalNumber(input)) {
                std::cout << "\"" << input << "\" là một chữ số hợp lệ trong Pascal.\n";
            } else {
                std::cout << "\"" << input << "\" không phải là một chữ số hợp lệ trong Pascal.\n";
            }
            break;
        }
        case 3: {
            std::cout << "Nhập một từ tố để kiểm tra toán tử quan hệ Pascal: ";
            std::getline(std::cin, input);

            if (isPascalRelation(input)) {
                std::cout << "\"" << input << "\" là một toán tử quan hệ hợp lệ trong Pascal.\n";
            } else {
                std::cout << "\"" << input << "\" không phải là một toán tử quan hệ hợp lệ trong Pascal.\n";
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