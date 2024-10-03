#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#define MESSEGE_SIZE 32

void expand(const char * src, char * dest) {
    int ind = 0;
    char start = 0;
    char end = 0;
    char * src_cpy = (char *) calloc(sizeof(char), MESSEGE_SIZE);
    assert(src_cpy != NULL);
    strcpy(src_cpy, src);
    char * token = strtok(src_cpy, "-"); // Get Start Token
    if (token) {
        strcat(dest, token);
        start = token[strlen(token) - 1];
L1:     token = strtok(NULL, "-"); // Get End Token
        if (token) {
            end = token[0];
        } else {
            free(src_cpy);
            return;
        }
    }
    if (start && end && (start < end)) {
        for (char i = start + 1; i < end; ++i) {
            char tmp[2] = {0};
            tmp[0] = i;
            strcat(dest, tmp);
        }
    }
    strcat(dest, token);
    start = token[strlen(token) - 1];
    goto L1;    
}

int main() {
    char * src = (char *) calloc(sizeof(char), MESSEGE_SIZE);
    assert(src != NULL);
    char * dest = (char *) calloc(sizeof(char), MESSEGE_SIZE);
    assert(dest != NULL);
    printf("Enter some string to be converted: ");
    scanf("%s", src);
    expand(src, dest);
    printf("Result: %s\n", dest);

}