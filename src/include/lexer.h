#ifndef __YATP_LEXER_H
#define __YATP_LEXER_H

#include <ctype.h>

#include "token.h"
#include "utils.h"

#define YATP_DEFAULT_TOKEN_LIST_CAPACITY (1)

#define is_valid_identifier_char(c) (isalnum(c) || c == '_')

token_t* lex(const char* contents);

token_t get_next_token(const char* contents, size_t* index);
token_t get_token_identifier(const char* contents, size_t* index);

int update_token_list_capacity(token_t** tokens, size_t* capacity, size_t count);

#endif