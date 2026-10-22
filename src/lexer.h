#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <any>

enum class Type {
    INT,
    FLOAT,
};

class Identifier {
    std::string name;
};

enum class Keyword {
    LET,
};

enum class Operator {
    PLUS,
    MINUS,

};

enum class Delimiter {
    LPARENTHESE,
    RPARENTHESE,
    BEGIN,
    END,
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

class Lexer{
public :
    explicit Lexer(const std::string input_file_name);
    void getLexedString();

private:
    std::string lexed_string = "";//More a vector
};
#endif
