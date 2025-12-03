// the explanation is in the bottom
// Bismillahirrahmanirrahim
// dengan menyebut nama Allah Subhanahuwata'ala yang Mahapengasih lagi Mahapenyayang.

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

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int usi;
#define POSINF 100000000
#define NEGINF -100000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

ll combo(int n, int k) {
    if(k > n-k) k = n-k;
    ll res = 1;
    for(ll i = 1; i <= k; i++) {
        res = res * (n - i + 1);
        res /= i;
    }
    return res;
}

int main(void) {
    ll n;
    scanf("%lld", &n);
    ll psc[n+1];
    psc[0] = 1; psc[n] = 1; psc[1] = n; psc[n-1] = n;

    for(ll i = 2; i < n-1; i++) {
        psc[i] = combo(n, i);
    }

    for(ll i = 0; i < n+1; i++) {
        printf("%lld ", psc[i]);
    }
    return 0;
}

// EXPLANATION:
/*

karena C(n, k) = C(n, n-k) maka k = n-k jika k awal > n-k. Ini memastikan K seminim mungkin

Mengapa 
for(ll i = 1; i <= k; i++) {
        res = res * (n - i + 1);
        res /= i;
} 

Karena gini (n * n-1 * n-2 *...* (n-k+1)) / (1 * 2 * 3 * ... * k)

Yang atas itu sudah n! / (n-k)!

misal C(5, 2) berarti:

= 5! / (5-2)! * 2!
= 5*4*3*2*1 / (3! * 2!)
= 5 * 4 / 2!

5 dikalikan sampai 5-2+1 yaitu 4.
*/