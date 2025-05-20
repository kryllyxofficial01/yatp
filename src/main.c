#include "include/lexer.h"

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <TOML file>\n", argv[0]);

        return EXIT_FAILURE;
    }

    char* contents = load_file(argv[1]);

    if (!contents) {
        perror("Error loading file");

        return EXIT_FAILURE;
    }

    token_list_t tokens_list = lex(contents);

    for (size_t i = 0; i < tokens_list.tokens_length; i++) {
        printf(token_to_string(tokens_list.tokens[i]));
    }

    free(tokens_list.tokens);

    return EXIT_SUCCESS;
}