#include <iostream>
#include <string>
#include <cctype>
#include <vector>

struct Token {
    std::string type;
    std::string value;

    Token(const std::string& t, const std::string& v) : type(t), value(v) {}
};

bool isVariable(const std::string& str) {
    if (str.empty()) return false;
    if (!std::isalpha(str[0])) return false; 
    for (size_t i = 0; i < str.size(); ++i) {
        if (!std::isalnum(str[i])) return false;  
    }
    return true;
}

std::vector<Token> lexicalAnalysis(const std::string& expression) {
    std::vector<Token> tokens;
    std::string currentToken;
    
    for (size_t i = 0; i < expression.size(); i++) {
        char ch = expression[i];
        
        if (std::isspace(ch)) {
            continue;
        }
        
        if (std::isalpha(ch)) {
            currentToken += ch;
            if (i + 1 < expression.size() && !std::isalnum(expression[i + 1])) {
                tokens.push_back(Token("tên", currentToken));
                currentToken.clear();
            }
        }
        else if (ch == '=' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ';') {
            if (!currentToken.empty() && isVariable(currentToken)) {
                tokens.push_back(Token("tên", currentToken));
                currentToken.clear();
            }
            if (ch == '=')
                tokens.push_back(Token("toán tử", "="));
            else if (ch == '+')
                tokens.push_back(Token("toán tử", "+"));
            else if (ch == '-')
                tokens.push_back(Token("toán tử", "-"));
            else if (ch == '*')
                tokens.push_back(Token("toán tử", "*"));
            else if (ch == '/')
                tokens.push_back(Token("toán tử", "/"));
            else if (ch == ';')
                tokens.push_back(Token("toán tử", ";"));
        }
    }
    
    if (!currentToken.empty() && isVariable(currentToken)) {
        tokens.push_back(Token("tên", currentToken));
    }
    
    return tokens;
}

int main() {
    std::string expression = "Bien1 = bien2 + bien3;";
    
    std::vector<Token> tokens = lexicalAnalysis(expression);
    
    std::cout<<"Vũ Đăng Khoa - 22010357";
    for (size_t i = 0; i < tokens.size(); ++i) {
        std::cout << "<" << tokens[i].type << ", " << tokens[i].value << ">" << std::endl;
    }

    return 0;
}