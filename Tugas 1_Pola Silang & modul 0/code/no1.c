#include <stdio.h>
#include <math.h>

int main() {
    long long x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    double theta1, theta2, diff;
    scanf("%lld %lld %lf %lld %lld", &x1, &y1, &theta1, &x2, &y2);
    theta2 = atan2(y2 - y1, x2 - x1);

    if(theta2 - theta1 > 0) {
        diff = theta2 - theta1;
    } else {
        diff = theta1 - theta2;
    }
    if((theta1 == 3.141 || theta1 == -3.141) && (x1 != x2 || y1 != y2)) {
        if((theta1 + theta2 < 0.01) || (theta1 - theta2 < 0.01)) {
            printf("Aku akan berjalan lurus ke Dan!");
            return 0;
        }
    }
    
    if(x1 == x2 && y1 == y2) {
        printf("Halo, Dan, aku Iel.");
    } else if(diff < 0.01) {
        printf("Aku akan berjalan lurus ke Dan!");
    } else {
        printf("Aku akan berputar ke arah tujuan!");
    }

    return 0;
}
