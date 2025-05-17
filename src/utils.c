#include "include/utils.h"

char* load_file(const char* filepath) {
    FILE* file = fopen(filepath, "rb");

    if (!file) {
        perror("Unable to open file");

        return NULL;
    }

    size_t contents_capacity = 1024;
    size_t contents_length = 0;

    char* contents = malloc(contents_capacity);

    if (!contents) {
        perror("Memory allocation failed");

        fclose(file);

        return NULL;
    }

    contents[0] = '\0';

    size_t line_capacity = 0;
    size_t line_length = 0;

    char* line = NULL;

    while ((line_length = getline(&line, &line_capacity, file)) != -1) {
        if (contents_length + line_length + 1 >= contents_capacity) {
            contents_capacity = (contents_length + line_length + 1) * 2;

            char* new_contents = realloc(contents, contents_capacity);

            if (!new_contents) {
                perror("Memory reallocation failed");

                free(line);
                free(contents);

                fclose(file);

                return NULL;
            }

            contents = new_contents;
        }

        memcpy(contents + contents_length, line, line_length);

        contents_length += line_length;

        contents[contents_length] = '\0';
    }

    free(line);

    fclose(file);

    return contents;
}

#ifdef _WIN32
    size_t getline(char** line, size_t* capacity, FILE* file_stream) {
        if (!line || !capacity || !file_stream) {
            return -1;
        }

        if (*line == NULL || *capacity == 0) {
            *capacity = 128;
            *line = malloc(*capacity);

            if (!(*line)) {
                return -1;
            }
        }

        char character;
        size_t position = 0;

        while ((character = fgetc(file_stream)) != EOF) {
            if (position + 1 >= *capacity) {
                size_t new_capacity = *capacity * 2;

                char* new_line = realloc(*line, new_capacity);

                if (!new_line) {
                    return -1;
                }

                *capacity = new_capacity;
                *line = new_line;
            }

            (*line)[position++] = character;

            if (character == '\n') {
                break;
            }
        }

        if (position == 0 && character == EOF) {
            return -1;
        }

        (*line)[position] = '\0';

        return position;
    }
#endif