#include <stdio.h>

int main() {
    int a1, b1, a2, b2, a3, b3;
    scanf("%d %d\n%d %d\n%d %d", &a1, &b1, &a2, &b2, &a3, &b3);
    if(a1 % b1 == 0) {
        printf("0\n");
    } else if(a1 > b1){
        int c = b1 - (a1 % b1);
        printf("%d\n", c);
    } else {
        int c = b1 - a1;
        printf("%d\n", c);
    }
    if(a2 % b2 == 0) {
        printf("0\n");
    } else if(a2 > b2) {
        int c = b2 - (a2 % b2);
        printf("%d\n", c);
    } else {
        int c = b2 - a2;
        printf("%d\n", c);
    }
    if(a3 % b3 == 0) {
        printf("0\n");
    } else if(a3 > b3) {
        int c = b3 - (a3 % b3);
        printf("%d\n", c);
    } else {
        int c = b3 - a3;
        printf("%d\n", c);
    }
    return 0;
}