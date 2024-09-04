#include <stdio.h>
#include <ctype.h>

int integer_regex(char* string) {
    if(isdigit(*string)) {
        string++;
        goto final;
    }

    if(*string == '+' || *string == '-') {
        string++;
        goto middleware;
    }

    return 0;
    
    middleware:
    if(isdigit(*string)) {
        string++;
        goto final;
    }

    return 0;

    final:
    if(isdigit(*string)) {
        string++;
        goto final;
    }

    if(*string == '\0') { return 1; }

    return 0;
}

int main(int argc, char* argv[]) {
    char* strings[5] = {"+42", "-39", "1074", "1083C", "abc"};

    for(int i = 0; i < 5; i++) {
        printf("String: %s\nIs it an integer token? %d\n\n", strings[i], 
        integer_regex(strings[i]));
    }

    return 0;
}