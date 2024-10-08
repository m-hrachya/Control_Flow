#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define STRING_SIZE 32

int is_palindrome(char * str) {
    char * check_str = (char *) malloc(sizeof(char) * STRING_SIZE);
    assert(check_str);
    int index = 0;
    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9')) check_str[index++] = *str;
        else if (*str >= 'A' && *str <= 'Z') check_str[index++] = *str + ('a' - 'A');
        ++str;
    }
    char * start = check_str;
    char * end = &check_str[strlen(check_str) - 1];
    while (start <= end) {
        if (*start != *end) {
            free(check_str);
            return 0;
        } 
        ++start;
        --end;
    }
    free(check_str);
    return 1;
}

int main() {
    char * str = (char *) malloc (sizeof(char) * STRING_SIZE);
    assert(str != NULL);
    printf("Enter string to check: ");
    fgets(str, STRING_SIZE - 2, stdin);
    str[strlen(str) - 1] = '\0';
    if (is_palindrome(str)) printf("String is palindrome!\n");
    else printf("String is not palindrome!\n");
    free(str);
    return 0;
}