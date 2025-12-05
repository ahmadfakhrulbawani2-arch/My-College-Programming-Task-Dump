// the explanation is in the bottom
// Bismillahirrahmanirrahim
// dengan menyebut nama Allah Subhanahuwata'ala yang Mahapengasih lagi Mahapenyayang.

// Header doang banyak, tapi gak dipake awokawokawoawok
#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

//  Terusin tambahin define terus sampai meleduck wkkwkkkwkwkw
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int usi;
#define POSINT 100000000
#define NEGINT -100000000
#define NEGLL -1000000000000000000
#define POSLL 1000000000000000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define DECISI(a, b) ((a > b) ? (1) : (2))
#define REP2(i, m, n) for(ll i = m; i <= n; i++) // change i with var. name.
#define REP1(i, m, n) for(ll i = m; i < n; i++) // change i with var. name.
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90
#define ASCII0 48
#define ASCII9 57
#define AWAL int main(void) {
#define AKHIR return 0;}

ll gcdll(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    return (b == 0 ? a : gcdll(b, a % b));
}

ll solveSteps(ll from, ll to, ll x) {
    if (from <= 0 || to <= 0) return POSLL;
    ll g = gcdll(from, to);
    if (x % g != 0) return POSLL;

    /* scale down */
    from /= g;
    to   /= g;
    x    /= g;

    if (x == from || x == to) return 0; 

    ll a = from, b = to;
    ll steps = 0; 

    while (b != 0) {
        if (a < b) {
            ll tmp = a; a = b; b = tmp;
        }

        ll q = a / b;
        ll r = a % b;

        if (x <= a && x >= a - (q - 1) * b) {
            if ((a - x) % b == 0) {
                ll k = (a - x) / b;
                if (0 <= k && k < q) {
                    return steps + k;
                }
            }
        }

        steps += (2 * q - 1);

        a = b;
        b = r;
    }

    return POSLL;
}

void showMins(int a, int b, int x) {

    if (x > FNDMAX(a, b) || x % gcdll(a, b) != 0) {
        printf("IMPOSSIBLE\n");
        return;
    }

    if (a == 1 && b == 1 && x == 1) {
        printf("0\n");
        return;
    }

    if (x == a || x == b) {
        printf("1\n");
        return;
    }

    ll res1 = solveSteps((ll)b, (ll)a, (ll)x);
    ll res2 = solveSteps((ll)a, (ll)b, (ll)x);
    ll actualMin = FNDMIN(res1, res2);

    if (actualMin >= POSLL/2) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%lld\n", actualMin + 1);
    }
}

void main2() {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    showMins(a, b, x);
}

AWAL

    int t;
    scanf("%d", &t);
    while(t--) {
        main2();
    }

AKHIR