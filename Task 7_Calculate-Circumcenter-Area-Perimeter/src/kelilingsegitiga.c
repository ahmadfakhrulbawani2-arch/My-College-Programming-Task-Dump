#include <stdio.h>
#include <math.h>
#include "kelilingsegitiga.h"

#define ll long long

double calcDis(ll x1, ll y1, ll x2, ll y2) 
{
    double res = sqrt( ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) );
    return res;
}


