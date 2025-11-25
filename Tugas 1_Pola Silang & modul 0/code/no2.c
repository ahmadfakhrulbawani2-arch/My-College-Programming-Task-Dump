#include <stdio.h>

int main() {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    if(a <= 0 || b <= 0 || c <= 0) {
        printf("Gomenasai, segitiga tidak dapat dibuat.");
    } else if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) {
        printf("Yatta, aku bisa membentuk segitiga!");
    } else {
        printf("Gomenasai, segitiga tidak dapat dibuat.");
    }
    return 0;
}