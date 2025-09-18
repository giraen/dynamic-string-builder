#include "dstring.h"

dstring *new_string() {
    dstring *ds = malloc(sizeof(dstring));
    (*ds).len = 0;
    (*ds).cap = 64;
    (*ds).buffer = malloc((*ds).cap);
    (*ds).buffer[0] = '\0';
    return ds;
}

void string_append(dstring *ds, char *s) {
    // Get the size of the string
    size_t txt_len = 0;
    while (s[txt_len] != '\0') {
        ++txt_len;
    }
    size_t new_len = txt_len + (*ds).len;

    // Reallocation of memory
    if (new_len + 1 > (*ds).cap) {
        while (new_len + 1 > (*ds).cap) {
            (*ds).cap *= 2;
        }
        (*ds).buffer = realloc((*ds).buffer, (*ds).cap);
    }

    // Copy the string with new string
    for (int i = 0; i <= txt_len; ++i) {
        (*ds).buffer[(*ds).len + i] = s[i];
    }
    (*ds).len = new_len;
}

void string_clear(dstring *ds) {
    for (int i = 0; i <= (*ds).len; ++i) {
        (*ds).buffer[i] = 0;
    }
    (*ds).len = 0;
    (*ds).buffer[0] = '\0';
}

void string_free(dstring *ds) {
    string_clear(ds);
    free((*ds).buffer);
    (*ds).buffer = NULL;

    free(ds);
    ds = NULL;
}