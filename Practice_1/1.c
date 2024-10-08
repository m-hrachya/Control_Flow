#include <stdio.h>

int fib(int num) {
    if (num < 0) return -1;
    if (num == 0) return 0;
    if (num == 1) return 1;
    return fib(num - 1 ) + fib(num - 2);
}

int main() {
   int num = 0;
   printf("Enter N: ");
   scanf("%d", &num);
   printf("Result: %d\n", fib(num));
   return 0;
}