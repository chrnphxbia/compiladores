// Código de resolução do exercício 01 proposto no PDF da aula
// Ler numero de digitos, letras, espaços em branco e linhas de um arquivo

#include <stdio.h>
#include <string.h>
// Digits, upper and lower case letters, whitespace
#define NUM_OF_READABLE_CHARS 63 // 10 + 26 + 26 + 1 = 63

int main(int argc, char *argv[]) {
    char ch;
    FILE *p_file;
    int offset = 0;
    int n_lines = 0;
    int occ_chars[NUM_OF_READABLE_CHARS]; // Num of occurrence of chars
    memset(occ_chars, 0, sizeof(occ_chars)); // Iniatilizing array as 0

    if(argc != 2) { 
        fprintf(stderr, "Could not find file.\n"); 
        fprintf(stderr, "Please, run as it follows:\n"); 
        fprintf(stderr, "./program_name file_name\n"); 
        return 1;
    }

    p_file = fopen(argv[1], "r");
    if (p_file == NULL) {
        fprintf(stderr, "\nCould not find file.");
        return 1;
    }

    printf("Number of occurrences of every character in %s:\n", argv[1]);

    while(fscanf(p_file, "%c", &ch) != EOF) {
        int ascii_code = (int) ch;

        if(ascii_code > 47 && ascii_code < 58) occ_chars[ascii_code - 48]++;
        if(ascii_code > 64 && ascii_code < 91) occ_chars[ascii_code - 55]++;
        if(ascii_code > 96 && ascii_code < 123) occ_chars[ascii_code - 61]++;
        if(ascii_code == 32) occ_chars[NUM_OF_READABLE_CHARS - 1]++;
        if(ascii_code == 10) n_lines++;
    }
    
    fclose(p_file);

    for(int i = 0; i < NUM_OF_READABLE_CHARS; i++) {
        if(occ_chars[i] > 0) {
            if(i < 10) offset = 48;
            else offset = 55;
            if(i > 35) offset = 61;
            if(i == NUM_OF_READABLE_CHARS - 1) offset = -30;
            printf("%c: %d\n", i + offset, occ_chars[i]);
        }
    }

    printf("\nNumber of lines: %d\n", n_lines + 1);

    return 0;
}