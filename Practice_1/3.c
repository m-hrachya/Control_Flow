#include <stdio.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; ++i) {
        if (!(num % i)) return 0;
    }
    return 1;
}

void is_sum_of_primes(int num) {
    int not_found = 1;
    for (int i = 1; i < num; ++i) {
        for (int j = num; j >= i; --j) {
            if (is_prime(j) && is_prime(i) && (i + j == num)) {
                not_found = 0;
                printf("%d and %d\n", i, j);
            }
        }
    }
    if (not_found) {
        printf("Can't represent as sum of prime numbers' sum!\n");
    }
    return;
}

int main() {
    int number = 0;
    printf("Enter your number: ");
    scanf("%d", &number);
    is_sum_of_primes(number);
    return 0;
}
