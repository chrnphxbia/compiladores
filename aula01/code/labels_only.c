// Código de resolução do exercício de desafio proposto no PDF da aula
// Definir se a quantidade de A é ímpar e a de B é par
// Restrição: NÃO USAR NENHUMA VARIÁVEL ALÉM DA STRING DE ENTRADA

#include <stdio.h>

int is_a_odd_b_even(char *input) {
    evenAevenB:
        if(*input == 'a') {
            input++;
            goto oddAevenB;
        }

        if(*input == 'b') {
            input++;
            goto evenAoddB;
        }

        return 0;

    oddAevenB:
        if(*input == 'a') {
            input++;
            goto evenAevenB;
        }

        if(*input == 'b') {
            input++;
            goto oddAoddB;
        }

        return 1;

    oddAoddB:
        if(*input == 'a') {
            input++;
            goto evenAoddB;
        }

        if(*input == 'b') {
            input++;
            goto oddAevenB;
        }

        return 0;

    evenAoddB:
        if(*input == 'a') {
            input++;
            goto oddAoddB;
        }

        if(*input == 'b') {
            input++;
            goto evenAevenB;
        }

        return 0;
}

int main(int argc, char* argv[]) {
    char* strings[4] = {"abbbaba", "aaaabbb", "aaaabbbb", "aabaaabb"};
    
    for(int i = 0; i < 4; i++) {
        printf("String: %s\nIs A odd and B even? %d\n\n", strings[i], 
            is_a_odd_b_even(strings[i]));
    }

    return 0;
}