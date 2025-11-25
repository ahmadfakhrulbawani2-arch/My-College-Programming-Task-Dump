#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);

    int i = 0;
    while (i < X) {
        int j = 0;
        while (j < X) {
            if (j == i || j == X - i - 1) {
                printf("*");
            } else {
                printf(" ");
            }
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}
