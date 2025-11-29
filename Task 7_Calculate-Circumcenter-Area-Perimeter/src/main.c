#include <stdio.h>
#include <math.h>
#include "circumcenter.h"
#include "luassegitiga.h"
#include "kelilingsegitiga.h"

#define ll long long

// // in luassegitiga.h
// double calcArea(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3);

// // in kelilingsegitiga.h
// double calcDis(ll x1, ll y1, ll x2, ll y2);

// // in circumcenter.h
// double calcCircumX(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3);
// double calcCircumY(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3);

// // in circumcenter.c
// ll sqr(ll a) {
//     return a * a;
// }

int main(void) 
{
    ll x1, x2, x3, y1, y2, y3;
    scanf("%lld %lld", &x1, &y1);
    scanf("%lld %lld", &x2, &y2);
    scanf("%lld %lld", &x3, &y3);

    double hasilLuas, hasilKeliling, xP, yP;

    hasilLuas = calcArea(x1, x2, x3, y1, y2, y3);
    printf("Luas segitiga: %lf\n", hasilLuas);

    double AB, BC, AC, total;
    AB = calcDis(x1, y1, x2, y2);
    BC = calcDis(x2, y2, x3, y3);
    AC = calcDis(x1, y1, x3, y3);
    total = AB + BC + AC;
    printf("Keliling segitiga: %lf\n", total);

    xP = calcCircumX(x1, x2, x3, y1, y2, y3);
    yP = calcCircumY(x1, x2, x3, y1, y2, y3);
    printf("Titik tengah lingkaran: (%lf, %lf)\n", xP, yP);

    return 0;
}

// // in luassegitiga.c
// double calcArea(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3)
// {
//     double res = fabs( (x1 * (y3 - y2)) + (x2 * (y1 - y3)) + (x3 * (y2 - y1)) );
//     res /= 2;
//     return res;
// }

// // in kelilingsegitiga.c
// double calcDis(ll x1, ll y1, ll x2, ll y2) 
// {
//     double res = sqrt( ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) );
//     return res;
// }

// // in circumcenter.c
// double calcCircumX(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) 
// {
//     ll x1sqr = sqr(x1);
//     ll x2sqr = sqr(x2);
//     ll x3sqr = sqr(x3);
//     ll y1sqr = sqr(y1);
//     ll y2sqr = sqr(y2);
//     ll y3sqr = sqr(y3);

//     double det = 2 * ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));
//     double xP = ((x1sqr + y1sqr) * (y2 - y3)) + ((x2sqr + y2sqr) * (y3 - y1)) + ((x3sqr + y3sqr) * (y1 - y2));
//     xP /= det;
//     return xP;
// }
// double calcCircumY(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) 
// {
//     ll x1sqr = sqr(x1);
//     ll x2sqr = sqr(x2);
//     ll x3sqr = sqr(x3);
//     ll y1sqr = sqr(y1);
//     ll y2sqr = sqr(y2);
//     ll y3sqr = sqr(y3);

//     double det = 2 * ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));
//     double yP = ((x1sqr + y1sqr) * (x3 - x2)) + ((x2sqr + y2sqr) * (x1 - x3)) + ((x3sqr + y3sqr) * (x2 - x1));
//     yP /= det;
//     return yP;
// }




// Solusi: 
/*
** Rumus keliling

K = AB + BC + AC
dengan A(x1, y1) dan B(x2, y2) panjang AB = sqrt((x2 - x1)(x2 - x1) + (y2 - y1)(y2 - y1))

** Rumus luas

L = (0.5) fabs( (x1 * (y3 - y2)) + (x2 * (y1 - y3)) + (x3 * (y2 - y1)) )

** Rumus tipus

Xp = ((x1sqr + y1sqr) * (y2 - y3)) + ((x2sqr + y2sqr) * (y3 - y1)) + ((x3sqr + y3sqr) * (y1 - y2)) / det
Yp = ((x1sqr + y1sqr) * (x3 - x2)) + ((x2sqr + y2sqr) * (x1 - x3)) + ((x3sqr + y3sqr) * (x2 - x1)) / det

*/