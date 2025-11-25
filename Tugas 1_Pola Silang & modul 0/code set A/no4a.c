#include <stdio.h>

int main() {
    int n, m, bk, bv, kk, kv;
    scanf("%d %d\n%d %d %d %d", &n, &m, &bk, &kk, &bv, &kv);

    int x = 0, y = 0;
    x = kv - kk;
    y = bv - bk;

    x = (x >= 0) ? x : x * -1;
    y = (y >= 0) ? y : y * -1;
    int jarakTotal = x + y;

    if(jarakTotal == 1 || (x == 1 && y == 1)) {
        printf("Now I am the master.");
    } else {
        printf("Only a master of evil, Darth.");
    }
    
    return 0;
}