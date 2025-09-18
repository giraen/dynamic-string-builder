#include "dstring.h"
#include <stdio.h>

int main() {
    dstring *my_string = new_string();

    string_append(my_string, "Hello");
    printf("%s\n", (*my_string).buffer);
    string_append(my_string, " ");
    string_append(my_string, "world!!!");
    printf("%s\n", (*my_string).buffer);

    string_clear(my_string);

    string_append(my_string, "This is");
    string_append(my_string, " ");
    string_append(my_string, "new string!!!!");
    printf("%s\n", (*my_string).buffer);

    string_clear(my_string);
    string_free(my_string);
    my_string = NULL;
}