#include <stdio.h>
#include <math.h>
#include "luassegitiga.h"

#define ll long long

double calcArea(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3)
{
    double res = fabs( (x1 * (y3 - y2)) + (x2 * (y1 - y3)) + (x3 * (y2 - y1)) );
    res /= 2;
    return res;
}