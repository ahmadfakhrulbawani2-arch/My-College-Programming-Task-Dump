#include <stdio.h>

int main() {
    unsigned long long n = 0, x = 0, vx = 0, p1 = 0, vp1 = 1, p2 = 0, vp2 = 0;
    scanf("%llu\n%llu %llu\n%llu %llu\n%llu %llu", &n, &x, &vx, &p1, &vp1, &p2, &vp2);

    while(n > x && 0 < x) {
        x += vx;
        if(x > n || x <= 0) {
            printf("bebas");
            break;
        } else if(x == p1 - 1 || x == p2 - 1 || x == p1 + 1 || x == p2 + 1 || x == p1 || x == p2) {
            printf("Tertangkap");
            break;
        }

        if(p1 > p2) {
            p1 += vp1;
            p2 += vp2;
            if(p2 >= p1) {
                p2 = p1 - 1;
            }
        } else if(p2 > p1) {
            p1 += vp1;
            p2 += vp2;
            if(p1 >= p2) {
                p1 = p2 - 1;
            }
        }
        
    }
    return 0;
}