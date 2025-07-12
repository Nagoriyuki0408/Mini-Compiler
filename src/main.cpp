#include <fstream>
#include "lexer.h"
#include "token.h"
#include "Lexer.cpp"

int main() {
    // 读取源代码文件
    std::ifstream file("test/example.mylang");
    if (!file) {
        std::cerr << "无法打开源代码文件！" << std::endl;
        return 1;
    }
    std::string source((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // 创建词法分析器
    Lexer lexer(source);

    // 分词并输出
    auto tokens = lexer.tokenize();
    for (const auto& token : tokens) {
        std::cout << "Type: " << static_cast<int>(token.type)
                  << ", Value: " << token.value
                  << ", Line: " << token.line
                  << ", Column: " << token.column << std::endl;
    }
    return 0;
}