#include <stdio.h>

int main() {
    int n0, n1, n2, n3;
    scanf("%d %d %d %d", &n3, &n2, &n1, &n0);
    int num = n0 * 1 + n1 * 2 + n2 * 4 + n3 * 8;

    switch(num) {
        case 0:
            printf("1 1 1 1 1 1 0");
            break;
        case 1:
            printf("0 1 1 0 0 0 0");
            break;
        case 2:
            printf("1 1 0 1 1 0 1");
            break;
        case 3:
            printf("1 1 1 1 0 0 1");
            break;
        case 4:
            printf("0 1 1 0 0 1 1");
            break;
        case 5:
            printf("1 0 1 1 0 1 1");
            break;
        case 6:
            printf("1 0 1 1 1 1 1");
            break;
        case 7:
            printf("1 1 1 0 0 0 0");
            break;
        case 8:
            printf("1 1 1 1 1 1 1");
            break;
        case 9:
            printf("1 1 1 1 0 1 1");
            break;
        default:
            printf("0 0 0 0 0 0 0");
            break;
    }
    return 0;
}