#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MESSEGE_SIZE 32

void my_escape(const char * src, char * dest) {
    for (int i = 0, j = 0; src[i] != '\0'; ++i, ++j) {
        switch (src[i]) {
            case '\n':
                strcat(dest, "\\n");
                j++;
                break;
            case '\t':
                strcat(dest, "\\t");
                j++;
                break;
            case '\b': 
                strcat(dest, "\\b");
                j++;
                break;
            case '\r':
                strcat(dest, "\\r");
                j++;
                break;
            default:
                dest[j] = src[i];
        }
    }
}

int main() {
    char * src = (char *) calloc(sizeof(char), MESSEGE_SIZE);
    assert(src != NULL);
    char * dest = (char *) calloc(sizeof(char), MESSEGE_SIZE);
    assert(dest != NULL);
    strcpy(src, "\tHello, World!\b\r\n");
    my_escape(src, dest);
    printf("Converted: %s\n", dest);
    printf("Not Converted: %s\n", src);
    free(dest);
    free(src);
    return 0;
}