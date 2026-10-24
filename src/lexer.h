#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <any>
#include <vector>

enum class Type {
    INT,
    FLOAT,
};

typedef struct {
    std::string name;
} Identifier;

enum class Keyword {
    LET,
    INT,
    FLOAT,
};

enum class Operator {
    PLUS,
    MINUS,

};

enum class Delimiter {
    LPARENTHESE,
    RPARENTHESE,
    LBRACKET, //gonna use bracket instead of begin and end
    RBRACKET,
};

class Constant {
private :
    Type type;
    union {
        int int_val;
        float float_val;
    };
public :
    void setConstant(float constant) {
        type = Type::FLOAT;
    }
    void setConstant(int constant) {
        type = Type::INT;
    }
    std::any getConstant() {
        if (type == Type::INT) {
            return int_val;
        } else if (type == Type::FLOAT) {
            return float_val;
        } else return 0;
    }
};

enum class TokenType {
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    DELIMITER,
    CONSTANT,
};

typedef struct {
    TokenType tokenType;
    //union { //TODO : do the union later...
    struct {
        Identifier identifier;
        Keyword keyword;
        Operator operat; //somehow operator was taken...
        Delimiter delimiter;
        Constant constant;
    } value;
    //} value;
} token_struct;



class Lexer {
public :
    Lexer(const std::string input_file_name);
    ~Lexer();
    void getLexedString();

private:
    void check_identifier_or_keyword(std::string word);
    std::vector<token_struct> lexed_tokens;
};
#endif
