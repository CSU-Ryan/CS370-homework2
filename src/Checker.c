#include <stdio.h>

int check(const int divisor, const int dividend) {
    printf("Checker process [%d]: Starting.\n", getpid());

    bool divides = dividend % divisor == 0);

    printf("Checker process [%d]: %d *%S* divisible by %d.\n",
        getpid(),
        dividend,
        (divides) ? "IS" : "IS NOT",
        divisor;
        );
    printf("Checker process [%d]: Returning %d.\n", getpid(), divides);

    return divides;
}
