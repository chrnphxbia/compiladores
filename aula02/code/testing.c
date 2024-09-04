#include <stdio.h>

int main() {
    char* string = "";
    for(int i = 0; i < 1; i++) {
        if(*string == '\0') {
            printf("True\n");
        }
    }

    return 0;
}