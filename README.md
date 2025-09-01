```MyLexer/
├── .vscode/
│   ├── c_cpp_properties.json  # VS Code C/C++ 扩展的智能感知配置
│   ├── launch.json            # VS Code 的调试配置
│   └── tasks.json             # VS Code 的构建任务配置 (如果不用 CMake Tools)
├── include/
│   ├── lexer.h              # 词法分析器类/函数的头文件声明
│   └── token.h              # 词法单元 (Token) 结构体/类和类型枚举的头文件
├── src/
│   ├── lexer.cpp            # 词法分析器类/函数的实现文件
│   └── main.cpp             # 项目入口文件，包含 main 函数，用于读取输入并调用词法分析器
├── test/
│   └── example.mylang       # 用于测试词法分析器的示例源代码文件
├── CMakeLists.txt           # CMake 构建系统配置文件 (推荐使用)
└── README.md                # 项目说明文件
```
