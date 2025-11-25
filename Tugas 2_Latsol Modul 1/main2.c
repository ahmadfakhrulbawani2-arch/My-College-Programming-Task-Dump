#include <stdio.h>

int main() {
    char str1[8];
    char str2[8];

    scanf("%c%c%c%c%c%c%c%c", &str1[0], &str1[1], &str1[2], &str1[3], &str1[4], &str1[5], &str1[6], &str1[7]);
    getchar();
    scanf("%c%c%c%c%c%c%c%c", &str2[0], &str2[1], &str2[2], &str2[3], &str2[4], &str2[5], &str2[6], &str2[7]);

    int sum1 = 0;
    int sum2 = 0;

    sum1 = str1[0] + str1[1] + str1[2] + str1[3] + str1[4] + str1[5] + str1[6] + str1[7];

    sum2 = str2[0] + str2[1] + str2[2] + str2[3] + str2[4] + str2[5] + str2[6] + str2[7];

    if(sum1 == sum2) {
        printf("YA");
    }

    int bnykOdd1 = 0, bnykEven1 = 0, bnykOdd2 = 0, bnykEven2 = 0;

    if(str1[0] % 2 == 0) {
        bnykEven1 += 1;
    } else {
        bnykOdd1 += 1;
    }

    if(str1[1] % 2 == 0) {
        bnykEven1 += 1;
    } else {
        bnykOdd1 += 1;
    }

    if(str1[2] % 2 == 0) {
        bnykEven1 += 1;
    } else {
        bnykOdd1 += 1;
    }

    if(str1[3] % 2 == 0) {
        bnykEven1 += 1;
    } else {
        bnykOdd1 += 1;
    }

    if(str1[4] % 2 == 0) {
        bnykEven1 += 1;
    } else {
        bnykOdd1 += 1;
    }

    if(str1[5] % 2 == 0) {
        bnykEven1 += 1;
    } else {
        bnykOdd1 += 1;
    }

    if(str1[6] % 2 == 0) {
        bnykEven1 += 1;
    } else {
        bnykOdd1 += 1;
    }

    if(str1[7] % 2 == 0) {
        bnykEven1 += 1;
    } else {
        bnykOdd1 += 1;
    }

    if(str2[0] % 2 == 0) {
        bnykEven2 += 1;
    } else {
        bnykOdd2 += 1;
    }

    if(str2[1] % 2 == 0) {
        bnykEven2 += 1;
    } else {
        bnykOdd2 += 1;
    }

    if(str2[2] % 2 == 0) {
        bnykEven2 += 1;
    } else {
        bnykOdd2 += 1;
    }

    if(str2[3] % 2 == 0) {
        bnykEven2 += 1;
    } else {
        bnykOdd2 += 1;
    }

    if(str2[4] % 2 == 0) {
        bnykEven2 += 1;
    } else {
        bnykOdd2 += 1;
    }

    if(str2[5] % 2 == 0) {
        bnykEven2 += 1;
    } else {
        bnykOdd2 += 1;
    }

    if(str2[6] % 2 == 0) {
        bnykEven2 += 1;
    } else {
        bnykOdd2 += 1;
    }

    if(str2[7] % 2 == 0) {
        bnykEven2 += 1;
    } else {
        bnykOdd2 += 1;
    }

    if(bnykEven1 >= bnykOdd1 && bnykEven2 >= bnykOdd2 && sum1 != sum2) {
        printf("YA");
    } else if(sum1 != sum2) {
        printf("TIDAK");
    }

    return 0;
}
