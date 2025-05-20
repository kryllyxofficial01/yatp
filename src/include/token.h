#ifndef __YATP_TOKEN_H
#define __YATP_TOKEN_H

typedef enum _YATP_TOKEN_TYPE {
    TOKEN_TYPE_IDENTIFIER,

    TOKEN_TYPE_STRING, // "..."

    TOKEN_TYPE_EQUALS_SIGN, // =
    TOKEN_TYPE_DOUBLE_QUOTES // "
} token_type_t;

typedef struct _YATP_TOKEN {
    token_type_t type;
    const char* value;
} token_t;

typedef struct _YATP_TOKEN_LIST {
    token_t* tokens;
    size_t tokens_length;
} token_list_t;

#define make_token_list(_tokens, _length) (token_list_t) { .tokens = _tokens, .tokens_length = _length }
#define make_token(_type, _value) (token_t) { .type = _type, .value = _value }
#define token_to_string(_token) "TOKEN(%u, '%s')\n", _token.type, _token.value

#endif