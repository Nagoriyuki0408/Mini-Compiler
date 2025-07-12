#pragma once
#include <string>
#include "token.h"

class Lexer {
public:
    Lexer(const std::string& source);

    char peek() const;
    char advance();
    void skipWhitespace();
    Token identifier();
    Token number();
    Token nextToken();
    std::vector<Token> Lexer::tokenize(); 

private:
    std::string source;
    size_t position;
    int line;
    int column;
};

// 获取当前字符但不前进
char Lexer::peek() const {
    if (position < source.size()) {
        return source[position];
    }
    return '\0'; // 返回空字符表示到达文件末尾
}


//获取当前字符并前进
char Lexer::advance() {
    if (position < source.size()) {
        char current = source[position++];
        if (current == '\n') {
            line++;
            column = 1;
        } else {
            column++;
        }
        return current;
    }
    return '\0'; // 返回空字符表示到达文件末尾
}

//跳过空白字符
void Lexer::skipWhitespace() {
    while (std::isspace(peek())) {
        advance();
    }
}

//识别标识符或关键词
Token Lexer::identifier() {
    std::string value;
    while (std::isalnum(peek()) || peek() == '_') {
        value += advance();
    }
    if (value == "if") return Token(TokenType::Keyword, value, line, column - value.length());
    if (value == "else") return Token(TokenType::Keyword, value, line, column - value.length());
    return Token(TokenType::Identifier, value, line, column - value.length());
}

//识别数字
Token Lexer::number() {
    std::string value;
    while (std::isdigit(peek())) {
        value += advance();
    }
    return Token(TokenType::Literal, value, line, column - value.length());
}

//获取下一个token
Token Lexer::nextToken() {
    skipWhitespace();
    int startCol =column;
    char current = peek();

    if (current == '\0') {
        return Token(TokenType::EndOfFile, "", line, startCol);
    }

    if (std::isalpha(current) || current == '_') {
        return identifier();
    }

    if (std::isdigit(current)) {
        return number();
    }

    // 处理操作符和标点符号
    if (current == '+' || current == '-' || current == '*' || current == '/' || current == '=') {
        std::string op(1, advance());
        return Token(TokenType::Operator, op, line, startCol);
    }
    if (current == ';' || current == ',' || current == '(' || current == ')') {
        std::string punc(1, advance());
        return Token(TokenType::Punctuation, punc, line, startCol);
    }
    // 跳过无法识别的字符
    advance();
    return Token(TokenType::Unknown, "", line, startCol);
}

//一次性分词
std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (true) {
        Token token = nextToken();
        tokens.push_back(token);
        if (token.type == TokenType::EndOfFile) {
            break;
        }
    }
    return tokens;
}
