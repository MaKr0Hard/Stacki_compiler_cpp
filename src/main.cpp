#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <ctype.h>
#include "lexer.h"

std::string program_name;

// i'm reading lots of characters one after another, the c way is just faster than the cpp way

int main(int argc, char** argv) { //TODO : Add multi-file support
    int opt;
    std::string input = "";
    std::string output = "";
    while ((opt = getopt(argc, argv, "s:o:")) != -1) { //-s : source
        //-o : output
        switch (opt) {
            case 's':
                input = optarg;//TODO: null-safe ?
                std::puts(input.data());
                break;
            case 'o':
                output = optarg;
                std::puts(output.data());
                break;
            default:
                std::putchar('\n');
                //printf("Unknown argmment : -%c", optarg);
                exit(EXIT_FAILURE);
                break;
        }
    }

    if ((input != "") && (output != "")) {
        Lexer *lexer = new Lexer(input);
    }
}
