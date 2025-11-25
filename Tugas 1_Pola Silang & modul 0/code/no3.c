#include <stdio.h>

int main() {
    unsigned long long a, b;
    scanf("%llu %llu", &a, &b);

    if (a & b) {
        printf("we'll try again tomorrow :(");
    } else {
        printf("hop on roblox!");
    }

    return 0;
}
