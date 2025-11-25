#include <stdio.h>

int main() {
    long long b, c;
    scanf("%lld %lld", &b, &c);

    if(b & c) {
        printf("we'll try again tomorrow :(");
    } else {
        printf("Hop on roblox!");
    }
    return 0;
}
