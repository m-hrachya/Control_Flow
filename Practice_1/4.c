#include <stdio.h>

void drow_triangle(int row) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < (((2 * row) - 1) / 2) - i; ++j) {
            printf(" ");
        }
        for (int k = 0; k < (2 * i) + 1; ++k) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int row_count = 0;
    printf("Enter row count: ");
    scanf("%d", &row_count);
    drow_triangle(row_count);
    return 0;
}