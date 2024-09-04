#include <stdio.h>

int suffix_aa_bb(char* string) {
    if(*string == 'a') {
        string++;
        goto q1;
    }

    if(*string == 'b') {
        string++;
        goto q3;
    }

    return 0;

    q1:
    if(*string == 'a') {
        string++;
        goto q2;
    }

    if(*string == 'b') {
        string++;
        goto q3;
    }

    return 0;

    q2:
    if(*string == 'a') {
        string++;
        goto q2;
    }

    if(*string == 'b') {
        string++;
        goto q3;
    }

    if(*string == '\0') { return 1; }

    return 0;

    q3:
    if(*string == 'a') {
        string++;
        goto q1;
    }

    if(*string == 'b') {
        string++;
        goto q4;
    }

    return 0;

    q4:
    if(*string == 'a') {
        string++;
        goto q1;
    }

    if(*string == 'b') {
        string++;
        goto q4;
    }

    if(*string == '\0') { return 1; }

    return 0;
}

int main(int argc, char* argv[]) {
    if(argc != 2) { 
        fprintf(stderr, "Could not find string to be read.\n"); 
        fprintf(stderr, "Please, run as it follows:\n"); 
        fprintf(stderr, "./program_name string\n"); 
        return 1;
    }

    printf("String \"%s\" has aa or bb as suffix? %d.\n\n", argv[1], 
    suffix_aa_bb(argv[1]));

    return 0;
}