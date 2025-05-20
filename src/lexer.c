#include "include/lexer.h"

token_list_t lex(const char* contents) {
    token_t* tokens = NULL;

    size_t tokens_capacity = 0;
    size_t tokens_count = 0;

    size_t index = 0;
    while (contents[index] != '\0') {
        if (update_token_list_capacity(&tokens, &tokens_capacity, tokens_count) < 0) {
            perror("Memory allocation failed");

            free(tokens);

            return make_token_list((tokens = NULL), 0);
        }

        tokens[tokens_count++] = get_next_token(contents, &index);
    }

    return make_token_list(tokens, tokens_count);
}

token_t get_next_token(const char* contents, size_t* index) {
    skip_whitespace(contents, index);

    if (is_valid_identifier_char(contents[*index])) {
        return get_token_identifier(contents, index);
    }
    else if (contents[*index] == '"') {
        return get_token_basic_string(contents, index);
    }
    else {
        return get_token_symbol(contents, index);
    }
}

token_t get_token_identifier(const char* contents, size_t* index) {
    char* identifier = NULL;
    char* temp_identifier = NULL;

    size_t identifier_length = 0;

    char current_char;

    while (is_valid_identifier_char((current_char = contents[*index]))) {
        temp_identifier = realloc(identifier, identifier_length + 2); // character + \0

        if (!temp_identifier) {
            free(identifier);

            identifier = NULL;

            break;
        }

        identifier = temp_identifier;

        identifier[identifier_length++] = current_char;

        (*index)++;
    }

    if (identifier) {
        identifier[identifier_length] = '\0';
    }

    return make_token(TOKEN_TYPE_IDENTIFIER, identifier);
}

token_t get_token_basic_string(const char* contents, size_t* index) {
    
}

token_t get_token_symbol(const char* contents, size_t* index);

void skip_whitespace(const char* contents, size_t* index) {
    while (is_whitespace_char(contents[*index])) {
        (*index)++;
    }
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

    return 0;
}