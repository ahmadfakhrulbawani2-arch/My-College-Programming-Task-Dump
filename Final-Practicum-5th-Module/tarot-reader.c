// the explanation is in the bottom

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdint-gcc.h>

#define ll long long
#define POSINF 100000000
#define NEGINF -100000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

ll root4(ll d) {
    ll min = 0, max = 35000;
    while(min <= max) {
        ll med = (max + min) / 2;

        ll a = med * med;
        if (a > d) { 
            max = med - 1; 
            continue; 
        }

        ll b = a * med;
        if (b > d) { 
            max = med - 1;
            continue;
        }

        ll c = b * med;

        if (c == d) return med;
        else if (c < d) min = med + 1;
        else max = med - 1;
    }
    return -1;
}

void solve() {
    ll d, m, n;
    scanf("%lld %lld %lld", &d, &m, &n);
    if(d < 0) {
        printf("NO\n");
        return;
    }

    ll dis = abs(n - m) + 1;
    ll root4th = root4(d);
    if(root4th < 0) {
        printf("NO\n");
    } else {
        if(root4th + m <= n) {
            printf("YES\n");
        } else printf("NO\n");
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}