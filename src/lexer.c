#include "include/lexer.h"

token_t* lex(const char* contents) {
    token_t* tokens = NULL;

    size_t tokens_capacity = 0;
    size_t tokens_count = 0;

    for (size_t index = 0; index < strlen(contents); index++) {
        if (!update_token_list_capacity(&tokens, &tokens_capacity, tokens_count)) {
            perror("Memory allocation failed");

            free(tokens);

            return NULL;
        }

        tokens[tokens_count] = get_next_token(contents, &index);
    }

    return tokens;
}

token_t get_next_token(const char* contents, size_t* index) {
    if (is_valid_identifier_char(contents[*index])) {
        return get_token_identifier(contents, index);
    }
}

token_t get_token_identifier(const char* contents, size_t* index) {
    
}

int update_token_list_capacity(token_t** tokens, size_t* capacity, size_t count) {
    if (count >= *capacity) {
        size_t new_capacity = (*capacity == 0) ? YATP_DEFAULT_TOKEN_LIST_CAPACITY : (*capacity + 1);

        token_t* new_tokens = realloc(*tokens, YATP_CAPACITY(new_capacity, token_t));

        if (!new_tokens) {
            return -1;
        }

        *capacity = new_capacity;
        *tokens = new_tokens;
    }
}