#include <stdio.h>

int main() {

    long long a, b;
    char operator;

    scanf("%lld %c %lld", &a, &operator, &b);

    if(a == b) {
        a = 0;
    }

    if((a % b == 0) || (b % a == 0)) {
        if(a > b) {
            b *= -1;
        } else {
            a *= -1;
        }
    }

    long double result = 0;
    switch(operator) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '/':
            if(b == 0) {
                break;
            } else {
                result = (long double) a / b;
            }
            break;
        case '*':
            result = a * b;
            break;
        default:
            break;
    }

    printf("%.2Lf", result);
    return 0;
}