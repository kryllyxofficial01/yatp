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

    token_t* tokens = lex(contents);

    free(tokens);

    return EXIT_SUCCESS;
}