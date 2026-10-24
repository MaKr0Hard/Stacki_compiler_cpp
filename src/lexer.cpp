#include "lexer.h"
#include <iostream>
#include <cstdio>

std::string lexed_string;

void Lexer::getLexedString() {

}

bool is_letter(char c) {
    if ((c <= 'z') && (c >= 'a')) {
        return 1;
    } else if ((c <= 'Z') && (c >= 'A')) {
        return 1;
    } else if (c == '_') {
        return 1;
    } else {
        return 0;
    }
}

void Lexer::check_identifier_or_keyword(std::string word) {
    if (!(word.empty())) {
        if (word == "int") {
            Keyword keyw;
            keyw = Keyword::INT;
        } else {
            Identifier identifier;
            identifier.name = word;
            token_struct token;
            token.tokenType = TokenType::IDENTIFIER;
            token.value.identifier = identifier;
            lexed_tokens.push_back(token);
        }
    }
}

Lexer::Lexer(const std::string input_file_name)
{
    std::FILE* input_file = std::fopen(input_file_name.data(), "r");
    std::string word; //not the binary kinda word but the word separated by spaces
    char c = ' ';
    while ((c = fgetc( input_file)) != EOF) {

        if (c == ' ') {
            check_identifier_or_keyword(word);
        } else if (is_letter(c)) {
            word.push_back(c);
        } else if (c == '(') {
            check_identifier_or_keyword(word);
            token_struct token;
            token.tokenType = TokenType::DELIMITER;
            token.value.delimiter = Delimiter::LPARENTHESE;
            lexed_tokens.push_back(token);
        }


    }
}

