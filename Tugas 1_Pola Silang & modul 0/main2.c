#include <stdio.h>
#include <math.h>

int main() {
    long long x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    double theta1 = 0, theta2 = 0;
    scanf("%lld %lld %lf %lld %lld", &x1, &y1, &theta1, &x2, &y2);

    theta2 = atan2((y2 - y1), (x2 - x1));

    if(x1 == x2 && y1 == y2) {
        printf("Halo, Dan, aku lel.");
    } else if((theta1 - theta2) < 0.01 && (theta2 - theta1) < 0.01) {
        printf("Aku akan berjalan lurus ke Dan!");
    } else {
        printf("Aku akan berputar ke arah tujuan!");
    }

    return 0;
}
