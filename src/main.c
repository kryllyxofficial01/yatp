#include "include/utils.h"

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <TOML file>\n", argv[0]);

        exit(EXIT_FAILURE);
    }

    char* contents = load_file(argv[1]);

    if (contents) {
        printf("%s\n", contents);

        free(contents);
    }

    return EXIT_SUCCESS;
}