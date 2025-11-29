#include <stdio.h>
#include <math.h>
#include "circumcenter.h"

#define ll long long

// in circumcenter.c

// in circumcenter.c
ll sqr(ll a) {
    return a * a;
}

double calcCircumX(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) 
{
    ll x1sqr = sqr(x1);
    ll x2sqr = sqr(x2);
    ll x3sqr = sqr(x3);
    ll y1sqr = sqr(y1);
    ll y2sqr = sqr(y2);
    ll y3sqr = sqr(y3);

    double det = 2 * ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));
    double xP = ((x1sqr + y1sqr) * (y2 - y3)) + ((x2sqr + y2sqr) * (y3 - y1)) + ((x3sqr + y3sqr) * (y1 - y2));
    xP /= det;
    return xP;
}
double calcCircumY(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) 
{
    ll x1sqr = sqr(x1);
    ll x2sqr = sqr(x2);
    ll x3sqr = sqr(x3);
    ll y1sqr = sqr(y1);
    ll y2sqr = sqr(y2);
    ll y3sqr = sqr(y3);

    double det = 2 * ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));
    double yP = ((x1sqr + y1sqr) * (x3 - x2)) + ((x2sqr + y2sqr) * (x1 - x3)) + ((x3sqr + y3sqr) * (x2 - x1));
    yP /= det;
    return yP;
}
