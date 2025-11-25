#include <stdio.h>

int main() {

    char cek;
    unsigned long long a, b;

    scanf("%llu %llu %c", &a, &b, &cek);

    if(!(cek == 'Y' || cek == 'N')) {
        printf("MUNDURRR!!!");
        return 0;
    }

    switch (cek)
    {
    case 'Y':
        if(a >= b) {
            printf("Strategi C");
        } else {
            printf("Strategi D");
        }
        break;
    case 'N':
        if(a >= b) {
            printf("Strategi A");
        } else {
            printf("Strategi B");
        }
        break;
    default:
        break;
    }
    return 0;
}