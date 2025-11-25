#include <stdio.h>

int main() {
    long long a;
    scanf("%lld", &a);

    long long b;
    if(a == 0) {
        printf("1");
    } else {
        ++a;
        a = a * 2 - 1;
        b = a * (a + 1) * (2 * a + 1) / 6;
        printf("%lld", b);
    }
    return 0;
}