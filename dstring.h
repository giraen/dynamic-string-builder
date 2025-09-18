#ifndef DSTRING_H
#define DSTRING_H

#include <stdio.h>
#include <stdlib.h>

// Size 12
// char size: 1 + 3 (padding)
// size_t size: 4
typedef struct {
    char *buffer;
    size_t len;
    size_t cap;
} dstring;

dstring *new_string();
void string_append(dstring *ds, char *s);
void string_clear(dstring *ds);
void string_free(dstring *ds);

#endif