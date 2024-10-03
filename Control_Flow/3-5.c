#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define HEX_BASE 16
#define OCT_BASE 8
#define BIN_BASE 2
#define IS_NEGATIVE 1
#define IS_NOT_NEGATIVE 0
#define STRING_SIZE 64

void reverse(char * str) {
    for (int i = 0, j = strlen(str) - 1; i < j; ++i, --j) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

void itob(int num, char * str, const int base) {
    memset(str, 0, STRING_SIZE);
    int is_negative = IS_NOT_NEGATIVE;
    int tmp_value = 0;
    int ind = 0;
    if (num < 0) {
        num ^= num;
        ++num;
        is_negative = IS_NEGATIVE;
    }
    switch (base)
    {
    case HEX_BASE:
        ind = strlen(str);
        while (num) {
            tmp_value = num % base;
            switch (tmp_value)
            {
                case 10:    str[ind++] = 'A';
                            break;
                case 11:    str[ind++] = 'B';
                            break;
                case 12:    str[ind++] = 'C';
                            break;
                case 13:    str[ind++] = 'D';
                            break;
                case 14:    str[ind++] = 'E';
                            break;
                case 15:    str[ind++] = 'F';
                            break;
                default:    str[ind++] = tmp_value + '0';
                            break;
            }
            num /= base;
        }
        strcat(str, "x0");
        reverse(str);
        break;
    case OCT_BASE:
        ind = strlen(str);
        while (num) {
            tmp_value = num % base;
            str[ind++] = tmp_value + '0';
            num /= base;
        }
        strcat(str, "0");
        reverse(str);
        break;
    case BIN_BASE:
        strcat(str, "b");
        ind = strlen(str);
        while (num) {
            tmp_value = num % base;
            str[ind++] = tmp_value + '0';
            num /= base;
        }
        reverse(str);
        break;
    default:
        printf("Invalid base!\n");
        free(str);
        exit(EXIT_FAILURE);
    }
    return;
}  

int main() {
    char * str = (char *) calloc(sizeof(char), STRING_SIZE);
    assert(str != NULL);
    int num = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    itob(num, str, HEX_BASE);
    printf("Hexadecimal: %s\n", str);
    itob(num, str, OCT_BASE);
    printf("Octal: %s\n", str);
    itob(num, str, BIN_BASE);
    printf("Binary: %s\n", str);
    free(str);
    return 0;
}