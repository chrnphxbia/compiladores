// Resposta do exercicio: a linguagem permite sequencias de b, mas nunca sequencias de a

#include <stdio.h>

int regex_ex02(char* string) {
    if(*string == 'a') {
        string++;
        goto q1;
    }

    if(*string == 'b') {
        string++;
        goto q2;
    }

    if(*string == '\0') { return 1; }
    return 0;

    q1:
    if(*string == 'b') {
        string++;
        goto q2;
    }

    if(*string == '\0') { return 1; }
    return 0;

    q2:
    if(*string == 'a') {
        string++;
        goto q3;
    }

    if(*string == 'b') {
        string++;
        goto q2;
    }

    if(*string == '\0') { return 1; }
    return 0;

    q3:
    if(*string == 'b') {
        string++;
        goto q2;
    }

    if(*string == '\0') { return 1; }
    return 0;  
}

int main(int argc, char* argv[]) {
    if(argc > 2) { 
        fprintf(stderr, "Too many arguments.\n"); 
        fprintf(stderr, "Please, run as it follows: ./program_name string\n"); 
        fprintf(stderr, "Notice that argument string might be empty.\n"); 
        return 1;
    }

    if(argc != 2) printf("String \" \" is recognizable? %d.\n", regex_ex02(""));
    else printf("String \"%s\" is recognizable? %d.\n", argv[1], regex_ex02(argv[1])); 

    return 0;
}