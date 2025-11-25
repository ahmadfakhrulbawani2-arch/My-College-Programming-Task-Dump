#include <stdio.h>

int main() {
    double a, b;
    char c;
    double d;
    scanf("Berapa nilai dari %lf %c %lf?", &a, &c, &b);

    switch(c) {
        case '+':
            d = a + b;
            printf("%.0lf %c %.0lf = %.2lf", a, c, b, d);
            break;
        case '-':
            d = a - b;
            printf("%.0lf %c %.0lf = %.2lf", a, c, b, d);
            break;
        case 'x':
            d = a * b;
            printf("%.0lf %c %.0lf = %.2lf", a, c, b, d);
            break;
        case '*':
            d = a * b;
            printf("%.0lf %c %.0lf = %.2lf", a, c, b, d);
            break;
        case ':':
            if(b != 0){
                d = (double)a / b;
                printf("%.0lf %c %.0lf = %.2lf", a, c, b, d);
                break;
            } else {
                printf("Error, can't divide by zero");
                break;
            }
        case '/':
            if(b != 0){
                d = (double)a / b;
                printf("%lf %c %lf = %.2lf", a, c, b, d);
                break;
            } else {
                printf("Error, can't divide by zero");
                break;
            }
        default:
            printf("Invalid operator");
            break;
    }
    return 0;
}