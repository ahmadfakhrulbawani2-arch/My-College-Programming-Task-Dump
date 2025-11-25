#include <stdio.h>

int main() {

    long long n;
    scanf("%lld", &n);

    n %= 100000;
    n = n * n * n;
    long long m = n % 100000;
    printf("%05lld", m);
    return 0;
}