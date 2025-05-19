#ifndef __YATP_TOKEN_H
#define __YATP_TOKEN_H

typedef enum _YATP_TOKEN_TYPE {
    TOKEN_TYPE_ID,

    TOKEN_TYPE_STRING, // "..."

    TOKEN_TYPE_EQUALS_SIGN, // =
    TOKEN_TYPE_DOUBLE_QUOTES // "
} token_type_t;

typedef struct _YATP_TOKEN {
    token_type_t token_type;
    const char* value;
} token_t;

#define make_token(type, value) (token_t) { .token_type = type, .value = value }

#endif