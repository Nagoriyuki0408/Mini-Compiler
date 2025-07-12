#include "lexer.h"
 enum class TokenType{
     Identifier,
     Keyword,
     Literal,
     Operator,
     Punctuation,
     Comment,
     Whitespace,
     Unknown,
     EndOfFile
 };

 //Token结构体
 struct Token{
      TokenType type;
      std::string value;
      int line;
      int column;
      Token(TokenType t,const std::string& v,int l,int c)
          : type(t), value(v), line(l), column(c) {}
 };
