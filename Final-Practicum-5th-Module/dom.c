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
#define POSINF 100000000
#define NEGINF -100000000
#define FNDMIN(a, b) ((a < b) ? (a) : (b))
#define FNDMAX(a, b) ((a > b) ? (a) : (b))
#define ASCIIa 97
#define ASCIIz 122
#define ASCIIA 65
#define ASCIIZ 90

int main(void) {
    ll n;
    scanf("%lld", &n);
    ll arr[n]; ll best = NEGINF; 

    ll flagPos[100000] = {0};
    ll flIdx = 0;

    for(ll i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        best = FNDMAX(best, arr[i]);
        if(arr[i] > 0) flagPos[flIdx++] = i;
    }

    if(best < 0) {
        ll x = -best; // parah emang gak dibolehin pakai stdlib.h
        printf("Critical instability detected with energy drain of %lld! The Dombest fragment is collapsing!\n", x);
        printf("CODE: %lld\n", best);
    } else if(best == 0) {
        printf("No usable signal detected! The fragment dissolves into pure static!\nCODE: 0\n");
    } else {
        // Kadane's algorithm w/ subarray indexing to get sub array.

        ll netStart = 0, netEnd = 0;

        ll currStart = 0;

        ll maxSum = arr[0]; // the "Actual" subarray max
        ll maxEnding = arr[0]; // the "Recent" or "current" subarray max

        for(ll i = 1; i < n; i++) {
            if(maxEnding + arr[i] < arr[i]) {
                maxEnding = arr[i];
                currStart = i;
            } else {
                maxEnding += arr[i];
            }

            if(maxEnding > maxSum) {
                maxSum = maxEnding;

                netStart = currStart;
                netEnd = i;
            }
        }

        printf("Peak energy resonance at %lld! Clearance granted, Dombest archives unlocked!\nCODE: ", maxSum);
        for(ll i = netStart; i <= netEnd; i++) {
            printf("%lld ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
